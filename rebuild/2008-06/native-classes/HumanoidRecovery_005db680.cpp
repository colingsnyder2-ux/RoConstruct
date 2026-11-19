// 2008-06 native RBX::Humanoid recovery: renderMultiplayer 005db680 (734 bytes, byte-exact).
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/draw-handles
#include "humanoid/Humanoid2008.h"
#include "v8tree/Service.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Teams.h"
#include "util/Color.h"
#include "util/Rect.h"
#include "RbxGraphics/Adorn.h"

namespace RBX
{
	// 005db680 (734 bytes): name tag and health bar of another player's character. Read from the target:
	// getHead 005d8a10, PartInstance::getCoordinateFrame 00598cb0 + 1.5f (0081e37c) up, Adorn::getViewport (slot 4),
	// GCamera::project 00510d00, GCamera::getCoordinateFrame 005107b0; drawn only under 100.0f (008163a4) and head
	// transparency (+0x1e8) under 0.99f (0083d7e0). Font size 12 / 10 / 8 below 20.0f (008222f0) / 50.0f (00819ba4).
	// ServiceProvider::find<Teams> 0049ab50 + Teams::getTeamColorForHumanoid 005d6180, else Color3::white 00514a60;
	// outline Color3::black 005149f0. The parent's name (+0x104 -> +0x110) through Adorn::drawFont2D (slot 13),
	// Vector3::xy (ICF 005185d0). The bar is fontSize * 4 wide and fontSize / 2 high (both int, fild'd), split at
	// health (+0x1a8) / maxHealth (+0x1ac): Rect2D::xyxy 004f35d0 and Adorn::rect2d (slot 11) with RBX::Color::lightGreen
	// 005d7560 then Color3::red 005148b0 (ICF with Vector3::unitX). Each bar is a Rect of two Vector2 corners, and the
	// Color3 -> Color4 temporary is built before the xyxy call, so the call is `rect2d(rect.toRect2D(), Color::x())`
	// with the Color3 implicitly converted (right-to-left argument evaluation).
	void Humanoid::renderMultiplayer(Adorn* adorn, const G3D::GCamera& camera)
	{
		PartInstance* head = getHead();
		if (head)
		{
			G3D::Vector3 headPosition = head->getCoordinateFrame().translation;
			headPosition.y += 1.5f;
			G3D::Vector3 screen = camera.project(headPosition, adorn->getViewport());
			float distance = (camera.getCoordinateFrame().translation - headPosition).magnitude();

			if (distance < 100.0f && head->getTransparencyXml() < 0.99f)
			{
				int fontSize = 8;
				if (distance < 20.0f)
					fontSize = 12;
				else if (distance < 50.0f)
					fontSize = 10;

				Teams* teams = ServiceProvider::find<Teams>(this);
				G3D::Color3 color = teams ? teams->getTeamColorForHumanoid(this) : G3D::Color3::white();

				adorn->drawFont2D(getParent()->getName(), screen.xy(), fontSize, G3D::Color4(color, 1.0f),
								  G3D::Color4(G3D::Color3::black(), 1.0f), Adorn::XALIGN_CENTER, Adorn::YALIGN_BOTTOM,
								  Adorn::PROPORTIONAL_SPACING);

				float width = (float)(fontSize * 4);
				G3D::Vector2 low(screen.x - 0.5f * width, screen.y);
				G3D::Vector2 high = low + G3D::Vector2(width, (float)(fontSize / 2));
				float healthX = low.x + relativeHealth() * width;

				Rect greenBarRect(low, G3D::Vector2(healthX, high.y));
				Rect redBarRect(G3D::Vector2(healthX, low.y), high);

				adorn->rect2d(greenBarRect.toRect2D(), Color::lightGreen());
				adorn->rect2d(redBarRect.toRect2D(), G3D::Color3::red());
			}
		}
	}
}
