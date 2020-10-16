#include "PrecompiledDeclarations.h"

#include "MeyersSingletonA.h"

using namespace std;

namespace example
{

	MeyersSingletonA * MeyersSingletonA::_instance = new MeyersSingletonA();

	MeyersSingletonA::MeyersSingletonA() :
		_counter(0)
	{

	}

	MeyersSingletonA::~MeyersSingletonA() = default;

	MeyersSingletonA * MeyersSingletonA::Instance()
	{
		return _instance;
	}

	void MeyersSingletonA::Print()
	{
		cout << __FUNCTION__ << "\n";
	}

	void MeyersSingletonA::Increment()
	{
		++_counter;
	}

}
