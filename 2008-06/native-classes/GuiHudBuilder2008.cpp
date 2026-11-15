// 2008-06 native RBX::GuiBuilder unit (inactive): 006023d0..00606100 (the player GUI hud builder).
// Layout and addresses in native-headers/GuiHud2008/GuiBuilder2008.h; verified by tests/record_native_gui_hud_builder.py.
// Unit profile + /fp:fast (the Layout / Vector2 x87 stores of every build method).
//
// NATIVE_GUIHUD_PENDING bodies need a declaration the core header lacks (the generated overlay under
// out/native-layouts/gui-hud-builder-pending supplies it; see the recorder):
//   * util/Object.h  Creatable<T>::create with three parameters (create<ArrowPanel> 00602650, create<PercentPanel>
//                    006021e0, create<ImageButton> 00601f00 take three by-value arguments).
// native-headers/gui/Gui.h (pass 2) declares TopMenuBar(const std::string&, Layout::Style, bool = false) (00601fd0 pushes
// 0 at 00602027) and TextDisplay setFontSize / setFontColor / setBorderColor inline (00604dd8, 00604e16, 00604e2e).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "GuiHud2008/GuiBuilder2008.h"
#include "gui/HealthHud.h"
#include "gui/ScoreHud.h"
#include "gui/ChatOutput.h"
#include "gui/WidgetChat.h"
#include "gui/WidgetMenuItem.h"
#include "gui/WidgetButtons.h"
#include "gui/EquationDisplay.h"
#include "gui/ArrowPanel.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include <G3D/Color3.h>
#include <boost/lexical_cast.hpp>

namespace RBX
{
	inline Verb* GuiBuilder::getVerb(const std::string& name)
	{
		return workspace->getVerb(name);
	}

#ifdef NATIVE_GUIHUD_PENDING
	boost::shared_ptr<TopMenuBar> GuiBuilder::buildControlHud(Adorn* adorn, int yOffset)
	{
		Layout panelLayout;
		panelLayout.offset.y = yOffset;
		panelLayout.xLocation = Rect::RIGHT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("ControlHud");

		panel->addGuiItem(Creatable<Instance>::create<ArrowPanel>(adorn, dataModel, Controller::PRIMARY_CONTROLLER));
		panel->addGuiItem(Creatable<Instance>::create<MenuSpacer>(5.0f, 5.0f));
		panel->addGuiItem(Creatable<Instance>::create<ArrowPanel>(adorn, dataModel, Controller::SECONDARY_CONTROLLER));

		return panel;
	}
#endif

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildMenu()
	{
		Layout layout;
		layout.backdropColor = GuiItem::translucentBackdrop();
		boost::shared_ptr<RelativePanel> menu = Creatable<Instance>::create<RelativePanel>(layout);
		menu->setName("MainMenu");

		menu->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("TogglePlayMode"), "Tools"));
		menu->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("ToggleToolbox"), "Insert"));
		menu->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("ToggleFullScreen"), "Fullscreen"));
		menu->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("Help"), "Help..."));
		menu->addGuiItem(Creatable<Instance>::create<MenuItem>(getVerb("Exit"), "   Exit"));

		for (unsigned int i = 0; i < menu->numChildren(); ++i)
		{
			GuiItem* item = menu->getGuiItem(i);
			if (item)
				item->setGuiSize(G3D::Vector2(100.0f, 20.0f));
		}

		return menu;
	}

#ifdef NATIVE_GUIHUD_PENDING
	void GuiBuilder::buildRightPaletteItems(Adorn* adorn, boost::shared_ptr<TopMenuBar> palette)
	{
		palette->addGuiItem(Creatable<Instance>::create<ImageButton>(adorn, getVerb("FirstPersonIndicator"), "FirstPersonIndicator"));
		palette->addGuiItem(Creatable<Instance>::create<ImageButton>(adorn, getVerb("ReportAbuse"), "ReportAbuse"));

		boost::shared_ptr<TopMenuBar> left = Creatable<Instance>::create<TopMenuBar>("CameraLeft", Layout::VERTICAL);
		left->addGuiItem(Creatable<Instance>::create<ImageButton>(adorn, getVerb("CameraTiltUp"), "Tilt Up"));
		left->addGuiItem(Creatable<Instance>::create<ImageButton>(adorn, getVerb("CameraTiltDown"), "Tilt Down"));

		boost::shared_ptr<TopMenuBar> right = Creatable<Instance>::create<TopMenuBar>("CameraRight", Layout::VERTICAL);
		right->addGuiItem(Creatable<Instance>::create<ImageButton>(adorn, getVerb("CameraZoomIn"), "Zoom In"));
		right->addGuiItem(Creatable<Instance>::create<ImageButton>(adorn, getVerb("CameraZoomOut"), "Zoom Out"));

		boost::shared_ptr<TopMenuBar> camera = Creatable<Instance>::create<TopMenuBar>("CameraPanel", Layout::HORIZONTAL);
		camera->addGuiItem(left);
		camera->addGuiItem(right);
		palette->addGuiItem(camera);
	}
