#include "PrecompiledDeclarations.h"

#include "MeyersSingletonA.h"

using namespace std;

namespace example
{

	MeyersSingletonA * MeyersSingletonA::_instance = nullptr;

	MeyersSingletonA::MeyersSingletonA() = default;
	MeyersSingletonA::~MeyersSingletonA() = default;

	MeyersSingletonA * MeyersSingletonA::Instance()
	{
		_instance = new MeyersSingletonA();
		return _instance;
	}

	void MeyersSingletonA::Print()
	{
		cout << __FUNCTION__ << "\n";
	}

}
