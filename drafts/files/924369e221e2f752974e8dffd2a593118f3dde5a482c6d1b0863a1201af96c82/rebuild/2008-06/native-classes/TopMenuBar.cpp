// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::TopMenuBar unit (inactive): init 00573530..0057356e, the (name, Layout::Style, bool)
// constructor 00573cb0..00573df8, getSize 00573e30..00573f20, the isVisible inline body 00573e00 and the
// generated destructor family (dtor 00573e20, scalar deleting destructor 00574150, subobject adjustor
// thunks 00573e10/00574130/00574140/005cf5b0/005cf860/00642340/00642350/00642360).
// Layout and addresses in native-headers/gui/Gui.h (class TopMenuBar, declared after TextDisplay).
// getChildPosition 00573f30 and render2d 00574050 are NOT recovered: see
// work/2008-06/shared-layouts/top-menu-bar-20261106.json for their evidence and next proof.
#include "gui/Gui.h"

namespace RBX
{
	void TopMenuBar::init()
	{
		layoutStyle = Layout::HORIZONTAL;
		backdropColor = G3D::Color4::clear();
		visible = true;
	}

	TopMenuBar::TopMenuBar(const std::string& name, Layout::Style style, bool visible)
		: GuiItem()
	{
		layoutStyle = Layout::HORIZONTAL;
		backdropColor = G3D::Color4::clear();
		this->visible = true;
		setName(name);
		this->layoutStyle = style;
		if (visible)
		{
			static const G3D::Color4 backdrop(0.6f, 0.6f, 0.6f, 0.6f);
			backdropColor = backdrop;
		}
	}

	G3D::Vector2 TopMenuBar::getSize() const
	{
		G3D::Vector2 size(0.0f, 0.0f);

		for (int i = 0; i < numChildren(); ++i)
		{
			const GuiItem* child = dynamic_cast<const GuiItem*>(getChild(i));
			if (child)
			{
				G3D::Vector2 childSize = child->getSize();
				switch (layoutStyle)
				{
				case Layout::HORIZONTAL:
					size.x += childSize.x;
					size.y = G3D::max(size.y, childSize.y);
					break;
				case Layout::VERTICAL:
					size.x = G3D::max(size.x, childSize.x);
					size.y += childSize.y;
					break;
				}
			}
		}

		return size;
	}

	G3D::Vector2 TopMenuBar::getChildPosition(const GuiItem* child) const
	{
		G3D::Vector2 position = getPosition();
		G3D::Vector2 size = getSize();

		for (int i = 0; i < numChildren(); ++i)
		{
			const GuiItem* item = dynamic_cast<const GuiItem*>(getChild(i));
			if (item)
			{
				G3D::Vector2 itemSize = item->getSize();
				if (item == child)
				{
					int axis = (layoutStyle + 1) % 2;
					position[axis] += (size[axis] - itemSize[axis]) * 0.5f;
					return position;
				}

				switch (layoutStyle)
				{
				case Layout::HORIZONTAL:
				case Layout::VERTICAL:
					position[layoutStyle] += item->getSize()[layoutStyle];
					break;
				}
			}
		}

		return position;
	}
}
