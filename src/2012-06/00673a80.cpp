// from server: 100% by Xemicl
// roc 2012-06 00673a80  unit: RBX::AdornBillboarder  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00673a80
//
// 00673a80  55                   push ebp
// 00673a81  8bec                 mov ebp, esp
// 00673a83  51                   push ecx
// 00673a84  33c0                 xor eax, eax
// 00673a86  8845ff               mov byte ptr [ebp - 1], al
// 00673a89  0fb64dff             movzx ecx, byte ptr [ebp - 1]
// 00673a8d  51                   push ecx
// 00673a8e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00673a91  52                   push edx
// 00673a92  8b4508               mov eax, dword ptr [ebp + 8]
// 00673a95  50                   push eax
// 00673a96  e8c5000000           call 0x673b60
// 00673a9b  83c40c               add esp, 0xc
// 00673a9e  8be5                 mov esp, ebp
// 00673aa0  5d                   pop ebp
// 00673aa1  c3                   ret 
// copied from an identical function in another client (function ?f@@YAXPAH0@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Tag {};
void g(int* a, int* b, Tag t);
void f(int* a, int* b) { g(a, b, Tag()); }