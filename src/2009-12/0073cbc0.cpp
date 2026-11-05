// from server: 100% by nuck16
// roc 2009-12 0073cbc0  unit: G3D::VVector2::?$TypedPropertyDescriptor  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073cbc0
//
// 0073cbc0  c701f41f9e00         mov dword ptr [ecx], 0x9e1ff4
// 0073cbc6  c74104e81f9e00       mov dword ptr [ecx + 4], 0x9e1fe8
// 0073cbcd  c74118dc1f9e00       mov dword ptr [ecx + 0x18], 0x9e1fdc
// 0073cbd4  c7411cd41f9e00       mov dword ptr [ecx + 0x1c], 0x9e1fd4
// 0073cbdb  c78194000000c41f9e00 mov dword ptr [ecx + 0x94], 0x9e1fc4
// 0073cbe5  c78198000000ac1f9e00 mov dword ptr [ecx + 0x98], 0x9e1fac
// 0073cbef  e93cae0000           jmp 0x747a30

extern "C" void func_747a30();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e1ff4;
    *(int *)((char *)this + 0x4) = 0x9e1fe8;
    *(int *)((char *)this + 0x18) = 0x9e1fdc;
    *(int *)((char *)this + 0x1c) = 0x9e1fd4;
    *(int *)((char *)this + 0x94) = 0x9e1fc4;
    *(int *)((char *)this + 0x98) = 0x9e1fac;
    func_747a30();
}
