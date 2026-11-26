// from server: 100% by Xemicl
// roc 2012-06 00759f50  unit: RBX::VPartInstance::?$EventDesc  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00759f50
//
// 00759f50  8b442404             mov eax, dword ptr [esp + 4]
// 00759f54  8b00                 mov eax, dword ptr [eax]
// 00759f56  50                   push eax
// 00759f57  89442408             mov dword ptr [esp + 8], eax
// 00759f5b  db442408             fild dword ptr [esp + 8]
// 00759f5f  689c0db500           push 0xb50d9c
// 00759f64  85c0                 test eax, eax
// 00759f66  7d06                 jge 0x759f6e
// 00759f68  dc0578fdb400         fadd qword ptr [0xb4fd78]
// 00759f6e  83ec08               sub esp, 8
// 00759f71  dd1c24               fstp qword ptr [esp]
// 00759f74  51                   push ecx
// 00759f75  e866feffff           call 0x759de0
// 00759f7a  83c414               add esp, 0x14
// 00759f7d  c20400               ret 4
// copied from an identical function in another client (function ?setValue@LaserTool@ns_ROCX000014@@QAEXPBI@Z)

namespace ns_ROCX000014 {
struct LaserTool {
    void setValue(const unsigned int *value);
};

extern const char message[];
extern void __cdecl report(LaserTool *, double, const char *, unsigned int);

void LaserTool::setValue(const unsigned int *value)
{
    unsigned int n = *value;
    report(this, (double)n, message, n);
}
}