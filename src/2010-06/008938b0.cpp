// from server: 100% by auto
// roc 2010-06 008938b0  unit: CXTColorPageCustom  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008938b0
//
// 008938b0  8b542404             mov edx, dword ptr [esp + 4]
// 008938b4  8bc1                 mov eax, ecx
// 008938b6  85d2                 test edx, edx
// 008938b8  7433                 je 0x8938ed
// 008938ba  56                   push esi
// 008938bb  57                   push edi
// 008938bc  8d7828               lea edi, [eax + 0x28]
// 008938bf  b917000000           mov ecx, 0x17
// 008938c4  8bf2                 mov esi, edx
// 008938c6  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 008938c8  8b4824               mov ecx, dword ptr [eax + 0x24]
// 008938cb  85c9                 test ecx, ecx
// 008938cd  741c                 je 0x8938eb
// 008938cf  8d74240c             lea esi, [esp + 0xc]
// 008938d3  56                   push esi
// 008938d4  52                   push edx
// 008938d5  c744241400000000     mov dword ptr [esp + 0x14], 0
// 008938dd  8b01                 mov eax, dword ptr [ecx]
// 008938df  8b500c               mov edx, dword ptr [eax + 0xc]
// 008938e2  6a00                 push 0
// 008938e4  6844040000           push 0x444
// 008938e9  ffd2                 call edx
// 008938eb  5f                   pop edi
// 008938ec  5e                   pop esi
// 008938ed  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?SetDefaultCharFormat@CXTPRichRender@@QAEXPAU_charformatw@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
