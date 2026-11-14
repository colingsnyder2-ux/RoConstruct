// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::ChatOutput::render2d (0064fe90) and ChatOutput::ParseCommand (00650660), rows of the ChatOutput
// unit 0064fb60..00651000 (inactive). Class in the read-only native gui/ChatOutput.h: fifo std::deque<ChatLine*> +0x174
// (offset +0x18c, size +0x190), time +0x194; ChatLine user +0x0c, message +0x28, profane +0x48.
//   render2d: getMyRect 00573310; font size 12.0 (double 0084bbf0); Adorn::get2DStringBounds (slot 0x30) and
//     drawFont2D (slot 0x34, XALIGN_LEFT / YALIGN_TOP / PROPORTIONAL_SPACING); separator "; " 00820f94; minimum
//     width 20.0f 008222f0, padding 4.0f 00826e6c, 2.0f 0081c434, line step 14.0f 0084bbe8; Rect2D::xyxy 004f35d0,
//     translucentBackdrop 00573290, Color3::white 00514a60 / red 005148b0 (folded with Vector3::unitX), Color4::clear
//     007baf10. The deque is indexed through operator[] (checked iterator deref 00436420) for each use.
//   ParseCommand: boost::char_separator(" -_/,") 0084bbfc over chat.message; parts std::vector<std::string>; empty
//     -> false; to_lower(parts[0]) with std::locale() (0064fd00); parts[0] == "sc" 0084bbf8; SafeChat::singleton
//     00658880, getMessage 006584e0 (vector by value), new ChatLine (0x4c) 00650560 with time + 60, push_back.
#include "gui/ChatOutput.h"
#include "v8datamodel/SafeChat.h"
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <algorithm>

namespace RBX
{
	// 0064fe90
	void ChatOutput::render2d(Adorn* adorn)
	{
		Rect rect = getMyRect();
		G3D::Vector2 position = rect.low;
		position.y -= fifo.size() * 12;

		for (size_t i = 0; i < fifo.size(); ++i)
		{
			std::string user = fifo[i]->user + "; ";
			G3D::Vector2 userSize = adorn->get2DStringBounds(user, 12, Adorn::PROPORTIONAL_SPACING);
			G3D::Vector2 messageSize = adorn->get2DStringBounds(fifo[i]->message, 12, Adorn::PROPORTIONAL_SPACING);
			float width = std::max(userSize.x + 4.0f, 20.0f);

			G3D::Rect2D backdrop = G3D::Rect2D::xyxy(G3D::Vector2(position.x - 2.0f, position.y + 1.0f),
													  G3D::Vector2(position.x + width + messageSize.x + 2.0f, position.y + userSize.y - 1.0f));
			adorn->rect2d(backdrop, GuiItem::translucentBackdrop());

			G3D::Color3 messageColor = G3D::Color3::white();
			if (fifo[i]->profane)
				messageColor = G3D::Color3::red();

			adorn->drawFont2D(user, position, 12, G3D::Color4(fifo[i]->userColor, 1.0f), G3D::Color4::clear(),
							  Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP, Adorn::PROPORTIONAL_SPACING);
			adorn->drawFont2D(fifo[i]->message, G3D::Vector2(position.x + width, position.y), 12,
							  G3D::Color4(messageColor, 1.0f), G3D::Color4::clear(), Adorn::XALIGN_LEFT, Adorn::YALIGN_TOP,
							  Adorn::PROPORTIONAL_SPACING);

			position.y += 14.0f;
		}
	}

	// 00650660
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
