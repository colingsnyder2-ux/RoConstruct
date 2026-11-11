// from server: 100% by EspClaude
// roc 2007-08 0040a630  unit: VCApp::?$CComObject  size: 33 bytes
// 0040a630  83ec10               sub esp, 0x10
// 0040a633  8d0424               lea eax, [esp]
// 0040a636  50                   push eax
// 0040a637  b924be8b00           mov ecx, 0x8bbe24
// 0040a63c  e8bff70100           call 0x429e00
// 0040a641  8d0c24               lea ecx, [esp]
// 0040a644  e817fcffff           call 0x40a260
// 0040a649  33c0                 xor eax, eax
// 0040a64b  83c410               add esp, 0x10
// 0040a64e  c20400               ret 4

struct Local16
{
    void* p[4];
    void __thiscall Cleanup();
};

struct GlobalObj
{
    void __thiscall Get(Local16* out);
};

extern GlobalObj g_obj_8bbe24;

int __stdcall func_0040A630(int arg)
{
    Local16 local;
    g_obj_8bbe24.Get(&local);
    local.Cleanup();
    return 0;
}
