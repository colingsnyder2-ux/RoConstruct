// from server: 100% by Espeon
// from server: 84% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
namespace boost {namespace detail {
struct sp_counted_base {
 virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 long use_count_,weak_count_;
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
 sp_counted_base*pi_;
 shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
 shared_count&operator=(const shared_count&);
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>struct shared_ptr {
 T*px;detail::shared_count pn;
 shared_ptr():px(0),pn(){}
 shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}
 shared_ptr&operator=(const shared_ptr&r){px=r.px;pn=r.pn;return *this;}
 T*operator->()const{return px;}
};
}
struct __declspec(dllimport) ImportedString {char data[28];ImportedString(const char*);~ImportedString()throw();};
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&r):x(r.x),y(r.y),z(r.z){}
 Vector3&operator=(const Vector3&r){x=r.x;y=r.y;z=r.z;return *this;}
};
struct Matrix3 {float data[9];Matrix3(const Matrix3&r){*this=r;}Matrix3&operator=(const Matrix3&);};
struct CoordinateFrame {
 Matrix3 rotation;Vector3 translation;
 CoordinateFrame();
 CoordinateFrame(const CoordinateFrame&r):rotation(r.rotation),translation(r.translation){}
 ~CoordinateFrame(){}
 void lookAt(const Vector3&,Vector3);
 CoordinateFrame operator*(const CoordinateFrame&)const;
 CoordinateFrame inverse()const;
 CoordinateFrame toObjectSpace(const CoordinateFrame&)const;
};
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;Velocity()throw();static __forceinline const Velocity&zero(){static Velocity value;return value;}};
struct Primitive;
struct Clump {char opaque[0x1c];Primitive*rootPrimitive;Primitive*getRootPrimitive(){return rootPrimitive;}};
struct Assembly {char opaque[0x24];Clump*rootClump;Primitive*getMainPrimitive()const{return rootClump->getRootPrimitive();}};
struct Primitive {
 Assembly*getAssembly()const;
 const G3D::CoordinateFrame&getCoordinateFrame()const;
 void setCoordinateFrame(const G3D::CoordinateFrame&);
 void setVelocity(const Velocity&);
};
struct Instance {virtual ~Instance();virtual void setName(const ImportedString&);void setParent(Instance*);};
struct PartInstance:Instance {const G3D::CoordinateFrame&getCoordinateFrame()const;};
struct AutoJoint:Instance {void setPart0(PartInstance*);void setPart1(PartInstance*);void setC0(const G3D::CoordinateFrame&);void setC1(const G3D::CoordinateFrame&);};
boost::shared_ptr<AutoJoint>__cdecl createSeatJoint();
struct Humanoid {Primitive*getTorsoPrimitive()const;PartInstance*getTorso()const;};
struct Seat:PartInstance {
 char unchanged[0x418-sizeof(PartInstance)];boost::shared_ptr<AutoJoint>weld;
 void seatCharacter(Humanoid*);
};
void Seat::seatCharacter(Humanoid*h){
 G3D::CoordinateFrame original=getCoordinateFrame();
 G3D::CoordinateFrame C0;
 C0.lookAt(G3D::Vector3(0,-1,0),G3D::Vector3(0,0,-1));
 C0.translation=G3D::Vector3(0,3,0);
 G3D::CoordinateFrame C1;
 C1.lookAt(G3D::Vector3(0,-1,0),G3D::Vector3(0,0,-1));
 C1.translation=G3D::Vector3(0,.6f,0);
 G3D::CoordinateFrame seatSpace=getCoordinateFrame()*C0;
 G3D::CoordinateFrame desired=seatSpace*C1.inverse();
 Primitive*torso=h->getTorsoPrimitive();
 Primitive*root=torso->getAssembly()->getMainPrimitive();
 if(root==torso){torso->setCoordinateFrame(desired);torso->setVelocity(Velocity::zero());}
 else{
  G3D::CoordinateFrame relative=torso->getCoordinateFrame().toObjectSpace(root->getCoordinateFrame());
  G3D::CoordinateFrame rootFrame=desired*relative;
  root->setCoordinateFrame(rootFrame);
  root->setVelocity(Velocity::zero());
 }
 G3D::CoordinateFrame seatJoint=getCoordinateFrame()*C0;
 G3D::CoordinateFrame torsoJoint=torso->getCoordinateFrame()*C1;
 weld=createSeatJoint();
 {ImportedString name("SeatWeld");weld->setName(name);}
 weld->setPart0(this);
 weld->setPart1(h->getTorso());
 weld->setC0(C0);weld->setC1(C1);weld->setParent(this);
}
}
