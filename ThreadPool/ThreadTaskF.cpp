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

	void ThreadTaskF::Init()
	{
		//std::packaged_task<void()> task(std::bind(&ThreadTaskF::StepInternal, shared_from_this()));
		//_task = std::packaged_task<void()>(std::bind(&ThreadTaskF::StepInternal, shared_from_this()));
	}

	void ThreadTaskF::StartStep()
	{
		//const auto future = _task.get_future();
		//future.wait();

		_future = std::async(std::launch::async, std::bind(&ThreadTaskF::StepInternal, shared_from_this()));
	}

	void ThreadTaskF::StepInternal()
	{
		Sleep(100);
		//std::cout << "StepInternal [" << std::this_thread::get_id() << "]" << std::endl;
	}

	void ThreadTaskF::StopStep()
	{
		_future.get();
	}

}
