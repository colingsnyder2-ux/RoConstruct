#pragma once
#include "util/Rect.h"
#include <G3D/Color4.h>

namespace RBX
{
	class Layout
	{
	public:
		enum Style
		{
			HORIZONTAL,
			VERTICAL
		};

	public:
		Rect::Location xLocation;
		Rect::Location yLocation;
		G3D::Vector2int16 offset;
		Style layoutStyle;
		G3D::Color4 backdropColor;

	public:
		Layout()
			: backdropColor(G3D::Color4::clear()),
			  offset(0, 0),
			  layoutStyle(HORIZONTAL),
			  xLocation(Rect::LEFT),
			  yLocation(Rect::TOP)
		{
		}
	};
}
// 2008-06 native header port of rbxgs App/include/gui/Layout.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
