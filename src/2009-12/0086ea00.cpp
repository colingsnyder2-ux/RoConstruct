// from server: 100% by auto
// roc 2009-12 0086ea00  unit: CXTPResourceManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086ea00
//
// 0086ea00  56                   push esi
// 0086ea01  8bf1                 mov esi, ecx
// 0086ea03  c60600               mov byte ptr [esi], 0
// 0086ea06  e8b5feffff           call 0x86e8c0
// 0086ea0b  8bc6                 mov eax, esi
// 0086ea0d  5e                   pop esi
// 0086ea0e  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ??0CManageState@CXTPResourceManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
