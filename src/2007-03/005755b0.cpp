// from server: 85% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/PartInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PartInstance.h"

#include "appdraw/Draw.h"
#include "appdraw/DrawAdorn.h"
#include "appdraw/HitTest.h"
#include "rbxgraphics/Adorn.h"
#include "tool/Dragger.h"
#include "util/Math.h"
#include "util/standardout.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8kernel/Body.h"
#include "v8world/Assembly2.h"
#include "v8world/Geometry.h"
#include "v8world/MotorJoint.h"
#include "v8world/RigidJoint.h"
#include "v8world/World.h"

#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>
#include <G3D/Ray.h>
#include <G3D/Sphere.h>

namespace RBX {

char sPart[] = "Part";

// GLOBAL: WEBSERVICE 0x102d4568
// GLOBAL: ROBLOX 0x009340f0
const char* category_Part = "Part";

bool PartInstance::highlightSleepParts;
bool PartInstance::highlightAwakeParts;
bool PartInstance::showAnchoredParts;
bool PartInstance::showPartCoord;
bool PartInstance::showUnalignedParts;
bool PartInstance::showSpanningTree;

static const Name& namePart = Name::declare(sPart, 1000);
static const Name& nameCFrame = Name::declare("CFrame", 1001);
static const Name& namePosition = Name::declare("Position", 1002);

const Reflection::PropDescriptor<PartInstance, CoordinateFrame> PartInstance::prop_CFrame(
	"CFrame", "Data", &PartInstance::getCoordinateFrame, &PartInstance::setCoordinateFrame
);

static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_PositionUi(
	"Position",
	"Data",
	&PartInstance::getTranslationUi,
	&PartInstance::setTranslationUi,
	Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_Velocity(
	"Velocity", "Data", &PartInstance::getLinearVelocity, &PartInstance::setLinearVelocity
);

static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_RotVelocity(
	"RotVelocity", "Data", &PartInstance::getRotationalVelocity, &PartInstance::setRotationalVelocity
);

static Reflection::BoundFuncDesc<PartInstance, void(), 0> desc_unjoin(
	&PartInstance::destroyJoints, "BreakJoints", Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<PartInstance, void(), 0> desc_join(
	&PartInstance::join, "MakeJoints", Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<PartInstance, float(), 0> desc_getMass(
	&PartInstance::getMass, "GetMass", Reflection::FunctionDescriptor::AnyCaller
);

const Reflection::EnumPropDescriptor<PartInstance, Part::PartType> PartInstance::prop_shapeXml(
	"shape",
	category_Part,
	&PartInstance::getPartType,
	&PartInstance::setPartTypeXml,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::EnumPropDescriptor<PartInstance, Part::PartType> prop_shapeUi(
	"Shape", category_Part, &PartInstance::getPartType, &PartInstance::setPartTypeUi, Reflection::PropertyDescriptor::UI
);

const Reflection::PropDescriptor<PartInstance, G3D::Color3> PartInstance::prop_Color(
	"Color", "Appearance", &PartInstance::getColor3, &PartInstance::setColor3, Reflection::PropertyDescriptor::LEGACY
);

const Reflection::PropDescriptor<PartInstance, BrickColor> PartInstance::prop_BrickColor(
	"BrickColor", "Appearance", &PartInstance::getColor, &PartInstance::setColor
);

const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Transparency(
	"Transparency", "Appearance", &PartInstance::getTransparencyXml, &PartInstance::setTransparency
);

const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Reflectance(
	"Reflectance", "Appearance", &PartInstance::getReflectance, &PartInstance::setReflectance
);

const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Locked(
	"Locked", "Behavior", &PartInstance::getPartLocked, &PartInstance::setPartLocked
);

const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Anchored(
	"Anchored", "Behavior", &PartInstance::getAnchored, &PartInstance::setAnchored
);

const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_CanCollide(
	"CanCollide", "Behavior", &PartInstance::getCanCollide, &PartInstance::setCanCollide
);

const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_RenderImportance(
	"RenderImportance",
	"Behavior",
	&PartInstance::getRenderImportance,
	&PartInstance::setRenderImportance,
	Reflection::PropertyDescriptor::LEGACY
);

static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_SizeUi(
	"Size",
	category_Part,
	&PartInstance::getPartSizeUi,
	&PartInstance::setPartSizeUi,
	Reflection::PropertyDescriptor::UI
);

const Reflection::PropDescriptor<PartInstance, G3D::Vector3> PartInstance::prop_Size(
	"size",
	category_Part,
	&PartInstance::getPartSizeXml,
	&PartInstance::setPartSizeXml,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::EnumPropDescriptor<PartInstance, PartInstance::FormFactor> prop_FormFactorUi(
	"formFactor",
	category_Part,
	&PartInstance::getFormFactor,
	&PartInstance::setFormFactorUi,
	Reflection::PropertyDescriptor::UI
);

static Reflection::EnumPropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactor(
	"FormFactor",
	category_Part,
	&PartInstance::getFormFactor,
	&PartInstance::setFormFactorXml,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::PropDescriptor<PartInstance, float> prop_Elasticity(
	"Elasticity", category_Part, &PartInstance::getElasticity, &PartInstance::setElasticity
);

static Reflection::PropDescriptor<PartInstance, float> prop_Friction(
	"Friction", category_Part, &PartInstance::getFriction, &PartInstance::setFriction
);

Reflection::SignalDesc<PartInstance, void(shared_ptr<Instance>)> PartInstance::event_Touched("Touched", "part");

static Reflection::PropDescriptor<PartInstance, bool> prop_Dragging(
	"DraggingV1",
	"Behavior",
	&PartInstance::getDragging,
	&PartInstance::setDragging,
	Reflection::PropertyDescriptor::STREAMING
);

// FUNCTION: WEBSERVICE 0x10059c10 FOLDED
// FUNCTION: ROBLOX 0x00564b10 FOLDED
bool PartInstance::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const ModelInstance*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x1009a8d0
// FUNCTION: ROBLOX 0x005ad300
void PartInstance::onChildAdded(Instance* child)
{
	PVInstance::onChildAdded(child);
}

// FUNCTION: ROBLOX 0x005ad310
void PartInstance::writeResizeData(XmlState* state)
{
	state->addProperty(Reflection::Property(prop_Size, this));
}

// FUNCTION: WEBSERVICE 0x1009a8e0 FOLDED
// FUNCTION: ROBLOX 0x005ad340 FOLDED
Surfaces& PartInstance::getSurfaces()
{
	return surfaces;
}

// FUNCTION: WEBSERVICE 0x1009a8e0 FOLDED
// FUNCTION: ROBLOX 0x005ad340 FOLDED
const Surfaces& PartInstance::getSurfaces() const
{
	return surfaces;
}

// FUNCTION: WEBSERVICE 0x1009ae00
// FUNCTION: ROBLOX 0x005ad840
void PartInstance::setName(const std::string& value)
{
	Instance::setName(value);

	if (value == "Torso") {
		getPrimitive()->setSizeMultiplier(5);
	}
	else {
		getPrimitive()->setSizeMultiplier(1);
	}
}

// FUNCTION: ROBLOX 0x005ad880
bool PartInstance::lockedInPlace() const
{
	bool top = false;
	bool bottom = false;
	for (Joint* joint = primitive->getFirstJoint(); joint; joint = primitive->getNextJoint(joint)) {
		if (RigidJoint::isRigidJoint(joint) || MotorJoint::isMotorJoint(joint)) {
			NormalId normalId = primitive.get() == joint->getPrimitive(0)
									? Matrix3ToNormalId(joint->getJointCoord(0).rotation)
									: normalIdOpposite(Matrix3ToNormalId(joint->getJointCoord(1).rotation));
			if (normalId == NORM_Y) {
				top = true;
			}
			else if (normalId == NORM_Y_NEG) {
				bottom = true;
			}
		}
	}
	return top && bottom;
}

// FUNCTION: WEBSERVICE 0x1009ae40
// FUNCTION: ROBLOX 0x005ad950
bool PartInstance::nonNullInWorkspace(shared_ptr<PartInstance> part)
{
	return part.get() != NULL && part->myWorld != NULL;
}

// FUNCTION: WEBSERVICE 0x1009ae90 FOLDED
// FUNCTION: ROBLOX 0x005ae5d0 FOLDED
PartInstance* PartInstance::fromPrimitive(Primitive* p)
{
	if (p != NULL) {
		IMoving* owner = p->getOwner();

		if (owner != NULL) {
			return static_cast<PartInstance*>(owner);
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1009ae90 FOLDED
// FUNCTION: ROBLOX 0x005ae5d0 FOLDED
const PartInstance* PartInstance::fromPrimitiveConst(const Primitive* p)
{
	if (p != NULL) {
		IMoving* owner = p->getOwner();

		if (owner != NULL) {
			return static_cast<const PartInstance*>(owner);
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1009aeb0
// FUNCTION: ROBLOX 0x005ad9a0
void PartInstance::destroyJoints()
{
	if (World* world = Workspace::getWorldIfInWorkspace(this)) {
		world->destroyJoints(getPrimitive());
	}
}

// FUNCTION: WEBSERVICE 0x1009aed0
// FUNCTION: ROBLOX 0x005ad9c0
void PartInstance::join()
{
	if (World* world = Workspace::getWorldIfInWorkspace(this)) {
		world->createJoints(getPrimitive());
	}
}

// FUNCTION: WEBSERVICE 0x1009aef0
// FUNCTION: ROBLOX 0x005ad9e0
bool PartInstance::computeSurfacesNeedAdorn() const
{
	for (int i = 0; i < 6; i++) {
		const Surface& surface = surfaces[(NormalId) i];

		if (surface.getSurfaceType() == ROTATE || surface.getSurfaceType() == ROTATE_P ||
			surface.getSurfaceType() == ROTATE_V) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1009af50
// FUNCTION: ROBLOX 0x005ada40
void PartInstance::legacyTraverseState(const CoordinateFrame& parentState)
{
	CoordinateFrame myState = parentState * *legacyOffset;

	primitive->setGridCorner(myState);
}

// FUNCTION: WEBSERVICE 0x1009af90
// FUNCTION: ROBLOX 0x005ada80
bool PartInstance::isControllable() const
{
	for (int i = 0; i < 6; i++) {
		const Surface& surface = surfaces[(NormalId) i];

		if ((surface.getSurfaceType() == ROTATE_P || surface.getSurfaceType() == ROTATE_V) &&
			surface.isControllable()) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1009aff0
// FUNCTION: ROBLOX 0x005adae0
void PartInstance::onSurfaceChanged(NormalId surfId)
{
	PersistentPart.setDirty();
	IsControllable.setDirty();
	SurfacesNeedAdorn.setDirty();
	shouldRenderSetDirty();
}

// FUNCTION: WEBSERVICE 0x1009b020
// FUNCTION: ROBLOX 0x005adb10
void PartInstance::setPhysics(const CoordinateFrame& cf, const Velocity& vel)
{
	primitive->getBody()->setVelocity(vel);

	if (cf != primitive->getCoordinateFrame()) {
		primitive->setCoordinateFrame(cf);
		PersistentPart.setDirty();
		onExtentsChanged();
	}
}

// FUNCTION: WEBSERVICE 0x1009b080
// FUNCTION: ROBLOX 0x005adb70
const CoordinateFrame& PartInstance::getCoordinateFrame() const
{
	return primitive->getCoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x1009b090
// FUNCTION: ROBLOX 0x005adb80
const Vector3& PartInstance::getTranslationUi() const
{
	return primitive->getBody()->getCoordinateFrame().translation;
}

// FUNCTION: WEBSERVICE 0x1009b0b0
float PartInstance::getMass()
{
	return primitive->getBody()->getMass();
}

// FUNCTION: WEBSERVICE 0x1009b0c0 FOLDED
// FUNCTION: ROBLOX 0x005adbb0 FOLDED
const Velocity& PartInstance::getVelocity() const
{
	return primitive->getBody()->getVelocity();
}

// FUNCTION: WEBSERVICE 0x1009b0c0 FOLDED
// FUNCTION: ROBLOX 0x005adbb0 FOLDED
const Vector3& PartInstance::getLinearVelocity() const
{
	return primitive->getBody()->getVelocity().linear;
}

// FUNCTION: WEBSERVICE 0x1009b0e0
// FUNCTION: ROBLOX 0x005adbd0
const Vector3& PartInstance::getRotationalVelocity() const
{
	return primitive->getBody()->getVelocity().rotational;
}

// FUNCTION: WEBSERVICE 0x1009b100
// FUNCTION: ROBLOX 0x005adbf0
const Vector3& PartInstance::getPartSizeXml() const
{
	return primitive->getGeometry()->getGridSize();
}

// FUNCTION: WEBSERVICE 0x1009b110
// FUNCTION: ROBLOX 0x005adc00
Vector3 PartInstance::getPartSizeUi() const
{
	return primitive->getGeometry()->getGridSize();
}

// FUNCTION: WEBSERVICE 0x1009b140
bool PartInstance::getDragging() const
{
	return primitive->getDragging();
}

// FUNCTION: WEBSERVICE 0x1009b150
// FUNCTION: ROBLOX 0x005adc40
bool PartInstance::getCanCollide() const
{
	if (!primitive->getDragging() && primitive->getCanCollide()) {
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1009b170
// FUNCTION: ROBLOX 0x005adc60
bool PartInstance::getAnchored() const
{
	return primitive->getAnchorObject() != NULL;
}

// FUNCTION: WEBSERVICE 0x1009b190
float PartInstance::getFriction() const
{
	return primitive->getFriction();
}

// FUNCTION: WEBSERVICE 0x1009b1a0
float PartInstance::getElasticity() const
{
	return primitive->getElasticity();
}

// FUNCTION: WEBSERVICE 0x1009b1b0
// FUNCTION: ROBLOX 0x005adca0
Extents PartInstance::getExtentsWorld() const
{
	return primitive->getExtentsWorld();
}

// FUNCTION: WEBSERVICE 0x1009b1d0
// FUNCTION: ROBLOX 0x005adcc0
Extents PartInstance::getExtentsLocal() const
{
	const Vector3 corner = primitive->getGeometry()->getGridSize() * 0.5f;

	return Extents(-corner, corner);
}

// FUNCTION: ROBLOX 0x005add10
Surface* PartInstance::getSurface(const G3D::Ray& worldRay, int& surfaceId)
{
	const CoordinateFrame& cframe = primitive->getCoordinateFrame();
	G3D::Ray localRay = cframe.toObjectSpace(worldRay);
	const Vector3 corner = primitive->getGeometry()->getGridSize() * 0.5f;
	Extents extents(-corner, corner);
	Vector3 location;
	G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
		localRay.origin, localRay.direction, G3D::AABox(extents.min(), extents.max()), location
	);

	for (int i = 0; i < 3; i++) {
		if (location[i] == extents.max()[i]) {
			surfaceId = i;
			return &surfaces[(NormalId) i];
		}
		if (location[i] == extents.min()[i]) {
			surfaceId = i + 3;
			return &surfaces[(NormalId) (i + 3)];
		}
	}
	return NULL;
}

Vector3 PartInstance::xmlToUiSize(const Vector3& size) const
{
	Vector3 uiSize = size;

	switch (formFactor) {
	case BRICK:
		uiSize.y = size.y / 1.2f;
		break;
	case PLATE:
		uiSize.y = size.y / 0.4f;
		break;
	}

	return uiSize;
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x1009b220
// FUNCTION: ROBLOX 0x005ade80
template <>
const Type& Type::singleton<CoordinateFrame>()
{
	static Type type("CoordinateFrame", typeid(CoordinateFrame));

	return type;
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x1009b4c0
// FUNCTION: ROBLOX 0x005ae3b0
CoordinateFrame PartInstance::worldSnapLocation() const
{
	Vector3 halfSize = primitive->getGeometry()->getGridSize() * 0.5f;

	Vector3 snapInPart;
	snapInPart.y = -halfSize.y;
	snapInPart.x = halfSize.x - G3D::iRound(floor(halfSize.x));
	snapInPart.z = halfSize.z - G3D::iRound(floor(halfSize.z));

	CoordinateFrame localSnapLocation(snapInPart);

	return primitive->getCoordinateFrame() * localSnapLocation;
}

// FUNCTION: WEBSERVICE 0x1009b5a0
// FUNCTION: ROBLOX 0x005ae490
bool PartInstance::aligned() const
{
	CoordinateFrame myCoord = worldSnapLocation();

	CoordinateFrame myCoordSnapped = Math::snapToGrid(myCoord, Dragger::dragSnap());

	return Math::fuzzyEq(myCoord, myCoordSnapped, 0.00001f, 0.00001f);
}

// FUNCTION: WEBSERVICE 0x1009b610
// FUNCTION: ROBLOX 0x005ae500
Vector3 PartInstance::uiToXmlSize(const Vector3& uiSize) const
{
	Vector3 gridUiSize = Math::iRoundVector3(uiSize.max(Vector3(1, 1, 1)));

	Vector3 xmlSize = gridUiSize;

	switch (formFactor) {
	case BRICK:
		xmlSize.y *= 1.2f;
		break;
	case PLATE:
		xmlSize.y *= 0.4f;
		break;
	}

	return xmlSize;
}

// FUNCTION: WEBSERVICE 0x1009b6e0
// FUNCTION: ROBLOX 0x005ae5f0
Part PartInstance::computePersistentPart() const
{
	return Part(partType, getPartSizeXml(), G3D::Color4(getColor3(), alpha()), surfaces.surf6(), getCoordinateFrame());
}

// FUNCTION: WEBSERVICE 0x1009b780
// FUNCTION: ROBLOX 0x005ae690
bool PartInstance::shouldRender3dAdorn() const
{
	return partType == Part::CYLINDER_PART || SurfacesNeedAdorn || highlightSleepParts || highlightAwakeParts ||
		   showPartCoord || showAnchoredParts || showUnalignedParts || showSpanningTree;
}

// FUNCTION: WEBSERVICE 0x1009b820
// FUNCTION: ROBLOX 0x005ae730
bool PartInstance::getLocked(Instance* instance)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(instance)) {
		return part->getPartLocked();
	}

	for (unsigned int i = 0; i < instance->numChildren(); i++) {
		if (getLocked(instance->getChild(i))) {
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1009bf50
// FUNCTION: ROBLOX 0x005af070
bool PartInstance::reportTouches() const
{
	return !event_Touched.empty(this);
}

// FUNCTION: WEBSERVICE 0x1009bfa0
// FUNCTION: ROBLOX 0x005af0c0
const Part& PartInstance::getPart() const
{
	Part& part = const_cast<Part&>(PersistentPart.getValueRef());

	part.coordinateFrame = getPrimitive()->getCoordinateFrame();

	return part;
}

// FUNCTION: WEBSERVICE 0x1009bff0
// FUNCTION: ROBLOX 0x005af110
void PartInstance::onAncestorChanged(const AncestorChanged& event)
{
	Instance::onAncestorChanged(event);

	World* world = Workspace::getWorldIfInWorkspace(this);

	if (world != myWorld) {
		if (myWorld != NULL) {
			setMovingManager(NULL);

			myWorld->removePrimitive(getPrimitive());
		}

		myWorld = world;

		if (world != NULL) {
			world->insertPrimitive(getPrimitive());

			setMovingManager(Workspace::getMyWorkspaceFast(this));

			getPrimitive()->setController(getTopPVController());
		}
	}
}

// FUNCTION: WEBSERVICE 0x1009c090
// FUNCTION: ROBLOX 0x005af1b0
void PartInstance::onParentControllerChanged()
{
	PVInstance::onParentControllerChanged();

	PersistentPart.setDirty();

	primitive->setController(getTopPVController());
}

// FUNCTION: WEBSERVICE 0x1009c0c0
// FUNCTION: ROBLOX 0x005af1e0
void PartInstance::render3dSelect(Adorn* adorn, SelectState selectState)
{
	Draw::selectionBox(getPart(), adorn, selectState);
}

// FUNCTION: WEBSERVICE 0x1009c0f0
// FUNCTION: ROBLOX 0x005af210
bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
{
	G3D::Ray rayInPartCoords = getCoordinateFrame().toObjectSpace(worldRay);

	Vector3 hitPointInPartCoords;

	bool hit = HitTest::hitTest(getPart(), rayInPartCoords, hitPointInPartCoords, 1.0f);

	if (hit) {
		worldHitPoint = getCoordinateFrame().pointToWorldSpace(hitPointInPartCoords);
		return true;
	}

	return false;
}

static float readFloat(const XmlElement* element, const Name& tag)
{
	float value;
	element->findFirstChildByTag(tag)->getValue(value);
	return value;
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x1009c1c0
// FUNCTION: ROBLOX 0x005af2e0
template <>
void TypedPropertyDescriptor<CoordinateFrame>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		CoordinateFrame c;
		c.translation.x = readFloat(element, tag_X);
		c.translation.y = readFloat(element, tag_Y);
		c.translation.z = readFloat(element, tag_Z);
		c.rotation[0][0] = readFloat(element, tag_R00);
		c.rotation[0][1] = readFloat(element, tag_R01);
		c.rotation[0][2] = readFloat(element, tag_R02);
		c.rotation[1][0] = readFloat(element, tag_R10);
		c.rotation[1][1] = readFloat(element, tag_R11);
		c.rotation[1][2] = readFloat(element, tag_R12);
		c.rotation[2][0] = readFloat(element, tag_R20);
		c.rotation[2][1] = readFloat(element, tag_R21);
		c.rotation[2][2] = readFloat(element, tag_R22);
		setValue(instance, c);
	}
}

// FUNCTION: WEBSERVICE 0x1009c3c0
// FUNCTION: ROBLOX 0x005af4e0
template <>
void TypedPropertyDescriptor<CoordinateFrame>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	CoordinateFrame c = getValue(instance);
	element->addChild(new XmlElement(tag_X, c.translation.x));
	element->addChild(new XmlElement(tag_Y, c.translation.y));
	element->addChild(new XmlElement(tag_Z, c.translation.z));
	element->addChild(new XmlElement(tag_R00, c.rotation[0][0]));
	element->addChild(new XmlElement(tag_R01, c.rotation[0][1]));
	element->addChild(new XmlElement(tag_R02, c.rotation[0][2]));
	element->addChild(new XmlElement(tag_R10, c.rotation[1][0]));
	element->addChild(new XmlElement(tag_R11, c.rotation[1][1]));
	element->addChild(new XmlElement(tag_R12, c.rotation[1][2]));
	element->addChild(new XmlElement(tag_R20, c.rotation[2][0]));
	element->addChild(new XmlElement(tag_R21, c.rotation[2][1]));
	element->addChild(new XmlElement(tag_R22, c.rotation[2][2]));
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x1009cc10
// FUNCTION: ROBLOX 0x005afb20
void PartInstance::onCanAggregateChanged(bool canAggregate)
{
	Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);

	shouldRenderSetDirty();
}

// FUNCTION: WEBSERVICE 0x1009cc30
// FUNCTION: ROBLOX 0x005afb40
void PartInstance::safeMove()
{
	if (World* world = Workspace::getWorldIfInWorkspace(this)) {
		G3D::Array<Primitive*> temp;

		temp.append(primitive.get());

		Dragger::safeMoveNoDrop(temp, Vector3::zero(), world->getContactManager());
	}
}

// FUNCTION: WEBSERVICE 0x1009ce00
// FUNCTION: ROBLOX 0x005afc20
void PartInstance::primitivesToParts(
	const G3D::Array<Primitive*>& primitives, G3D::Array<shared_ptr<PartInstance> >& parts
)
{
	for (int i = 0; i < primitives.size(); i++) {
		PartInstance* part = fromPrimitive(primitives[i]);
		parts.append(shared_from(part));
	}
}

// FUNCTION: WEBSERVICE 0x1009d150
// FUNCTION: ROBLOX 0x005afd20
PartInstance::~PartInstance()
{
}

// FUNCTION: WEBSERVICE 0x1009d2e0 FOLDED
// FUNCTION: ROBLOX 0x005afeb0 FOLDED
PartInstance* PartInstance::getPrimaryPart()
{
	return this;
}

// FUNCTION: WEBSERVICE 0x1009d2e0 FOLDED
const PartInstance* PartInstance::getPrimaryPartConst() const
{
	return this;
}

// FUNCTION: WEBSERVICE 0x1009d3b0
// FUNCTION: ROBLOX 0x005aff80
const Primitive* PartInstance::getBiggestPrimitive() const
{
	return primitive.get();
}

// FUNCTION: WEBSERVICE 0x1009d3c0
// FUNCTION: ROBLOX 0x005aff90
const CoordinateFrame PartInstance::getLocation() const
{
	return primitive->getCoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x1009d7d0
// FUNCTION: ROBLOX 0x005b02e0
void PartInstance::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
{
	primitives.push_back(getPrimitive());
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x1009daf0
// FUNCTION: ROBLOX 0x005b0600
template <>
EnumDesc<PartInstance::FormFactor>::EnumDesc() : EnumDescriptor("FormFactor", typeid(PartInstance::FormFactor))
{
	addPair(PartInstance::SYMETRIC, "Symmetric");
	addPair(PartInstance::BRICK, "Brick");
	addPair(PartInstance::PLATE, "Plate");

	addLegacyName("Block", PartInstance::BRICK);
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x1009dca0
// FUNCTION: ROBLOX 0x005b07b0
void PartInstance::findParts(Instance* instance, std::vector<boost::weak_ptr<PartInstance> >& parts)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(instance)) {
		parts.push_back(shared_from(part));
	}

	for (unsigned int i = 0; i < instance->numChildren(); i++) {
		findParts(instance->getChild(i), parts);
	}
}

// FUNCTION: WEBSERVICE 0x1009ef30
// FUNCTION: ROBLOX 0x005b19c0
void PartInstance::onGuidChanged()
{
	getPrimitive()->setGuid(getGuid());
}

// FUNCTION: WEBSERVICE 0x1009f220
// FUNCTION: ROBLOX 0x005b1cb0
PartInstance::PartInstance()
	: DescribedCreatable<PartInstance, PVInstance, sPart>("Part"), partType(Part::BLOCK_PART), formFactor(BRICK),
	  transparency(0.0f), reflectance(0.0f), locked(false), surfaces(this), renderImportance(0.0f),
	  primitive(new Primitive(Geometry::GEOMETRY_BLOCK)), myWorld(NULL), alphaModifier(1.0f),
	  PersistentPart(this, &PartInstance::computePersistentPart),
	  SurfacesNeedAdorn(this, &PartInstance::computeSurfacesNeedAdorn)
{
	primitive->setSurfaceType(NORM_Y, STUDS);
	primitive->setSurfaceType(NORM_Y_NEG, INLET);
	primitive->setGridSize(Vector3(4.0f, 1.2f, 2.0f));
	primitive->setFriction(0.3f);
	primitive->setElasticity(0.5f);
	primitive->setAnchor(false);
	primitive->setCanCollide(true);
	primitive->setOwner(this);

	primitive->setGuid(getGuid());
}

// FUNCTION: WEBSERVICE 0x1009f560
// FUNCTION: ROBLOX 0x005b1ff0
void PartInstance::onTouchThisStep(shared_ptr<PartInstance> other)
{
	event_Touched.fire(this, other);
}

// FUNCTION: WEBSERVICE 0x1009f610
// FUNCTION: ROBLOX 0x005b20a0
void PartInstance::setCoordinateFrame(const CoordinateFrame& value)
{
	if (value != primitive->getCoordinateFrame()) {
		CoordinateFrame orthoValue = value;
		Math::orthonormalizeIfNecessary(orthoValue.rotation);

		if (orthoValue != primitive->getCoordinateFrame()) {
			primitive->setCoordinateFrame(orthoValue);
			PersistentPart.setDirty();
			onExtentsChanged();
		}

		raisePropertyChanged(prop_CFrame);
		raisePropertyChanged(prop_PositionUi);
	}
}

// FUNCTION: WEBSERVICE 0x1009f6c0
// FUNCTION: ROBLOX 0x005b2150
void PartInstance::setTranslationUi(const Vector3& set)
{
	CoordinateFrame current = getCoordinateFrame();

	if (current.translation != set) {
		current.translation = set;
		destroyJoints();
		setCoordinateFrame(current);
		safeMove();
		join();
	}
}

// FUNCTION: WEBSERVICE 0x1009f790
// FUNCTION: ROBLOX 0x005b2220
void PartInstance::setLinearVelocity(const Vector3& set)
{
	Velocity vel = getVelocity();

	if (vel.linear != set) {
		vel.linear = set;
		primitive->getBody()->setVelocity(vel);
		raisePropertyChanged(prop_Velocity);
	}
}

// FUNCTION: WEBSERVICE 0x1009f850
// FUNCTION: ROBLOX 0x005b22e0
void PartInstance::setRotationalVelocity(const Vector3& set)
{
	Velocity vel = getVelocity();

	if (vel.rotational != set) {
		vel.rotational = set;
		primitive->getBody()->setVelocity(vel);
		raisePropertyChanged(prop_RotVelocity);
	}
}

// FUNCTION: WEBSERVICE 0x1009f910
// FUNCTION: ROBLOX 0x005b23a0
void PartInstance::setPartSizeXml(const Vector3& rbxSize)
{
	if (rbxSize != getPartSizeXml()) {
		Vector3 newRbxSize = partType == Part::BLOCK_PART ? rbxSize : rbxSize.xxx();

		if (legacyOffset) {
			CoordinateFrame oldCorner = primitive->getGridCorner();

			primitive->setGridSize(newRbxSize);
			primitive->setGridCorner(oldCorner);
		}
		else {
			primitive->setGridSize(newRbxSize);
		}

		raisePropertyChanged(prop_Size);
		raisePropertyChanged(prop_SizeUi);

		PersistentPart.setDirty();

		onExtentsChanged();
	}
}

// FUNCTION: WEBSERVICE 0x1009f9f0
// FUNCTION: ROBLOX 0x005b2480
void PartInstance::setPartSizeUi(const Vector3& uiSize)
{
	World* world = Workspace::getWorldIfInWorkspace(this);

	if (world != NULL) {
		world->destroyJoints(primitive.get());
	}

	setPartSizeXml(uiToXmlSize(xmlToUiSize(uiSize)));

	safeMove();

	world = Workspace::getWorldIfInWorkspace(this);

	if (world != NULL) {
		world->createJoints(primitive.get());
	}
}

// FUNCTION: WEBSERVICE 0x1009faa0
// FUNCTION: ROBLOX 0x005b2530
void PartInstance::setDragging(bool value)
{
	if (value != primitive->getDragging()) {
		primitive->setDragging(value);
		raisePropertyChanged(prop_Dragging);
	}
}

// FUNCTION: WEBSERVICE 0x1009fad0
// FUNCTION: ROBLOX 0x005b2560
void PartInstance::setRenderImportance(float value)
{
	if (value != renderImportance) {
		renderImportance = value;
		raisePropertyChanged(prop_RenderImportance);
	}
}

// FUNCTION: WEBSERVICE 0x1009fb00
// FUNCTION: ROBLOX 0x005b2590
void PartInstance::setCanCollide(bool value)
{
	if (value != getCanCollide()) {
		primitive->setCanCollide(value);
		raisePropertyChanged(prop_CanCollide);
	}
}

// FUNCTION: WEBSERVICE 0x1009fb40
// FUNCTION: ROBLOX 0x005b25d0
void PartInstance::setAnchored(bool value)
{
	if (value != getAnchored()) {
		primitive->setAnchor(value);
		raisePropertyChanged(prop_Anchored);
	}
}

// FUNCTION: WEBSERVICE 0x1009fb80
// FUNCTION: ROBLOX 0x005b2610
void PartInstance::setPartLocked(bool value)
{
	if (value != locked) {
		locked = value;
		raisePropertyChanged(prop_Locked);
	}
}

// FUNCTION: ROBLOX 0x005b2640
void PartInstance::setLocked(Instance* instance, bool value)
{
	if (PartInstance* part = dynamic_cast<PartInstance*>(instance)) {
		part->setPartLocked(value);
	}
	else {
		for (unsigned int i = 0; i < instance->numChildren(); i++) {
			setLocked(instance->getChild(i), value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1009fbb0
// FUNCTION: ROBLOX 0x005b26e0
void PartInstance::setTransparency(float value)
{
	if (value != transparency) {
		transparency = value;
		raisePropertyChanged(prop_Transparency);
	}
}

// FUNCTION: WEBSERVICE 0x1009fbe0
// FUNCTION: ROBLOX 0x005b2710
void PartInstance::setAlphaModifier(float value)
{
	if (value != alphaModifier) {
		alphaModifier = value;
		raisePropertyChanged(prop_Transparency);
	}
}

// FUNCTION: WEBSERVICE 0x1009fc10
// FUNCTION: ROBLOX 0x005b2740
void PartInstance::setReflectance(float value)
{
	if (value != reflectance) {
		reflectance = value;
		raisePropertyChanged(prop_Reflectance);
	}
}

// FUNCTION: WEBSERVICE 0x1009fc40
// FUNCTION: ROBLOX 0x005b2770
void PartInstance::setColor(BrickColor value)
{
	if (value.number != color.number) {
		color = value;
		raisePropertyChanged(prop_BrickColor);
		raisePropertyChanged(prop_Color);
	}
}

// FUNCTION: WEBSERVICE 0x1009fc70
// FUNCTION: ROBLOX 0x005b27a0
void PartInstance::setFormFactorXml(FormFactor value)
{
	if (value != formFactor) {
		formFactor = value;
		raisePropertyChanged(prop_formFactor);
	}
}

// FUNCTION: WEBSERVICE 0x1009fca0
// FUNCTION: ROBLOX 0x005b27d0
void PartInstance::setFormFactorUi(FormFactor value)
{
	if (partType != Part::BLOCK_PART) {
		value = SYMETRIC;
	}

	if (value != formFactor) {
		destroyJoints();
		setFormFactorXml(value);

		Vector3 uiSize = getPartSizeUi();

		uiSize.y = std::max(1.0f, (float) G3D::iRound(uiSize.y));

		setPartSizeUnjoined(uiSize);
		join();
	}
}

// FUNCTION: WEBSERVICE 0x1009fda0
// FUNCTION: ROBLOX 0x005b28d0
void PartInstance::setFriction(float friction)
{
	friction = G3D::clamp(friction, 0.0f, 2.0f);

	if (friction != primitive->getFriction()) {
		primitive->setFriction(friction);
		raisePropertyChanged(prop_Friction);
	}
}

// FUNCTION: WEBSERVICE 0x1009fe00
// FUNCTION: ROBLOX 0x005b2930
void PartInstance::setElasticity(float elasticity)
{
	elasticity = G3D::clamp(elasticity, 0.0f, 1.0f);

	if (elasticity != primitive->getElasticity()) {
		primitive->setElasticity(elasticity);
		raisePropertyChanged(prop_Elasticity);
	}
}

// STUB: ROBLOX 0x005b2990
bool PartInstance::resize(NormalId p_unk0x04, int p_unk0x08)
{
	if (p_unk0x08 != 0) {
		Vector3 oldSizeXml = getPartSizeXml();
		CoordinateFrame oldCoord = getCoordinateFrame();
		Vector3 deltaSizeUi;
		float posNeg = p_unk0x04 < 3 ? 1.0f : -1.0f;

		if (partType == Part::BLOCK_PART) {
			deltaSizeUi[p_unk0x04 % 3] = (float) p_unk0x08;
		}
		else {
			deltaSizeUi = Vector3((float) p_unk0x08, (float) p_unk0x08, (float) p_unk0x08);
		}

		Vector3 newSizeUi = xmlToUiSize(oldSizeXml) + deltaSizeUi;
		Vector3 newSizeXml = uiToXmlSize(newSizeUi);
		Vector3 deltaSizeXml = newSizeXml - oldSizeXml;
		Vector3 offset = oldCoord.rotation * deltaSizeXml;
		Vector3 newTranslation = offset * 0.5f * posNeg + oldCoord.translation;
		CoordinateFrame newCoord(oldCoord.rotation, newTranslation);

		setCoordinateFrame(newCoord);
		Vector3 sizeXml = uiToXmlSize(newSizeUi);
		setPartSizeXml(sizeXml);
		safeMove();

		if (Math::fuzzyEq(getCoordinateFrame(), newCoord, 0.00001f, 0.00001f)) {
			return true;
		}

		setCoordinateFrame(oldCoord);
		setPartSizeXml(oldSizeXml);
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1009fe60
// FUNCTION: ROBLOX 0x005b2be0
void PartInstance::setColor3(const G3D::Color3& value)
{
	setColor(BrickColor::closest(value));
}

// FUNCTION: WEBSERVICE 0x1009fec0
// FUNCTION: ROBLOX 0x005b2c40
void PartInstance::onCameraNear(float distance)
{
	if (distance < 3.0f) {
		setAlphaModifier(0.0f);
	}
	else if (distance < 6.0f) {
		setAlphaModifier(0.5f);
	}
	else {
		setAlphaModifier(1.0f);
	}
}

// STUB: WEBSERVICE 0x1009ff60
// STUB: ROBLOX 0x005b2ce0
void PartInstance::render3dAdorn(Adorn* adorn)
{
	if (partType == Part::CYLINDER_PART || SurfacesNeedAdorn) {
		Draw::partAdorn(getPart(), adorn, Controller::controllerTypeToColor(getTopPVController()->getControllerType()));
	}

	if (highlightSleepParts && primitive->getAssembly()) {
		Sim::AssemblyState status = primitive->getAssembly()->getRootAssemblyConst()->getSleepStatus();

		if (status != Sim::ANCHORED && status != Sim::AWAKE) {
			Color3 sleepColor;

			switch (status) {
			case Sim::RECURSIVE_WAKE_PENDING:
			case Sim::WAKE_PENDING:
				sleepColor = Color3::purple();
				break;
			case Sim::SLEEPING_CHECKING:
				sleepColor = Color3::orange();
				break;
			case Sim::SLEEPING_DEEPLY:
				sleepColor = Color3::yellow();
				break;
			}

			Draw::selectionBox(getPart(), adorn, sleepColor);
		}
	}

	if (highlightAwakeParts && primitive->getAssembly()) {
		Sim::AssemblyState status = primitive->getAssembly()->getRootAssemblyConst()->getSleepStatus();

		if (status != Sim::ANCHORED && status != Sim::SLEEPING_DEEPLY) {
			Color3 wakeColor;

			switch (status) {
			case Sim::AWAKE:
				wakeColor = Color3::red();
				break;
			case Sim::SLEEPING_CHECKING:
				wakeColor = Color3::orange();
				break;
			case Sim::RECURSIVE_WAKE_PENDING:
			case Sim::WAKE_PENDING:
				wakeColor = Color3::purple();
				break;
			}

			Draw::selectionBox(getPart(), adorn, wakeColor);
		}
	}

	if (showPartCoord) {
		renderCoordinateFrame(adorn);
	}

	if (showAnchoredParts && primitive->getAnchorObject()) {
		DrawAdorn::partSurface(
			getPart(),
			Math::getClosestObjectNormalId(Vector3(0.0f, -1.0f, 0.0f), primitive->getCoordinateFrame().rotation),
			adorn,
			G3D::Color4(Color3::gray(), alpha())
		);
	}

	if (showUnalignedParts && !aligned()) {
		Draw::selectionBox(getPart(), adorn, Color3::yellow());
	}

	if (showSpanningTree) {
		setAlphaModifier(0.3f);

		if (Assembly* assembly = primitive->getAssembly()) {
			if (primitive.get() == assembly->getAssemblyPrimitiveConst()) {
				adorn->setObjectToWorldMatrix(
					CoordinateFrame(Matrix3::identity(), primitive->getCoordinateFrame().translation)
				);
				if (primitive->getAnchorObject()) {
					adorn->sphere(G3D::Sphere(Vector3::zero(), 0.5f), Color3::green(), G3D::Color4::clear());
				}
				else {
					Vector3 boxSize = Vector3::one() * 0.25f;
					adorn->box(G3D::AABox(-boxSize, boxSize), Color3::green(), G3D::Color4::clear());
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a0450
// FUNCTION: ROBLOX 0x005b31d0
void PartInstance::setPartTypeXml(Part::PartType _type)
{
	if (partType != _type) {
		partType = _type;
		primitive->setPrimitiveType(partType == Part::BLOCK_PART ? Geometry::GEOMETRY_BLOCK : Geometry::GEOMETRY_BALL);

		if (partType != Part::BLOCK_PART) {
			if (formFactor != SYMETRIC) {
				formFactor = SYMETRIC;

				raisePropertyChanged(prop_formFactor);
			}
		}

		raisePropertyChanged(prop_shapeXml);
		raisePropertyChanged(prop_shapeUi);

		PersistentPart.setDirty();
		shouldRenderSetDirty();

		onExtentsChanged();
	}
}

// FUNCTION: WEBSERVICE 0x100a04e0
// FUNCTION: ROBLOX 0x005b3260
void PartInstance::setPartTypeUi(Part::PartType _type)
{
	if (partType != _type) {
		World* world = Workspace::getWorldIfInWorkspace(this);

		if (world != NULL) {
			world->destroyJoints(primitive.get());
		}

		setPartTypeXml(_type);

		if (_type != Part::BLOCK_PART) {
			Vector3 xmlSize = uiToXmlSize(getPartSizeUi());

			setPartSizeXml(xmlSize);
			safeMove();
		}

		safeMove();

		world = Workspace::getWorldIfInWorkspace(this);

		if (world != NULL) {
			world->createJoints(primitive.get());
		}
	}
}

} // namespace RBX
