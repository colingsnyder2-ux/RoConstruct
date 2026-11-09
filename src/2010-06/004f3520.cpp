// from server: 39% by atomic.potato
extern "C" void* __stdcall make_desc_004d12d0(const char*, int);
extern "C" void __stdcall sub_0067a200();
extern "C" int __stdcall sub_005a5510();

struct VReplicatorBoundFuncDesc {
    void* field_0;
    char pad_04[0x10];
    int field_14;
    char pad_18[0x20];
    int field_38;
    int field_3c;
    void* ctor(int a, int b, int c, int d);
};

void* VReplicatorBoundFuncDesc::ctor(int a, int b, int c, int d) {
    void* p = make_desc_004d12d0((const char*)a, b);
    sub_0067a200();
    this->field_0 = (void*)0xa1b3f8;
    this->field_38 = c;
    this->field_3c = d;
    *(int*)0xc18600 = *(int*)0xc18600 + 1;
    this->field_14 = sub_005a5510();
    return this;
}
