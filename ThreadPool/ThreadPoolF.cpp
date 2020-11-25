#include "PrecompiledDeclarations.h"

#include "ThreadPoolF.h"
#include "ThreadTaskF.h"

namespace example
{

	ThreadPoolF::ThreadPoolF() :
		_isRunning(false)
	{

	}

	ThreadPoolF::~ThreadPoolF()
	{

	}

	bool ThreadPoolF::Empty() const
	{
		return _tasks.empty();
	}

	size_t ThreadPoolF::Size() const
	{
		return _tasks.size();
	}

	void ThreadPoolF::Add(const TaskElementFType & task)
	{
		const auto iter = std::find_if(_tasks.begin(), _tasks.end(),
			[&task](const auto & element)
			{
				return task->GetId() == element->GetId();
			}
		);

		if (iter == _tasks.end())
		{
			_tasks.push_back(task);
		}
	}

	void ThreadPoolF::Remove(const TaskElementFType & task)
	{
		const auto iter = std::find_if(_tasks.begin(), _tasks.end(),
			[&task](const auto & element)
			{
				return task->GetId() == element->GetId();
			}
		);

		if (iter != _tasks.end())
		{
			_tasks.erase(iter);
		}
	}

	void ThreadPoolF::Clear()
	{
		_tasks.clear();
	}

	bool ThreadPoolF::IsRunning() const
	{
		return _isRunning.load(std::memory_order_relaxed);
	}

	void ThreadPoolF::Start()
	{
		if (_isRunning.load(std::memory_order_relaxed) == false)
		{
			_isRunning.store(true, std::memory_order_relaxed);
			_thread = std::thread(std::bind(&ThreadPoolF::Thread, shared_from_this()));
		}
	}

	void ThreadPoolF::Stop()
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

	void ThreadPoolF::Thread()
	{
		std::cout << "Thread [" << std::this_thread::get_id() << "] starting..." << std::endl;
		const auto minStepInterval = std::chrono::milliseconds(15);

		while (_isRunning.load(std::memory_order_relaxed))
		{
			const auto t1 = std::chrono::high_resolution_clock::now();
			for (const auto & task : _tasks)
			{
				task->StartStep();
			}

			//for (const auto & task : _tasks)
			//{
			//	task->StepInternal();
			//}

			for (const auto & task : _tasks)
			{
				task->StopStep();
			}

			const auto t2 = std::chrono::high_resolution_clock::now();
			const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

			if (duration < minStepInterval)
			{
				const auto expectedInterval = minStepInterval - duration;
				std::this_thread::sleep_for(expectedInterval);
			}
			else
			{
				std::cout << "Thread duration: [" << duration.count() << "]" << std::endl;
			}
		}

		std::cout << "Thread [" << std::this_thread::get_id() << "] ending..." << std::endl;
		std::this_thread::yield();
	}

}
