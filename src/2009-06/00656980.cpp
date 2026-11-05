// from server: 100% by EspClaude
// roc 2009-06 00656980  unit: RBX::Stats::Item  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00656980
//
// 00656980  8b442404             mov eax, dword ptr [esp + 4]
// 00656984  8b00                 mov eax, dword ptr [eax]
// 00656986  50                   push eax
// 00656987  89442408             mov dword ptr [esp + 8], eax
// 0065698b  db442408             fild dword ptr [esp + 8]
// 0065698f  68683b8b00           push 0x8b3b68
// 00656994  85c0                 test eax, eax
// 00656996  7d06                 jge 0x65699e
// 00656998  dc05c8178b00         fadd qword ptr [0x8b17c8]
// 0065699e  83ec08               sub esp, 8
// 006569a1  dd1c24               fstp qword ptr [esp]
// 006569a4  51                   push ecx
// 006569a5  e866feffff           call 0x656810
// 006569aa  83c414               add esp, 0x14
// 006569ad  c20400               ret 4
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
