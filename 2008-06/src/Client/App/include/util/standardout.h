#pragma once
#include "util/Utilities.h"
#include "util/Events.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/function.hpp>
#include <time.h>

namespace RBX
{
	enum MessageType
	{
		MESSAGE_OUTPUT,
		MESSAGE_INFO,
		MESSAGE_WARNING,
		MESSAGE_ERROR
	};

	struct StandardOutMessage
	{
	public:
		const MessageType type;
		const std::string message;
		__time64_t time;
	  
	public:
		//StandardOutMessage(const StandardOutMessage&);
		StandardOutMessage(MessageType type, const char* message)
			: type(type),
			  message(message)
		{
			_time64(&time);
		}
		~StandardOutMessage()
		{
		}
	};

	class StandardOut : public boost::enable_shared_from_this<StandardOut>, public Notifier<StandardOut, StandardOutMessage>
	{
	public:
		boost::mutex sync;
	  
	public:
		void print(MessageType, const std::exception&);
		void print(MessageType type, const char* format, ...);
	public:
		//StandardOut(const StandardOut&);
		StandardOut();
		virtual ~StandardOut();
	public:
		//StandardOut& operator=(const StandardOut&);
	  
	public:
		static boost::shared_ptr<StandardOut> singleton();
		static void print_exception(const boost::function0<void>&, MessageType, bool);
	};
}
