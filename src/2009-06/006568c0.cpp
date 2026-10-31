// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c90e0  unit: RBX::LaserTool  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c90e0
//
// 005c90e0  8b442404             mov eax, dword ptr [esp + 4]
// 005c90e4  d900                 fld dword ptr [eax]
// 005c90e6  83ec08               sub esp, 8
// 005c90e9  dd1c24               fstp qword ptr [esp]
// 005c90ec  68c8358100           push 0x8135c8
// 005c90f1  d900                 fld dword ptr [eax]
// 005c90f3  83ec08               sub esp, 8
// 005c90f6  dd1c24               fstp qword ptr [esp]
// 005c90f9  51                   push ecx
// 005c90fa  e821feffff           call 0x5c8f20
// 005c90ff  83c418               add esp, 0x18
// 005c9102  c20400               ret 4

extern void __cdecl formatValue(void *, double, const char *, ...);

struct LaserTool {
    void setValue(const float &value);
};

void LaserTool::setValue(const float &value)
{
    formatValue(this, value, "%.3g", value);
}
