#pragma once
// 2008-06 native RBX::GuiBuilder (inactive). Shape after the donor tools/rbxgs v8datamodel/GuiBuilder.h (a differently
// named header so that it does not shadow the donor one). Not polymorphic, no RTTI. Read from the binary
// (tests/record_native_gui_hud_builder.py checks it):
//   GuiBuilder  buildGui 00605c20 (Adorn*, DataModel*, Workspace*; ret 0xc) stores workspace +0x04 (00605c4a) and
//               dataModel +0x00 (00605c50), then adds the nine huds to dataModel->getGuiRoot() (DataModel +0x21c,
//               00605c84) through GuiItem::addGuiItem 00600f10. The build methods return
//               boost::shared_ptr<TopMenuBar> through a hidden pointer. getVerb is inline: Workspace's VerbContainer
//               base (+0x2ec, 0060285d) then VerbContainer::getVerb(std::string) 00583380.
//   ChatOption  the SafeChat tree node buildChatMenu 006034d0 walks: children +0x00 (a 0x18-byte std::vector of this
//               STL build; size read from _Myfirst +0x0c / _Mylast +0x10 at 006034f7) and text +0x18 (std::string,
//               copied at 006035a7). Only the members these bodies read; no size is claimed.
//   SafeChat    singleton() 00658880 (called at 00603803); chatRoot (boost::scoped_ptr<ChatOption>) +0x00 is read
//               directly by buildChatMenu(Adorn*) (00603808). Only that member; no size is claimed.
#include "gui/Gui.h"
#include "v8tree/Verb.h"
#include <boost/scoped_ptr.hpp>
#include <vector>
#include <string>

struct NativeGuiHudBuilderLayout;

namespace RBX
{
	class DataModel;
	class Workspace;
	class UnifiedWidget;

	class ChatOption
	{
	public:
		std::vector<ChatOption*> children;                           // +0x00 (006034f7)
		std::string text;                                            // +0x18 (006035a7)
	};

	class SafeChat
	{
	private:
		boost::scoped_ptr<ChatOption> chatRoot;                      // +0x00 (00603808)

	public:
		ChatOption* getChatRoot()
		{
			return chatRoot.get();
		}
		static SafeChat& singleton();                                // 00658880
	};

	class GuiBuilder
	{
	private:
		DataModel* dataModel;                                        // +0x00 (00605c50)
		Workspace* workspace;                                        // +0x04 (00605c4a)

	private:
		boost::shared_ptr<TopMenuBar> buildMenu();                   // 00602770
		boost::shared_ptr<TopMenuBar> buildRightPalette(Adorn*);     // 00604070
		boost::shared_ptr<TopMenuBar> buildScoreHud();               // 00603920
		boost::shared_ptr<TopMenuBar> buildControlHud(Adorn*, int);  // 00603c60
		boost::shared_ptr<TopMenuBar> buildChatHud();                // 00603330
		void buildChatMenu(ChatOption*, std::string, boost::shared_ptr<UnifiedWidget>);  // 006034d0
		boost::shared_ptr<TopMenuBar> buildChatMenu(Adorn*);         // 00603730
		boost::shared_ptr<TopMenuBar> buildHealthHud();              // 00603ac0
		boost::shared_ptr<TopMenuBar> buildStatsHud1();              // 006041d0
		boost::shared_ptr<TopMenuBar> buildStatsHud2();              // 00604f30
		void buildRightPaletteItems(Adorn*, boost::shared_ptr<TopMenuBar>);  // 00602cb0
		Verb* getVerb(const std::string&);                           // inline (0060285d)
	public:
		void buildGui(Adorn*, DataModel*, Workspace*);               // 00605c20
		friend struct ::NativeGuiHudBuilderLayout;
	};
}
