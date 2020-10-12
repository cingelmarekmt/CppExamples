#include "PrecompiledDeclarations.h"

#include "ModernSingleton.h"

using namespace std;

namespace example
{

	std::once_flag ModernSingleton::_initFlag;
	ModernSingleton * ModernSingleton::_instance = nullptr;

	ModernSingleton::ModernSingleton() = default;
	ModernSingleton::~ModernSingleton() = default;

	ModernSingleton * ModernSingleton::Instance()
	{
		std::call_once(_initFlag, []() { _instance = new ModernSingleton(); });
		return _instance;
	}

	void ModernSingleton::Print()
	{
		cout << __FUNCTION__ << "\n";
	}

}
