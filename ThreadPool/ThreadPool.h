#pragma once

#include "ThreadTask.h"
#include "ThreadWorker.h"

namespace example
{
	class ThreadTask;
	class ThreadWorker;

	class ThreadPool : public std::enable_shared_from_this<ThreadPool>
	{
	public:

		using TaskElementType = std::shared_ptr<ThreadTask>;
		using TaskContainerType = std::vector<TaskElementType>;

		using WorkerElementType = std::shared_ptr<ThreadWorker>;
		using WorkerContainerType = std::unordered_set<WorkerElementType>;

	private:

		TaskContainerType _tasks;
		WorkerContainerType _workers;

	public:

		ThreadPool();
		virtual ~ThreadPool();

	public:

		bool Empty() const;
		size_t Size() const;

		void Add(const std::shared_ptr<ThreadTask> & task);
		void Remove(const std::shared_ptr<ThreadTask> & task);
		void Clear();

	private:

		WorkerElementType FindThreadWorker();

	};

}
