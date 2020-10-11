#pragma once

namespace example
{

	class MeyersSingletonA
	{
	private:

		static MeyersSingletonA * _instance;

	public:

		MeyersSingletonA();
		virtual ~MeyersSingletonA();

	public:

		MeyersSingletonA(MeyersSingletonA & other) = delete;				// Disable copy constructor.
		void operator=(const MeyersSingletonA &) = delete;				// Disable assignee operator.
		MeyersSingletonA(MeyersSingletonA &&) = delete;					// Disable move constructor.
		MeyersSingletonA & operator=(MeyersSingletonA &&) = delete;		// Disable move assignee operator.

	public:

		static MeyersSingletonA * Instance();

	public:

		void Print();

	};

}
