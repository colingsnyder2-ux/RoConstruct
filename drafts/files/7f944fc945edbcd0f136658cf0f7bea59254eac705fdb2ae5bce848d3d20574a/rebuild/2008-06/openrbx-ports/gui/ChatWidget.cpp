#include "gui/ChatWidget.h"

#include "network/Players.h"
#include "util/Sound.h"
#include "v8tree/Service.h"

namespace RBX {

// FUNCTION: ROBLOX 0x00657480
void UnifiedImageWidget::render2dMe(Adorn* p_unk0x04)
{
	if (isVisible()) {
		guiImageDraw.render2d(
			p_unk0x04, true, const_cast<Rect&>(static_cast<const Rect&>(getMyRect())), getWidgetState()
		);
	}
}

// FUNCTION: ROBLOX 0x006574e0
void ChatWidget::onMenuStateChanged()
{
	if (getMenuState() == HOVER) {
		setMenuState(SHOWN);
	}
}

// FUNCTION: ROBLOX 0x00657500
ChatWidget::ChatWidget(const std::string& p_unk0x04, std::string p_unk0x08)
{
	setName(p_unk0x04);
	code = p_unk0x08;
}

// FUNCTION: ROBLOX 0x006576d0
// PORT: ChatButton::isVisible is already inline in the 2008 header (C2084).

// FUNCTION: ROBLOX 0x00657710
GuiResponse ChatWidget::process(const GuiEvent& p_unk0x04)
{
	if (isVisible() && p_unk0x04.isMouseEvent() && p_unk0x04.eventType == UIEvent::MOUSE_LEFT_BUTTON_UP &&
		getMyRect().pointInRect(p_unk0x04.mousePosition)) {
		if (Network::Players* players = ServiceProvider::find<Network::Players>(this)) {
			ServiceProvider::create<Soundscape::SoundService>(this)->playSound(CLICK_SOUND);
			std::string message = "/sc " + code;
			players->chat(message);
			return GuiResponse::finished();
		}
	}

	return UnifiedWidget::process(p_unk0x04);
}

} // namespace RBX