#endif

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildChatHud()
	{
		Layout panelLayout;
		panelLayout.offset.x = 25;
		panelLayout.offset.y = 100;
		panelLayout.xLocation = Rect::LEFT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("ChatHud");

		panel->addGuiItem(Creatable<Instance>::create<ChatOutput>());

		return panel;
	}

	void GuiBuilder::buildChatMenu(ChatOption* parentOption, std::string parentCode, boost::shared_ptr<UnifiedWidget> parentGui)
	{
		for (size_t i = 0; i < parentOption->children.size(); ++i)
		{
			ChatOption* option = parentOption->children[i];
			std::string code = parentCode + " " + boost::lexical_cast<std::string>(i);

			boost::shared_ptr<ChatWidget> button = Creatable<Instance>::create<ChatWidget>(option->text, code);
			parentGui->addGuiItem(button);

			buildChatMenu(option, code, button);
		}
	}

#ifdef NATIVE_GUIHUD_PENDING
	boost::shared_ptr<TopMenuBar> GuiBuilder::buildChatMenu(Adorn* adorn)
	{
		boost::shared_ptr<PercentPanel> panel = Creatable<Instance>::create<PercentPanel>(Rect::LEFT, Rect::BOTTOM, G3D::Vector2(2.0f, 26.0f));
		panel->setName("ChatMenuPanel");

		boost::shared_ptr<ChatButton> button = Creatable<Instance>::create<ChatButton>(adorn, "Chat");
		panel->addGuiItem(button);

		ChatOption* chatRoot = SafeChat::singleton().getChatRoot();
		std::string code = "";
		buildChatMenu(chatRoot, code, button);

		return panel;
	}
