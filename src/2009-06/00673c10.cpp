// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_9889e1d4ffcdb015.cpp

// Candidate translation unit (score above; library headers required).
#undef _DEBUG
#define _DLL
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
namespace RBX {
class Instance;
class PartInstance;
class InstancePad0 { public: virtual ~InstancePad0(); char pad[0x20]; };
class Instance : public InstancePad0, public boost::enable_shared_from_this<Instance> {
public:
    char pad2[0x48 - 0x2c];
    Instance* parent;
    Instance* getParent() const { return parent; }
    Instance* findFirstChildByName(const std::string& name);
};
template<class T> boost::shared_ptr<T> shared_from_dynamic_cast(boost::enable_shared_from_this<Instance>* p);
class HumanoidX : public Instance { public: PartInstance* getTorso(); PartInstance* getLeftLeg(); PartInstance* getRightLeg(); };
PartInstance* HumanoidX::getTorso()
{
	boost::shared_ptr<PartInstance> leg;
	if (getParent())
		leg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Torso"));
	return leg.get();
}
PartInstance* HumanoidX::getLeftLeg()
{
	boost::shared_ptr<PartInstance> leg;
	if (getParent())
		leg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Left Leg"));
	return leg.get();
}
PartInstance* HumanoidX::getRightLeg()
{
	boost::shared_ptr<PartInstance> leg;
	if (getParent())
		leg = shared_from_dynamic_cast<PartInstance>(getParent()->findFirstChildByName("Right Leg"));
	return leg.get();
}
}
