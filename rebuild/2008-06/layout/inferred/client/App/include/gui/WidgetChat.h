#pragma once
#include "gui/Widget.h"
#include "gui/GuiDraw.h"

struct NativeWidgetLayout;

namespace RBX
{
	class ChatWidget : public UnifiedWidget
	{
	private:
		std::string code;                                            // +0x148

	private:
		virtual void onMenuStateChanged();                           // slot 25, 0064e8a0 (pending)
		virtual GuiResponse process(const GuiEvent&);                // 0064ead0 (not attempted)
	public:
		ChatWidget(const std::string&, std::string);                 // 0064e8c0
		friend struct ::NativeWidgetLayout;
	};

	class UnifiedImageWidget : public UnifiedWidget
	{
	protected:
		GuiDrawImage guiImageDraw;                                   // +0x148

	public:
		UnifiedImageWidget(Adorn*, const std::string&);              // 00601c50
		virtual void render2dMe(Adorn*);                             // slot 28, 0064e840
		virtual G3D::Vector2 getSize() const;                        // slot 23, 0064f280
		friend struct ::NativeWidgetLayout;
	};

	class ChatButton : public UnifiedImageWidget
	{
	private:
		virtual bool isVisible() const;                              // slot 21, 0064ea90 (not attempted)
	public:
		ChatButton(Adorn*, const std::string&);                      // 00601d00
	};
}
