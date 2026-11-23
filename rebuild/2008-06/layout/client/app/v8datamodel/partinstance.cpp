// =============================================================================
// partinstance.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/partinstance.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#undef _RELEASEASSERT
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

	const Reflection::PropDescriptor<PartInstance, G3D::Color3> PartInstance::prop_Color(
		"Color", "Appearance", &PartInstance::getColor3, &PartInstance::setColor3, Reflection::PropertyDescriptor::LEGACY);
	const Reflection::PropDescriptor<PartInstance, BrickColor> PartInstance::prop_BrickColor(
		"BrickColor", "Appearance", &PartInstance::getColor, &PartInstance::setColor, Reflection::PropertyDescriptor::STANDARD);
	const char* category_Part = "Part";
	static Reflection::EnumPropDescriptor<PartInstance, Part::PartType> prop_shapeUi(
		"Shape", category_Part, &PartInstance::getPartType, &PartInstance::setPartTypeUi, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_SizeUi(
		"Size", category_Part, &PartInstance::getPartSizeUi, &PartInstance::setPartSizeUi, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<PartInstance, float> prop_Friction(
		"Friction", category_Part, &PartInstance::getFriction, &PartInstance::setFriction, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactorUi(
		"formFactor", category_Part, &PartInstance::getFormFactor, &PartInstance::setFormFactorUi, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactor(
		"FormFactor", category_Part, &PartInstance::getFormFactor, &PartInstance::setFormFactorXml, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<PartInstance, float> prop_Elasticity(
		"Elasticity", category_Part, &PartInstance::getElasticity, &PartInstance::setElasticity, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::PropDescriptor<PartInstance, bool> prop_Dragging(
		"DraggingV1", "Behavior", &PartInstance::getDragging, &PartInstance::setDragging, Reflection::PropertyDescriptor::STREAMING);

	bool PartInstance::getCanCollide() const
	{
		return !primitive.getDragging() && !primitive.getCanSleep();
	}

	void PartInstance::setCanCollide(bool value)
	{
		value = !value;
		if (value != primitive.getCanSleep())
		{
			primitive.setCanSleep(value);
			raisePropertyChanged(prop_CanCollide);
		}
	}

	Extents PartInstance::getExtentsWorld() const
	{
		return primitive.getExtentsWorld();
	}

	Extents PartInstance::getExtentsLocal() const
	{
		return primitive.getExtentsLocal();
	}

	bool PartInstance::showContactPoints = false;

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

	void PartInstance::safeMove()
	{
		if (World* world = Workspace::getWorldIfInWorkspace(this))
		{
			G3D::Array<Primitive*> temp;
			temp.append(&primitive);
			Dragger::safeMoveNoDrop(temp, G3D::Vector3::zero(), world->getContactManager());
		}
	}

	void PartInstance::findParts(Instance* instance, std::vector<boost::weak_ptr<RBX::PartInstance>>& parts)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
			parts.push_back(shared_from(part));

		for (size_t i = 0; i < instance->numChildren(); i++)
		{
			findParts(instance->getChild(i), parts);
		}
	}

	void PartInstance::onGuidChanged()
	{
		registerGuid();
		primitive.setGuid(guid);
	}

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

	// setPartSizeXml 0059db90, safeMove 0059b4f0. INFERRED: destroyJoints 00598c70 / join 00598c90 (AppUnit598PartInstance.cpp)
	void PartInstance::setPartSizeUi(const G3D::Vector3& uiSize)
	{
		if (World* world = Workspace::getWorldIfInWorkspace(this))
			world->destroyJoints(&primitive);

		G3D::Vector3 adjustedUiSize = uiSize;

		switch (formFactor)
		{
		case BRICK:
			adjustedUiSize.y = uiSize.y * 5.0f/6.0f;
			break;
		case PLATE:
			adjustedUiSize.y = uiSize.y * 2.5f;
			break;
		}

		setPartSizeXml(uiToXmlSize(adjustedUiSize));
		safeMove();

		if (World* world = Workspace::getWorldIfInWorkspace(this))
			world->createJoints(&primitive);
	}

	void PartInstance::setDragging(bool value)
	{
		if (value != primitive.getDragging())
		{
			primitive.setDragging(value);
			raisePropertyChanged(prop_Dragging);
		}
	}

	void PartInstance::setRenderImportance(float value)
	{
		if (value != getRenderImportance())
		{
			renderImportance = value;
			raisePropertyChanged(prop_RenderImportance);
		}
	}

	void PartInstance::setPartLocked(bool value)
	{
		if (value != getPartLocked())
		{
			locked = value;
			raisePropertyChanged(prop_Locked);
		}
	}

	void PartInstance::setAnchored(bool value)
	{
		if (value != primitive.getAnchor())
		{
			primitive.setAnchor(value);
			raisePropertyChanged(prop_Anchored);
		}
	}

	void PartInstance::setTransparency(float value)
	{
		if (value != transparency)
		{
			transparency = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	void PartInstance::setAlphaModifier(float value)
	{
		if (value != alphaModifier)
		{
			alphaModifier = value;
			raisePropertyChanged(prop_Transparency);
		}
	}

	void PartInstance::onCameraNear(float distance)
	{
		if (distance < 3.0f)
			setAlphaModifier(0.0f);
		else if (distance < 6.0f)
			setAlphaModifier(0.5f);
		else
			setAlphaModifier(1.0f);
	}

	void PartInstance::setColor(BrickColor value)
	{
		if (value != color)
		{
			color = value;
			raisePropertyChanged(prop_BrickColor);
			raisePropertyChanged(prop_Color);
		}
	}

	void PartInstance::setReflectance(float value)
	{
		if (value != getReflectance())
		{
			reflectance = value;
			raisePropertyChanged(prop_Reflectance);
		}
	}

	void PartInstance::setFormFactorXml(FormFactor value)
	{
		if (value != getFormFactor())
		{
			formFactor = value;
			raisePropertyChanged(prop_formFactor);
		}
	}

	// 00599eb0, setPartSizeXml 0059db90, safeMove 0059b4f0. INFERRED: destroyJoints / join expanded inline (see above).
	void PartInstance::setFormFactorUi(FormFactor value)
	{
		if (partType != Part::BLOCK_PART)
			value = SYMETRIC;

		if (value != getFormFactor())
		{
			if (World* world = Workspace::getWorldIfInWorkspace(this))
				world->destroyJoints(&primitive);

			setFormFactorXml(value);

			G3D::Vector3 uiSize = primitive.getGeometry()->getGridSize();
			uiSize.y = G3D::max<float>(1.0, G3D::iRound(uiSize.y));

			G3D::Vector3 xmlSize = uiToXmlSize(uiSize);
			setPartSizeXml(xmlSize);
			safeMove();

			if (World* world = Workspace::getWorldIfInWorkspace(this))
				world->createJoints(&primitive);
		}
	}

	void PartInstance::setFriction(float friction)
	{
		float newFriction = G3D::clamp(friction, 0.0f, 2.0f);
		if (newFriction != primitive.getFriction())
		{
			primitive.setFriction(newFriction);
			raisePropertyChanged(prop_Friction);
		}
	}

	void PartInstance::setElasticity(float elasticity)
	{
		float newElasticity = G3D::clamp(elasticity, 0.0f, 1.0f);
		if (newElasticity != primitive.getElasticity())
		{
			primitive.setElasticity(newElasticity);
			raisePropertyChanged(prop_Elasticity);
		}
	}

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

			DrawAdorn::partSurface(
				getPart(),
				Math::getClosestObjectNormalId(G3D::Vector3(0.0f, -1.0f, 0.0f), cframe.rotation),
				adorn,
				color);
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

	void PartInstance::setPartTypeXml(Part::PartType _type)
	{
		if (getPartType() != _type)
		{
			partType = _type;
			primitive.setPrimitiveType(_type == Part::BLOCK_PART ? Geometry::GEOMETRY_BLOCK : Geometry::GEOMETRY_BALL);

			if (partType != Part::BLOCK_PART)
				setFormFactorXml(SYMETRIC);

			raisePropertyChanged(prop_shapeXml);
			raisePropertyChanged(prop_shapeUi);

			PersistentPart.setDirty();
			shouldRenderSetDirty();
			onExtentsChanged();
		}
	}

	// safeMove again. INFERRED: destroyJoints / join expanded inline (see setPartSizeUi).
	void PartInstance::setPartTypeUi(Part::PartType _type)
	{
		if (getPartType() != _type)
		{
			if (World* world = Workspace::getWorldIfInWorkspace(this))
				world->destroyJoints(&primitive);

			setPartTypeXml(_type);

			if (_type != Part::BLOCK_PART)
			{
				G3D::Vector3 uiSize = primitive.getGeometry()->getGridSize();
				G3D::Vector3 xmlSize = uiToXmlSize(uiSize);
				setPartSizeXml(xmlSize);
				safeMove();
			}

			safeMove();

			if (World* world = Workspace::getWorldIfInWorkspace(this))
				world->createJoints(&primitive);
		}
	}

	Reflection::EnumDesc<PartInstance::FormFactor>::EnumDesc()
		: EnumDescriptor("FormFactor", typeid(PartInstance::FormFactor))
	{
		addPair(PartInstance::SYMETRIC, "Symmetric");
		addPair(PartInstance::BRICK, "Brick");
		addPair(PartInstance::PLATE, "Plate");
		addLegacyName("Block", PartInstance::BRICK);
	}
}

template class RBX::Reflection::EnumDesc<enum RBX::PartInstance::FormFactor>;

#define NATIVE_PRIMITIVE_NATIVE_BODY

namespace RBX
{
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_PositionUi(
	"Position", "Data", &PartInstance::getTranslationUi, &PartInstance::setTranslationUi,
	Reflection::PropertyDescriptor::UI);
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_Velocity(
	"Velocity", "Data", &PartInstance::getLinearVelocity, &PartInstance::setLinearVelocity,
	Reflection::PropertyDescriptor::STANDARD);
static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_RotVelocity(
	"RotVelocity", "Data", &PartInstance::getRotationalVelocity, &PartInstance::setRotationalVelocity,
	Reflection::PropertyDescriptor::STANDARD);

void PartInstance::setCoordinateFrame(const G3D::CoordinateFrame& value)
{
	Primitive* storage = &primitive;
	const G3D::CoordinateFrame& current = storage->getCoordinateFrame();
	const G3D::CoordinateFrame* source = &value;
	if (*source != current) {
		G3D::CoordinateFrame newValue = *source;
		Math::orthonormalizeIfNecessary(newValue.rotation);
		if (newValue != storage->getCoordinateFrame()) {
			storage->setCoordinateFrame(newValue);
			PersistentPart.setDirty();
			onExtentsChanged();
		}
		raisePropertyChanged(prop_CFrame);
		raisePropertyChanged(prop_PositionUi);
	}
}
void PartInstance::setTranslationUi(const G3D::Vector3& value)
{
	G3D::CoordinateFrame current = primitive.getCoordinateFrame();
	if (current.translation != value) {
		current.translation = value;
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world) world->destroyJoints(&primitive);
		setCoordinateFrame(current);
		safeMove();
		world = Workspace::getWorldIfInWorkspace(this);
		if (world) world->createJoints(&primitive);
	}
}
void PartInstance::setLinearVelocity(const G3D::Vector3& set)
{
	Velocity vel = primitive.getBody()->getVelocity();
	if (vel.linear != set) {
		vel.linear = set;
		primitive.getBody()->setVelocity(vel);
		raisePropertyChanged(prop_Velocity);
	}
}
void PartInstance::setRotationalVelocity(const G3D::Vector3& set)
{
	Velocity vel = primitive.getBody()->getVelocity();
	if (vel.rotational != set) {
		vel.rotational = set;
		primitive.getBody()->setVelocity(vel);
		raisePropertyChanged(prop_RotVelocity);
	}
}
}

#include "reflection/property.h"
#include "G3D/CoordinateFrame.h"
#include "v8xml/XmlElement.h"

// INFERRED: 0059aeb0 builds each child in place (tag at +0x10, FLOAT 7 at +0x14, float at +0x18) with no call and no
inline XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, float value)
	: tag(tag),
	  valueType(FLOAT),
	  floatValue(value)
{
}

namespace RBX
{
namespace Reflection
{

template<>
void TypedPropertyDescriptor<G3D::CoordinateFrame>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		G3D::CoordinateFrame frame;
		float value;
		element->findFirstChildByTag(tag_X)->getValue(value);
		frame.translation.x = value;
		element->findFirstChildByTag(tag_Y)->getValue(value);
		frame.translation.y = value;
		element->findFirstChildByTag(tag_Z)->getValue(value);
		frame.translation.z = value;
		element->findFirstChildByTag(tag_R00)->getValue(value);
		frame.rotation[0][0] = value;
		element->findFirstChildByTag(tag_R01)->getValue(value);
		frame.rotation[0][1] = value;
		element->findFirstChildByTag(tag_R02)->getValue(value);
		frame.rotation[0][2] = value;
		element->findFirstChildByTag(tag_R10)->getValue(value);
		frame.rotation[1][0] = value;
		element->findFirstChildByTag(tag_R11)->getValue(value);
		frame.rotation[1][1] = value;
		element->findFirstChildByTag(tag_R12)->getValue(value);
		frame.rotation[1][2] = value;
		element->findFirstChildByTag(tag_R20)->getValue(value);
		frame.rotation[2][0] = value;
		element->findFirstChildByTag(tag_R21)->getValue(value);
		frame.rotation[2][1] = value;
		element->findFirstChildByTag(tag_R22)->getValue(value);
		frame.rotation[2][2] = value;
		getset->setValue(instance, frame);
	}
}

template<>
void TypedPropertyDescriptor<G3D::CoordinateFrame>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	G3D::CoordinateFrame frame = getValue(instance);
	element->addChild(new XmlElement(tag_X, frame.translation.x));
	element->addChild(new XmlElement(tag_Y, frame.translation.y));
	element->addChild(new XmlElement(tag_Z, frame.translation.z));
	element->addChild(new XmlElement(tag_R00, frame.rotation[0][0]));
	element->addChild(new XmlElement(tag_R01, frame.rotation[0][1]));
	element->addChild(new XmlElement(tag_R02, frame.rotation[0][2]));
	element->addChild(new XmlElement(tag_R10, frame.rotation[1][0]));
	element->addChild(new XmlElement(tag_R11, frame.rotation[1][1]));
	element->addChild(new XmlElement(tag_R12, frame.rotation[1][2]));
	element->addChild(new XmlElement(tag_R20, frame.rotation[2][0]));
	element->addChild(new XmlElement(tag_R21, frame.rotation[2][1]));
	element->addChild(new XmlElement(tag_R22, frame.rotation[2][2]));
}

}
}
