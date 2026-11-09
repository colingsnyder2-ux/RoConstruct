#include "gui/Widget.h"
#include "gui/GuiDraw.h"

namespace RBX
{
	class TextButton : public VerbWidget
	{
	protected:
		virtual bool canLoseFocus();
	public:
		TextButton(Verb*, const std::string&, int);
		TextButton();
		virtual G3D::Color4 getFontColor();
	};

	class ImageWidget : public Widget
	{
	private:
		GuiDrawImage guiImageDraw;

	public:
		ImageWidget(Adorn*, const std::string&);
		virtual void render2d(Adorn*);
		virtual G3D::Vector2 getSize() const;
	};

	class ImageButton : public VerbWidget
	{
	protected:
		GuiDrawImage guiImageDraw;

	public:
		ImageButton(Adorn*, Verb*, const std::string&);
		virtual void render2d(Adorn*);
		void setSize(const G3D::Vector2&);
		virtual G3D::Vector2 getSize() const;
	};

	class ImageToggleButton : public ImageButton
	{
	public:
		ImageToggleButton(Adorn*, Verb*, const std::string&);
		virtual void render2d(Adorn*);
	};

	class MultiImageButton : public MultiVerbWidget
	{
	private:
		std::map<Verb*, GuiDrawImage*> images;

	protected:
		virtual bool canLoseFocus();
		void addVerb(Adorn*, Verb*);
	public:
		MultiImageButton(const std::string&, const G3D::Vector2&);
		virtual ~MultiImageButton();
		virtual void render2d(Adorn*);
	};

	class KeyButton : public Widget
	{
	private:
		SDLKey keyCode;
		bool keyIsDown;

	protected:
		virtual void onDown(const UIEvent&);
		virtual void onUp(const UIEvent&);
		virtual bool isEnabled();
		virtual GuiResponse process(const GuiEvent&);
	public:
		KeyButton(const std::string&, SDLKey);
	};

	class ImageKeyButton : public KeyButton
	{
	private:
		GuiDrawImage imageDraw;

	public:
		ImageKeyButton(Adorn*, const std::string&, SDLKey);
		virtual void render2d(Adorn*);
		virtual G3D::Vector2 getSize() const;
	};
}
