// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8datamodel/Camera.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Camera.h"

#include "reflection/reflection.h"
#include "util/ICameraSubject.h"
#include "util/Math.h"
#include "util/NavKeys.h"
#include "v8datamodel/ICameraOwner.h"
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Workspace.h"

namespace RBX {

char sCamera[] = "Camera";

static const char category_Camera[] = "Camera";

static Reflection::EnumPropDescriptor<Camera, Camera::CameraType> desc_cameraType(
	"CameraType", category_Camera, &Camera::getCameraType, &Camera::setCameraType
);

static Reflection::PropDescriptor<Camera, G3D::CoordinateFrame> desc_CoordFrame(
	"CoordinateFrame",
	"Data",
	&Camera::getCameraCoordinateFrame,
	&Camera::setCameraCoordinateFrameNoLerp,
	Reflection::PropertyDescriptor::STREAMING
);

static Reflection::PropDescriptor<Camera, G3D::CoordinateFrame> desc_Focus(
	"Focus", "Data", &Camera::getCameraFocus, &Camera::setCameraFocus, Reflection::PropertyDescriptor::STREAMING
);

static Reflection::RefPropDescriptor<Camera, Instance> cameraSubjectProp(
	"CameraSubject", category_Camera, &Camera::getCameraSubjectInstance, &Camera::setCameraSubject
);

// FUNCTION: WEBSERVICE 0x100c2600
// FUNCTION: ROBLOX 0x005d5f60
bool Camera::askSetParent(const Instance* instance) const
{
	return dynamic_cast<const Workspace*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x100c2630
// FUNCTION: ROBLOX 0x005d5f90
ICameraOwner* Camera::getCameraOwner()
{
	Instance* parent = getParent();
	while (parent) {
		if (ICameraOwner* owner = dynamic_cast<ICameraOwner*>(parent)) {
			return owner;
		}

		parent = parent->getParent();
	}

	return NULL;
}

// FUNCTION: ROBLOX 0x005d5fd0
bool Camera::canZoom(int p_unk0x04) const
{
	if (p_unk0x04 > 0) {
		return goalToFocusDistance() > distanceMin();
	}

	return goalToFocusDistance() < distanceMax();
}

// FUNCTION: WEBSERVICE 0x100c2670
// FUNCTION: ROBLOX 0x005d6040
void Camera::alwaysMode()
{
	animationType = ALWAYS;
}

// FUNCTION: WEBSERVICE 0x100c2680
// FUNCTION: ROBLOX 0x005d6050
void Camera::lookAt(const G3D::Vector3& point)
{
	cameraFocus.translation = point;
	cameraGoal.lookAt(point);
}

// FUNCTION: ROBLOX 0x005d6080
bool Camera::canTilt(int p_unk0x04) const
{
	float elevation = Math::elevationAngle(cameraGoal.lookVector());

	if (p_unk0x04 < 0) {
		return -1.57079637f <= elevation;
	}

	return 1.57079637f >= elevation;
}

// FUNCTION: WEBSERVICE 0x100c26b0
// FUNCTION: ROBLOX 0x005d6100
void Camera::getHeadingElevationDistance(float& heading, float& elevation, float& distance)
{
	Math::getHeadingElevation(cameraGoal, heading, elevation);

	distance = goalToFocusDistance();
}

// FUNCTION: WEBSERVICE 0x100c2810
// FUNCTION: ROBLOX 0x005d6290
float Camera::getNewZoomDistance(float currentDistance, float in)
{
	static const float ZOOM_FACTOR = 0.25f;

	float newDistance;

	if (in > 0.0f) {
		newDistance = std::max(currentDistance / (1.0f + in * ZOOM_FACTOR), distanceMin());
	}
	else if (in < 0.0f) {
		newDistance = std::min(currentDistance * (1.0f - in * ZOOM_FACTOR), distanceMax());
	}
	else {
		newDistance = currentDistance;
	}

	return newDistance;
}

// FUNCTION: WEBSERVICE 0x100c28a0
// FUNCTION: ROBLOX 0x005d6320
bool Camera::setDistanceFromTarget(float newDistance)
{
	G3D::Vector3 lookVector = cameraFocus.translation - cameraGoal.translation;
	float currentDistance = lookVector.magnitude();
	const float min = distanceMin();
	const float max = distanceMax();

	if (newDistance < min && currentDistance == min) {
		return false;
	}

	if (newDistance > max && currentDistance == max) {
		return false;
	}

	newDistance = std::max(min, newDistance);
	newDistance = std::min(max, newDistance);

	cameraGoal.translation = cameraFocus.translation - lookVector * newDistance / currentDistance;

	tellCameraMoved();

	return true;
}

// FUNCTION: WEBSERVICE 0x100c29e0
// FUNCTION: ROBLOX 0x005d6460
Instance* Camera::getCameraSubjectInstance() const
{
	return cameraSubject.get();
}

// FUNCTION: WEBSERVICE 0x100c29f0
// FUNCTION: ROBLOX 0x005d6470
ICameraSubject* Camera::getCameraSubject() const
{
	return cameraSubject ? dynamic_cast<ICameraSubject*>(cameraSubject.get()) : NULL;
}

// FUNCTION: WEBSERVICE 0x100c2a20
// FUNCTION: ROBLOX 0x005d64a0
void Camera::autoMode()
{
	if (animationType != AUTO) {
		animationType = AUTO;
		tellCameraMoved();
	}
}

// FUNCTION: WEBSERVICE 0x100c2a50
// FUNCTION: ROBLOX 0x005d64d0
bool Camera::nonCharacterZoom(float in)
{
	G3D::Vector3 lookVector = cameraFocus.translation - cameraGoal.translation;
	const float currentDistance = lookVector.magnitude();

	float newDistance = getNewZoomDistance(currentDistance, in);
	if (newDistance == currentDistance) {
		return false;
	}

	float scale = newDistance / currentDistance;
	cameraGoal.translation -= lookVector * (scale - 1.0f);
	tellCameraMoved();
	return true;
}

// FUNCTION: WEBSERVICE 0x100c2b30
// FUNCTION: ROBLOX 0x005d65b0
bool Camera::characterZoom(float in)
{
	G3D::Vector3 focusToGoal = cameraGoal.translation - cameraFocus.translation;
	float currentDistance = focusToGoal.magnitude();

	float newDistance = std::min(getNewZoomDistance(currentDistance, in), distanceMaxCharacter());

	if (newDistance == currentDistance) {
		return false;
	}

	focusToGoal.y = 0.0f;
	focusToGoal.unitize();
	focusToGoal.y = newDistance * 0.03f;

	cameraGoal.translation = cameraFocus.translation + focusToGoal.direction() * newDistance;

	return true;
}

// FUNCTION: WEBSERVICE 0x100c2c60
// FUNCTION: ROBLOX 0x005d66e0
void Camera::setHeadingElevationDistance(float heading, float elevation, float distance)
{
	Math::setHeadingElevation(cameraGoal, heading, elevation);

	cameraFocus.rotation = cameraGoal.rotation;

	cameraGoal.translation = cameraFocus.translation - cameraGoal.lookVector() * distance;

	cameraExternallyAdjusted = true;
}

// FUNCTION: ROBLOX 0x005d6790
bool Camera::tiltRadians(float p_unk0x04)
{
	if (p_unk0x04 != 0.0f) {
		float heading;
		float elevation;
		float distance;

		getHeadingElevationDistance(heading, elevation, distance);

		static const float maxElevation = (float) G3D::toRadians(81.0);

		float newElevation = G3D::clamp(p_unk0x04 + elevation, -maxElevation, maxElevation);

		if (newElevation != elevation) {
			setHeadingElevationDistance(heading, newElevation, distance);

			tellCameraMoved();
			return true;
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100c2d10
// FUNCTION: ROBLOX 0x005d6860
void Camera::panRadians(float angle)
{
	if (angle != 0.0f) {
		float heading;
		float elevation;
		float distance;

		getHeadingElevationDistance(heading, elevation, distance);

		heading = Math::radWrap(heading + angle);

		setHeadingElevationDistance(heading, elevation, distance);

		tellCameraMoved();
	}
}

// FUNCTION: ROBLOX 0x005d68e0
bool Camera::tiltUnits(int p_unk0x04)
{
	float elevation = Math::elevationAngle(cameraGoal.lookVector());

	float degrees = elevation * 57.2957764f;

	return tiltRadians((G3D::iRound(degrees * 0.1f) + p_unk0x04) * 0.174532935f - elevation);
}

// FUNCTION: ROBLOX 0x005d6980
void Camera::panUnits(int p_unk0x04)
{
	G3D::Vector3 look = cameraGoal.lookVector();
	float heading = atan2f(-look.z, -look.x);

	panRadians(heading - G3D::iRound(heading * 1.27323949f + p_unk0x04) * 0.785398185f);
}

// FUNCTION: ROBLOX 0x005d6b00
bool Camera::isFirstPersonCamera() const
{
	ICharacterSubject* subject = dynamic_cast<ICharacterSubject*>(getCameraSubject());
	if (subject) {
		return subject->getCursorCenterLocked();
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100c2ef0
// FUNCTION: ROBLOX 0x005d6b50
void Camera::updateFocus()
{
	if (cameraSubject) {
		cameraFocus = dynamic_cast<ICameraSubject*>(cameraSubject.get())->getLocation();
	}
}

// FUNCTION: WEBSERVICE 0x100c2f60
// FUNCTION: ROBLOX 0x005d6bc0
void Camera::updateGoal()
{
	switch (cameraType) {
	case FIXED_CAMERA:
		break;

	case WATCH_CAMERA:
		updateFocus();
		break;

	case ATTACH_CAMERA: {
		G3D::Vector3 delta = cameraGoal.translation - cameraFocus.translation;
		float distance = delta.xz().length();

		updateFocus();

		G3D::Vector2 offset = -cameraFocus.lookVector().xz().direction() * distance;

		cameraGoal.translation = cameraFocus.translation + G3D::Vector3(offset.x, delta.y, offset.y);
		break;
	}

	case TRACK_CAMERA: {
		G3D::Vector3 oldFocusPt = cameraFocus.translation;

		updateFocus();

		cameraGoal.translation += cameraFocus.translation - oldFocusPt;
		break;
	}

	case FOLLOW_CAMERA: {
		G3D::Vector3 delta = cameraFocus.translation - cameraGoal.translation;
		float distance = delta.xz().length();

		updateFocus();

		G3D::Vector2 offset = (cameraFocus.translation.xz() - cameraGoal.translation.xz()).direction() * distance;

		cameraGoal.translation = cameraFocus.translation - G3D::Vector3(offset.x, delta.y, offset.y);
		break;
	}

	case CUSTOM_CAMERA: {
		ICameraSubject* subject = getCameraSubject();
		if (subject) {
			subject->stepGoalAndFocus(cameraGoal, cameraFocus, cameraExternallyAdjusted);
		}
		cameraExternallyAdjusted = false;
		break;
	}
	}

	cameraGoal.lookAt(cameraFocus.translation);
}

// FUNCTION: ROBLOX 0x005d6e40
void Camera::onWrapMouse(const G3D::Vector2& wrapMouseDelta)
{
	tiltRadians(wrapMouseDelta.y * -0.0052359882f);
	panRadians(wrapMouseDelta.x * -0.0069813174f);
}

// FUNCTION: WEBSERVICE 0x100c31e0
// FUNCTION: ROBLOX 0x005d6e80
bool Camera::zoom(float in)
{
	if (cameraType == CUSTOM_CAMERA) {
		if (ICameraSubject* subject = getCameraSubject()) {
			return subject->zoom(in, cameraGoal, cameraFocus);
		}
		return false;
	}

	return isCharacterCamera() ? characterZoom(in) : nonCharacterZoom(in);
}

// FUNCTION: WEBSERVICE 0x100c3500
// FUNCTION: ROBLOX 0x005d7110
void Camera::onHeartbeat()
{
	updateGoal();
	G3D::CoordinateFrame adjustedGoal = cameraGoal;

	if (ICharacterSubject* characterSubject = dynamic_cast<ICharacterSubject*>(getCameraSubject())) {
		characterSubject->onHeartBeat(cameraGoal, cameraFocus);
	}

	G3D::CoordinateFrame oldC = gCamera.getCoordinateFrame();
	G3D::CoordinateFrame newC = oldC.lerp(adjustedGoal, 0.9f);

	setGCameraCoordinateFrame(newC);

	if (animationType == ALWAYS || !Math::fuzzyEq(newC, oldC, 0.01f, 0.01f)) {
		tellCameraMoved();
	}
}

// FUNCTION: WEBSERVICE 0x100c3860
// FUNCTION: ROBLOX 0x005d7400
template <>
Reflection::EnumDesc<Camera::CameraType>::EnumDesc() : EnumDescriptor("CameraType", typeid(Camera::CameraType))
{
	addPair(Camera::FIXED_CAMERA, "Fixed");
	addPair(Camera::WATCH_CAMERA, "Watch");
	addPair(Camera::ATTACH_CAMERA, "Attach");
	addPair(Camera::TRACK_CAMERA, "Track");
	addPair(Camera::FOLLOW_CAMERA, "Follow");
	addPair(Camera::CUSTOM_CAMERA, "Custom");
}

// FUNCTION: WEBSERVICE 0x100c4120
// FUNCTION: ROBLOX 0x005d7c80
Camera::Camera()
	: gCamera(), cameraGoal(), cameraFocus(G3D::Vector3(0, 0, -5)), cameraType(FIXED_CAMERA), animationType(AUTO),
	  cameraSubject(), cameraExternallyAdjusted(false)
{
	setName("Camera");

	gCamera.setNearPlaneZ(-1.25f);
	gCamera.setFarPlaneZ(-5000.0f);
	gCamera.setFieldOfView(1.0471976f);

	G3D::CoordinateFrame defaultC(G3D::Matrix3::identity(), G3D::Vector3(0, 5, 5));
	defaultC.lookAt(G3D::Vector3::zero());

	setGCameraCoordinateFrame(defaultC);
}

// FUNCTION: WEBSERVICE 0x100c4470
// FUNCTION: ROBLOX 0x005d7fd0
void Camera::setCameraType(CameraType value)
{
	if (cameraType != value) {
		cameraType = value;
		raisePropertyChanged(desc_cameraType);
		tellCameraMoved();
	}
}

// FUNCTION: WEBSERVICE 0x100c44b0
// FUNCTION: ROBLOX 0x005d8010
void Camera::setCameraSubject(Instance* newSubject)
{
	if (newSubject != cameraSubject.get() && dynamic_cast<ICameraSubject*>(newSubject)) {
		cameraSubject = shared_from(newSubject);
		raisePropertyChanged(cameraSubjectProp);
		tellCameraMoved();
	}
}

// FUNCTION: WEBSERVICE 0x100c45a0
// FUNCTION: ROBLOX 0x005d8100
void Camera::setCameraFocus(const G3D::CoordinateFrame& value)
{
	if (value != cameraFocus) {
		cameraFocus = value;
		raisePropertyChanged(desc_Focus);
		tellCameraMoved();
	}
}

// FUNCTION: WEBSERVICE 0x100c4610
// FUNCTION: ROBLOX 0x005d8170
void Camera::goalToCamera()
{
	if (gCamera.getCoordinateFrame() != cameraGoal) {
		cameraExternallyAdjusted = true;
		setGCameraCoordinateFrame(cameraGoal);
		raisePropertyChanged(desc_CoordFrame);
		tellCameraMoved();
	}
}

// FUNCTION: WEBSERVICE 0x100c4690
// FUNCTION: ROBLOX 0x005d81f0
void Camera::tryZoomExtents(float low, float current, float high, const Extents& extents, const G3D::Rect2D& viewPort)
{
	if (!(high - low < 0.1)) {
		setDistanceFromTarget(current);

		updateGoal();

		goalToCamera();

		bool contained = extents.containedByFrustum(gCamera.frustum(viewPort));
		if (contained) {
			tryZoomExtents(low, (low + current) * 0.5f, current, extents, viewPort);
		}
		else {
			tryZoomExtents(current, (current + high) * 0.5f, high, extents, viewPort);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100c4770
// FUNCTION: ROBLOX 0x005d82d0
void Camera::zoomExtents(Extents extents, const G3D::Rect2D& viewPort, ZoomType zoomType)
{
	G3D::CoordinateFrame currentCoord = gCamera.getCoordinateFrame();

	extents.expand(0.1f);

	if (zoomType == ZOOM_CHAR_PART_DRAG && cameraType != CUSTOM_CAMERA) {
		return;
	}

	if (cameraType == FIXED_CAMERA) {
		G3D::Vector3 center = extents.center();
		G3D::Vector3 delta = center - cameraFocus.translation;
		cameraFocus.translation += delta;
		cameraGoal.translation += delta;
	}

	float min = (zoomType == ZOOM_OUT_ONLY || zoomType == ZOOM_CHAR_PART_DRAG) ? goalToFocusDistance() : distanceMin();

	float current = goalToFocusDistance();
	if (zoomType == ZOOM_CHAR_PART_DRAG) {
		extents.scale(1.1f);
	}

	if (G3D::isFinite(min) && G3D::isFinite(current) && G3D::isFinite(distanceMax())) {
		tryZoomExtents(min, current, distanceMax(), extents, viewPort);
	}

	cameraGoal = gCamera.getCoordinateFrame();

	setGCameraCoordinateFrame(currentCoord);

	tellCameraMoved();
}

// FUNCTION: WEBSERVICE 0x100c4aa0
// FUNCTION: ROBLOX 0x005d8600
bool Camera::zoomExtents(const G3D::Rect2D& viewPort)
{
	if (ICameraOwner* owner = getCameraOwner()) {
		zoomExtents(owner->computeCameraOwnerExtents(), viewPort, ZOOM_IN_OR_OUT);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100c4ae0
// FUNCTION: ROBLOX 0x005d8640
void Camera::setCameraCoordinateFrameNoLerp(const G3D::CoordinateFrame& value)
{
	cameraGoal = value;
	goalToCamera();
}

// FUNCTION: WEBSERVICE 0x100c4b20
// FUNCTION: ROBLOX 0x005d8680
void Camera::setImageServerViewNoLerp(const G3D::CoordinateFrame& modelCoord, const G3D::Rect2D& viewPort)
{
	G3D::Vector3 look = modelCoord.lookVector();

	if (fabs(look.y) > 0.95) {
		look = -G3D::Vector3::unitZ();
	}
	else {
		look.y = 0.0f;
		look = look.direction();
	}

	G3D::CoordinateFrame lookCoord;
	lookCoord.lookAt(look);

	lookCoord.rotation *= G3D::Matrix3::fromEulerAnglesZXY(0.7853982f, 0.61086524f, 0.0f);

	look = lookCoord.lookVector();
	lookCoord.translation = modelCoord.translation + 10.0f * look;
	lookCoord.lookAt(modelCoord.translation);

	setCameraType(FIXED_CAMERA);
	setCameraFocus(G3D::CoordinateFrame(modelCoord.translation));
	setCameraCoordinateFrameNoLerp(lookCoord);
	zoomExtents(viewPort);
	goalToCamera();
}

// FUNCTION: WEBSERVICE 0x100c4d80
// FUNCTION: ROBLOX 0x005d88e0
void Camera::doFly(const NavKeys& nav, int steps)
{
	if (!nav.navKeyDown()) {
		return;
	}

	float acceleration = 2.0f;
	if (steps > 120) {
		acceleration = 8.0f;
	}
	else if (steps > 60) {
		acceleration = 4.0f;
	}

	G3D::CoordinateFrame current = getCameraCoordinateFrame();

	G3D::Vector3 look = current.lookVector();
	G3D::Vector3 right = current.rightVector();

	G3D::Vector3 delta;
	if (nav.forward_arrow || nav.forward_asdw) {
		delta += look * acceleration;
	}

	if (nav.backward_arrow || nav.backward_asdw) {
		delta -= look * acceleration;
	}

	if (nav.right_arrow || nav.right_asdw) {
		delta += right * acceleration;
	}

	if (nav.left_arrow || nav.left_asdw) {
		delta -= right * acceleration;
	}

	current.translation += delta;

	setCameraType(FIXED_CAMERA);
	setCameraCoordinateFrameNoLerp(current);
	setCameraFocus(G3D::CoordinateFrame(current.translation + look * 20.0f));
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Camera, RBX::Instance, RBX::sCamera>;
template class RBX::Reflection::
	Described<RBX::Camera, RBX::sCamera, RBX::FactoryProduct<RBX::Camera, RBX::Instance, RBX::sCamera> >;
template class RBX::DescribedCreatable<RBX::Camera, RBX::Instance, RBX::sCamera>;
