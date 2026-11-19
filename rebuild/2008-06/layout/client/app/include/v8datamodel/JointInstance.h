#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "v8world/Joint.h"
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
#include "util/IRenderable.h"
#include "reflection/reflection.h"

namespace RBX {
extern const char sJointInstance[];
class JointInstance : public DescribedNonCreatable<JointInstance, Instance, sJointInstance>, public IRenderable, public IJointOwner {
private:
    boost::weak_ptr<PartInstance> part[2];   // +0x140 / +0x148
protected:
    Joint* joint;                            // +0x150
    void setPart(int i, PartInstance* value);                       // 005e2cd0
    virtual bool askSetParent(const Instance* instance) const;      // 005e3790
    virtual void onAncestorChanged(const AncestorChanged& event);   // 005e3a80
    virtual bool shouldRender3dAdorn() const;                       // 005e27a0
    virtual void render3dAdorn(Adorn* adorn);                       // 005e2af0
public:
    JointInstance(Joint* joint);             // 005e3870
    ~JointInstance();                        // 005e2e10
    Joint::JointType getJointType() const;
    PartInstance* getPart0() const;          // 005e2a10
    PartInstance* getPart1() const;          // 005e2a70
};

extern const char sAutoJoint[];
class AutoJoint : public DescribedNonCreatable<AutoJoint, JointInstance, sAutoJoint> {
private:
    void setPartNull(int);
    void setPrimitiveFromPart(int);
    World* computeWorld();
public:
    AutoJoint(Joint* joint);
    virtual ~AutoJoint();
    void setPart0(PartInstance* value);
    void setPart1(PartInstance* value);
    const G3D::CoordinateFrame& getC0() const;
    const G3D::CoordinateFrame& getC1() const;
    void setC0(const G3D::CoordinateFrame& value);
    void setC1(const G3D::CoordinateFrame& value);
};

extern const char sSnap[];
// INFERRED: binary RTTI/bindings bind DescribedCreatable<Snap, JointInstance, sSnap> (all 7 joint classes use
class Snap : public DescribedCreatable<Snap, JointInstance, sSnap> { public: Snap(Joint* joint); Snap(); };
extern const char sWeld[];
// INFERRED: 2008 binary RTTI binds the vftable/deleting-dtor thunks stored by Weld's ctors at 005e4710/005e4810 to
class Weld : public DescribedCreatable<Weld, JointInstance, sWeld> { public: Weld(Joint* joint); Weld(); };
extern const char sGlue[];
class Glue : public DescribedCreatable<Glue, JointInstance, sGlue> { public: Glue(Joint* joint); Glue(); };
extern const char sRotate[];
class Rotate : public DescribedCreatable<Rotate, JointInstance, sRotate> { public: Rotate(Joint* joint); Rotate(); };
extern const char sRotateP[];
class RotateP : public DescribedCreatable<RotateP, JointInstance, sRotateP> { public: RotateP(Joint* joint); RotateP(); };
extern const char sRotateV[];
class RotateV : public DescribedCreatable<RotateV, JointInstance, sRotateV> { public: RotateV(Joint* joint); RotateV(); };
extern const char sMotor[];
// INFERRED: binary layout requires maxVelocity at offset +0x154, desiredAngle at +0x158, currentAngle at +0x15c
// within the Motor class sub-object (following JointInstance base at +0x140/class size 0x144).
class Motor : public DescribedCreatable<Motor, JointInstance, sMotor> {
private:
    const MotorJoint* getMotorJoint() const;
    MotorJoint* getMotorJoint();
    void renderJointCylinder(Adorn*, int);
public:
    Motor(Joint* joint);
    Motor();
    float getMaxVelocity() const;
    void setMaxVelocity(float value);
    float getDesiredAngle() const;
    void setDesiredAngle(float value);
    float getCurrentAngle() const;
    void setCurrentAngle(float value);
};
}
