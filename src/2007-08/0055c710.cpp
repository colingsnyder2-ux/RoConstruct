// from server: 61% by colin
// roc 2007-08 0055c710  unit: RBX::VDataModel::?$BoundFuncDesc  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055c710
//
// 0055c710  8964244c             mov dword ptr [esp + 0x4c], esp
// 0055c714  50                   push eax
// 0055c715  ff159ce67700         call dword ptr [0x77e69c]
// 0055c71b  8b4f2c               mov ecx, dword ptr [edi + 0x2c]
// 0055c71e  8b5728               mov edx, dword ptr [edi + 0x28]
// 0055c721  03ce                 add ecx, esi
// 0055c723  ffd2                 call edx
// 0055c725  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055c729  85c9                 test ecx, ecx
// 0055c72b  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0055c733  7408                 je 0x55c73d
// 0055c735  8b01                 mov eax, dword ptr [ecx]
// 0055c737  8b10                 mov edx, dword ptr [eax]
// 0055c739  6a01                 push 1
// 0055c73b  ffd2                 call edx
// 0055c73d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0055c741  5f                   pop edi
// 0055c742  64890d00000000       mov dword ptr fs:[0], ecx
// 0055c749  5e                   pop esi
// 0055c74a  83c420               add esp, 0x20
// 0055c74d  c20800               ret 8

struct BoundFuncDesc {
    void construct(char* dst, const char* src);
};

extern "C" void __stdcall sub_77E69C();

void BoundFuncDesc::construct(char* dst, const char* src)
{
    char* saved;
    saved = dst;
    sub_77E69C();
    void (__thiscall *fn)(void*, int);
    fn = *(void (__thiscall **)(void*, int))((char*)this + 0x28);
    int arg = *(int*)((char*)this + 0x2c);
    fn((char*)this + 0x2c, arg);
    void* p = *(void**)(dst + 0xc);
    *(int*)(dst + 0x24) = -1;
    if (p) {
        void** vt = *(void***)p;
        void (__thiscall *dtor)(void*, int) = (void (__thiscall *)(void*, int))vt[0];
        dtor(p, 1);
    }
}
