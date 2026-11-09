// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
#include <intrin.h>
#include <string>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& m);
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Matrix3& rotation, const Vector3& translation) : rotation(rotation), translation(translation) {}
};
}
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
const G3D::Matrix3& normalIdToMatrix3(NormalId id);
class Instance {
public:
    virtual ~Instance();
    virtual void setName(const std::string& name);
    void setParent(Instance* parent);
    Instance* getParent() const { return parent; }
private:
    char pad[0x104 - 4];
    Instance* parent;
};
class ModelInstance : public Instance {};
class PartInstance : public Instance {};
class AutoJoint : public Instance {
public:
    void setPart0(PartInstance* part);
    void setPart1(PartInstance* part);
    void setC0(const G3D::CoordinateFrame& c);
    void setC1(const G3D::CoordinateFrame& c);
};
boost::shared_ptr<AutoJoint> newJoint(bool);
class Humanoid : public Instance {
public:
    void buildJoints();
    static ModelInstance* getCharacterFromHumanoid(Humanoid* humanoid)
    {
        return humanoid ? dynamic_cast<ModelInstance*>(humanoid->getParent()) : 0;
    }
    PartInstance* getHead();
    PartInstance* getTorso();
    PartInstance* getRightArm();
    PartInstance* getLeftArm();
    PartInstance* getRightLeg();
    PartInstance* getLeftLeg();
};
void Humanoid::buildJoints()
	{
		ModelInstance* character = getCharacterFromHumanoid(this);

		if (!character)
			return;

		PartInstance* head = getHead();
		PartInstance* torso = getTorso();
		PartInstance* rightArm = getRightArm();
		PartInstance* leftArm = getLeftArm();
		PartInstance* rightLeg = getRightLeg();
		PartInstance* leftLeg = getLeftLeg();

		if (!torso)
			return;

		boost::shared_ptr<AutoJoint> rightShoulder = newJoint(true);
		boost::shared_ptr<AutoJoint> leftShoulder = newJoint(true);
		boost::shared_ptr<AutoJoint> rightHip = newJoint(true);
		boost::shared_ptr<AutoJoint> leftHip = newJoint(true);
		boost::shared_ptr<AutoJoint> neck = newJoint(false);

		rightShoulder->setName("Right Shoulder");
		leftShoulder->setName("Left Shoulder");
		rightHip->setName("Right Hip");
		leftHip->setName("Left Hip");
		neck->setName("Neck");

		rightShoulder->setPart0(torso);
		leftShoulder->setPart0(torso);
		rightHip->setPart0(torso);
		leftHip->setPart0(torso);
		neck->setPart0(torso);

		rightShoulder->setPart1(rightArm);
		leftShoulder->setPart1(leftArm);
		rightHip->setPart1(rightLeg);
		leftHip->setPart1(leftLeg);
		neck->setPart1(head);

		G3D::Matrix3 xPos = normalIdToMatrix3(NORM_X);
		G3D::Matrix3 xNeg = normalIdToMatrix3(NORM_X_NEG);
		G3D::Matrix3 yPos = normalIdToMatrix3(NORM_Y);

		G3D::CoordinateFrame rightShoulderP(xPos, G3D::Vector3(1.0f, 0.5f, 0.0f));
		G3D::CoordinateFrame leftShoulderP(xNeg, G3D::Vector3(-1.0f, 0.5f, 0.0f));
		G3D::CoordinateFrame rightHipP(xPos, G3D::Vector3(1.0f, -1.0f, 0.0f));
		G3D::CoordinateFrame leftHipP(xNeg, G3D::Vector3(-1.0f, -1.0f, 0.0f));
		G3D::CoordinateFrame neckP(yPos, G3D::Vector3(0.0f, 1.0f, 0.0f));

		G3D::CoordinateFrame rightArmP(xPos, G3D::Vector3(-0.5f, 0.5f, 0.0f));
		G3D::CoordinateFrame leftArmP(xNeg, G3D::Vector3(0.5f, 0.5f, 0.0f));
		G3D::CoordinateFrame rightLegP(xPos, G3D::Vector3(0.5f, 1.0f, 0.0f));
		G3D::CoordinateFrame leftLegP(xNeg, G3D::Vector3(-0.5f, 1.0f, 0.0f));
		G3D::CoordinateFrame headP(yPos, G3D::Vector3(0.0f, -0.5f, 0.0f));

		rightShoulder->setC0(rightShoulderP);
		leftShoulder->setC0(leftShoulderP);
		rightHip->setC0(rightHipP);
		leftHip->setC0(leftHipP);
		neck->setC0(neckP);

		rightShoulder->setC1(rightArmP);
		leftShoulder->setC1(leftArmP);
		rightHip->setC1(rightLegP);
		leftHip->setC1(leftLegP);
		neck->setC1(headP);

		rightShoulder->setParent(torso);
		leftShoulder->setParent(torso);
		rightHip->setParent(torso);
		leftHip->setParent(torso);
		neck->setParent(torso);
	}
}
