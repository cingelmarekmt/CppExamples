#include "PrecompiledDeclarations.h"

#include "MeyersSingletonA.h"
#include "MeyersSingletonB.h"
#include "ModernSingleton.h"

namespace example
{
	template<class SINGLETON_TYPE>
	void Print()
	{
		SINGLETON_TYPE::Instance()->Print();
	}
}

int main()
{
	{
		std::thread t1(example::Print<example::MeyersSingletonA>);
		std::thread t2(example::Print<example::MeyersSingletonA>);
		std::thread t3(example::Print<example::MeyersSingletonA>);
		std::thread t4(example::Print<example::MeyersSingletonA>);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}

	std::cout << std::endl;

	{
		std::thread t1(example::Print<example::MeyersSingletonB>);
		std::thread t2(example::Print<example::MeyersSingletonB>);
		std::thread t3(example::Print<example::MeyersSingletonB>);
		std::thread t4(example::Print<example::MeyersSingletonB>);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}

	std::cout << std::endl;

	{
		std::thread t1(example::Print<example::ModernSingleton>);
		std::thread t2(example::Print<example::ModernSingleton>);
		std::thread t3(example::Print<example::ModernSingleton>);
		std::thread t4(example::Print<example::ModernSingleton>);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}

	size_t iterationCount = 100000;

	//std::cout << std::fixed << std::setw(24) << std::endl;

	{
		const auto t1 = std::chrono::high_resolution_clock::now();
		for (int index = 0; index < iterationCount; ++index)
		{
			example::MeyersSingletonA::Instance()->Increment();
		}
		const auto t2 = std::chrono::high_resolution_clock::now();
		const auto timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "MeyersSingletonA time span: " << timeSpan.count() << std::endl;
	}

	{
		const auto t1 = std::chrono::high_resolution_clock::now();
		for (int index = 0; index < iterationCount; ++index)
		{
			example::MeyersSingletonB::Instance()->Increment();
		}
		const auto t2 = std::chrono::high_resolution_clock::now();
		const auto timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "MeyersSingletonB time span: " << timeSpan.count() << std::endl;
	}

	{
		const auto t1 = std::chrono::high_resolution_clock::now();
		for (int index = 0; index < iterationCount; ++index)
		{
			example::ModernSingleton::Instance()->Increment();
		}
		const auto t2 = std::chrono::high_resolution_clock::now();
		const auto timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "ModernSingleton time span: " << timeSpan.count() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Hello Singleton!" << std::endl;


	int i;
	while (std::cin >> i)
		std::cout << i << std::endl;
}
