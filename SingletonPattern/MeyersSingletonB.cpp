#include "PrecompiledDeclarations.h"

#include "MeyersSingletonB.h"

using namespace std;

namespace example
{

	std::mutex MeyersSingletonB::_initMutex;
	MeyersSingletonB * MeyersSingletonB::_instance = nullptr;

	MeyersSingletonB::MeyersSingletonB() = default;
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
		cout << __FUNCTION__ << "\n";
	}

}
