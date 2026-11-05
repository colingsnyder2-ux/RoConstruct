// from server: 46% by colin
// roc 2007-08 00592e00  unit: RBX::VVisit::BoundFuncDesc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00592e00
//
// 00592e00  89642458             mov dword ptr [esp + 0x58], esp
// 00592e04  50                   push eax
// 00592e05  ff159ce67700         call dword ptr [0x77e69c]
// 00592e0b  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00592e0e  8b4628               mov eax, dword ptr [esi + 0x28]
// 00592e11  03cf                 add ecx, edi
// 00592e13  ffd0                 call eax
// 00592e15  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00592e19  85c9                 test ecx, ecx
// 00592e1b  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00592e20  7408                 je 0x592e2a
// 00592e22  8b11                 mov edx, dword ptr [ecx]
// 00592e24  8b02                 mov eax, dword ptr [edx]
// 00592e26  6a01                 push 1
// 00592e28  ffd0                 call eax
// 00592e2a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00592e2e  85c9                 test ecx, ecx
// 00592e30  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00592e38  7408                 je 0x592e42
// 00592e3a  8b11                 mov edx, dword ptr [ecx]
// 00592e3c  8b02                 mov eax, dword ptr [edx]
// 00592e3e  6a01                 push 1
// 00592e40  ffd0                 call eax
// 00592e42  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00592e46  5f                   pop edi
// 00592e47  64890d00000000       mov dword ptr fs:[0], ecx
// 00592e4e  5e                   pop esi
// 00592e4f  83c428               add esp, 0x28
// 00592e52  c20800               ret 8
// library g3d-6.09/G3Dcpp\debugAssert.cpp (function ?setAssertionHook@G3D@@YAXP6A_NPBDABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0HAA_N_N@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 G3Dcpp/debugAssert.cpp

extern "C" void* __stdcall GetCurrentSEH(void*);

struct RefCounted {
    virtual void release(int);
};

struct BoundFuncDesc {
    char pad0[0x28];
    void (*fn)(void*);
    char* ctx;
    void destroy();
};

void BoundFuncDesc::destroy()
{
    void* seh = GetCurrentSEH(0);
    fn((char*)ctx + (int)seh);
    RefCounted* a = *(RefCounted**)((char*)this + 0x0c);
    if (a) {
        a->release(1);
    }
    RefCounted* b = *(RefCounted**)((char*)this + 0x14);
    if (b) {
        b->release(1);
    }
}
