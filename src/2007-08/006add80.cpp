// from server: 49% by colin
// roc 2007-08 006add80  unit: CXTPRibbonTheme  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006add80
//
// 006add80  8939                 mov dword ptr [ecx], edi
// 006add82  895904               mov dword ptr [ecx + 4], ebx
// 006add85  896908               mov dword ptr [ecx + 8], ebp
// 006add88  33d2                 xor edx, edx
// 006add8a  89510c               mov dword ptr [ecx + 0xc], edx
// 006add8d  8b10                 mov edx, dword ptr [eax]
// 006add8f  83ec10               sub esp, 0x10
// 006add92  8bcc                 mov ecx, esp
// 006add94  8911                 mov dword ptr [ecx], edx
// 006add96  8b5004               mov edx, dword ptr [eax + 4]
// 006add99  895104               mov dword ptr [ecx + 4], edx
// 006add9c  8b5008               mov edx, dword ptr [eax + 8]
// 006add9f  8b400c               mov eax, dword ptr [eax + 0xc]
// 006adda2  895108               mov dword ptr [ecx + 8], edx
// 006adda5  8b9424a0000000       mov edx, dword ptr [esp + 0xa0]
// 006addac  89410c               mov dword ptr [ecx + 0xc], eax
// 006addaf  8d4c2460             lea ecx, [esp + 0x60]
// 006addb3  51                   push ecx
// 006addb4  52                   push edx
// 006addb5  8bce                 mov ecx, esi
// 006addb7  e8e41a0600           call 0x70f8a0
// 006addbc  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 006addc0  64890d00000000       mov dword ptr fs:[0], ecx
// 006addc7  59                   pop ecx
// 006addc8  5f                   pop edi
// 006addc9  5e                   pop esi
// 006addca  5d                   pop ebp
// 006addcb  5b                   pop ebx
// 006addcc  83c468               add esp, 0x68
// 006addcf  c20800               ret 8

struct CXTPRibbonTheme
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    void func_006add80(int* src, int arg2);
};

extern "C" void __stdcall func_0070f8a0(int* dst, int arg2, int* src);

void CXTPRibbonTheme::func_006add80(int* src, int arg2)
{
    field0 = 0;
    field4 = 0;
    field8 = 0;
    fieldC = 0;

    int tmp[4];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    tmp[3] = src[3];

    func_0070f8a0(tmp, arg2, &fieldC);
}
