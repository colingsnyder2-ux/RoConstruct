// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_chatoutput_native_command_d8cd282c24104329.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <v8datamodel/SafeChat.h>
#include "gui/Gui.h"
#include "gui/ProfanityFilter.h"
#include <deque>
// Only forward declarations needed by this TU. Preserve the entire genuine
// ChatOutput/ChatLine declarations, all bases, fields and access controls.
namespace RBX { class RunService; class Heartbeat;
namespace Network { class Players; class Player;
// Native revision, not the older44-byte SDK message. Actual field names of
// first string unknown; descriptive senderName here is a codegen analogue.
struct ChatMessage {
    const std::string senderName;
    const std::string message;
    const boost::shared_ptr<Player> source;
    const boost::shared_ptr<Player> destination;
}; } }


namespace RBX
{
	class ChatLine
	{
	public:
		G3D::Color3 userColor;
		std::string user;
		std::string message;
		float dieTime;
		bool profane;

	public:
		ChatLine(Network::Player*, const std::string&, float);
		ChatLine(const std::string&, const std::string&, float);
	};

	class ChatOutput : public GuiItem,
					   public Listener<Network::Players, Network::ChatMessage>,
					   public Listener<RunService, Heartbeat>
	{
	private:
		RunService* runService;
		Network::Players* players;
		ProfanityFilter filter;
		std::deque<ChatLine*> fifo;
		float time;

	private:
		void removeOldest();
		void frontIsOld();
		bool ParseCommand(Network::ChatMessage);
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
		virtual void onEvent(const Network::Players*, Network::ChatMessage);
		virtual void onEvent(const RunService*, Heartbeat);
		virtual void render2d(Adorn*);
	public:
		ChatOutput();
		virtual ~ChatOutput();
	};
}

namespace RBX {
void ChatOutput::render2d(Adorn* adorn) {
    Rect rect=getMyRect();
    // Native deque proxy at174, offset18c and size190. Genuine std::deque
    // supplies its checked iterators/ownership; no substitute container layout.
    G3D::Vector2 position(rect.low.x,rect.low.y-(*(std::deque<ChatLine*>*)((char*)this+0x174)).size()*12);
    for(unsigned i=0;i<(*(std::deque<ChatLine*>*)((char*)this+0x174)).size();++i) {
        std::string user=(*(std::deque<ChatLine*>*)((char*)this+0x174))[i]->user+"; ";
        G3D::Vector2 userSize=adorn->get2DStringBounds(user,12,Adorn::PROPORTIONAL_SPACING);
        G3D::Vector2 messageSize=adorn->get2DStringBounds((*(std::deque<ChatLine*>*)((char*)this+0x174))[i]->message,12,Adorn::PROPORTIONAL_SPACING);
        float width=G3D::max(20.0f,userSize.x+4.0f);
        adorn->rect2d(G3D::Rect2D::xyxy(position.x-2,position.y-2,position.x+width+messageSize.x+1,position.y+userSize.y+1),GuiItem::translucentBackdrop());
        G3D::Color3 messageColor=G3D::Color3::white();
        if((*(std::deque<ChatLine*>*)((char*)this+0x174))[i]->profane) messageColor=G3D::Color3::red();
        adorn->drawFont2D(user,position,12,G3D::Color4((*(std::deque<ChatLine*>*)((char*)this+0x174))[i]->userColor,1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        adorn->drawFont2D((*(std::deque<ChatLine*>*)((char*)this+0x174))[i]->message,G3D::Vector2(position.x+width,position.y),12,G3D::Color4(messageColor,1),G3D::Color4::zero(),Adorn::XALIGN_LEFT,Adorn::YALIGN_TOP,Adorn::PROPORTIONAL_SPACING);
        position.y+=14;
    }
}
}

namespace RBX {
bool ChatOutput::ParseCommand(Network::ChatMessage chat) {
    std::vector<std::string> parts;
    boost::char_separator<char> separator(" -_/,");
    boost::tokenizer<boost::char_separator<char>> tokens(chat.message,separator);
    for(boost::tokenizer<boost::char_separator<char>>::iterator it=tokens.begin();it!=tokens.end();++it)
        parts.push_back(*it);
    if(parts.empty()) return false;
    boost::algorithm::to_lower(parts[0]);
    if(parts[0]!="sc") return false;
    std::string message=SafeChat::singleton().getMessage(parts);
    ChatLine* line=new ChatLine(chat.source.get(),message,*(float*)((char*)this+0x194)+60.0f);
    (*(std::deque<ChatLine*>*)((char*)this+0x174)).push_back(line);
    return true;
}
}
