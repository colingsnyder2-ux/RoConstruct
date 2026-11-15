#pragma once
// 2008-06 native RBX::ChatLine and RBX::ChatOutput (inactive). Shape after the donor tools/rbxgs gui/ChatOutput.h.
// Read from the binary (tests/record_native_hud.py checks it):
//   ChatLine    non-polymorphic, 0x4c bytes (ChatOutput::onEvent 00650cc0 allocates 0x4c). Constructor 00650560
//               (Player*, const std::string&, float; ret 0xc): userColor +0x00 (three floats stored last), user
//               +0x0c (default-constructed, then assigned the player's name), message +0x28 (copy), dieTime +0x44,
//               profane +0x48 (= false). Implicit destructor 0064f8c0 (called by removeOldest 0064fded).
//   ChatOutput  vtable 0084bb84 .?AVChatOutput@RBX@@ -> GuiItem -> Instance (+ GuiTarget +0x130),
//               Listener<Players, ChatMessage> +0x144 (vtable 0084baf4), Listener<RunService, Heartbeat> +0x148
//               (vtable 0084bae8). Constructor 0064fb60: GuiItem() 005739d0, the 13 vtables, runService (+0x14c)
//               and players (+0x150) = 0, filter +0x154 (ProfanityFilter() 0066a340), fifo +0x174
//               (std::deque<ChatLine*>), time +0x194 = 0.0f. Size 0x198 (006020a0 allocates 0x198).
//               Destructor 00650440 (removeOldest 0064fd70 until fifo is empty, ~deque, ~ProfanityFilter 0066a060,
//               ~GuiItem 00411540), deleting destructor 00650540.
//               onServiceProvider 00650c00 (slot 12), onEvent(Heartbeat) 0064fe10 (Listener<RunService, Heartbeat>
//               slot 0; the unit needs /fp:fast for its x87 compare order), onEvent(ChatMessage) 00650cc0 (Listener<Players, ChatMessage> slot 0; not attempted),
//               ParseCommand 00650660 (not attempted), render2d 0064fe90 (slot 24; not attempted).
#include "gui/Gui.h"
#include "gui/ProfanityFilter.h"
#include "Network/Players.h"
#include "util/RunStateOwner.h"
#include <deque>

struct NativeHudLayout;

namespace RBX
{
	class ChatLine
	{
	public:
		G3D::Color3 userColor;                                       // +0x00
		std::string user;                                            // +0x0c
		std::string message;                                         // +0x28
		float dieTime;                                               // +0x44
		bool profane;                                                // +0x48

	public:
		ChatLine(Network::Player*, const std::string&, float);       // 00650560 (not attempted)
	};

	class ChatOutput : public GuiItem,
					   public Listener<Network::Players, Network::ChatMessage>,
					   public Listener<RunService, Heartbeat>
	{
	private:
		RunService* runService;                                      // +0x14c
		Network::Players* players;                                   // +0x150
		ProfanityFilter filter;                                      // +0x154
		std::deque<ChatLine*> fifo;                                  // +0x174
		float time;                                                  // +0x194

	private:
		void removeOldest();                                         // 0064fd70
		bool frontIsOld();                                           // inlined into onEvent 0064fe10 (the loop condition; donor: void)
		bool ParseCommand(Network::ChatMessage);                     // 00650660 (not attempted)
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);  // slot 12, 00650c00
		virtual void onEvent(const Network::Players*, Network::ChatMessage);            // 00650cc0 (not attempted)
		virtual void onEvent(const RunService*, Heartbeat);          // 0064fe10
		virtual void render2d(Adorn*);                               // slot 24, 0064fe90 (not attempted)
	public:
		ChatOutput();                                                // 0064fb60
		virtual ~ChatOutput();                                       // 00650440
		friend struct ::NativeHudLayout;
	};
}
