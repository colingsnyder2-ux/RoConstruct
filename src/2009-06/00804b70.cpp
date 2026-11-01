// from server: 100% by auto
// roc 2009-06 00804b70  unit: CXTColorPageCustom  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804b70
//
// 00804b70  8b542404             mov edx, dword ptr [esp + 4]
// 00804b74  8bc1                 mov eax, ecx
// 00804b76  85d2                 test edx, edx
// 00804b78  7433                 je 0x804bad
// 00804b7a  56                   push esi
// 00804b7b  57                   push edi
// 00804b7c  8d7828               lea edi, [eax + 0x28]
// 00804b7f  b917000000           mov ecx, 0x17
// 00804b84  8bf2                 mov esi, edx
// 00804b86  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00804b88  8b4824               mov ecx, dword ptr [eax + 0x24]
// 00804b8b  85c9                 test ecx, ecx
// 00804b8d  741c                 je 0x804bab
// 00804b8f  8d74240c             lea esi, [esp + 0xc]
// 00804b93  56                   push esi
// 00804b94  52                   push edx
// 00804b95  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00804b9d  8b01                 mov eax, dword ptr [ecx]
// 00804b9f  8b500c               mov edx, dword ptr [eax + 0xc]
// 00804ba2  6a00                 push 0
// 00804ba4  6844040000           push 0x444
// 00804ba9  ffd2                 call edx
// 00804bab  5f                   pop edi
// 00804bac  5e                   pop esi
// 00804bad  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?SetDefaultCharFormat@CXTPRichRender@@QAEXPAU_charformatw@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
