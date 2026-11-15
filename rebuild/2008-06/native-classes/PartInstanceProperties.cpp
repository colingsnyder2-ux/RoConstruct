// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// 2008-06 native recovery (inactive): PartInstance property accessors/setters with no other out-of-line definition.
// Layout from native-headers/part-embedded/v8datamodel/PartInstance.h (Primitive embedded at +0x228, IRenderable at
// +0x1cc). Bodies follow the donor tools/rbxgs PartInstance.cpp shape, corrected to the 2008 bytes.
#undef _RELEASEASSERT
// The 2008 Body / Contact / ContactConnector / GeoPair path of part-embedded v8world/Primitive.h (render3dAdorn
// showContactPoints loop: Contact slots 8 / 9, ContactConnector +0x8, GeoPair::computePosition 00599250).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "tool/Dragger.h"
#include <G3D/g3dmath.h>
#include <G3D/Sphere.h>
#include <G3D/AABox.h>
#include "v8world/AssemblyLayout.h"  // 2008 sleepInfo +0x18 / root primitive views (render3dAdorn)
#include "v8world/Controller.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include "RbxGraphics/Adorn.h"
#include "util/Math.h"
#include "v8world/Contact2008.h"     // 2008 Contact slot 8 numConnectors (+0x20) / slot 9 getConnector (+0x24)
#include "v8kernel/Connector2008.h"  // ContactConnector::getGeoPair (+0x8), GeoPair2008.h computePosition 00599250

namespace RBX
{
	// Unit-local redeclaration (pattern of BlockBlockContactStep.cpp): Sim::AssemblyState copied from the donor
	// tools/rbxgs v8world/Assembly.h. That header reaches the donor IPipelined -> Kernel -> Body.h, which cannot sit
	// next to the 2008 Body2008.h this unit takes through NATIVE_PRIMITIVE_NATIVE_BODY (C2011); the 2008 values are the
	// same (AssemblyLayout::getSleepStatus, jump tables 0059eb28 / 0059eb3c).
	namespace Sim
	{
		enum AssemblyState
		{
			ANCHORED,
			RECURSIVE_WAKE_PENDING,
			WAKE_PENDING,
			AWAKE,
			SLEEPING_CHECKING,
			SLEEPING_DEEPLY
		};
	}

	// 00976250: file-local UI "Size" descriptor raised by setPartSizeXml (donor prop_SizeUi).
	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_SizeUi(
		"Size", "Part", &PartInstance::getPartSizeUi, &PartInstance::setPartSizeUi, Reflection::PropertyDescriptor::UI);
	// 009761b8: file-local "Friction" descriptor raised by setFriction (donor prop_Friction).
	static Reflection::PropDescriptor<PartInstance, float> prop_Friction(
		"Friction", "Part", &PartInstance::getFriction, &PartInstance::setFriction, Reflection::PropertyDescriptor::STANDARD);
	// 009762ec: file-local "FormFactor" descriptor (initializer 007f4a50, setter 0059df70, getter 00598bd0, STREAMING).
	static Reflection::PropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactor(
		"FormFactor", "Part", &PartInstance::getFormFactor, &PartInstance::setFormFactorXml, Reflection::PropertyDescriptor::STREAMING);
	// 00975f90: file-local "Elasticity" descriptor (initializer 007f4ab0, setter 0059e0f0).
	static Reflection::PropDescriptor<PartInstance, float> prop_Elasticity(
		"Elasticity", "Part", &PartInstance::getElasticity, &PartInstance::setElasticity, Reflection::PropertyDescriptor::STANDARD);
	// 00975fc8: file-local "DraggingV1" descriptor (initializer 007f4bc0, setter 0059dd20).
	static Reflection::PropDescriptor<PartInstance, bool> prop_Dragging(
		"DraggingV1", "Behavior", &PartInstance::getDragging, &PartInstance::setDragging, Reflection::PropertyDescriptor::STREAMING);

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

	// 00975f89: debug flag (rbxgs patch name showContactPoints), the byte before highlightSleepParts 00975f8a in the
	// 0x975f89..8f run of PartInstance debug bools; tested first by shouldRender3dAdorn 00599fa0 (00599ff6) and by the
	// contact loop of render3dAdorn 0059e4d0 (0059e99e). Zero-initialized like its neighbours.
	bool PartInstance::showContactPoints = false;

	// 00599fa0: IRenderable override (this = PartInstance + 0x1cc). Tests the static bools in the order 00975f89
	// (showContactPoints), 8a highlightSleepParts, 8b highlightAwakeParts, 8d showPartCoord, 8c showAnchoredParts,
	// 8e showUnalignedParts, 8f showSpanningTree (render3dAdorn 0059e4d0 reads 8a/8b at 0059e581/0059e633).
	bool PartInstance::shouldRender3dAdorn() const
	{
		return partType == Part::CYLINDER_PART ||
			   SurfacesNeedAdorn ||
			   showContactPoints ||
			   highlightSleepParts ||
			   highlightAwakeParts ||
			   showPartCoord ||
			   showAnchoredParts ||
			   showUnalignedParts ||
			   showSpanningTree;
	}

