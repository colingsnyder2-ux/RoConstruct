// from server: 100% by EspClaude
// from server: 81% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_30eaa6250df6d74d.cpp

// Candidate translation unit (score above; library headers required).
#include "util/ICameraSubject.h"
#pragma once
#include <G3D/GCamera.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Rect2D.h>
#include <G3D/Array.h>
#include "v8tree/Instance.h"
#include "util/Extents.h"

namespace RBX
{
	class Primitive;
	class ContactManager;
	class ICameraSubject;
	class ICameraOwner;

	extern char sCamera[];
	struct CameraSubject2009 {
		virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
		virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
		virtual void stepGoalAndFocus(G3D::CoordinateFrame& goal, G3D::CoordinateFrame& focus, double dt);
	};
	struct CameraPad2009 { char pad[0x98]; };
	class Camera : public CameraPad2009
	{
	private:
		enum AnimationType
		{
			ALWAYS,
			AUTO
		};
	public:
		enum CameraType
		{
			FIXED_CAMERA,
			ATTACH_CAMERA,
			WATCH_CAMERA,
			TRACK_CAMERA,
			FOLLOW_CAMERA,
			CUSTOM_CAMERA,
			NUM_CAMERA_TYPE
		};
		enum ZoomType
		{
			ZOOM_IN_OR_OUT,
			ZOOM_OUT_ONLY,
			ZOOM_CHAR_PART_DRAG,
		};

	private:
		G3D::GCamera gCamera;
		G3D::CoordinateFrame cameraGoal;
		G3D::CoordinateFrame cameraFocus;
		CameraType cameraType;
		AnimationType animationType;
		boost::shared_ptr<Instance> cameraSubject;
		bool cameraExternallyAdjusted;

	private:
		ICameraOwner* getCameraOwner();
		void updateFocus();
		void updateGoal(double dt);
		bool characterZoom(float in);
		bool nonCharacterZoom(float in);
		void tryZoomExtents(float low, float current, float high, const RBX::Extents& extents, const G3D::Rect2D& viewPort);
		ContactManager& getContactManager();
		float goalToFocusDistance() const
		{
			return (cameraGoal.translation - cameraFocus.translation).magnitude();
		}
		void setGCameraCoordinateFrame(const G3D::CoordinateFrame& coord);
		G3D::CoordinateFrame computeLineOfSiteGoal();
		void getHeadingElevationDistance(float& heading, float& elevation, float& distance);
		void setHeadingElevationDistance(float, float, float);
		void tellCameraMoved();
		void getIgnorePrims(G3D::Array<const Primitive*>&);
	public:
		Camera();
	public:
		const G3D::GCamera& getGCamera() const
		{
			return gCamera;
		}
		void onHeartbeat();
		void autoMode();
		void alwaysMode();
		bool isCharacterCamera() const;
		bool isFirstPersonCamera() const;
		CameraSubject2009* getCameraSubject() const;
		Instance* getCameraSubjectInstance() const;
		void setCameraSubject(Instance* newSubject);
		const G3D::CoordinateFrame& getCameraFocus() const
		{
			return cameraFocus;
		}
		void setCameraFocus(const G3D::CoordinateFrame& value);
		G3D::CoordinateFrame getCameraCoordinateFrame() const
		{
			return gCamera.getCoordinateFrame();
		}
		void setCameraCoordinateFrameNoLerp(const G3D::CoordinateFrame& value);
		void goalToCamera();
		CameraType getCameraType() const
		{
			return cameraType;
		}
		void setCameraType(CameraType type);
		bool canZoom(int) const;
		bool canTilt(int) const;
		void onWrapMouse(const G3D::Vector2&);
		bool zoom(float in);
		bool setDistanceFromTarget(float newDistance);
		void zoomExtents(Extents extents, const G3D::Rect2D& viewPort, ZoomType zoomType);
		bool zoomExtents(const G3D::Rect2D& viewPort);
		void panRadians(float angle);
		void panUnits(int);
		bool tiltRadians(float angle);
		bool tiltUnits(int);
		void lookAt(const G3D::Vector3& point);
		void setImageServerViewNoLerp(const G3D::CoordinateFrame& modelCoord, const G3D::Rect2D& viewPort);

	public:
		static float distanceDefault();
		static float distanceMin()
		{
			return 0.5f;
		}
		static float distanceMax()
		{
			return 1000.0f;
		}
		static float distanceMaxCharacter()
		{
			return 400.0f;
		}
		static float distanceMinOcclude();
		static float getNewZoomDistance(float currentDistance, float in);
	};
}

namespace RBX {
	void Camera::updateGoal(double dt)
	{
		switch (cameraType)
		{
			case WATCH_CAMERA:
			{
				updateFocus();
				break;
			}
			case ATTACH_CAMERA: 
			{
				G3D::Vector3 delta = cameraGoal.translation - cameraFocus.translation;
				float distance = delta.xz().length();

				updateFocus();

				G3D::Vector2 direction = -cameraFocus.lookVector().xz().direction() * distance;
				cameraGoal.translation = cameraFocus.translation + G3D::Vector3(direction.x, delta.y, direction.y);

				break;
			}
			case TRACK_CAMERA:
			{
				G3D::Vector3 oldFocusPt = cameraFocus.translation;
				updateFocus();

				cameraGoal.translation += cameraFocus.translation - oldFocusPt;
				break;
			}
			case FOLLOW_CAMERA:
			{
				G3D::Vector3 delta = cameraFocus.translation - cameraGoal.translation;
				float distance = delta.xz().length();

				updateFocus();
			
				G3D::Vector2 direction = (cameraFocus.translation.xz() - cameraGoal.translation.xz()).direction() * distance;
				cameraGoal.translation = cameraFocus.translation - G3D::Vector3(direction.x, delta.y, direction.y);

				break;
			}
			case CUSTOM_CAMERA:
			{
				if (CameraSubject2009* cameraSubject = getCameraSubject())
					cameraSubject->stepGoalAndFocus(cameraGoal, cameraFocus, dt);
				break;
			}
		}

		cameraGoal.lookAt(cameraFocus.translation);
	}


}

