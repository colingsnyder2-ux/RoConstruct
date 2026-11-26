// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 00458cb0  unit: G3D::VColor3::?$XItem  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00458cb0
//
// 00458cb0  8b442404             mov eax, dword ptr [esp + 4]
// 00458cb4  85c0                 test eax, eax
// 00458cb6  7405                 je 0x458cbd
// 00458cb8  83c01c               add eax, 0x1c
// 00458cbb  eb02                 jmp 0x458cbf
// 00458cbd  33c0                 xor eax, eax
// 00458cbf  8b8930010000         mov ecx, dword ptr [ecx + 0x130]
// 00458cc5  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00458cc8  8b11                 mov edx, dword ptr [ecx]
// 00458cca  56                   push esi
// 00458ccb  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00458ccf  56                   push esi
// 00458cd0  50                   push eax
// 00458cd1  8b420c               mov eax, dword ptr [edx + 0xc]
// 00458cd4  ffd0                 call eax
// 00458cd6  5e                   pop esi
// 00458cd7  c20800               ret 8

struct S
{
    int value;
    int f(int *a, int b);
};

int S::f(int *a, int b)
{
    int *p = a ? a + 7 : 0;
    int *q = *(int **)((char *)this + 0x124);
    q = *(int **)((char *)q + 0x28);
    return ((int (__thiscall *)(int *, int *, int))(*(int ***)q)[3])(q, p, b);
}
