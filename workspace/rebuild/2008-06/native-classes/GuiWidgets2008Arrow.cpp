// 2008-06 native RBX::ArrowPanel / RBX::ArrowButton unit, second part (inactive): 00656c30..00657c00 (the rows that
// native-classes/ArrowPanel.cpp, verified by tests/record_native_widget.py, does not compile). Classes and layout in
// native-headers/gui/ArrowPanel.h (read-only here); verified by tests/record_native_gui_widgets2008.py.
//
//   ArrowButton::isEnabled 00657be0 (slot 30 of 0084bffc): dataModel (+0x188) -> ServiceProvider::create<RunService>
//   004530f0, then RunService::runState (+0x1b4) == RS_RUNNING.
//   The create<...> / shared_ptr<...> template instances that only ArrowPanel::init 00657240 calls:
//   create<ImageWidget>(Adorn*, std::string) 00656f60 (call 00657295), create<TopMenuBar>(std::string, Layout::Style)
//   00657000 (call 00657504) are instantiated explicitly so that the main build compiles them from the current
//   headers; shared_ptr<ImageWidget>(ImageWidget*, Deleter) 00656e00 (call 00656fce) follows from create<ImageWidget>.
//   shared_ptr<ArrowButton>(ArrowButton*, Deleter) 00656eb0 (call 0065720d) follows only from the pending
//   create<ArrowButton>.
//
// NATIVE_GUIWIDGETS_PENDING bodies need declarations the owners' headers lack (the generated overlay under
// out/native-layouts/gui-widgets2008-pending supplies them; see the recorder):
//   * gui/ArrowPanel.h  ArrowPanel::init(Adorn*, five const std::string&, four SDLKey) (the constructor 00657780 calls
//                       00657240 with ten arguments, ret 0x28);
//   * util/Object.h     Creatable<T>::create with five parameters (create<ArrowButton> 00657190 forwards five
//                       arguments to the ArrowButton constructor 006570a0 at 006571f3).
#include "gui/ArrowPanel.h"
#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	bool ArrowButton::isEnabled()
	{
		return dataModel->create<RunService>()->getRunState() == RS_RUNNING;
	}

#ifdef NATIVE_GUIWIDGETS_PENDING
	void ArrowPanel::init(Adorn* adorn, const std::string& title, const std::string& up, const std::string& down,
						  const std::string& left, const std::string& right, SDLKey upKey, SDLKey downKey, SDLKey leftKey,
						  SDLKey rightKey)
	{
		boost::shared_ptr<TopMenuBar> leftPanel = Creatable<Instance>::create<TopMenuBar>("LeftPanel", Layout::VERTICAL);
		leftPanel->addGuiItem(Creatable<Instance>::create<ImageWidget>(adorn, title));
		leftPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, left, leftKey, controller, dataModel));

		boost::shared_ptr<TopMenuBar> forwardBackPanel =
			Creatable<Instance>::create<TopMenuBar>("ForwardBackPanel", Layout::VERTICAL);
		forwardBackPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, up, upKey, controller, dataModel));
		forwardBackPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, down, downKey, controller, dataModel));

		boost::shared_ptr<TopMenuBar> rightPanel = Creatable<Instance>::create<TopMenuBar>(right, Layout::VERTICAL);
		rightPanel->addGuiItem(Creatable<Instance>::create<MenuSpacer>(32.0f, 32.0f));
		rightPanel->addGuiItem(Creatable<Instance>::create<ArrowButton>(adorn, right, rightKey, controller, dataModel));

		addGuiItem(leftPanel);
		addGuiItem(forwardBackPanel);
		addGuiItem(rightPanel);
	}

	ArrowPanel::ArrowPanel(Adorn* adorn, DataModel* dataModel, Controller::ControllerType controller)
		: TopMenuBar("ArrowPanel", Layout::HORIZONTAL)
	{
		this->dataModel = dataModel;
		this->controller = controller;
		switch (controller)
		{
		case Controller::PLAYER_CONTROLLER:
			init(adorn, "Character", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
			break;
		case Controller::PRIMARY_CONTROLLER:
			init(adorn, "Controller1", "U_key", "J_key", "H_key", "K_key", SDLK_u, SDLK_j, SDLK_h, SDLK_k);
			break;
		case Controller::SECONDARY_CONTROLLER:
			init(adorn, "Controller2", "W_key", "S_key", "A_key", "D_key", SDLK_w, SDLK_s, SDLK_a, SDLK_d);
			break;
		}
	}
#endif

	template boost::shared_ptr<ImageWidget> Creatable<Instance>::create<ImageWidget, Adorn*, std::string>(Adorn*, std::string);
	template boost::shared_ptr<TopMenuBar> Creatable<Instance>::create<TopMenuBar, std::string, Layout::Style>(std::string, Layout::Style);
}
