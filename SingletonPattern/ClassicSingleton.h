#pragma once

namespace example
{

	class ClassicSingleton
	{
	private:

		static ClassicSingleton * _instance;

	public:

		ClassicSingleton();
		virtual ~ClassicSingleton();

	public:

		ClassicSingleton(ClassicSingleton & other) = delete;			// Disable copy constructor.
		void operator=(const ClassicSingleton &) = delete;				// Disable assignee operator.
		ClassicSingleton(ClassicSingleton &&) = delete;					// Disable move constructor.
		ClassicSingleton & operator=(ClassicSingleton &&) = delete;		// Disable move assignee operator.

	public:

		ClassicSingleton * Instance();

	};

}
