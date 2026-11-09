// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_6d7830ecce99cc59.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
typedef std::vector<boost::shared_ptr<void> > Collection;
typedef std::string String;
struct Transform {
    float data[12];
};

struct Connection {
    char storage[4];
    void disconnect();
};

struct Part {
    void setParent(void*);
};

struct Context {
    void* getState();
    Transform getTransform(const Transform*, const String*);
};

struct Grip {
    char storage[4];
    void update(void*, Part*, const Transform&);
};

struct Tool {
    char padding0[0x48];
    void* parent;
    char padding1[0x8c - 0x4c];
    Grip grip;
    char padding2[0xc4 - 0x90];
    Transform transform;
    Connection connection;

    Part* getPart();
    void updateGrip();
};

extern "C" void __cdecl collect(Tool*, Collection&);
extern "C" void __cdecl prepare(const Collection&);
extern "C" Context* __cdecl getContext(void*);

void Tool::updateGrip()
{
    connection.disconnect();
    Collection objects;
    collect(this, objects);
    prepare(objects);
    void* p = parent;
    Context* context = getContext(p);
    if (!context)
        return;
    if (void* state = context->getState()) {
        if (Part* part = getPart()) {
            part->setParent(0);
            String name("HeadWeld");
            grip.update(state, part, context->getTransform(&transform, &name));
        }
    }
}


