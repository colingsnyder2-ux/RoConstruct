// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /U_RELEASEASSERT
#include "gui/Gui.h"
namespace RBX {
	void UnifiedWidget::init()
	{
		setGuiSize(G3D::Vector2(140.0f, 24.0f));
		menuState = NOTHING;
	}

	void UnifiedWidget::render2dChildren(Adorn* adorn)
	{
		if (menuState >= SHOWN_APPEARING)
		{
			for (size_t i = 0; i < numChildren(); ++i)
			{
				if (GuiItem* guiItem = dynamic_cast<GuiItem*>(getChild(i)))
					guiItem->render2d(adorn);
			}
		}
	}

	GuiResponse UnifiedWidget::processShown_OutOfTitle(const GuiEvent& event)
	{
		UnifiedWidget* oldFocus = dynamic_cast<UnifiedWidget*>(getFocus());

		if (event.eventType >= GuiEvent::MOUSE_LEFT_BUTTON_DOWN)
		{
			if (event.eventType > GuiEvent::MOUSE_LEFT_BUTTON_UP)
			{
				if (event.eventType == GuiEvent::MOUSE_MOVE)
				{
					MenuState oldFocusMenuState = oldFocus ? oldFocus->menuState : NOTHING;
					GuiResponse response = GuiItem::process(event);

					if (oldFocus)
					{
						if (UnifiedWidget* newFocus = dynamic_cast<UnifiedWidget*>(getFocus()))
						{
							if (newFocus != oldFocus)
								newFocus->setMenuState(oldFocusMenuState);
						}
					}

					return GuiResponse::used();
				}
			}
			else
			{
				GuiResponse response = GuiItem::process(event);

				if (response.wasNotUsed())
				{
					RBXASSERT(!getFocus());
					setMenuState(NOTHING);
				}
				else if (response.wasFinished())
				{
					loseFocus();
					setMenuState(NOTHING);
				}

				return response;
			}
		}

		RBXASSERT(false);
		return GuiResponse::notUsed();
	}
}
