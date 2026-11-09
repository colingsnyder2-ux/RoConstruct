// from server: 64% by colin
// roc 2007-08 0060b7b0  unit: CXTCaptionButtonTheme  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060b7b0
//
// 0060b7b0  0100                 add dword ptr [eax], eax
// 0060b7b2  807e4c00             cmp byte ptr [esi + 0x4c], 0
// 0060b7b6  740f                 je 0x60b7c7
// 0060b7b8  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0060b7bb  8b5654               mov edx, dword ptr [esi + 0x54]
// 0060b7be  ffd2                 call edx
// 0060b7c0  d95e48               fstp dword ptr [esi + 0x48]
// 0060b7c3  c6464c00             mov byte ptr [esi + 0x4c], 0
// 0060b7c7  d94648               fld dword ptr [esi + 0x48]
// 0060b7ca  83ec08               sub esp, 8
// 0060b7cd  d905888a7a00         fld dword ptr [0x7a8a88]
// 0060b7d3  8d442410             lea eax, [esp + 0x10]
// 0060b7d7  d95c2404             fstp dword ptr [esp + 4]
// 0060b7db  8bcf                 mov ecx, edi
// 0060b7dd  d91c24               fstp dword ptr [esp]
// 0060b7e0  50                   push eax
// 0060b7e1  e8eacc0100           call 0x6284d0
// 0060b7e6  5f                   pop edi
// 0060b7e7  5e                   pop esi
// 0060b7e8  83c430               add esp, 0x30
// 0060b7eb  c3                   ret 

struct CXTCaptionButtonTheme
{
    char pad[0x48];
    float field_48;
    char field_4c;
    char pad2[3];
    void* field_50;
    void (__stdcall* field_54)();

    void func_0060b7b0();
};

extern float G_007a8a88;
extern void __stdcall func_006284d0(void*, float, float);

void CXTCaptionButtonTheme::func_0060b7b0()
{
    if (field_4c != 0)
    {
        field_54();
        field_48 = *(float*)&field_50;
        field_4c = 0;
    }
    float f = field_48;
    float g = G_007a8a88;
    float tmp;
    func_006284d0(&tmp, f, g);
}
