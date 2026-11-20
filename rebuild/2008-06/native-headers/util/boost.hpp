#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>

namespace RBX
{
	boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name);

	class worker_thread : public boost::noncopyable
	{
	public:
		enum work_result
		{
			done,
			more
		};

	private:
		struct data
		{
		public:
			boost::mutex sync;
			boost::condition wakeCondition;
			bool endRequest;
		  
		public:
			//data(const data&);
			data()
				: endRequest(false)
			{
			}
			~data()
			{
			}

		public:
			//data& operator=(const data&);
		};

	private:
		boost::shared_ptr<data> _data;
		boost::thread thread;
	
	public:
		//worker_thread(const worker_thread&);
		worker_thread(const boost::function0<enum work_result>&, const char*);
	public:
		~worker_thread();

	public:
		void wake();
		void join();
	public:
		//worker_thread& operator=(const worker_thread&);
	  
	private:
		static void threadProc(boost::shared_ptr<data>, const boost::function0<enum work_result>&);
	};
}
