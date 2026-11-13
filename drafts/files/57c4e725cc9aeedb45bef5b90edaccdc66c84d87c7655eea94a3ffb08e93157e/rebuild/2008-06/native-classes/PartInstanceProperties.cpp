// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native recovery (inactive): PartInstance property accessors/setters with no other out-of-line definition.
// Layout from native-headers/part-embedded/v8datamodel/PartInstance.h (Primitive embedded at +0x228, IRenderable at
// +0x1cc). Bodies follow the donor tools/rbxgs PartInstance.cpp shape, corrected to the 2008 bytes.
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "tool/Dragger.h"
#include <G3D/g3dmath.h>

namespace RBX
{
	// 00976250: file-local UI "Size" descriptor raised by setPartSizeXml (donor prop_SizeUi).
	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_SizeUi(
		"Size", "Part", &PartInstance::getPartSizeUi, &PartInstance::setPartSizeUi, Reflection::PropertyDescriptor::UI);
	// 009761b8: file-local "Friction" descriptor raised by setFriction (donor prop_Friction).
	static Reflection::PropDescriptor<PartInstance, float> prop_Friction(
		"Friction", "Part", &PartInstance::getFriction, &PartInstance::setFriction, Reflection::PropertyDescriptor::STANDARD);

	// 00598d20: getter of the "CanCollide" descriptor (initializer 007f4892). Reads Primitive +0xa8 (dragging) and
	// +0xab; the 2008 +0xab flag is the inverted collide flag (setter 0059dd80 stores !value there), which the shared
	// Primitive header currently names canSleep.
	bool PartInstance::getCanCollide() const
	{
		return !primitive.getDragging() && !primitive.getCanSleep();
	}

	// 0059dd80: setter of the "CanCollide" descriptor (initializer 007f487b); Primitive 005e75e0, prop 00976000.
	void PartInstance::setCanCollide(bool value)
	{
		value = !value;
		if (value != primitive.getCanSleep())
		{
			primitive.setCanSleep(value);
			raisePropertyChanged(prop_CanCollide);
		}
	}

	// 00598d70: out-of-line Primitive::getExtentsWorld 00598b60
	Extents PartInstance::getExtentsWorld() const
	{
		return primitive.getExtentsWorld();
	}

	// 00598d90
	Extents PartInstance::getExtentsLocal() const
	{
		return primitive.getExtentsLocal();
	}

	// 00599fa0: IRenderable override (this = PartInstance + 0x1cc). PARKED: the 2008 body also tests a third
	// PartInstance static bool at 00975f8b (between highlightAwakeParts 00975f8a and showAnchoredParts 00975f8c)
	// that the shared header does not declare; this draft omits it until the header gains the member.
	bool PartInstance::shouldRender3dAdorn() const
	{
		return partType == Part::CYLINDER_PART ||
			   SurfacesNeedAdorn ||
			   highlightSleepParts ||
			   highlightAwakeParts ||
			   showPartCoord ||
			   showAnchoredParts ||
			   showUnalignedParts ||
			   showSpanningTree;
	}

	// 0059b4f0: Workspace::getWorldIfInWorkspace 005a3390, Array append 0059a190,
	// Dragger::safeMoveNoDrop 00610930 with World contact manager (+0x84), Vector3::zero 0096f044.
	void PartInstance::safeMove()
	{
		if (World* world = Workspace::getWorldIfInWorkspace(this))
		{
			G3D::Array<Primitive*> temp;
			temp.append(&primitive);
			Dragger::safeMoveNoDrop(temp, G3D::Vector3::zero(), world->getContactManager());
		}
	}

	// 0059d370: GuidItem<Instance>::registerGuid 0049bba0, Primitive::setGuid 005e7450 (guid at +0x8)
	void PartInstance::onGuidChanged()
	{
		registerGuid();
		primitive.setGuid(guid);
	}

	// 0059db90: Vector3::xxx 00518630, getGridCorner 005e82e0 / setGridSize 005e8470 / setGridCorner 005e8500,
	// prop_Size 00976148 then prop_SizeUi 00976250, PersistentPart (+0x398) dirty, onExtentsChanged (vtable +0x50).
	void PartInstance::setPartSizeXml(const G3D::Vector3& rbxSize)
	{
		if (rbxSize != primitive.getGridSize())
		{
			G3D::Vector3 newRbxSize = partType == Part::BLOCK_PART ? rbxSize : rbxSize.xxx();
			if (legacyOffset.get())
			{
				G3D::CoordinateFrame oldCorner = primitive.getGridCorner();
				primitive.setGridSize(newRbxSize);
				primitive.setGridCorner(oldCorner);
			}
			else
			{
				primitive.setGridSize(newRbxSize);
			}
			raisePropertyChanged(prop_Size);
			raisePropertyChanged(prop_SizeUi);
			PersistentPart.setDirty();
			onExtentsChanged();
		}
	}

	// 0059ddc0: Primitive::setAnchor 005e80d0, prop_Anchored 00975fe4
	void PartInstance::setAnchored(bool value)
	{
		if (value != primitive.getAnchor())
		{
			primitive.setAnchor(value);
			raisePropertyChanged(prop_Anchored);
		}
	}

	// 0059deb0: setter of the "Transparency" descriptor (initializer 007f46fb, getter 00598be0 reads +0x1e8).
	// The identity registry labels this row setAlphaModifier; the descriptor and the +0x1e8 store prove it is
	// setTransparency (transparency +0x1e8, prop_Transparency 00976128).
	void PartInstance::setTransparency(float value)
	{
		if (value != transparency)
		{
			transparency = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	// 0059df40: color +0x1e4, prop_BrickColor 009762d0 then prop_Color 0097610c
	void PartInstance::setColor(BrickColor value)
	{
		if (value != color)
		{
			color = value;
			raisePropertyChanged(prop_BrickColor);
			raisePropertyChanged(prop_Color);
		}
	}

	// 0059e090: clamp to [0, 2] (0081c434 = 2.0f), Primitive::setFriction 005e7600, prop_Friction 009761b8
	void PartInstance::setFriction(float friction)
	{
		float newFriction = G3D::clamp(friction, 0.0f, 2.0f);
		if (newFriction != primitive.getFriction())
		{
			primitive.setFriction(newFriction);
			raisePropertyChanged(prop_Friction);
		}
	}
}
