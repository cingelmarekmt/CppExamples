#include "PrecompiledDeclarations.h"

#include "MeyersSingletonB.h"

using namespace std;

namespace example
{

	MeyersSingletonB * MeyersSingletonB::_instance = nullptr;

	MeyersSingletonB::MeyersSingletonB() = default;
	MeyersSingletonB::~MeyersSingletonB() = default;

	MeyersSingletonB * MeyersSingletonB::Instance()
	{
		if (_instance == nullptr)
		{
			assertm(_instance != nullptr, "Singleton is valid!");
			_instance = new MeyersSingletonB();
		}

		return _instance;
	}

	void MeyersSingletonB::Print()
	{
		cout << __FUNCTION__ << "\n";
	}

}
