// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /GS-
#include "../native-headers/gui/ChatOutput.h"

namespace RBX {
void ChatOutput::render2d(Adorn* adorn)
{
	const int fontSize = 12;

	Rect uiRect = getMyRect();

	G3D::Vector2 topPos = uiRect.low;
	topPos.y -= fontSize * fifo.size();

	for (size_t i = 0; i < fifo.size(); ++i)
	{
		std::string username = fifo[i]->user + "; ";

		G3D::Vector2 usernameBounds = adorn->get2DStringBounds(username, fontSize, Adorn::PROPORTIONAL_SPACING);
		G3D::Vector2 messageBounds = adorn->get2DStringBounds(fifo[i]->message, fontSize, Adorn::PROPORTIONAL_SPACING);
		float usernameXOffset = std::max(usernameBounds.x + 4.0f, 20.0f);

		float backgroundWidth = messageBounds.x + usernameXOffset;
		Rect backgroundRect(topPos.x - 2.0f, topPos.y + 1.0f,
			topPos.x + backgroundWidth + 2.0f,
			topPos.y + usernameBounds.y - 1.0f);
		adorn->rect2d(backgroundRect.toRect2D(), GuiItem::translucentBackdrop());

		G3D::Color3 messageColor = G3D::Color3::white();
		if (fifo[i]->profane)
			messageColor = G3D::Color3::red();

		adorn->drawFont2D(
			username,
			topPos,
			fontSize,
			fifo[i]->userColor,
			G3D::Color4::zero(),
			Adorn::XALIGN_LEFT,
			Adorn::YALIGN_TOP,
			Adorn::PROPORTIONAL_SPACING
		);

		adorn->drawFont2D(
			fifo[i]->message,
			G3D::Vector2(topPos.x + usernameXOffset, topPos.y),
			fontSize,
			messageColor,
			G3D::Color4::zero(),
			Adorn::XALIGN_LEFT,
			Adorn::YALIGN_TOP,
			Adorn::PROPORTIONAL_SPACING
		);

		topPos.y += fontSize + 2;
	}
}
}
