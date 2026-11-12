// from server: 96% by EspClaude
// from server: 69% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_6b965e75450d0663.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 0x574a40 PartInstance::computePersistentPart: self-contained codegen analog.
// Offsets read off the target: partType +0x18c, color +0x194, transparency +0x198,
// surfaces +0x1a4, primitive +0x1d8, alphaModifier +0x1e0; Primitive geometry +0x60,
// body +0x64; Body pv.position +0x84 after updatePV(); Geometry gridSize +4.
#pragma float_control(precise, off)
#include "AppDraw/Part.h"
#include <G3D/Color3.h>
namespace RBX
{
	class Body
	{
		char pad0[0x84];
		G3D::CoordinateFrame position;
	public:
		void updatePV() const;
		const G3D::CoordinateFrame& getCoordinateFrame() const
		{
			updatePV();
			return position;
		}
	};
	class Geometry
	{
		void* vtbl;
		G3D::Vector3 gridSize;
	public:
		const G3D::Vector3& getGridSize() const
		{
			return this->gridSize;
		}
	};
	class Primitive
	{
		char pad0[0x60];
		Geometry* geometry;
		Body* body;
	public:
		Geometry* getGeometry() const { return geometry; }
		const G3D::CoordinateFrame& getCoordinateFrame() const
		{
			return body->getCoordinateFrame();
		}
	};
	class BrickColor
	{
		int number;
	public:
		G3D::Color3 color3() const;
	};
	class Surfaces
	{
		int data[0x30 / 4];
	public:
		Vector6<SurfaceType> surf6() const;
	};
	class PartInstance
	{
		char pad0[0x18c];
		Part::PartType partType;
		int formFactor;
		BrickColor color;
		float transparency;
		float reflectance;
		bool locked;
		mutable Surfaces surfaces;
		float renderImportance;
		Primitive* primitive;
		void* myWorld;
		float alphaModifier;

		Part computePersistentPart() const;
	public:
		const G3D::Vector3& getPartSizeXml() const;
		float getTransparencyUi() const
		{
			return (1.0f - transparency) * alphaModifier;
		}
		G3D::Color3 getColor3() const
		{
			return color.color3();
		}
		float alpha() const
		{
			return 1.0f - getTransparencyUi();
		}
	};

	const G3D::Vector3& PartInstance::getPartSizeXml() const
	{
		return primitive->getGeometry()->getGridSize();
	}

	Part PartInstance::computePersistentPart() const
	{
		const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();
		float transparency = 1.0f - alpha();

		return Part(partType, getPartSizeXml(), G3D::Color4(getColor3(), transparency), surfaces.surf6(), cframe);
	}
}
