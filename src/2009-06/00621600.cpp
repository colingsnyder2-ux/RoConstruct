// from server: 96% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_c13a3e5cf94b0124.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include "G3D/Vector3.h"
namespace RBX {
class Instance { public:
    virtual ~Instance();
    char pad[0x100];
    Instance* next;
};

struct ServiceProvider : Instance {
    ServiceProvider* finish();
};

class HopperBin : public Instance {};
class Tool : public Instance {};
}

extern RBX::ServiceProvider* __cdecl func_00590d80(RBX::Instance*);
extern "C" int (__stdcall *messageBox)(void*, const char*, const char*, unsigned int);

struct RawV3 { float x, y, z; };
struct Bounds {
    G3D::Vector3 low;
    G3D::Vector3 high;
    G3D::Vector3 center() const { return (this->high + this->low) * 0.5f; }
};

struct Collection {
    char pad[12];
    RBX::Instance** first;
    RBX::Instance** last;
};

struct Camera { void lookAt(const G3D::Vector3&); };
struct ICameraOwner {
    virtual ~ICameraOwner();
    virtual Camera* getCamera();
};

struct Item : RBX::Instance {
    void assign(RBX::ServiceProvider*);
};

extern Bounds __cdecl computeExtents(Collection*);
extern const float midpointScale;
extern const char insertionCaption[];
extern const char insertionQuestion[];

struct RootInstance : RBX::Instance {
    char reserved[0x10];
    ICameraOwner position;

    void insert(Collection*, Collection*, int, bool);
    void getInsertPoint(struct RawV3*);
    void moveTo(Collection*, struct RawV3*);
    void process(Collection*, RootInstance*, Collection*);
    void prepare(Collection*);
};

void RootInstance::insert(Collection* input, Collection* output, int suppressPrompt, bool noCamera)
{
    if (((unsigned int)((char*)input->last - (char*)input->first) & ~7U) == 8) {
        RBX::Instance* item = *input->first;
        if (dynamic_cast<RBX::HopperBin*>(item)) {
            ((Item*)item)->assign(func_00590d80(this));
            return;
        }
        if (dynamic_cast<RBX::Tool*>(item) && !suppressPrompt) {
            ((Item*)item)->assign(func_00590d80(this));
            return;
        }
    }

    RawV3 pos;
    getInsertPoint(&pos);
    process(input, this, output);
    if (!noCamera && ((unsigned int)((char*)output->last - (char*)output->first) & ~7U) != 0) {
        moveTo(output, &pos);
        Bounds bounds = computeExtents(output);
        G3D::Vector3& v = reinterpret_cast<G3D::Vector3&>(pos);
        v = bounds.center();
        position.getCamera()->lookAt(v);
    }
}
