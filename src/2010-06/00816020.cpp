// from server: 100% by auto
// roc 2010-06 00816020  unit: CXTPToolTipContextToolTip::PAUTOOLITEM::?$CArray  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00816020
//
// 00816020  8b442404             mov eax, dword ptr [esp + 4]
// 00816024  56                   push esi
// 00816025  8bf1                 mov esi, ecx
// 00816027  894668               mov dword ptr [esi + 0x68], eax
// 0081602a  85c0                 test eax, eax
// 0081602c  7549                 jne 0x816077
// 0081602e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00816031  85c9                 test ecx, ecx
// 00816033  7427                 je 0x81605c
// 00816035  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 0081603b  85c0                 test eax, eax
// 0081603d  741d                 je 0x81605c
// 0081603f  50                   push eax
// 00816040  51                   push ecx
// 00816041  ff1560ba9e00         call dword ptr [0x9eba60]
// 00816047  8d8ee0000000         lea ecx, [esi + 0xe0]
// 0081604d  c7861801000000000000 mov dword ptr [esi + 0x118], 0
// 00816057  e834e2ffff           call 0x814290
// 0081605c  8b4620               mov eax, dword ptr [esi + 0x20]
// 0081605f  85c0                 test eax, eax
// 00816061  7414                 je 0x816077
// 00816063  50                   push eax
// 00816064  ff15e8bb9e00         call dword ptr [0x9ebbe8]
// 0081606a  85c0                 test eax, eax
// 0081606c  7409                 je 0x816077
// 0081606e  6a00                 push 0
// 00816070  8bce                 mov ecx, esi
// 00816072  e8f9e6ffff           call 0x814770
// 00816077  5e                   pop esi
// 00816078  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?Activate@CXTPToolTipContextToolTip@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
