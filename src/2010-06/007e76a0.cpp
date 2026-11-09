// from server: 100% by auto
// roc 2010-06 007e76a0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e76a0
//
// 007e76a0  83ec10               sub esp, 0x10
// 007e76a3  57                   push edi
// 007e76a4  8bf9                 mov edi, ecx
// 007e76a6  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e76a9  e8c208fcff           call 0x7a7f70
// 007e76ae  837f0400             cmp dword ptr [edi + 4], 0
// 007e76b2  744c                 je 0x7e7700
// 007e76b4  56                   push esi
// 007e76b5  8bcf                 mov ecx, edi
// 007e76b7  e864f0ffff           call 0x7e6720
// 007e76bc  8bf0                 mov esi, eax
// 007e76be  85f6                 test esi, esi
// 007e76c0  743d                 je 0x7e76ff
// 007e76c2  53                   push ebx
// 007e76c3  8b1d78ba9e00         mov ebx, dword ptr [0x9eba78]
// 007e76c9  8da42400000000       lea esp, [esp]
// 007e76d0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e76d3  6a01                 push 1
// 007e76d5  8d442410             lea eax, [esp + 0x10]
// 007e76d9  50                   push eax
// 007e76da  56                   push esi
// 007e76db  e8560cfcff           call 0x7a8336
// 007e76e0  8b5734               mov edx, dword ptr [edi + 0x34]
// 007e76e3  8b4220               mov eax, dword ptr [edx + 0x20]
// 007e76e6  6a01                 push 1
// 007e76e8  8d4c2410             lea ecx, [esp + 0x10]
// 007e76ec  51                   push ecx
// 007e76ed  50                   push eax
// 007e76ee  ffd3                 call ebx
// 007e76f0  56                   push esi
// 007e76f1  8bcf                 mov ecx, edi
// 007e76f3  e878f0ffff           call 0x7e6770
// 007e76f8  8bf0                 mov esi, eax
// 007e76fa  85f6                 test esi, esi
// 007e76fc  75d2                 jne 0x7e76d0
// 007e76fe  5b                   pop ebx
// 007e76ff  5e                   pop esi
// 007e7700  5f                   pop edi
// 007e7701  83c410               add esp, 0x10
// 007e7704  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnKillFocus@CXTTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
