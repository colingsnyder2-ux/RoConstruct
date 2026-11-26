// from server: 100% by Xemicl
// roc 2012-06 006270e0  unit: seg_00620000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006270e0
//
// 006270e0  55                   push ebp
// 006270e1  8bec                 mov ebp, esp
// 006270e3  51                   push ecx
// 006270e4  894dfc               mov dword ptr [ebp - 4], ecx
// 006270e7  8b45fc               mov eax, dword ptr [ebp - 4]
// 006270ea  8b00                 mov eax, dword ptr [eax]
// 006270ec  034508               add eax, dword ptr [ebp + 8]
// 006270ef  8be5                 mov esp, ebp
// 006270f1  5d                   pop ebp
// 006270f2  c20400               ret 4
// copied from an identical function in another client (function ?f@S_005bacd0@@QAEPAHH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /EHsc /MD
struct S_005bacd0 { int* p; int* f(int); };
int* S_005bacd0::f(int i) { return (int*)((char*)p + i); }