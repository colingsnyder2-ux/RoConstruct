// from server: 74% by colin
// roc 2007-08 00644400  unit: CXTPCommandBar  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00644400
//
// 00644400  0000                 add byte ptr [eax], al
// 00644402  00ff                 add bh, bh
// 00644404  7519                 jne 0x64441f
// 00644406  83be2801000000       cmp dword ptr [esi + 0x128], 0
// 0064440d  7510                 jne 0x64441f
// 0064440f  8b06                 mov eax, dword ptr [esi]
// 00644411  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 00644417  6a00                 push 0
// 00644419  6aff                 push -1
// 0064441b  8bce                 mov ecx, esi
// 0064441d  ffd2                 call edx
// 0064441f  5e                   pop esi
// 00644420  c3                   ret 

struct CXTPCommandBar
{
    void func_00644400();
};

void CXTPCommandBar::func_00644400()
{
    if (*(unsigned char*)((char*)this + 0x00) != 0)
        return;
    if (*(int*)((char*)this + 0x128) != 0)
        return;
    void (__thiscall *fn)(CXTPCommandBar*, int, int) = *(void (__thiscall **)(CXTPCommandBar*, int, int))((*(char**)this) + 0x148);
    fn(this, -1, 0);
}
