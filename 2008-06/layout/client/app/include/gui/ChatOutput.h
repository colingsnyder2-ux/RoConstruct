// =============================================================================
// ChatOutput.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/ChatOutput.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
		bool ParseCommand(Network::ChatMessage);                     // 00650660 (ChatOutputCommands.cpp)
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);  // slot 12, 00650c00
		virtual void onEvent(const Network::Players*, Network::ChatMessage);            // 00650cc0 (not attempted)
		virtual void onEvent(const RunService*, Heartbeat);          // 0064fe10
		virtual void render2d(Adorn*);                               // slot 24, 0064fe90 (ChatOutputCommands.cpp)
	public:
		ChatOutput();                                                // 0064fb60
		virtual ~ChatOutput();                                       // 00650440
		friend struct ::NativeHudLayout;
	};
}
