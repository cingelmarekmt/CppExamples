#pragma once

namespace example
{
	class ThreadTaskF;

	class ThreadPoolF : public std::enable_shared_from_this<ThreadPoolF>
	{
	public:

		using TaskElementFType = std::shared_ptr<ThreadTaskF>;
		using TaskContainerFType = std::vector<TaskElementFType>;

	private:

		std::mutex _mutex;
		std::thread _thread;
		std::atomic<bool> _isRunning;

		TaskContainerFType _tasks;

	public:

		ThreadPoolF();
		virtual ~ThreadPoolF();

	public:

		bool Empty() const;
		size_t Size() const;

		void Add(const TaskElementFType & task);
		void Remove(const TaskElementFType & task);
		void Clear();

	public:

		bool IsRunning() const;
		void Start();
		void Stop();

	private:

		void Thread();

	};

}