	// 0059b4f0: Workspace::getWorldIfInWorkspace 005a3390, Array append 0059a190,
	// Dragger::safeMoveNoDrop 00610930 with World contact manager (+0x84 in the 2008 World: native-headers/engine-world,
	// as Humanoid::getContactManager 005d77b0 reads), Vector3::zero 0096f044.
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

	// 0059dd20: setter of prop_Dragging (00975fc8); Primitive::setDragging 005e8050, dragging at Primitive +0xa8 (+0x2d0).
	void PartInstance::setDragging(bool value)
	{
		if (value != primitive.getDragging())
		{
			primitive.setDragging(value);
			raisePropertyChanged(prop_Dragging);
		}
	}

	// 0059dd50: setter of the "RenderImportance" descriptor (initializer 007f48d0); renderImportance +0x224,
	// prop_RenderImportance 0097626c.
	void PartInstance::setRenderImportance(float value)
	{
		if (value != getRenderImportance())
		{
			renderImportance = value;
			raisePropertyChanged(prop_RenderImportance);
		}
	}

	// 0059ddf0: setter of the "Locked" descriptor (initializer 007f47b0); locked +0x1f0, prop_Locked 009760cc.
	void PartInstance::setPartLocked(bool value)
	{
		if (value != getPartLocked())
		{
			locked = value;
			raisePropertyChanged(prop_Locked);
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
	// The identity registry (library-replay) labels this row setAlphaModifier; the descriptor and the +0x1e8 store
	// prove it is setTransparency (transparency +0x1e8, prop_Transparency 00976128). The real setAlphaModifier is the
	// next row 0059dee0 (+0x328, the field onCameraNear 0059e430 writes).
	void PartInstance::setTransparency(float value)
	{
		if (value != transparency)
		{
			transparency = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	// 0059dee0 (registry placeholder func_0059dee0): alphaModifier +0x328, raises prop_Transparency 00976128. Also
	// inlined into onCameraNear 0059e430, render3dAdorn 0059e80d and 0062d241.
	void PartInstance::setAlphaModifier(float value)
	{
		if (value != alphaModifier)
		{
			alphaModifier = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	// 0059e430: ICameraSubject override (this = PartInstance + 0x3fc; vtordisp thunk 0059ec90). Constants
	// 0081e380 = 3.0f, 00826e74 = 6.0f, 00819bac = 0.5f; setAlphaModifier inlined.
	void PartInstance::onCameraNear(float distance)
	{
		if (distance < 3.0f)
			setAlphaModifier(0.0f);
		else if (distance < 6.0f)
			setAlphaModifier(0.5f);
		else
			setAlphaModifier(1.0f);
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

	// 0059df10: setter of the "Reflectance" descriptor (initializer 007f4750); reflectance +0x1ec, prop_Reflectance 0097601c.
	void PartInstance::setReflectance(float value)
	{
		if (value != getReflectance())
		{
			reflectance = value;
			raisePropertyChanged(prop_Reflectance);
		}
	}

	// 0059df70: setter of prop_formFactor (009762ec, initializer 007f4a50); formFactor +0x1e0.
	void PartInstance::setFormFactorXml(FormFactor value)
	{
		if (value != getFormFactor())
		{
			formFactor = value;
			raisePropertyChanged(prop_formFactor);
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

	// 0059e0f0: clamp to [0, 1], Primitive::setElasticity 005e7640 (elasticity Primitive +0xb4), prop_Elasticity 00975f90
	void PartInstance::setElasticity(float elasticity)
	{
		float newElasticity = G3D::clamp(elasticity, 0.0f, 1.0f);
		if (newElasticity != primitive.getElasticity())
		{
			primitive.setElasticity(newElasticity);
			raisePropertyChanged(prop_Elasticity);
		}
	}

	// The out-of-line GeoPair::computePosition 00599250 (GeoPair2008.h inline, emitted here by the showContactPoints
	// loop) compiles byte-identical to the target, but the proof binder rejects it: its jump-table label $LN10 binds
	// to 0064373a instead of the original 005992b1 (a tool label-identity limit, no codegen difference).

	// 0059e4d0: IRenderable override (this = PartInstance + 0x1cc, like shouldRender3dAdorn 00599fa0). Donor rbxgs
	// PartInstance::render3dAdorn with the 2008 callees: getTopPVController 0059a9e0, Controller::controllerTypeToColor
	// 00614f80, getPart 0059aa90, Draw::partAdorn 006770f0 / selectionBox(Color4) 00676e00, Primitive::getAssembly
	// 005e7570 (called twice per sleep block), the 2008 Clump sleep state [[assembly+0x18]] (AssemblyLayout view),
	// Color3 purple 00514940 / orange 005149b0 / yellow 00514980 / red 005148b0 (2008: AWAKE red, SLEEPING_CHECKING
	// orange, the donor has them the other way round; jump tables 0059eb28 / 0059eb3c), renderCoordinateFrame 00608aa0,
	// gray 00514a20, Math::getClosestObjectNormalId 005de560, DrawAdorn::partSurface 00677630, aligned 005994c0,
	// setAlphaModifier(0.3f) inlined (0059e7f0..0059e821, 0082711c), main primitive [[assembly+0x24]+0x1c],
	// Adorn slots +0x38 setObjectToWorldMatrix / +0x40 box / +0x44 sphere, Sphere 00501d10, Vector3::zero 004782a0,
	// Vector3::one 00599190, AABox 00518ed0, Color4::clear 007baf10, green 005148e0, 0.25f 0083a3e4.
	void PartInstance::render3dAdorn(Adorn* adorn)
	{
		if (partType == Part::CYLINDER_PART || SurfacesNeedAdorn)
			Draw::partAdorn(getPart(), adorn, Controller::controllerTypeToColor(getTopPVController()->getControllerType()));

		if (highlightSleepParts && primitive.getAssembly())
		{
			Sim::AssemblyState sleepStatus = (Sim::AssemblyState)AssemblyLayout::getSleepStatus(primitive.getAssembly());

			if (sleepStatus != Sim::ANCHORED && sleepStatus != Sim::AWAKE)
			{
				G3D::Color3 sleepColor;

				switch (sleepStatus)
				{
				case Sim::RECURSIVE_WAKE_PENDING:
				case Sim::WAKE_PENDING:
					sleepColor = G3D::Color3::purple();
					break;
				case Sim::SLEEPING_CHECKING:
					sleepColor = G3D::Color3::orange();
					break;
				case Sim::SLEEPING_DEEPLY:
					sleepColor = G3D::Color3::yellow();
					break;
				default:
					sleepColor = sleepColor;
					break;
				}

				Draw::selectionBox(getPart(), adorn, sleepColor);
			}
		}

		if (highlightAwakeParts && primitive.getAssembly())
		{
			Sim::AssemblyState sleepStatus = (Sim::AssemblyState)AssemblyLayout::getSleepStatus(primitive.getAssembly());

			if (sleepStatus != Sim::ANCHORED && sleepStatus != Sim::SLEEPING_DEEPLY)
			{
				G3D::Color3 wakeColor;

				switch (sleepStatus)
				{
				case Sim::AWAKE:
					wakeColor = G3D::Color3::red();
					break;
				case Sim::SLEEPING_CHECKING:
					wakeColor = G3D::Color3::orange();
					break;
				case Sim::RECURSIVE_WAKE_PENDING:
				case Sim::WAKE_PENDING:
					wakeColor = G3D::Color3::purple();
					break;
				default:
					wakeColor = wakeColor;
					break;
				}

				Draw::selectionBox(getPart(), adorn, wakeColor);
			}
		}

		if (showPartCoord)
			renderCoordinateFrame(adorn);

		if (showAnchoredParts && primitive.getAnchor())
		{
			float transparency = 1.0f - alpha();
			G3D::Color4 color(G3D::Color3::gray(), transparency);
			const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();

			DrawAdorn::partSurface(getPart(), Math::getClosestObjectNormalId(G3D::Vector3(0.0f, -1.0f, 0.0f), cframe.rotation), adorn, color);
		}

		if (showUnalignedParts && !aligned())
			Draw::selectionBox(getPart(), adorn, G3D::Color3::yellow());

		if (showSpanningTree)
		{
			setAlphaModifier(0.3f);

			Assembly* assembly = primitive.getAssembly();
			if (assembly && &primitive == AssemblyLayout::getRootPrimitive(assembly))
			{
				adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(primitive.getCoordinateFrame().translation));

				if (primitive.getAnchor())
				{
					adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), 0.5f), G3D::Color3::green(), G3D::Color4::clear());
				}
				else
				{
					G3D::Vector3 boxSize = G3D::Vector3::one() * 0.25f;
					adorn->box(G3D::AABox(-boxSize, boxSize), G3D::Color3::green(), G3D::Color4::clear());
				}
			}
		}

		// 0059e99e..0059eb0d: per contact (Primitive::getContact 005e7af0, count at Primitive +0x20), per connector
		// (Contact slot 8 numConnectors +0x20, slot 9 getConnector +0x24): GeoPair::computePosition 00599250 on
		// connector +0x8, CoordinateFrame(position) through slot +0x38, then slot +0x44 with an inlined Sphere (vtable
		// 00827404, inlined Vector3::zero static 0096f044 / guard 0096f050, radius 0.5f 00819bac), Color4(Color3::red()
		// 005148b0) and Color4::clear() 007baf10.
		if (showContactPoints)
		{
			for (int i = 0; i < primitive.getNumContacts(); ++i)
			{
				Contact* contact = primitive.getContact(i);
				for (int j = 0; j < contact->numConnectors(); ++j)
				{
					G3D::Vector3 position = contact->getConnector(j)->getGeoPair().computePosition();
					adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(position));
					adorn->sphere(G3D::Sphere(G3D::Vector3::zero(), 0.5f), G3D::Color3::red(), G3D::Color4::clear());
				}
			}
		}
	}
}
