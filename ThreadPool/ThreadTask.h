#pragma once

namespace example
{

	class ThreadTask : public std::enable_shared_from_this<ThreadTask>
	{
	public:

		using IdType = size_t;

	private:

		IdType _id;

		std::chrono::nanoseconds _avgStepDuration;
		std::vector<std::chrono::nanoseconds> _stepDurations;

	public:

		ThreadTask();
		virtual ~ThreadTask();

	public:

		const IdType & GetId() const;

		void PushStepDuration(const std::chrono::nanoseconds & stepDuration);

	public:

		virtual void Step();

	};

}
