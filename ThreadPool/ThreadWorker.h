#pragma once

namespace example
{
	class ThreadPool;
	class ThreadTask;

	class ThreadWorker : public std::enable_shared_from_this<ThreadWorker>
	{
	private:

		friend class ThreadPool;

	public:

		using TaskElementType = ThreadTask;
		using TaskElementWType = std::weak_ptr<TaskElementType>;
		using TaskContainerWType = std::vector<TaskElementWType>;
		using TaskElementSType = std::shared_ptr<TaskElementType>;
		using TaskContainerSType = std::vector<TaskElementSType>;

	private:

		std::mutex _mutex;
		std::thread _thread;
		std::atomic<bool> _isRunning;

		std::chrono::nanoseconds _minStepInterval;
		std::chrono::nanoseconds _maxStepInterval;

		std::weak_ptr<ThreadPool> _threadPool;
		TaskContainerWType _tasks;

	public:

		ThreadWorker();
		virtual ~ThreadWorker();

	public:

		void Add(const TaskElementSType & task);

	private:

		bool IsRunning() const;
		void Start();
		void Stop();

		void Thread();

	};

}
