#include "gui/Gui.h"
#include "v8tree/Verb.h"

namespace RBX
{
	class DataModel;
	class Workspace;
	class ChatOption;
	class UnifiedWidget;

	class GuiBuilder
	{
	private:
		DataModel* dataModel;
		Workspace* workspace;

	private:
		boost::shared_ptr<TopMenuBar> buildMenu();
		boost::shared_ptr<TopMenuBar> buildRightPalette(Adorn*);
		boost::shared_ptr<TopMenuBar> buildRightControlPalette(Adorn*, GuiRoot*);
		boost::shared_ptr<TopMenuBar> buildScoreHud();
		boost::shared_ptr<TopMenuBar> buildScoreHud(int);
		boost::shared_ptr<TopMenuBar> buildControlHud(Adorn*, int);
		boost::shared_ptr<TopMenuBar> buildMessageHud(int);
		boost::shared_ptr<TopMenuBar> buildChatHud();
		void buildChatMenu(ChatOption*, std::string, boost::shared_ptr<UnifiedWidget>);
		boost::shared_ptr<TopMenuBar> buildChatMenu(Adorn*);
		boost::shared_ptr<TopMenuBar> buildHealthHud();
		boost::shared_ptr<TopMenuBar> buildStatsHud1();
		boost::shared_ptr<TopMenuBar> buildStatsHud2();
		void buildRightPaletteItems(Adorn*, boost::shared_ptr<TopMenuBar>);
		TopMenuBar* buildColorPanel(Adorn*, GuiRoot*);
		Verb* getVerb(const std::string&);
	public:
		void buildGui(Adorn*, DataModel*, Workspace*);
	};
}
