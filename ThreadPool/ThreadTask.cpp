#include "PrecompiledDeclarations.h"

#include "ThreadTask.h"

namespace example
{

	inline ThreadTask::IdType GenerateTaskId()
	{
		static std::mutex mtx;
		static ThreadTask::IdType taskId = 0;

		const std::lock_guard<std::mutex> lock(mtx);
		return ++taskId;
	}

	ThreadTask::ThreadTask() :
		_id(GenerateTaskId())
	{
		//std::cout << "task id: " << _id << std::endl;
	}

	ThreadTask::~ThreadTask()
	{

	}

	const ThreadTask::IdType & ThreadTask::GetId() const
	{
		return _id;
	}

	void ThreadTask::PushStepDuration(const std::chrono::nanoseconds & stepDuration)
	{
		if (_stepDurations.size() > 100)
		{
			_stepDurations.erase(_stepDurations.begin());
		}

		_stepDurations.push_back(stepDuration);
		//std::cout << "T: " << stepDuration.count() << std::endl;

		std::chrono::duration<double> sum;
		for (const auto & tmpStepDuration : _stepDurations)
		{
			sum += std::chrono::duration_cast<std::chrono::duration<double>>(tmpStepDuration);
		}
		_avgStepDuration =
			std::chrono::duration_cast<std::chrono::nanoseconds>(
				static_cast<std::chrono::duration<double>> (
					(double)(sum.count()) / (double)(_stepDurations.size())));

		std::cout << "Push step duration [" << std::this_thread::get_id() << "] avg: " << _avgStepDuration.count() << "]." << std::endl;
	}

	void ThreadTask::Step()
	{
		//std::cout << "Task [" << std::this_thread::get_id() << "] step..." << std::endl;
		Sleep(100);
	}


}
