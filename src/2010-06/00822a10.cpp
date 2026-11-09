// from server: 100% by auto
// roc 2010-06 00822a10  unit: CXTPResourceManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822a10
//
// 00822a10  56                   push esi
// 00822a11  8bf1                 mov esi, ecx
// 00822a13  c60600               mov byte ptr [esi], 0
// 00822a16  e8b5feffff           call 0x8228d0
// 00822a1b  8bc6                 mov eax, esi
// 00822a1d  5e                   pop esi
// 00822a1e  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ??0CManageState@CXTPResourceManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
