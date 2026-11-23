// =============================================================================
// standardout.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/standardout.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
