// from server: 100% by auto
// roc 2009-06 00758660  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758660
//
// 00758660  83ec10               sub esp, 0x10
// 00758663  57                   push edi
// 00758664  8bf9                 mov edi, ecx
// 00758666  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00758669  e89a09fcff           call 0x719008
// 0075866e  837f0400             cmp dword ptr [edi + 4], 0
// 00758672  744c                 je 0x7586c0
// 00758674  56                   push esi
// 00758675  8bcf                 mov ecx, edi
// 00758677  e864f0ffff           call 0x7576e0
// 0075867c  8bf0                 mov esi, eax
// 0075867e  85f6                 test esi, esi
// 00758680  743d                 je 0x7586bf
// 00758682  53                   push ebx
// 00758683  8b1d7cee8900         mov ebx, dword ptr [0x89ee7c]
// 00758689  8da42400000000       lea esp, [esp]
// 00758690  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00758693  6a01                 push 1
// 00758695  8d442410             lea eax, [esp + 0x10]
// 00758699  50                   push eax
// 0075869a  56                   push esi
// 0075869b  e82e0dfcff           call 0x7193ce
// 007586a0  8b5734               mov edx, dword ptr [edi + 0x34]
// 007586a3  8b4220               mov eax, dword ptr [edx + 0x20]
// 007586a6  6a01                 push 1
// 007586a8  8d4c2410             lea ecx, [esp + 0x10]
// 007586ac  51                   push ecx
// 007586ad  50                   push eax
// 007586ae  ffd3                 call ebx
// 007586b0  56                   push esi
// 007586b1  8bcf                 mov ecx, edi
// 007586b3  e878f0ffff           call 0x757730
// 007586b8  8bf0                 mov esi, eax
// 007586ba  85f6                 test esi, esi
// 007586bc  75d2                 jne 0x758690
// 007586be  5b                   pop ebx
// 007586bf  5e                   pop esi
// 007586c0  5f                   pop edi
// 007586c1  83c410               add esp, 0x10
// 007586c4  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnKillFocus@CXTPTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
