#pragma once
#include <g3d/coordinateframe.h>

namespace RBX
{
	class __declspec(novtable) ILocation
	{
	public:
		virtual const G3D::CoordinateFrame getLocation() const = 0;
	};
}
// 2008-06 native header port of rbxgs App/include/util/ILocation.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
