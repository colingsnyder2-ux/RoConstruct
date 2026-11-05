// from server: 55% by colin
// roc 2007-08 00592af0  unit: RBX::VVisit::?$BoundFuncDesc  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00592af0
//
// 00592af0  8964244c             mov dword ptr [esp + 0x4c], esp
// 00592af4  50                   push eax
// 00592af5  ff159ce67700         call dword ptr [0x77e69c]
// 00592afb  8b4f2c               mov ecx, dword ptr [edi + 0x2c]
// 00592afe  8b5728               mov edx, dword ptr [edi + 0x28]
// 00592b01  03ce                 add ecx, esi
// 00592b03  ffd2                 call edx
// 00592b05  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00592b09  85c9                 test ecx, ecx
// 00592b0b  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00592b13  7408                 je 0x592b1d
// 00592b15  8b01                 mov eax, dword ptr [ecx]
// 00592b17  8b10                 mov edx, dword ptr [eax]
// 00592b19  6a01                 push 1
// 00592b1b  ffd2                 call edx
// 00592b1d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00592b21  5f                   pop edi
// 00592b22  64890d00000000       mov dword ptr fs:[0], ecx
// 00592b29  5e                   pop esi
// 00592b2a  83c420               add esp, 0x20
// 00592b2d  c20800               ret 8

struct S {
    char pad[0x28];
    int field28;
    int field2c;
    void method(int, int);
};

extern "C" void __stdcall sub_77e69c();

void S::method(int a, int b)
{
    sub_77e69c();
    int (*fn)(void*, int) = (int (*)(void*, int))field2c;
    fn((char*)this + field28, a);
    void* p = *(void**)((char*)&a + 4);
    if (p) {
        void** vt = *(void***)p;
        ((void (__thiscall*)(void*, int))vt[0])(p, 1);
    }
}
