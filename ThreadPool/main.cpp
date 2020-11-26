#include "PrecompiledDeclarations.h"

#include "ThreadPool.h"
#include "ThreadTask.h"

#include "ThreadPoolF.h"
#include "ThreadTaskF.h"

using namespace example;

int main()
{
	std::cout << "Hello ThreadPool!\n";

	//{
	//	const auto threadPool = std::make_shared<ThreadPool>();

	//	for (int index = 0; index < 10; ++index)
	//	{
	//		const auto threadTask = std::make_shared<ThreadTask>();
	//		threadPool->Add(threadTask);
	//	}
	//	std::cout << "Task count: [" << threadPool->Size() << "]" << std::endl;

	//	while (threadPool->Empty() == false)
	//	{
	//		std::cout << "Main step..." << std::endl;
	//		Sleep(500);
	//	}
	//}

	{
		const auto threadPool = std::make_shared<ThreadPoolF>();

		for (int index = 0; index < 1; ++index)
		{
			const auto threadTask = std::make_shared<ThreadTaskF>();
			threadPool->Add(threadTask);
		}

		std::cout << "Task count: [" << threadPool->Size() << "]" << std::endl;

		threadPool->Start();
		while (threadPool->Empty() == false)
		{
			std::cout << "Main step..." << std::endl;
			Sleep(500);
		}
	}

	std::cout << "Bye ThreadPool!" << std::endl;
	return 0;
}
