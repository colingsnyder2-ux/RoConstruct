// from server: 56% by atomic.potato
struct EdgeListBuilder {
    EdgeListBuilder();
    ~EdgeListBuilder();
    void addVertexData(const void* vd);
    void addIndexData(const void* id, unsigned int offset, int opType);
    void* build();
};

struct VertexData {
    void prepareForShadowVolume();
};

struct RbxTextureProxy {
    char pad0[4];
    int field4;
    void* field8;
    void* fieldC;
    char pad10[0xb8];
    char fieldC8;
    char padC9[3];
    void* fieldCC;

    void func();
};

extern "C" {
    void __stdcall sub_9eb6c0();
    void __stdcall sub_9eb6bc();
    void __stdcall sub_9eb6b8();
    void __stdcall sub_9eb6b4();
    void __stdcall sub_9eb6b0();
    void __stdcall sub_9eb6ac();
}

void RbxTextureProxy::func()
{
    if (fieldC8 == 0)
    {
        sub_9eb6c0();
        EdgeListBuilder elb;
        fieldC8 = 1;
        sub_9eb6bc();
        sub_9eb6b8();
        elb.addVertexData(field8);
        elb.addIndexData(fieldC, 0, field4);
        void* result = elb.build();
        fieldCC = result;
        sub_9eb6ac();
    }
}
