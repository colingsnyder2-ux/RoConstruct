// from server: 100% by Xemicl
// roc 2012-06 00675a40  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00675a40
//
// 00675a40  55                   push ebp
// 00675a41  8bec                 mov ebp, esp
// 00675a43  51                   push ecx
// 00675a44  894dfc               mov dword ptr [ebp - 4], ecx
// 00675a47  8b45fc               mov eax, dword ptr [ebp - 4]
// 00675a4a  81380090d003         cmp dword ptr [eax], 0x3d09000
// 00675a50  7209                 jb 0x675a5b
// 00675a52  b800040000           mov eax, 0x400
// 00675a57  eb07                 jmp 0x675a60
// 00675a59  eb05                 jmp 0x675a60
// 00675a5b  b800020000           mov eax, 0x200
// 00675a60  8be5                 mov esp, ebp
// 00675a62  5d                   pop ebp
// 00675a63  c3                   ret 
// copied from an identical function in another client (function ?f@C@@QAEHXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct C { unsigned int n; int f(); };
int C::f()
{
    if (n >= 0x3d09000)
        return 0x400;
    else
        return 0x200;
}