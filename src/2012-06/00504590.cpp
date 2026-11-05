// from server: 100% by Intel
struct OgreRbxMeshPartAdapter {
    char pad[8];
    void* member;

    void* __thiscall func(void* out);
};

void* __thiscall OgreRbxMeshPartAdapter::func(void* out) {
    void* value = this->member;
    *static_cast<void**>(out) = value;
    return out;
}
