#include "gui/Widget.h"
#include "gui/GuiDraw.h"

namespace RBX
{
	class ChatWidget : public UnifiedWidget
	{
	private:
		std::string code;

	private:
		std::string findMenuString(GuiItem*);
		virtual void onMenuStateChanged();
		virtual GuiResponse process(const GuiEvent&);
	public:
		ChatWidget(const std::string&, std::string);
	};

	class UnifiedImageWidget : public UnifiedWidget
	{
	protected:
		GuiDrawImage guiImageDraw;

	public:
		UnifiedImageWidget(Adorn*, const std::string&);
		Widget::WidgetState getWidgetState() const;
		virtual void render2dMe(Adorn*);
		void setSize(const G3D::Vector2&);
		virtual G3D::Vector2 getSize() const;
	};

	class ChatButton : public UnifiedImageWidget
	{
	private:
		virtual bool isVisible() const;
	public:
		ChatButton(Adorn*, const std::string&);
	};
}
