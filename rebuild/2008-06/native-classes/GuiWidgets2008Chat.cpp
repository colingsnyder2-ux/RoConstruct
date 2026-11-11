// 2008-06 native gui widget leaves (inactive): the ChatWidget / ChatButton rows of the Button unit 0064e840..0064eaf0
// and EquationDisplay::getLabel 00656940, which native-classes/WidgetChat.cpp and EquationDisplay.cpp (verified by
// tests/record_native_widget.py) do not compile. Classes and layouts in native-headers/gui/WidgetChat.h and
// gui/EquationDisplay.h (read-only here); verified by tests/record_native_gui_widgets2008.py.
//
//   ChatButton::isVisible 0064ea90 (slot 21 of 0084232c): ServiceProvider::find<Network::Players>(this) 00491d50, the
//   inline Players::getLocalPlayer (localPlayer +0x1a0, 0064eaa0), then Players::clientIsPresent(this, true) 00495e60.
//
// NATIVE_GUIWIDGETS_PENDING bodies need declarations the owners' headers lack (the generated overlay under
// out/native-layouts/gui-widgets2008-pending supplies them; see the recorder):
//   * util/Rect.h (donor)  `bool pointInRect(G3D::Vector2int16)` out of line: ChatWidget::process 0064ead0 calls
//                          00573130 (0064eb3b) like Widget::processMouse (record_native_widget.py, same proposal);
//   * v8tree/Instance.h    the donor's inline Instance::getRootAncestor() / getRootAncestor() const and static
//                          getRootAncestor(const Instance*): EquationDisplay::getLabel 00656940 tests this (00656963),
//                          inlines two parent steps (+0x104) and calls the out-of-line one 0042a5f0 (0065697b).
// >>> native-status (generated) -- do not edit >>>
// GuiWidgets2008Chat | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 58795820 | roc native-status --write
#include "gui/WidgetChat.h"
#include "gui/EquationDisplay.h"
#include "Network/Players.h"
#include "util/Sound.h"
#include "util/Evaluator.h"

namespace RBX
{
	bool ChatButton::isVisible() const
	{
		Network::Players* players = ServiceProvider::find<Network::Players>(this);
		return players && players->getLocalPlayer() && Network::Players::clientIsPresent(this, true);
	}

#ifdef NATIVE_GUIWIDGETS_PENDING
	GuiResponse ChatWidget::process(const GuiEvent& event)
	{
		// The range test (cmp 1 / jl, cmp 7 / jg at 0064eb0e) is the inline isMouseEvent of the 2008 build, written out
		// as in Widget::process (native-classes/Widget.cpp): the donor UIEvent::isMouseEvent compares each type.
		if (isVisible() && event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN && event.eventType <= UIEvent::MOUSE_IDLE
			&& event.eventType == UIEvent::MOUSE_LEFT_BUTTON_UP
			&& getMyRect().pointInRect(event.mousePosition))
		{
			if (Network::Players* players = ServiceProvider::find<Network::Players>(this))
			{
				ServiceProvider::create<Soundscape::SoundService>(this)->playSound(CLICK_SOUND);
				std::string message = "/sc " + code;   // a named temporary, then copied into the by-value argument
				players->chat(message);
				return GuiResponse::finished();
			}
		}
		return UnifiedWidget::process(event);
	}

	std::string EquationDisplay::getLabel() const
	{
		if (const Evaluator* evaluator = dynamic_cast<const Evaluator*>(Instance::getRootAncestor(this)))
		{
			std::string value = evaluator->evaluate(equation);   // a named local (EH state 0 at 006569cc)
			return label + " " + value;
		}
		return label;
	}
#endif
}
