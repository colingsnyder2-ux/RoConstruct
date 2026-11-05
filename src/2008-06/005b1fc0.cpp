// from server: 100% by king_originala
// from server: 89% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_king_originala_hat_drop_8e5a2f396007f523.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <util/ICameraSubject.h>
#include <util/ISelectable3d.h>
#include <v8datamodel/IPrimaryPart.h>
#include <v8datamodel/PartInstance.h>
#include <humanoid/Humanoid.h>
#include <typeinfo>
struct NativeHatJoint {
 RBX::PartInstance* getAttachedPart()const;
 void setParent(RBX::Instance*);
};
namespace boost {template<> void shared_ptr<NativeHatJoint>::reset();}
// Borrowed nonvirtual prefixes. Native RTTI supplies the virtual bases below.
struct NativeModelPrefix {
 virtual ~NativeModelPrefix();
 char unknown[0x130];
};
struct NativeModelView:NativeModelPrefix,virtual RBX::IPrimaryPart,
 virtual RBX::ILocation,virtual RBX::ICameraSubject,virtual RBX::ISelectable3d {};
struct NativeHatPrefix {
 virtual ~NativeHatPrefix();
 char unknown[0x130];
 boost::shared_ptr<NativeHatJoint> joint;
 char tail[0x14];
};
struct NativeHatView:NativeHatPrefix,virtual RBX::ICameraSubject,virtual RBX::ISelectable3d {
 RBX::PartInstance* getHandle();
 void finishDrop();
 void drop();
};
extern "C" void* __cdecl __RTDynamicCast(void*,long,void*,void*,int);
extern const type_info nativeInstanceType;
extern const type_info nativeModelType;
static __forceinline RBX::Instance* nativePartParent(const RBX::PartInstance*part){
 return *reinterpret_cast<RBX::Instance*const*>(reinterpret_cast<const char*>(part)+0x104);
}
void NativeHatView::drop(){
 NativeModelView*model=0;
 if(joint){
  RBX::PartInstance*part=joint->getAttachedPart();
  if(part)model=static_cast<NativeModelView*>(__RTDynamicCast(nativePartParent(part),0,const_cast<type_info*>(&nativeInstanceType),const_cast<type_info*>(&nativeModelType),0));
  joint->setParent(0);
  joint.reset();
 }
 if(RBX::Humanoid::modelIsCharacter(reinterpret_cast<RBX::Instance*>(model))){
  G3D::CoordinateFrame frame=model->getLocation();
  G3D::Vector3 position=frame.translation;
  position.y+=4.0f;
  float distance=G3D::CoordinateFrame::zLookDirection;
  G3D::Vector3 look=frame.rotation.getColumn(2)*distance;
  position+=look*8.0f;
  RBX::PartInstance*part=getHandle();
  if(part){
   part->setCanCollide(true);
   part->moveToPoint(position);
   position.x=1.0f;position.y=1.0f;position.z=1.0f;
   part->setRotationalVelocity(position);
  }
 }
 onCameraNear(999.0f);
 finishDrop();
}
