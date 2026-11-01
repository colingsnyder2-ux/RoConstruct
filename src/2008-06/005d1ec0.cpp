// from server: 100% by EspClaude
// from server: 74% by king_originala
// roc 2008-06 005d1ec0  unit: RBX::VSpawnerService::?$FactoryProduct  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d1ec0
//

#include <intrin.h>

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();

    long strong;
    long weak;
};

struct Object {
    char padding[0x104];
    void* instance;
};

struct Shared {
    Object* object;
    Control* control;

    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct BrickColor {
    int value;
};

struct Player {
    void setTeamColor(BrickColor color);
    void setNeutral(bool neutral);
};

int __cdecl checkInstance(void* instance);
Player* __cdecl getPlayer(void* instance);

struct S {
    char padding0[0x3e8];
    BrickColor color;
    char padding1[0x14];
    bool neutral;
    bool enabled;

    void f(Shared object);
    BrickColor getTeamColor() const { return color; }
};

void S::f(Shared object)
{
    if (!enabled)
        return;

    void* instance = object.object->instance;
    if (instance && checkInstance(instance)) {
        Player* player = getPlayer(instance);
        if (player) {
            player->setTeamColor(getTeamColor());
            player->setNeutral(neutral);
        }
    }
}
