#include "PrecompiledDeclarations.h"

#include "ThreadTaskF.h"

namespace example
{

	inline ThreadTaskF::IdType GenerateTaskId()
	{
		static std::mutex mtx;
		static ThreadTaskF::IdType taskId = 0;

		const std::lock_guard<std::mutex> lock(mtx);
		return ++taskId;
	}

	ThreadTaskF::ThreadTaskF() :
		_id(GenerateTaskId())
	{

	}

	ThreadTaskF::~ThreadTaskF()
	{

	}

	const ThreadTaskF::IdType & ThreadTaskF::GetId() const
	{
		return _id;
	}

	void ThreadTaskF::StartStep()
	{
		//const auto t1 = std::chrono::high_resolution_clock::now();
		_future = std::async(std::launch::async, std::bind(&ThreadTaskF::StepInternal, shared_from_this()));
		//const auto t2 = std::chrono::high_resolution_clock::now();
		//const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
		//std::cout << "StartStep duration: [" << duration.count() << "]" << std::endl;
	}

	void ThreadTaskF::StepInternal()
	{
		Sleep(100);
		//std::cout << "StepInternal [" << std::this_thread::get_id() << "]" << std::endl;
	}

	void ThreadTaskF::StopStep()
	{
		//const auto t1 = std::chrono::high_resolution_clock::now();
		_future.get();
		//const auto t2 = std::chrono::high_resolution_clock::now();
		//const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
		//std::cout << "StopStep duration: [" << duration.count() << "]" << std::endl;
	}

}
