// from server: 100% by colin
struct RBX_ModelInstance {
    char pad[0x134];
    int field_134;
    int method(int, int);
};

extern "C" int __stdcall sub_6098d0(int, int);

int RBX_ModelInstance::method(int a, int b) {
    if (b != 0) {
        field_134 = 0x830fac;
    }
    sub_6098d0(a, 0);
    int v = field_134;
    *(int*)((char*)this + 0x00) = 0x830c2c;
    *(int*)((char*)this + 0x10) = 0x830c1c;
    *(int*)((char*)this + 0x14) = 0x830c14;
    *(int*)((char*)this + 0x20) = 0x830c0c;
    *(int*)((char*)this + 0x24) = 0x830bfc;
    *(int*)((char*)this + 0x44) = 0x830bec;
    *(int*)((char*)this + 0x64) = 0x830bdc;
    *(int*)((char*)this + 0x84) = 0x830bcc;
    *(int*)((char*)this + 0xa4) = 0x830bbc;
    *(int*)((char*)this + 0xc4) = 0x830bac;
    *(int*)((char*)this + 0x130) = 0x830ba0;
    int* p = *(int**)(v + 4);
    *(int*)((char*)p + (int)this + 0x134) = 0x830b94;
    int* q = *(int**)(field_134 + 8);
    *(int*)((char*)q + (int)this + 0x134) = 0x830b8c;
    return (int)this;
}
