// from server: 81% by colin
// roc 2011-06 009464e0 45 bytes
// library g3d-6.09/GLG3Dcpp\RenderDevice.cpp

struct RbxSceneNode {
    char pad[0x1c4];
    int field_1c4;
    int field_1c8;
    bool method(int);
};

extern "C" void __stdcall sub_5c9a30(int*, int*);

bool RbxSceneNode::method(int arg) {
    int local;
    sub_5c9a30(&this->field_1c4, &local);
    return local != this->field_1c8;
}
