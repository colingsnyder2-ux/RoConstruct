// from server: 100% by Intel
struct VTable {
    void* gap[13];
    void (__thiscall* func)(void*);
};

struct Interface {
    VTable* vptr;
};

struct Member {
    Interface* ptr;
};

struct OgreRbxMeshPartAdapter {
    char pad[0x44];
    Member member;

    void __thiscall func();
};

void __thiscall OgreRbxMeshPartAdapter::func() {
    Interface* iface = this->member.ptr;
    VTable* vtable = iface->vptr;
    void (__thiscall* target)(void*) = vtable->func;
    target(iface);
}
