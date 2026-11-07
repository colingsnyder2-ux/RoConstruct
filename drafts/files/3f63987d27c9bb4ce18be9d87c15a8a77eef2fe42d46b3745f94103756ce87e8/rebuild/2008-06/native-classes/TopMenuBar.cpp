// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /DNOMINMAX
// 2008-06 native RBX::TopMenuBar unit (inactive): init 00573530..0057356e, the (name, Layout::Style, bool)
// constructor 00573cb0..00573df8, getSize 00573e30..00573f20, the isVisible inline body 00573e00 and the
// generated destructor family (dtor 00573e20, scalar deleting destructor 00574150, subobject adjustor
// thunks 00573e10/00574130/00574140/005cf5b0/005cf860/00642340/00642350/00642360).
// Layout and addresses in native-headers/gui/Gui.h (class TopMenuBar, declared after TextDisplay).
// getChildPosition 00573f30 is recovered (merged). render2d 00574050 is NOT: the recorded blocker below is now
// resolved as a MISREADING of mine - the call is to vtable slot 11 = rect2d (2 args), not outlineRect2d - but the
// method is still blocked on the shared header's getMyRect2D being inline. Body and evidence:
// work/2008-06/shared-layouts/top-menu-bar-20261106.json (render2d_decoded).
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

	// render2d 00574050 (220 B). The original's key call is 005740ad: it pushes &backdropColor and then the sret,
	// i.e. the callee at 0x573960 (evidence: GuiItem::getMyRect2D, score 34) is called as
	// getMyRect2D(&rect, backdropColor) - NOT as the zero-argument form the shared native-headers/gui/Gui.h
	// declares (that inline 2-liner is a LATER-interface simplification and inlines to 41 B where the binary's
	// function is 105 B). Because Gui.h declares the zero-argument form, the extra argument cannot be spelled
	// with the real name from this unit, so the call is bound through a stand-in whose only content is what the
	// binary proves: (this, const Color4&, sret). The reference unit src/2008-06/00574050.cpp (100% by
	// king_originala) carries the same shape. Merging this into a clean class body needs the owner to give
	// GuiItem::getMyRect2D its original one-argument signature and out-of-line body.
	struct GetRect2DHelper
	{
		void __thiscall query(G3D::Rect2D* result, const G3D::Color4& color);
	};

	void TopMenuBar::render2d(Adorn* adorn)
	{
		if (isVisible())
		{
			if (backdropColor != G3D::Color4::clear())
			{
				GetRect2DHelper* helper = (GetRect2DHelper*)this;
				G3D::Rect2D rect;
				helper->query(&rect, backdropColor);
				adorn->rect2d(rect, backdropColor);
			}

			for (size_t i = 0; i < numChildren(); ++i)
			{
				GuiItem* item = dynamic_cast<GuiItem*>(getChild(i));
				if (item)
					item->render2d(adorn);
			}
		}
	}
}
