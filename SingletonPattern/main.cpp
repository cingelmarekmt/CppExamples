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

	std::cout << std::endl;
	std::cout << "Hello Singleton!" << std::endl;
}
