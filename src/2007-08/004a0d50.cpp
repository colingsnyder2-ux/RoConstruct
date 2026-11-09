// from server: 19% by 41k
struct BoundFuncDesc {
    int field0;
    int field4;
    int field8;
    void* fieldC;
    unsigned char field10;
    BoundFuncDesc* init();
};

BoundFuncDesc* BoundFuncDesc::init() {
    field0 = 0;
    field4 = 0x800;
    field8 = 0;
    fieldC = (char*)this + 0x11;
    field10 = 1;
    return this;
}
