// from server: 100% by auto
// roc 2009-06 00760920  unit: CXTPToolBar::CControlButtonExpand  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760920
//
// 00760920  56                   push esi
// 00760921  6894000000           push 0x94
// 00760926  8bf1                 mov esi, ecx
// 00760928  6a00                 push 0
// 0076092a  56                   push esi
// 0076092b  e84493fbff           call 0x719c74
// 00760930  83c40c               add esp, 0xc
// 00760933  56                   push esi
// 00760934  c70694000000         mov dword ptr [esi], 0x94
// 0076093a  ff15c8e18900         call dword ptr [0x89e1c8]
// 00760940  8bc6                 mov eax, esi
// 00760942  5e                   pop esi
// 00760943  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ??0CXTPSystemVersion@@AAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
