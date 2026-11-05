// from server: 44% by atomic.potato
struct RbxSpatialHashedSceneNode {
    char pad0[0x1c4];
    void* field1c4;
    char pad1c8[4];
    int field1cc;
    int field1d0;
    int field1d4;
    float field1d8;
    float field1dc;
    float field1e0;
    RbxSpatialHashedSceneNode(void* mgr);
};

struct Alloc8 {
    void ctor(int, int, int);
};

extern "C" void* __stdcall sub_a41478(void*);
extern "C" void* __cdecl sub_80a05e(unsigned int);

RbxSpatialHashedSceneNode::RbxSpatialHashedSceneNode(void* mgr) {
    sub_a41478(mgr);
    *(void**)this = (void*)0xaf83c4;
    field1cc = 0;
    field1d0 = 0;
    field1d4 = 0;
    field1d8 = 0.0f;
    field1dc = 0.0f;
    field1e0 = 0.0f;
    Alloc8* p = (Alloc8*)sub_80a05e(0xc4);
    if (p != 0) {
        p->ctor(0, 0, 8);
        field1c4 = p;
    } else {
        field1c4 = 0;
    }
}
