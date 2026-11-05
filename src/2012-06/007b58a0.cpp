// from server: 53% by Intel
struct VWedgeFactoryProduct {
    int f();
};

extern "C" int __stdcall sub_781230();
extern "C" void __stdcall sub_7B5600(int);

int VWedgeFactoryProduct::f() {
    int v;
    if (v) {
        *(int*)((char*)this + 0x84) = 0xBB92F8;
        *(int*)((char*)this + 0xB8) = 0xBB92F0;
    }
    sub_7B5600(0);
    int eax = sub_781230();
    *(int*)((char*)this + 0x28) = eax;
    ++* (int*)0xE48CBC;
    int edx = *(int*)((char*)this + 0x84);
    *(int*)this = 0xBB9244;
    *(int*)((char*)this + 4) = 0xBB923C;
    *(int*)((char*)this + 0x18) = 0xBB9230;
    *(int*)((char*)this + 0x1C) = 0xBB9224;
    *(int*)((char*)this + 0x80) = 0xBB921C;
    *(int*)((char*)this + 0x90) = 0xBB9204;
    *(int*)((char*)this + 0x9C) = 0xBB91D8;
    *(int*)((char*)this + 0xB4) = 0xBB91AC;
    *(int*)((char*)this + 0xC8) = 0xBB91A4;
    int ecx = *(int*)(edx + 4);
    *(int*)((char*)this + ecx + 0x84) = 0xBB919C;
    edx = *(int*)((char*)this + 0x84);
    eax = *(int*)(edx + 4);
    ecx = eax - 0x248;
    *(int*)((char*)this + eax + 0x80) = ecx;
    return (int)this;
}
