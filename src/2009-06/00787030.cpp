// from server: 100% by auto
// roc 2009-06 00787030  unit: CXTPToolTipContextToolTip::PAUTOOLITEM::?$CArray  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787030
//
// 00787030  8b442404             mov eax, dword ptr [esp + 4]
// 00787034  56                   push esi
// 00787035  8bf1                 mov esi, ecx
// 00787037  894668               mov dword ptr [esi + 0x68], eax
// 0078703a  85c0                 test eax, eax
// 0078703c  7549                 jne 0x787087
// 0078703e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00787041  85c9                 test ecx, ecx
// 00787043  7427                 je 0x78706c
// 00787045  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0078704b  85c0                 test eax, eax
// 0078704d  741d                 je 0x78706c
// 0078704f  50                   push eax
// 00787050  51                   push ecx
// 00787051  ff1584ee8900         call dword ptr [0x89ee84]
// 00787057  8d8ee0000000         lea ecx, [esi + 0xe0]
// 0078705d  c7861801000000000000 mov dword ptr [esi + 0x118], 0
// 00787067  e834e2ffff           call 0x7852a0
// 0078706c  8b4620               mov eax, dword ptr [esi + 0x20]
// 0078706f  85c0                 test eax, eax
// 00787071  7414                 je 0x787087
// 00787073  50                   push eax
// 00787074  ff15c8ed8900         call dword ptr [0x89edc8]
// 0078707a  85c0                 test eax, eax
// 0078707c  7409                 je 0x787087
// 0078707e  6a00                 push 0
// 00787080  8bce                 mov ecx, esi
// 00787082  e8f9e6ffff           call 0x785780
// 00787087  5e                   pop esi
// 00787088  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?Activate@CXTPToolTipContextToolTip@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
