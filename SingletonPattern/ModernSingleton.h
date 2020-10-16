#pragma once

namespace example
{

	class ModernSingleton
	{
	private:

		static std::once_flag _initFlag;
		static ModernSingleton * _instance;

		int _counter;

	public:

		ModernSingleton();
		virtual ~ModernSingleton();

	public:

		ModernSingleton(ModernSingleton & other) = delete;				// Disable copy constructor.
		void operator=(const ModernSingleton &) = delete;				// Disable assignee operator.
		ModernSingleton(ModernSingleton &&) = delete;					// Disable move constructor.
		ModernSingleton & operator=(ModernSingleton &&) = delete;		// Disable move assignee operator.

	public:

		static ModernSingleton * Instance();

	public:

		void Print();
		void Increment();

	};

}
