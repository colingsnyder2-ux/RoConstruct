// from server: 100% by auto
// roc 2009-06 0079b2a0  unit: CXTPResourceManager  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b2a0
//
// 0079b2a0  56                   push esi
// 0079b2a1  8bf1                 mov esi, ecx
// 0079b2a3  c60600               mov byte ptr [esi], 0
// 0079b2a6  e8b5feffff           call 0x79b160
// 0079b2ab  8bc6                 mov eax, esi
// 0079b2ad  5e                   pop esi
// 0079b2ae  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ??0CManageState@CXTPResourceManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
