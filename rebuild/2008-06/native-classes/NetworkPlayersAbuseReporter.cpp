// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::AbuseReporter worker body (inactive; original unit Network/Players.cpp, 00495e60..
// 0049e2xx). Flags copied from NetworkPlayers.cpp (same unit). Layout: native-headers/Network/Players.h.
//
// Identity of 0049bf90 (registry placeholder func_0049bf90, 1198 B) as AbuseReporter::processRequests
// (donor openrbx Network/Players.cpp): it sits in the Players unit between Players members; the strings are the
// donor's exactly ("report" 00810cf0, "userID" 00822708, "comment" 00822a40, "messages" 00822a34, "Posted abuse
// report to %s" 00822a18, "Unable to post abuse report to %s. %s" 008229f0); callees are AbuseReport's list ctor
// 00498770 / dtor 00499370 / operator= 0049a830, the data mutex (+0x20) lock 00594ce0 / unlock 00594d00, deque
// front 00496020, XmlWriter ctor 0058fff0 with the TextXmlWriter vtable 0080ea1c, TextXmlWriter::serialize
// 0058e810, ~XmlElement 00413a70, Http(const std::string&) 0041d4b0, Http::post 00569a40, ~Http 005df620,
// StandardOut::singleton 00569620 / print 005693a0, std::for_each 004992e0 bound to writeMessage 00497620.
// It returns worker_thread::done (0) when the queue is empty and more (1) otherwise (ret, cdecl: shared_ptr<data>
// and std::string by value).
#include "Network/Players.h"
#include "v8xml/XmlElement.h"
#include "v8xml/XmlSerializer.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <boost/bind.hpp>
#include <algorithm>
#include <sstream>

// 00497620 writeMessage (file-local in Players.cpp; 280 B). Not exact: the 2008 target also writes a third
// Message string (+0x20) as the attribute "guid" (00822700) through XmlElement::addAttribute<std::string> 00497120,
// while Network/Players.h declares AbuseReport::Message as only { int userID; std::string text; } (header
// proposal: add `std::string guid; // +0x20` after text). Donor body kept so processRequests binds the same callee.
static void writeMessage(const RBX::Network::AbuseReport::Message& msg, XmlElement* messages)
{
	XmlElement* message = messages->addChild(RBX::Name::declare("message", -1));
	message->setValue(msg.text);
	message->addAttribute(RBX::Name::declare("userID", -1), msg.userID);
}

namespace RBX
{
	namespace Network
	{
		// 0049bf90 AbuseReporter::processRequests (identity in the banner above).
		worker_thread::work_result AbuseReporter::processRequests(boost::shared_ptr<data> _data, std::string abuseUrl)
		{
			try
			{
				AbuseReport r;

				{
					boost::mutex::scoped_lock lock(_data->requestSync);
					if (_data->queue.empty())
						return worker_thread::done;
					r = _data->queue.front();
				}

				std::stringstream body;

				{
					TextXmlWriter writer(body);
					XmlElement root(Name::declare("report", -1));
					root.addAttribute(Name::declare("userID", -1), r.submitterID);

					root.addChild(new XmlElement(Name::declare("comment", -1), r.comment));
					XmlElement* messages = root.addChild(new XmlElement(Name::declare("messages", -1)));
					std::for_each(r.messages.begin(), r.messages.end(), boost::bind(writeMessage, _1, messages));
					writer.serialize(&root);

					body.flush();
				}

				std::string response;

				Http(abuseUrl).post(body, false, response);
				StandardOut::singleton()->print(MESSAGE_INFO, "Posted abuse report to %s", abuseUrl.c_str());
			}
			catch (std::exception& e)
			{
				StandardOut::singleton()->print(MESSAGE_WARNING, "Unable to post abuse report to %s. %s", abuseUrl.c_str(), e.what());
			}

			{
				boost::mutex::scoped_lock lock(_data->requestSync);
				_data->queue.pop();
			}

			return worker_thread::more;
		}
	}
}
