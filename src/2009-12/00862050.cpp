// from server: 100% by auto
// roc 2009-12 00862050  unit: CXTPPropertyGridToolTip  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00862050
//
// 00862050  8b442404             mov eax, dword ptr [esp + 4]
// 00862054  56                   push esi
// 00862055  8bf1                 mov esi, ecx
// 00862057  894668               mov dword ptr [esi + 0x68], eax
// 0086205a  85c0                 test eax, eax
// 0086205c  7549                 jne 0x8620a7
// 0086205e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00862061  85c9                 test ecx, ecx
// 00862063  7427                 je 0x86208c
// 00862065  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0086206b  85c0                 test eax, eax
// 0086206d  741d                 je 0x86208c
// 0086206f  50                   push eax
// 00862070  51                   push ecx
// 00862071  ff15d0cb9800         call dword ptr [0x98cbd0]
// 00862077  8d8ee0000000         lea ecx, [esi + 0xe0]
// 0086207d  c7861801000000000000 mov dword ptr [esi + 0x118], 0
// 00862087  e824e2ffff           call 0x8602b0
// 0086208c  8b4620               mov eax, dword ptr [esi + 0x20]
// 0086208f  85c0                 test eax, eax
// 00862091  7414                 je 0x8620a7
// 00862093  50                   push eax
// 00862094  ff1564ca9800         call dword ptr [0x98ca64]
// 0086209a  85c0                 test eax, eax
// 0086209c  7409                 je 0x8620a7
// 0086209e  6a00                 push 0
// 008620a0  8bce                 mov ecx, esi
// 008620a2  e8e9e6ffff           call 0x860790
// 008620a7  5e                   pop esi
// 008620a8  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?Activate@CXTPToolTipContextToolTip@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
