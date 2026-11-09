// from server: 100% by nuck16
// roc 2009-12 00749420  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00749420
//
// 00749420  c7014c3c9e00         mov dword ptr [ecx], 0x9e3c4c
// 00749426  c74104443c9e00       mov dword ptr [ecx + 4], 0x9e3c44
// 0074942d  c74118383c9e00       mov dword ptr [ecx + 0x18], 0x9e3c38
// 00749434  c7411c303c9e00       mov dword ptr [ecx + 0x1c], 0x9e3c30
// 0074943b  c78194000000203c9e00 mov dword ptr [ecx + 0x94], 0x9e3c20
// 00749445  c78198000000083c9e00 mov dword ptr [ecx + 0x98], 0x9e3c08
// 0074944f  e9ccf7ffff           jmp 0x748c20

extern "C" void func_748c20();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e3c4c;
    *(int *)((char *)this + 0x4) = 0x9e3c44;
    *(int *)((char *)this + 0x18) = 0x9e3c38;
    *(int *)((char *)this + 0x1c) = 0x9e3c30;
    *(int *)((char *)this + 0x94) = 0x9e3c20;
    *(int *)((char *)this + 0x98) = 0x9e3c08;
    func_748c20();
}
