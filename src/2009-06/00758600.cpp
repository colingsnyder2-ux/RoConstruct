// from server: 100% by auto
// roc 2009-06 00758600  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758600
//
// 00758600  83ec10               sub esp, 0x10
// 00758603  57                   push edi
// 00758604  8bf9                 mov edi, ecx
// 00758606  837f0400             cmp dword ptr [edi + 4], 0
// 0075860a  7444                 je 0x758650
// 0075860c  56                   push esi
// 0075860d  e8cef0ffff           call 0x7576e0
// 00758612  8bf0                 mov esi, eax
// 00758614  85f6                 test esi, esi
// 00758616  7437                 je 0x75864f
// 00758618  53                   push ebx
// 00758619  8b1d7cee8900         mov ebx, dword ptr [0x89ee7c]
// 0075861f  90                   nop 
// 00758620  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00758623  6a01                 push 1
// 00758625  8d442410             lea eax, [esp + 0x10]
// 00758629  50                   push eax
// 0075862a  56                   push esi
// 0075862b  e89e0dfcff           call 0x7193ce
// 00758630  8b5734               mov edx, dword ptr [edi + 0x34]
// 00758633  8b4220               mov eax, dword ptr [edx + 0x20]
// 00758636  6a01                 push 1
// 00758638  8d4c2410             lea ecx, [esp + 0x10]
// 0075863c  51                   push ecx
// 0075863d  50                   push eax
// 0075863e  ffd3                 call ebx
// 00758640  56                   push esi
// 00758641  8bcf                 mov ecx, edi
// 00758643  e8e8f0ffff           call 0x757730
// 00758648  8bf0                 mov esi, eax
// 0075864a  85f6                 test esi, esi
// 0075864c  75d2                 jne 0x758620
// 0075864e  5b                   pop ebx
// 0075864f  5e                   pop esi
// 00758650  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 00758653  e8b009fcff           call 0x719008
// 00758658  5f                   pop edi
// 00758659  83c410               add esp, 0x10
// 0075865c  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnSetFocus@CXTPTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
