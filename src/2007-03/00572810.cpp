// from server: 96% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/PartInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PartInstance.h"

#include "tool/Dragger.h"
#include "util/standardout.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8kernel/Body.h"
#include "v8world/Geometry.h"
#include "v8world/World.h"

namespace RBX {

// GLOBAL: WEBSERVICE 0x102d4568
const char* const category_Part = "Part";

char sPart[] = "Part";

bool PartInstance::highlightSleepParts;
bool PartInstance::highlightAwakeParts;
bool PartInstance::showAnchoredParts;
bool PartInstance::showPartCoord;
bool PartInstance::showUnalignedParts;
bool PartInstance::showSpanningTree;

const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_RenderImportance(
	"RenderImportance",
	"Behavior",
	&RBX::PartInstance::getRenderImportance,
	&RBX::PartInstance::setRenderImportance,
	Reflection::PropertyDescriptor::LEGACY
);

const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Transparency(
	"Transparency",
	"Appearance",
	&RBX::PartInstance::getTransparencyXml,
	&RBX::PartInstance::setTransparency
);

const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Reflectance(
	"Reflectance",
	"Appearance",
	&RBX::PartInstance::getReflectance,
	&RBX::PartInstance::setReflectance
);

const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Locked(
	"Locked",
	"Behavior",
	&RBX::PartInstance::getPartLocked,
	&RBX::PartInstance::setPartLocked
);

const Reflection::PropDescriptor<PartInstance, G3D::Color3> PartInstance::prop_Color(
	"Color",
	"Appearance",
	&RBX::PartInstance::getColor3,
	&RBX::PartInstance::setColor3
);

const Reflection::PropDescriptor<PartInstance, BrickColor> PartInstance::prop_BrickColor(
	"BrickColor",
	"Appearance",
	&RBX::PartInstance::getColor,
	&RBX::PartInstance::setColor
);

const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_CanCollide(
	"CanCollide",
	"Behavior",
	&RBX::PartInstance::getCanCollide,
	&RBX::PartInstance::setCanCollide
);

const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Anchored(
	"Anchored",
	"Behavior",
	&RBX::PartInstance::getAnchored,
	&RBX::PartInstance::setAnchored
);

const Reflection::EnumPropDescriptor<PartInstance, Part::PartType> PartInstance::prop_shapeXml(
	"shape",
	category_Part,
	&RBX::PartInstance::getPartType,
	&RBX::PartInstance::setPartTypeXml,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::EnumPropDescriptor<PartInstance, Part::PartType> prop_shapeUi(
	"Shape",
	category_Part,
	&RBX::PartInstance::getPartType,
	&RBX::PartInstance::setPartTypeUi,
	Reflection::PropertyDescriptor::UI
);

static Reflection::PropDescriptor<PartInstance, G3D::Vector3> prop_SizeUi(
	"Size",
	category_Part,
	&RBX::PartInstance::getPartSizeUi,
	&RBX::PartInstance::setPartSizeUi,
	Reflection::PropertyDescriptor::UI
);

const Reflection::PropDescriptor<PartInstance, G3D::Vector3> PartInstance::prop_Size(
	"size",
	category_Part,
	&RBX::PartInstance::getPartSizeXml,
	&RBX::PartInstance::setPartSizeXml,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::EnumPropDescriptor<PartInstance, PartInstance::FormFactor> prop_formFactor(
	"FormFactor",
	category_Part,
	&RBX::PartInstance::getFormFactor,
	&RBX::PartInstance::setFormFactorXml,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::PropDescriptor<PartInstance, bool> prop_Dragging(
	"DraggingV1",
	"Behavior",
	&RBX::PartInstance::getDragging,
	&RBX::PartInstance::setDragging,
	Reflection::PropertyDescriptor::STREAMING
);

// FUNCTION: WEBSERVICE 0x10059c10
bool PartInstance::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const ModelInstance*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x1009a8d0
void PartInstance::onChildAdded(Instance* child)
{
	PVInstance::onChildAdded(child);
}

// FUNCTION: WEBSERVICE 0x1009a8e0 FOLDED
Surfaces& PartInstance::getSurfaces()
{
	return surfaces;
}

// FUNCTION: WEBSERVICE 0x1009a8e0 FOLDED
const Surfaces& PartInstance::getSurfaces() const
{
	return surfaces;
}

// FUNCTION: WEBSERVICE 0x1009ae00
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

// FUNCTION: WEBSERVICE 0x1009ae40
bool PartInstance::nonNullInWorkspace(shared_ptr<PartInstance> part)
{
	return part.get() != NULL && part->myWorld != NULL;
}

// FUNCTION: WEBSERVICE 0x1009ae90 FOLDED
PartInstance* PartInstance::fromPrimitive(Primitive* primitive)
{
	if (primitive != NULL) {
		IMoving* owner = primitive->getOwner();

		if (owner != NULL) {
			return static_cast<PartInstance*>(owner);
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1009ae90 FOLDED
const PartInstance* PartInstance::fromPrimitiveConst(const Primitive* primitive)
{
	if (primitive != NULL) {
		IMoving* owner = primitive->getOwner();

		if (owner != NULL) {
			return static_cast<const PartInstance*>(owner);
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x1009aef0
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
void PartInstance::legacyTraverseState(const CoordinateFrame& parentState)
{
	CoordinateFrame gridCorner = parentState * *legacyOffset;

	primitive->setGridCorner(gridCorner);
}

// FUNCTION: WEBSERVICE 0x1009af90
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
void PartInstance::onSurfaceChanged(NormalId normalId)
{
	PersistentPart.setDirty();
	IsControllable.setDirty();
	SurfacesNeedAdorn.setDirty();
	shouldRenderSetDirty();
}

// FUNCTION: WEBSERVICE 0x1009b080
const CoordinateFrame& PartInstance::getCoordinateFrame() const
{
	return primitive->getCoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x1009b0b0
float PartInstance::getMass()
{
	return primitive->getBody()->getMass();
}

// FUNCTION: WEBSERVICE 0x1009b100
const Vector3& PartInstance::getPartSizeXml() const
{
	return primitive->getGeometry()->getGridSize();
}

// FUNCTION: WEBSERVICE 0x1009b110
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
bool PartInstance::getCanCollide() const
{
	if (!primitive->getDragging() && primitive->getCanCollide()) {
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x1009b170
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
Extents PartInstance::getExtentsWorld() const
{
	return primitive->getExtentsWorld();
}

// FUNCTION: WEBSERVICE 0x1009b1d0
Extents PartInstance::getExtentsLocal() const
{
	const Vector3 corner = primitive->getGeometry()->getGridSize() * 0.5f;

	return Extents(-corner, corner);
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

// FUNCTION: WEBSERVICE 0x1009b610
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

// STUB: WEBSERVICE 0x1009b6e0
Part PartInstance::computePersistentPart() const
{
	return Part(
		partType,
		getPartSizeXml(),
		G3D::Color4(getColor3(), 1.0f - (1.0f - (1.0f - transparency) * alphaModifier)),
		surfaces.surf6(),
		getCoordinateFrame()
	);
}

// FUNCTION: WEBSERVICE 0x1009b780
bool PartInstance::shouldRender3dAdorn() const
{
	return partType == Part::CYLINDER_PART || SurfacesNeedAdorn || highlightSleepParts || highlightAwakeParts ||
		   showPartCoord || showAnchoredParts || showUnalignedParts || showSpanningTree;
}

// STUB: WEBSERVICE 0x1009bf50
bool PartInstance::reportTouches() const
{
	STUB(0x1009bf50);
	return false;
}

// FUNCTION: WEBSERVICE 0x1009bfa0
const Part& PartInstance::getPart()
{
	Part& part = PersistentPart.getValueRef();

	part.coordinateFrame = getPrimitive()->getCoordinateFrame();

	return part;
}

// FUNCTION: WEBSERVICE 0x1009bff0
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
void PartInstance::onParentControllerChanged()
{
	PVInstance::onParentControllerChanged();

	PersistentPart.setDirty();

	primitive->setController(getTopPVController());
}

// STUB: WEBSERVICE 0x1009c0c0
void PartInstance::render3dSelect(Adorn* adorn, SelectState selectState)
{
	STUB(0x1009c0c0);
}

// STUB: WEBSERVICE 0x1009c0f0
bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
{
	STUB(0x1009c0f0);
	return false;
}

// FUNCTION: WEBSERVICE 0x1009cc10
void PartInstance::onCanAggregateChanged(bool canAggregate)
{
	Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);

	shouldRenderSetDirty();
}

// FUNCTION: WEBSERVICE 0x1009cc30
void PartInstance::safeMove()
{
	if (World* world = Workspace::getWorldIfInWorkspace(this)) {
		G3D::Array<Primitive*> temp;

		temp.append(primitive.get());

		Dragger::safeMoveNoDrop(temp, Vector3::zero(), *world->getContactManager());
	}
}

// FUNCTION: WEBSERVICE 0x1009d150
PartInstance::~PartInstance()
{
}

// FUNCTION: WEBSERVICE 0x1009d2e0
PartInstance* PartInstance::getPrimaryPart()
{
	return this;
}

const PartInstance* PartInstance::getPrimaryPartConst() const
{
	STUB(0x1009d2e1);
	return NULL;
}

// FUNCTION: WEBSERVICE 0x1009d3b0
const Primitive* PartInstance::getBiggestPrimitive() const
{
	return primitive.get();
}

// FUNCTION: WEBSERVICE 0x1009d3c0
const CoordinateFrame PartInstance::getLocation() const
{
	return primitive->getCoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x1009d7d0
void PartInstance::getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
{
	primitives.push_back(getPrimitive());
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x1009daf0
template <>
EnumDesc<PartInstance::FormFactor>::EnumDesc() : EnumDescriptor("FormFactor", typeid(PartInstance::FormFactor))
{
	addPair(PartInstance::SYMETRIC, "Symmetric");
	addPair(PartInstance::BRICK, "Brick");
	addPair(PartInstance::PLATE, "Plate");

	addLegacyName("Block", PartInstance::BRICK);
}

} // namespace Reflection

// STUB: WEBSERVICE 0x1009f220
PartInstance::PartInstance()
	: DescribedCreatable<PartInstance, PVInstance, sPart>("Part"), surfaces(this),
	  PersistentPart(this, &PartInstance::computePersistentPart),
	  SurfacesNeedAdorn(this, &PartInstance::computeSurfacesNeedAdorn)
{
	STUB(0x1009f220);
}

// FUNCTION: WEBSERVICE 0x1009f910
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
void PartInstance::setDragging(bool value)
{
	if (value != primitive->getDragging()) {
		primitive->setDragging(value);
		raisePropertyChanged(prop_Dragging);
	}
}

// FUNCTION: WEBSERVICE 0x1009fad0
void PartInstance::setRenderImportance(float value)
{
	if (value != renderImportance) {
		renderImportance = value;
		raisePropertyChanged(prop_RenderImportance);
	}
}

// FUNCTION: WEBSERVICE 0x1009fb00
void PartInstance::setCanCollide(bool value)
{
	if (value != getCanCollide()) {
		primitive->setCanCollide(value);
		raisePropertyChanged(prop_CanCollide);
	}
}

// FUNCTION: WEBSERVICE 0x1009fb40
void PartInstance::setAnchored(bool value)
{
	if (value != getAnchored()) {
		primitive->setAnchor(value);
		raisePropertyChanged(prop_Anchored);
	}
}

// FUNCTION: WEBSERVICE 0x1009fb80
void PartInstance::setPartLocked(bool value)
{
	if (value != locked) {
		locked = value;
		raisePropertyChanged(prop_Locked);
	}
}

// FUNCTION: WEBSERVICE 0x1009fbb0
void PartInstance::setTransparency(float value)
{
	if (value != transparency) {
		transparency = value;
		raisePropertyChanged(prop_Transparency);
	}
}

// FUNCTION: WEBSERVICE 0x1009fbe0
void PartInstance::setAlphaModifier(float value)
{
	if (value != alphaModifier) {
		alphaModifier = value;
		raisePropertyChanged(prop_Transparency);
	}
}

// FUNCTION: WEBSERVICE 0x1009fc10
void PartInstance::setReflectance(float value)
{
	if (value != reflectance) {
		reflectance = value;
		raisePropertyChanged(prop_Reflectance);
	}
}

// FUNCTION: WEBSERVICE 0x1009fc40
void PartInstance::setColor(BrickColor value)
{
	if (value.number != color.number) {
		color = value;
		raisePropertyChanged(prop_BrickColor);
		raisePropertyChanged(prop_Color);
	}
}

// FUNCTION: WEBSERVICE 0x1009fc70
void PartInstance::setFormFactorXml(FormFactor value)
{
	if (value != formFactor) {
		formFactor = value;
		raisePropertyChanged(prop_formFactor);
	}
}
// STUB: WEBSERVICE 0x1009fe60
void PartInstance::setColor3(const G3D::Color3& value)
{
	BrickColor closest = BrickColor::closest(value);

	if (closest != color) {
		color = closest;

		raisePropertyChanged(prop_Color);
		raisePropertyChanged(prop_BrickColor);
	}
}

// STUB: WEBSERVICE 0x1009fec0
void PartInstance::onCameraNear(float distance)
{
	if (distance > 3.0f) {
		if (distance > 6.0f) {
			setAlphaModifier(1.0f);
		}
		else {
			setAlphaModifier(0.5f);
		}
	}
	else {
		setAlphaModifier(0.0f);
	}
}

// STUB: WEBSERVICE 0x1009ff60
void PartInstance::render3dAdorn(Adorn* adorn)
{
	STUB(0x1009ff60);
}

// FUNCTION: WEBSERVICE 0x100a0450
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