#endif

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildScoreHud()
	{
		Layout panelLayout;
		panelLayout.offset.x = 10;
		panelLayout.offset.y = 10;
		panelLayout.xLocation = Rect::RIGHT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("ScoreHud");

		panel->addGuiItem(Creatable<Instance>::create<ScoreHud>(dataModel));

		return panel;
	}

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildHealthHud()
	{
		Layout panelLayout;
		panelLayout.offset.x = 60;
		panelLayout.offset.y = 200;
		panelLayout.xLocation = Rect::RIGHT;
		panelLayout.yLocation = Rect::TOP;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("HealthHud");

		panel->addGuiItem(Creatable<Instance>::create<HealthHud>());

		return panel;
	}

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildRightPalette(Adorn* adorn)
	{
		Layout panelLayout;
		panelLayout.xLocation = Rect::RIGHT;
		panelLayout.yLocation = Rect::BOTTOM;
		panelLayout.layoutStyle = Layout::VERTICAL;
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(panelLayout);
		panel->setName("RightPalette");

		buildRightPaletteItems(adorn, panel);

		return panel;
	}

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildStatsHud1()
	{
		Layout layout;
		layout.xLocation = Rect::LEFT;
		layout.yLocation = Rect::BOTTOM;
		layout.offset.x = 50;
		layout.offset.y = 40;
		layout.layoutStyle = Layout::VERTICAL;
		layout.backdropColor = GuiItem::translucentBackdrop();
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(layout);
		panel->setName("StatsHud1");

		panel->addGuiItem(Creatable<Instance>::create<TextDisplay>("", "----- World ----"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Primitives    : ", "numPrimitives"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Joints        : ", "numJoints"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Contacts      : ", "numContacts"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Tree          : ", "maxTreeDepth"));
		panel->addGuiItem(Creatable<Instance>::create<TextDisplay>("", "----- Timing -----"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("FPS           : ", "FPS"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("SimCpu        : ", "SimCpu"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("GfxCpu        : ", "GfxCpu"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("UiCpu         : ", "UiCpu"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("IdleCpu       : ", "IdleCpu"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Gfx           : ", "GfxTime"));
		panel->addGuiItem(Creatable<Instance>::create<TextDisplay>("", "----- Graphics ----"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Mode          : ", "graphicsMode"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Video Memory  : ", "videoMemory"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Shadows:      : ", "Shadows"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Anti-Aliasing : ", "antiAliasing"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Bevels        : ", "bevels"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("FrameId       : ", "drawId"));
		panel->addGuiItem(Creatable<Instance>::create<TextDisplay>("", "----- Throttles ----"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("eThrottle %   : ", "eThrottle"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("FRM           : ", "FRM"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Particles     : ", "Particles"));

		for (size_t i = 0; i < panel->numChildren(); ++i)
		{
			boost::shared_ptr<TextDisplay> text = shared_from_dynamic_cast<TextDisplay>(panel->getChild(i));
			text->setFontSize(14);
			text->setFontColor(G3D::Color4(G3D::Color3::purple(), 1.0f));
			text->setBorderColor(G3D::Color4::clear());
			text->setGuiSize(G3D::Vector2(310.0f, 22.0f));
		}
		panel->setVisible(false);

		return panel;
	}

	boost::shared_ptr<TopMenuBar> GuiBuilder::buildStatsHud2()
	{
		Layout layout;
		layout.xLocation = Rect::RIGHT;
		layout.yLocation = Rect::BOTTOM;
		layout.offset.x = 50;
		layout.offset.y = 40;
		layout.layoutStyle = Layout::VERTICAL;
		layout.backdropColor = GuiItem::translucentBackdrop();
		boost::shared_ptr<RelativePanel> panel = Creatable<Instance>::create<RelativePanel>(layout);
		panel->setName("StatsHud2");

		panel->addGuiItem(Creatable<Instance>::create<TextDisplay>("", "----- Contacts ----"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("CtctStageCtcts: ", "numContactsInCollisionStage"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("SteppingCtcts : ", "numSteppingContacts"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("TouchingCtcts : ", "numTouchingContacts"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("% Pair Hit    : ", "contactPairHitRatio"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("% Feature Hit : ", "contactFeatureHitRatio"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("# link(p)     : ", "numLinkCalls"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("sH Nodes Out  : ", "numHashNodes"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("sH Max Bucket : ", "maxBucketSize"));
		panel->addGuiItem(Creatable<Instance>::create<TextDisplay>("", "----- Kernel ----"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Solver Iteratn: ", "solverIterations"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Matrix Size   : ", "matrixSize"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Bodies        : ", "numBodies"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Leaves        : ", "numLeafBodies"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("grpJobs       : ", "numGroupJobs"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("projJobs      : ", "numProjectileJobs"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Constraints   : ", "numConstraints"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Points        : ", "numPoints"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("% Active CC's : ", "percentConnectorsActive"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Energy B      : ", "energyBody"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Energy C      : ", "energyConnector"));
		panel->addGuiItem(Creatable<Instance>::create<EquationDisplay>("Energy T      : ", "energyTotal"));

		for (size_t i = 0; i < panel->numChildren(); ++i)
		{
			boost::shared_ptr<TextDisplay> text = shared_from_dynamic_cast<TextDisplay>(panel->getChild(i));
			text->setFontSize(14);
			text->setFontColor(G3D::Color4(G3D::Color3::purple(), 1.0f));
			text->setBorderColor(G3D::Color4::clear());
			text->setGuiSize(G3D::Vector2(260.0f, 22.0f));
		}
		panel->setVisible(false);

		return panel;
	}

	void GuiBuilder::buildGui(Adorn* adorn, DataModel* model, Workspace* world)
	{
		dataModel = model;
		workspace = world;

		dataModel->getGuiRoot()->addGuiItem(buildStatsHud1());
		dataModel->getGuiRoot()->addGuiItem(buildStatsHud2());
		dataModel->getGuiRoot()->addGuiItem(buildChatHud());
		dataModel->getGuiRoot()->addGuiItem(buildChatMenu(adorn));
		dataModel->getGuiRoot()->addGuiItem(buildScoreHud());
		dataModel->getGuiRoot()->addGuiItem(buildHealthHud());
		dataModel->getGuiRoot()->addGuiItem(buildMenu());
		dataModel->getGuiRoot()->addGuiItem(buildRightPalette(adorn));
		dataModel->getGuiRoot()->addGuiItem(buildControlHud(adorn, 20));
	}

	// The two-parameter create<...> instances whose only callers in this unit are the NATIVE_GUIHUD_PENDING bodies
	// (create<ChatButton> 00602280 from buildChatMenu(Adorn*) 006037c9, create<TopMenuBar> 00601fd0 from
	// buildRightPaletteItems 00602e66, create<MenuSpacer> 006026e0 from buildControlHud 00603da5): instantiated
	// explicitly so that the main build compiles them from the current headers.
	template boost::shared_ptr<ChatButton> Creatable<Instance>::create<ChatButton, Adorn*, const char*>(Adorn*, const char*);
	template boost::shared_ptr<TopMenuBar> Creatable<Instance>::create<TopMenuBar, const char*, Layout::Style>(const char*, Layout::Style);
	template boost::shared_ptr<MenuSpacer> Creatable<Instance>::create<MenuSpacer, float, float>(float, float);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::ChatButton>;
template class boost::shared_ptr<RBX::ChatOutput>;
template class boost::shared_ptr<RBX::ChatWidget>;
template class boost::shared_ptr<RBX::EquationDisplay>;
template class boost::shared_ptr<RBX::HealthHud>;
template class boost::shared_ptr<RBX::MenuItem>;
template class boost::shared_ptr<RBX::MenuSpacer>;
template class boost::shared_ptr<RBX::RelativePanel>;
template class boost::shared_ptr<RBX::ScoreHud>;
template class boost::shared_ptr<RBX::TextDisplay>;
template class boost::shared_ptr<RBX::TopMenuBar>;
template class boost::shared_ptr<RBX::UnifiedWidget>;
template class std::vector<RBX::ChatOption *,std::allocator<RBX::ChatOption *> >;
