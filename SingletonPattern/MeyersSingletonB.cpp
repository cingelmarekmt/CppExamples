#include "PrecompiledDeclarations.h"

#include "MeyersSingletonB.h"

namespace example
{

	std::mutex MeyersSingletonB::_initMutex;
	MeyersSingletonB * MeyersSingletonB::_instance = nullptr;

	MeyersSingletonB::MeyersSingletonB() :
		_counter(0)
	{

	}

	MeyersSingletonB::~MeyersSingletonB() = default;

	MeyersSingletonB * MeyersSingletonB::Instance()
	{
		if (_instance == nullptr)
		{
			std::lock_guard lk(_initMutex);
			if (_instance == nullptr)
			{
				_instance = new MeyersSingletonB();
			}
		}

		return _instance;
	}

	void MeyersSingletonB::Print()
	{
		std::cout << __FUNCTION__ << "\n";
	}

	void MeyersSingletonB::Increment()
	{
		++_counter;
	}

}
