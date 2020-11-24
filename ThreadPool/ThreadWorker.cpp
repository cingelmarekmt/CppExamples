#include "PrecompiledDeclarations.h"

#include "ThreadWorker.h"
#include "ThreadTask.h"

namespace example
{

	ThreadWorker::ThreadWorker() :
		_isRunning(false)
	{

	}

	ThreadWorker::~ThreadWorker()
	{
		Stop();
	}

	void ThreadWorker::Add(const ThreadWorker::TaskElementSType & task)
	{
		_tasks.push_back(task);
	}

	bool ThreadWorker::IsRunning() const
	{
		return _isRunning.load(std::memory_order_relaxed);
	}

	void ThreadWorker::Start()
	{
		if (_isRunning.load(std::memory_order_relaxed) == false)
		{
			_isRunning.store(true, std::memory_order_relaxed);
			_thread = std::thread(std::bind(&ThreadWorker::Thread, shared_from_this()));
		}
	}

	void ThreadWorker::Stop()
	{
		if (_isRunning.load(std::memory_order_relaxed))
		{
			_isRunning.store(false, std::memory_order_relaxed);
			if (_thread.joinable())
			{
				_thread.join();
			}
		}
	}

	void ThreadWorker::Thread()
	{
		std::cout << "Thread [" << std::this_thread::get_id() << "] starting..." << std::endl;

		auto CopyTaskLambda = [=](TaskContainerWType & sTasks, TaskContainerSType & tTasks)
		{
			const std::lock_guard<std::mutex> lock(_mutex);
			for (auto iter = sTasks.begin(); iter != sTasks.end(); /*++iter*/)
			{
				const auto task = iter->lock();
				if (task == nullptr)
				{
					iter = sTasks.erase(iter);
				}
				else
				{
					tTasks.push_back(task);
					++iter;
				}
			}
		};

		while (_isRunning.load(std::memory_order_relaxed))
		{
			TaskContainerSType tasks;
			CopyTaskLambda(_tasks, tasks);

			for (const auto & task : tasks)
			{
				auto t1 = std::chrono::high_resolution_clock::now();
				task->Step();
				auto t2 = std::chrono::high_resolution_clock::now();
				task->PushStepDuration(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1));
			}



		}

		std::cout << "Thread [" << std::this_thread::get_id() << "] ending..." << std::endl;
		std::this_thread::yield();
	}

}
