// =============================================================================
// ChatWidget.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/gui/ChatWidget.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

	GuiResponse UnifiedWidget::process(const GuiEvent& event)
	{
		if (isVisible() && event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN && event.eventType <= UIEvent::MOUSE_IDLE)
		{
			switch (menuState)
			{
			case NOTHING:
				return processNothing(event);
			case HOVER:
				return processHover(event);
			case SHOWN_APPEARING:
			case SHOWN:
				return processShown(event);
			default:
				return GuiResponse::notUsed();
			}
		}
		else
		{
			return GuiResponse::notUsed();
		}
	}

	GuiResponse ChatWidget::process(const GuiEvent& event)
	{
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

#ifdef NATIVE_GUIWIDGETS_PENDING
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

namespace RBX
{
	inline UnifiedWidget::MenuState UnifiedWidget::getMenuState() const { return menuState; }

	void UnifiedImageWidget::render2dMe(Adorn* adorn)
	{
		if (isVisible())
		{
			Widget::WidgetState state;
			switch (getMenuState())
			{
			case HOVER:
				state = Widget::HOVER;
				break;
			case SHOWN_APPEARING:
			case SHOWN:
				state = Widget::DOWN_OVER;
				break;
			default:
				state = Widget::NOTHING;
				break;
			}
			guiImageDraw.render2d(adorn, true, getMyRect(), state);
		}
	}

	void ChatWidget::onMenuStateChanged()
	{
		if (getMenuState() == HOVER)
			setMenuState(SHOWN);
	}

	ChatWidget::ChatWidget(const std::string& title, std::string code)
	{
		setName(title);
		this->code = code;
	}

	UnifiedImageWidget::UnifiedImageWidget(Adorn* adorn, const std::string& name)
		: guiImageDraw(adorn, name)
	{
	}

	G3D::Vector2 UnifiedImageWidget::getSize() const
	{
		return guiImageDraw.getImageSize();
	}

	ChatButton::ChatButton(Adorn* adorn, const std::string& name)
		: UnifiedImageWidget(adorn, name)
	{
	}
}
