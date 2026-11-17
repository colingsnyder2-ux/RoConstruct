// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /fp:fast /U_RELEASEASSERT
#include "v8datamodel/Feature.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
bool Feature::getRenderCoord(G3D::CoordinateFrame& c) const
	{
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());

		if (part)
		{
			// for some reason local is being taken as operator*'s LHS
			// and not part->getCoordinateFrame()
			G3D::CoordinateFrame local = computeLocalCoordinateFrame();
			c = part->getCoordinateFrame()*local;

			return true;
		}
		else
		{
			return false;
		}
	}

	G3D::CoordinateFrame Feature::computeLocalCoordinateFrame() const
	{
		PartInstance* part = dynamic_cast<PartInstance*>(getParent());

		if (!part)
			return G3D::CoordinateFrame();

		Extents extents = part->getPrimitive()->getExtentsLocal();

		G3D::Vector3 corner = extents.max();
		G3D::Vector3 uv = Math::vector3Abs(RBX::objectToUvw(corner, faceId));

		uv.z = 0.0f;

		switch (leftRight)
		{
			case LEFT:
				uv.x = -uv.x;
				break;

			case CENTER_LR:
				uv.x = 0.0f;
				break;
		}

		switch (topBottom)
		{
			case CENTER_TB:
				uv.y = 0.0f;
				break;

			case BOTTOM:
				uv.y = -uv.y;
				break;
		}

		switch (inOut)
		{
		case INSET:
			uv.x = RBX::Math::sign(uv.x) * std::max(0.0f, std::abs(uv.x) - 1.0f);
			uv.y = RBX::Math::sign(uv.y) * std::max(0.0f, std::abs(uv.y) - 1.0f);
			break;

		case CENTER_IO:
			uv.x = 0.0f;
			uv.y = 0.0f;
			break;
		}

		G3D::Vector3 uvInObject = RBX::uvwToObject(uv, faceId);
		G3D::Vector3 ptInObject = extents.faceCenter(faceId) + uvInObject;

		RBX::NormalId face = getCoordOrientation() == Z_OUT
							     ? faceId
							     : RBX::intToNormalId((faceId + NORM_X_NEG) % NORM_UNDEFINED);

		return G3D::CoordinateFrame(RBX::normalIdToMatrix3(face), ptInObject);
	}

	
}
