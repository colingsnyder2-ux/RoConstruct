// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c9110  unit: RBX::LaserTool  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c9110
//
// 005c9110  8b442404             mov eax, dword ptr [esp + 4]
// 005c9114  8b00                 mov eax, dword ptr [eax]
// 005c9116  50                   push eax
// 005c9117  89442408             mov dword ptr [esp + 8], eax
// 005c911b  db442408             fild dword ptr [esp + 8]
// 005c911f  68d0358100           push 0x8135d0
// 005c9124  83ec08               sub esp, 8
// 005c9127  dd1c24               fstp qword ptr [esp]
// 005c912a  51                   push ecx
// 005c912b  e8f0fdffff           call 0x5c8f20
// 005c9130  83c414               add esp, 0x14
// 005c9133  c20400               ret 4

extern const char label[];
extern void __cdecl helper(void *, double, const char *, int);

struct LaserTool {
    void f(const int *value);
};

void LaserTool::f(const int *value)
{
    int n = *value;
    helper(this, (double)n, label, n);
}
