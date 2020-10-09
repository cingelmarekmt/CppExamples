#include "PrecompiledDeclarations.h"
#include "ClassicSingleton.h"

namespace example
{
	ClassicSingleton * ClassicSingleton::_instance = nullptr;

	ClassicSingleton::ClassicSingleton() = default;
	ClassicSingleton::~ClassicSingleton() = default;

	ClassicSingleton * ClassicSingleton::Instance()
	{
		if (_instance == nullptr)
		{
			_instance = new ClassicSingleton();
		}
		return _instance;
	}

}
