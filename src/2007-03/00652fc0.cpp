// from server: 100% by auto
// roc 2007-03 00652fc0  unit: seg_00650000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652fc0
//
// 00652fc0  83ec10               sub esp, 0x10
// 00652fc3  57                   push edi
// 00652fc4  8bf9                 mov edi, ecx
// 00652fc6  837f0400             cmp dword ptr [edi + 4], 0
// 00652fca  7444                 je 0x653010
// 00652fcc  56                   push esi
// 00652fcd  e8def0ffff           call 0x6520b0
// 00652fd2  8bf0                 mov esi, eax
// 00652fd4  85f6                 test esi, esi
// 00652fd6  7437                 je 0x65300f
// 00652fd8  53                   push ebx
// 00652fd9  8b1d54ee7700         mov ebx, dword ptr [0x77ee54]
// 00652fdf  90                   nop 
// 00652fe0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00652fe3  6a01                 push 1
// 00652fe5  8d442410             lea eax, [esp + 0x10]
// 00652fe9  50                   push eax
// 00652fea  56                   push esi
// 00652feb  e822b9fcff           call 0x61e912
// 00652ff0  8b5734               mov edx, dword ptr [edi + 0x34]
// 00652ff3  8b4220               mov eax, dword ptr [edx + 0x20]
// 00652ff6  6a01                 push 1
// 00652ff8  8d4c2410             lea ecx, [esp + 0x10]
// 00652ffc  51                   push ecx
// 00652ffd  50                   push eax
// 00652ffe  ffd3                 call ebx
// 00653000  56                   push esi
// 00653001  8bcf                 mov ecx, edi
// 00653003  e8f8f0ffff           call 0x652100
// 00653008  8bf0                 mov esi, eax
// 0065300a  85f6                 test esi, esi
// 0065300c  75d2                 jne 0x652fe0
// 0065300e  5b                   pop ebx
// 0065300f  5e                   pop esi
// 00653010  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00653013  e8bab6fcff           call 0x61e6d2
// 00653018  5f                   pop edi
// 00653019  83c410               add esp, 0x10
// 0065301c  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnSetFocus@CXTPTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
