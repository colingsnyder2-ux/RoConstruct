// from server: 100% by nuck16
// roc 2009-12 00757240  unit: RBX::ScreenGui  size: 62 bytes
//
// 00757240  c70184529e00         mov dword ptr [ecx], 0x9e5284
// 00757246  c741047c529e00       mov dword ptr [ecx + 4], 0x9e527c
// 0075724d  c7411870529e00       mov dword ptr [ecx + 0x18], 0x9e5270
// 00757254  c7411c68529e00       mov dword ptr [ecx + 0x1c], 0x9e5268
// 0075725b  c7819400000058529e00 mov dword ptr [ecx + 0x94], 0x9e5258
// 00757265  c7819800000040529e00 mov dword ptr [ecx + 0x98], 0x9e5240
// 0075726f  c781b800000034529e00 mov dword ptr [ecx + 0xb8], 0x9e5234
// 00757279  e9b2fdffff           jmp 0x757030

extern "C" void func_757030();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e5284;
    *(int *)((char *)this + 0x4) = 0x9e527c;
    *(int *)((char *)this + 0x18) = 0x9e5270;
    *(int *)((char *)this + 0x1c) = 0x9e5268;
    *(int *)((char *)this + 0x94) = 0x9e5258;
    *(int *)((char *)this + 0x98) = 0x9e5240;
    *(int *)((char *)this + 0xb8) = 0x9e5234;
    func_757030();
}
