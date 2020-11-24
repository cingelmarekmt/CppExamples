#include "PrecompiledDeclarations.h"

#include "ThreadPool.h"
#include "ThreadTask.h"
#include "ThreadWorker.h"

using namespace std;

namespace example
{

	ThreadPool::ThreadPool()
	{

	}

	ThreadPool::~ThreadPool()
	{
		Clear();
	}

	bool ThreadPool::Empty() const
	{
		return _tasks.empty();
	}

	size_t ThreadPool::Size() const
	{
		return _tasks.size();
	}

	void ThreadPool::Add(const std::shared_ptr<ThreadTask> & task)
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

			const auto threadWorker = FindThreadWorker();
			if (threadWorker)
			{
				threadWorker->Add(task);
			}
		}
	}

	void ThreadPool::Remove(const std::shared_ptr<ThreadTask> & task)
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

	void ThreadPool::Clear()
	{
		_tasks.clear();

		for (const auto & worker : _workers)
		{
			worker->Stop();
		}
		_workers.clear();
	}

	ThreadPool::WorkerElementType ThreadPool::FindThreadWorker()
	{
		ThreadPool::WorkerElementType threadWorker;

		if (_workers.empty())
		{
			threadWorker = std::make_shared<ThreadWorker>();
			threadWorker->Start();

			_workers.insert(threadWorker);
		}

		return threadWorker;
	}

}
