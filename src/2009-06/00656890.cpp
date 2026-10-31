// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c90b0  unit: RBX::LaserTool  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c90b0
//
// 005c90b0  8b442404             mov eax, dword ptr [esp + 4]
// 005c90b4  dd00                 fld qword ptr [eax]
// 005c90b6  83ec08               sub esp, 8
// 005c90b9  dd1c24               fstp qword ptr [esp]
// 005c90bc  68c8358100           push 0x8135c8
// 005c90c1  dd00                 fld qword ptr [eax]
// 005c90c3  83ec08               sub esp, 8
// 005c90c6  dd1c24               fstp qword ptr [esp]
// 005c90c9  51                   push ecx
// 005c90ca  e851feffff           call 0x5c8f20
// 005c90cf  83c418               add esp, 0x18
// 005c90d2  c20400               ret 4

extern void __cdecl formatValue(void *, double, const char *, ...);

struct LaserTool {
    void setValue(const double &value);
};

void LaserTool::setValue(const double &value)
{
    formatValue(this, value, "%.3g", value);
}
