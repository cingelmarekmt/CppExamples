#pragma once

namespace example
{

	class MeyersSingletonB
	{
		static std::mutex _initMutex;
		static MeyersSingletonB * _instance;

	public:

		MeyersSingletonB();
		virtual ~MeyersSingletonB();

	public:

		MeyersSingletonB(MeyersSingletonB & other) = delete;			// Disable copy constructor.
		void operator=(const MeyersSingletonB &) = delete;				// Disable assignee operator.
		MeyersSingletonB(MeyersSingletonB &&) = delete;					// Disable move constructor.
		MeyersSingletonB & operator=(MeyersSingletonB &&) = delete;		// Disable move assignee operator.

	public:

		static MeyersSingletonB * Instance();

	public:

		void Print();

	};

}
