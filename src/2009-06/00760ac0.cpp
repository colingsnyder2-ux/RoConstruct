// from server: 100% by auto
// roc 2009-06 00760ac0  unit: CXTPToolBar::CControlButtonExpand  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760ac0
//
// 00760ac0  8b4108               mov eax, dword ptr [ecx + 8]
// 00760ac3  85c0                 test eax, eax
// 00760ac5  7501                 jne 0x760ac8
// 00760ac7  c3                   ret 
// 00760ac8  56                   push esi
// 00760ac9  68ac7e8f00           push 0x8f7eac
// 00760ace  8d7110               lea esi, [ecx + 0x10]
// 00760ad1  50                   push eax
// 00760ad2  c70614000000         mov dword ptr [esi], 0x14
// 00760ad8  ff15e8e18900         call dword ptr [0x89e1e8]
// 00760ade  85c0                 test eax, eax
// 00760ae0  740b                 je 0x760aed
// 00760ae2  56                   push esi
// 00760ae3  ffd0                 call eax
// 00760ae5  f7d8                 neg eax
// 00760ae7  1bc0                 sbb eax, eax
// 00760ae9  f7d8                 neg eax
// 00760aeb  5e                   pop esi
// 00760aec  c3                   ret 
// 00760aed  33c0                 xor eax, eax
// 00760aef  5e                   pop esi
// 00760af0  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersionInfo@CXTPModuleHandle@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
