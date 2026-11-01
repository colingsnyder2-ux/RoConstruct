// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_98798bdc32050787.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
namespace RBX {
class PartInstance;
class Pad { public: virtual ~Pad(); char pad[0x20]; };
class Instance : public Pad, public boost::enable_shared_from_this<Instance> {
public:
    char pad2[0x48 - 0x2c];
    Instance* parent;
    Instance* getParent() const { return parent; }
    Instance* findFirstChildByName(const std::string& name);
};
boost::shared_ptr<PartInstance> __cdecl acquire(boost::enable_shared_from_this<Instance>* p);
class Humanoid : public Instance {
public:
    PartInstance* getLeftArm();
};
PartInstance* Humanoid::getLeftArm()
{
    boost::shared_ptr<PartInstance> part;
    if (getParent()) {
        part = acquire(getParent()->findFirstChildByName("Left Arm"));
    }
    return part.get();
}
}
