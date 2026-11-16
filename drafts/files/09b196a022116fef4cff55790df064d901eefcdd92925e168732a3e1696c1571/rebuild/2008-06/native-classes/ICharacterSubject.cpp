// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/ICharacterSubject.h"
#include "v8datamodel/Camera.h"
#include "util/Math.h"
namespace RBX {
ICharacterSubject::ICharacterSubject()
    : lastOffset(G3D::Vector3::ZERO), cursorLocked(false), wasOccluded(false), hasGoalInFocus(false)
{
}
// Original goalFromDistance calls this helper at 00641293.
__declspec(noinline) G3D::CoordinateFrame ICharacterSubject::getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal)
{
    G3D::CoordinateFrame temp = cameraFocus;
    temp.lookAt(cameraGoal.translation);
    return temp;
}
G3D::CoordinateFrame ICharacterSubject::goalFromDistance(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, const float distance)
{
    G3D::CoordinateFrame manLookCamera = getFocusLookingAtGoal(cameraFocus, cameraGoal);
    G3D::Vector3 newCameraPt = manLookCamera.lookVector() * distance + manLookCamera.translation;
    return G3D::CoordinateFrame(G3D::Matrix3::identity(), newCameraPt);
}
	bool ICharacterSubject::zoom(const float in, G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus)
	{
		// INFERRED: 006413a7/006413c3 select the unoccluded goal when wasOccluded.
		G3D::CoordinateFrame newGoal = wasOccluded ? goalFromDistance(cameraFocus, cameraGoal, unoccludedDistance) : cameraGoal;
		G3D::Vector3 focusToGoal = newGoal.translation - cameraFocus.translation;

		float currentDistance = focusToGoal.magnitude();
		float newDistance = Camera::getNewZoomDistance(currentDistance, in);

		float clampedDistance = G3D::min(400.0f, newDistance);

		if (clampedDistance == currentDistance)
			return false;

		focusToGoal.y = 0.0f;
		focusToGoal.unitize();
		focusToGoal.y = clampedDistance * 0.03f;

		newGoal.translation = focusToGoal.direction() * clampedDistance + cameraFocus.translation;
		// INFERRED: 006414e1 branches to distance storage or full goal assignment.
		if (wasOccluded)
			unoccludedDistance = (newGoal.translation - cameraFocus.translation).magnitude();
		else
			cameraGoal = newGoal;

		return true;
	}

void ICharacterSubject::stepGoalAndFocus(G3D::CoordinateFrame&cameraGoal,G3D::CoordinateFrame&cameraFocus,bool){
 G3D::Vector3 focusToGoal=cameraFocus.translation-cameraGoal.translation;
 if((cameraGoal.translation-cameraFocus.translation).magnitude()<2.75f){
  G3D::Vector3 oldFocus=cameraFocus.translation;
  cameraFocus=getLocation();
  cameraGoal.translation+=cameraFocus.translation-oldFocus;
 }else{
  cameraFocus=getLocation();
  G3D::Vector3 intended=getIntendedMovementVector()*16.0f;intended/=30.0f;
  G3D::Vector3 filterInput=cameraFocus.translation-focusERA.getAverage()-intended;
  filterInput.y=0;
  G3D::Vector3 offset;
  offset=focusOffsetERA.pushAndGetAverage(filterInput);
  (void)focusERA.pushAndGetAverage(cameraFocus.translation);
  (void)getIntendedRotationAboutYAxis();
  G3D::CoordinateFrame subjectFrame=getLocation();
  {G3D::Vector3 back=subjectFrame.rotation.getColumn(2);
  (void)rotationERA.getAverage();
  (void)rotationERA.pushAndGetAverage((float)-atan2(-back.x,back.z));}
  G3D::CoordinateFrame focusSpace=Math::getFocusSpace(cameraFocus);
  cameraGoal.translation+=offset;
  float radius=focusToGoal.xz().length();
  G3D::Vector2 direction=(cameraFocus.translation.xz()-cameraGoal.translation.xz()).direction();
  cameraGoal.translation=(cameraFocus.translation-G3D::Vector3(direction.x*radius,focusToGoal.y,direction.y*radius));
  goalInFocus=focusSpace.pointToObjectSpace(cameraGoal.translation);hasGoalInFocus=true;
 }
 G3D::CoordinateFrame testGoal=wasOccluded?goalFromDistance(cameraFocus,cameraGoal,unoccludedDistance):cameraGoal;
 {float distance;
 bool occluded=testOcclusion(cameraFocus,testGoal,distance);
 if(occluded){if(!wasOccluded)unoccludedDistance=focusToGoal.magnitude();cameraGoal=goalFromDistance(cameraFocus,cameraGoal,distance);}
 else if(wasOccluded)cameraGoal=testGoal;
 wasOccluded=occluded;tellCameraNear(distance);}
}

}
