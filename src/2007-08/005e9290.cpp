// from server: 40% by colin
struct PartInstance;
struct MegaClusterInstance;

struct Explosion {
    char pad[0x100];
    float x;
    float y;
    float z;
    char pad2[0x8];
    float blastRadius;

    void doBlast(MegaClusterInstance* terrain, void* parts);
};

struct Instance {
    char pad[0x64];
    void* primitive;
};

struct Primitive {
    char pad[0xa8];
    float px;
    float py;
    float pz;
};

extern "C" {
    void* __stdcall sub_570270(void*);
    bool __stdcall sub_727630(void*);
    void* __stdcall sub_573d40(void*);
    void __stdcall sub_530100(void*);
    void __stdcall sub_49d670(void*, void*, void*);
    void __stdcall sub_5e8da0(void*, void*);
}

struct Container {
    int count;
    void** items;
};

void Explosion::doBlast(MegaClusterInstance* terrain, void* partsPtr)
{
    Container* c = (Container*)partsPtr;
    int i;
    for (i = 0; i < c->count; i++) {
        Instance* inst = (Instance*)c->items[i];
        void** vtbl = *(void***)inst;
        float (*getRadius)(void*) = (float (*)(void*))vtbl[3];
        float r = getRadius(inst);
        if (r > this->blastRadius * 2.0f) {
            continue;
        }
        void* p = sub_573d40(inst);
        if (!p) {
            continue;
        }
        Primitive* prim = (Primitive*)inst->primitive;
        sub_530100(prim);
        float dx = prim->px - this->x;
        float dy = prim->py - this->y;
        float dz = prim->pz - this->z;
        float dist = dx*dy + dx*dy + dz*dz;
        float len = 0.0f;
        if (dist > 0.0f) {
            len = dist;
        }
        sub_49d670(p, &len, &len);
        sub_5e8da0(&this->x, 0);
    }
}
