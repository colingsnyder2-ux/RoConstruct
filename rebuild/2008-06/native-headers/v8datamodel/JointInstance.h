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
// 2008 layout (bases: IRenderable +0x130, empty IJointOwner +0x140): the parts live on JointInstance, not AutoJoint.
// JointInstance(Joint*) 005e3870 constructs the weak_ptr pair at +0x140 (eh vector ctor, 2 x 8 bytes) and stores
// joint at +0x150; ~JointInstance 005e2e10 calls setPart(0/1, NULL) 005e2cd0, deletes joint +0x150 and destroys the
// pair (eh vector dtor, element dtor 005576e0); the getters 005e2a10 / 005e2a70 lock +0x140 / +0x148 (005cab00).
// VelocityMotor (Feature.h) derives from JointInstance and starts its fields at +0x154.
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
// JointInstance as the 2nd template arg; AutoJoint declarations here do not match the 2008 binary).
class Snap : public DescribedCreatable<Snap, JointInstance, sSnap> { public: Snap(Joint* joint); Snap(); };
extern const char sWeld[];
// INFERRED: 2008 binary RTTI binds the vftable/deleting-dtor thunks stored by Weld's ctors at 005e4710/005e4810 to
// FactoryProduct<Weld, JointInstance, sWeld> and DescribedCreatable<Weld, JointInstance, sWeld> (class-identity-bindings.json),
// so the template argument is JointInstance, not AutoJoint; the ctor bytes are unchanged.
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
