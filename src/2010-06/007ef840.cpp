// from server: 100% by auto
// roc 2010-06 007ef840  unit: CXTPToolBar::CControlButtonExpand  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef840
//
// 007ef840  56                   push esi
// 007ef841  6894000000           push 0x94
// 007ef846  8bf1                 mov esi, ecx
// 007ef848  6a00                 push 0
// 007ef84a  56                   push esi
// 007ef84b  e89493fbff           call 0x7a8be4
// 007ef850  83c40c               add esp, 0xc
// 007ef853  56                   push esi
// 007ef854  c70694000000         mov dword ptr [esi], 0x94
// 007ef85a  ff1554a39e00         call dword ptr [0x9ea354]
// 007ef860  8bc6                 mov eax, esi
// 007ef862  5e                   pop esi
// 007ef863  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ??0CXTPSystemVersion@@AAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
