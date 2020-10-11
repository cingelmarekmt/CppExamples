#pragma once

namespace example
{

	class ModernSingleton
	{
	private:

		static ModernSingleton * _instance;
		static std::once_flag static_flag;

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

	};

}
