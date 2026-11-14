// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native ChatOutput::ParseCommand (inactive).
#include "gui/ChatOutput.h"
#include "v8datamodel/SafeChat.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/case_conv.hpp>

namespace RBX
{
	bool ChatOutput::ParseCommand(Network::ChatMessage chat)
	{
		std::vector<std::string> parts;
		boost::char_separator<char> separator(" -_/,");
		boost::tokenizer<boost::char_separator<char> > tokens(chat.message, separator);
		for (boost::tokenizer<boost::char_separator<char> >::iterator it = tokens.begin(); it != tokens.end(); ++it)
			parts.push_back(*it);

		if (parts.size() == 0)
			return false;

		boost::algorithm::to_lower(parts[0]);
		if (parts[0] == "sc")
		{
			std::string message = SafeChat::singleton().getMessage(parts);
			ChatLine* line = new ChatLine(chat.source.get(), message, time + 60.0f);
			fifo.push_back(line);
			return true;
		}

		return false;
	}
}
