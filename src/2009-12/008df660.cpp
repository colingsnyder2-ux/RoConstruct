// from server: 100% by auto
// roc 2009-12 008df660  unit: CXTColorPageCustom  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df660
//
// 008df660  8b542404             mov edx, dword ptr [esp + 4]
// 008df664  8bc1                 mov eax, ecx
// 008df666  85d2                 test edx, edx
// 008df668  7433                 je 0x8df69d
// 008df66a  56                   push esi
// 008df66b  57                   push edi
// 008df66c  8d7828               lea edi, [eax + 0x28]
// 008df66f  b917000000           mov ecx, 0x17
// 008df674  8bf2                 mov esi, edx
// 008df676  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 008df678  8b4824               mov ecx, dword ptr [eax + 0x24]
// 008df67b  85c9                 test ecx, ecx
// 008df67d  741c                 je 0x8df69b
// 008df67f  8d74240c             lea esi, [esp + 0xc]
// 008df683  56                   push esi
// 008df684  52                   push edx
// 008df685  c744241400000000     mov dword ptr [esp + 0x14], 0
// 008df68d  8b01                 mov eax, dword ptr [ecx]
// 008df68f  8b500c               mov edx, dword ptr [eax + 0xc]
// 008df692  6a00                 push 0
// 008df694  6844040000           push 0x444
// 008df699  ffd2                 call edx
// 008df69b  5f                   pop edi
// 008df69c  5e                   pop esi
// 008df69d  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?SetDefaultCharFormat@CXTPRichRender@@QAEXPAU_charformatw@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
