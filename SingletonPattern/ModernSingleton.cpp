#include "PrecompiledDeclarations.h"

#include "ModernSingleton.h"

using namespace std;

namespace example
{

	std::once_flag ModernSingleton::_initFlag;
	ModernSingleton * ModernSingleton::_instance = nullptr;

	ModernSingleton::ModernSingleton() :
		_counter(0)
	{

	}

	ModernSingleton::~ModernSingleton() = default;

	ModernSingleton * ModernSingleton::Instance()
	{
		if (_instance == nullptr)
		{
			std::call_once(_initFlag, []() { _instance = new ModernSingleton(); });
		}
		return _instance;
	}

	void ModernSingleton::Print()
	{
		cout << __FUNCTION__ << "\n";
	}

	void ModernSingleton::Increment()
	{
		++_counter;
	}

}
