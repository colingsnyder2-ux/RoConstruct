// from server: 100% by colin
// roc 2007-08 00596c70  unit: RBX::LaserTool  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00596c70
//
// 00596c70  8b442404             mov eax, dword ptr [esp + 4]
// 00596c74  dd00                 fld qword ptr [eax]
// 00596c76  83ec08               sub esp, 8
// 00596c79  dd1c24               fstp qword ptr [esp]
// 00596c7c  6898d37800           push 0x78d398
// 00596c81  dd00                 fld qword ptr [eax]
// 00596c83  83ec08               sub esp, 8
// 00596c86  dd1c24               fstp qword ptr [esp]
// 00596c89  51                   push ecx
// 00596c8a  e851feffff           call 0x596ae0
// 00596c8f  83c418               add esp, 0x18
// 00596c92  c20400               ret 4
// copied from an identical function in another client (function ?setValue@LaserTool@@QAEXABN@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern void __cdecl formatValue(void *, double, const char *, ...);

struct LaserTool {
    void setValue(const double &value);
};

void LaserTool::setValue(const double &value)
{
    formatValue(this, value, "%.3g", value);
}