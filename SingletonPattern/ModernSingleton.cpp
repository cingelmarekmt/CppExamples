#include "PrecompiledDeclarations.h"

#include "ModernSingleton.h"

using namespace std;

namespace example
{

	ModernSingleton * ModernSingleton::_instance = nullptr;
	std::once_flag ModernSingleton::static_flag;

	ModernSingleton::ModernSingleton() = default;
	ModernSingleton::~ModernSingleton() = default;

	ModernSingleton * ModernSingleton::Instance()
	{
		std::call_once(static_flag, []() { _instance = new ModernSingleton(); });
		return _instance;
	}

	void ModernSingleton::Print()
	{
		cout << __FUNCTION__ << "\n";
	}

}
