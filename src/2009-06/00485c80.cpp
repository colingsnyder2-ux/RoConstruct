// from server: 100% by why2
struct RbxMeshPartAdapter {
    char pad[0x10];
    float value;
    void setValue(float v);
};

void RbxMeshPartAdapter::setValue(float v) {
    value = v;
}
