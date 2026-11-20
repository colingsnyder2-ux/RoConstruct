#include "gui/WidgetButtons.h"

namespace RBX
{
	inline const Name& Verb::getName() const { return name; }

	GuiResponse KeyButton::process(const GuiEvent& event)
	{
		if (event.eventType == UIEvent::KEY_DOWN && event.key == keyCode)
			keyIsDown = true;
		if (event.eventType == UIEvent::KEY_UP && event.key == keyCode)
			keyIsDown = false;
		return Widget::process(event);
	}

	void KeyButton::onDown(const UIEvent& event)
	{
		event.userInput->setKeyState(keyCode, true);
	}

	void KeyButton::onUp(const UIEvent& event)
	{
		event.userInput->setKeyState(keyCode, false);
	}

	void ImageKeyButton::render2d(Adorn* adorn)
	{
		if (isVisible())
			imageDraw.render2d(adorn, isEnabled(), getMyRect(), keyIsDown ? Widget::DOWN_OVER : widgetState);
	}

	void ImageWidget::render2d(Adorn* adorn)
	{
		if (isVisible())
			guiImageDraw.render2d(adorn, isEnabled(), getMyRect(), Widget::NOTHING);
	}

	void ImageButton::render2d(Adorn* adorn)
	{
		if (isVisible())
			guiImageDraw.render2d(adorn, isEnabled(), getMyRect(), widgetState);
	}

	KeyButton::KeyButton(const std::string& name, SDLKey keyCode)
		: keyCode(keyCode),
		  keyIsDown(false)
	{
		setName(name);
	}

	ImageWidget::ImageWidget(Adorn* adorn, const std::string& name)
		: guiImageDraw(adorn, name)
	{
		setName(name);
	}

	G3D::Vector2 ImageWidget::getSize() const
	{
		return guiImageDraw.getImageSize();
	}

	ImageButton::ImageButton(Adorn* adorn, Verb* verb, const std::string& title)
		: VerbWidget(verb),
		  guiImageDraw(adorn, verb->getName().toString())
	{
		setName(title);
	}

	G3D::Vector2 ImageButton::getSize() const
	{
		return guiImageDraw.getImageSize();
	}

	ImageKeyButton::ImageKeyButton(Adorn* adorn, const std::string& name, SDLKey keyCode)
		: KeyButton(name, keyCode),
		  imageDraw(adorn, name)
	{
	}

	G3D::Vector2 ImageKeyButton::getSize() const
	{
		return imageDraw.getImageSize();
	}
}
