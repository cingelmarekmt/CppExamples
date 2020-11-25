#pragma once

namespace example
{

	class ThreadTaskF : public std::enable_shared_from_this<ThreadTaskF>
	{
	public:

		using IdType = size_t;

	private:

		IdType _id;

		std::future<void> _future;

	public:

		ThreadTaskF();
		virtual ~ThreadTaskF();

	public:

		const IdType & GetId() const;

	public:

		void Init();

		void StartStep();
		void StepInternal();
		void StopStep();

	};

}
