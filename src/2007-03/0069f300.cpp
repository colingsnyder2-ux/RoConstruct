// from server: 100% by auto
// roc 2007-03 0069f300  unit: seg_00690000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069f300
//
// 0069f300  56                   push esi
// 0069f301  8bf1                 mov esi, ecx
// 0069f303  c60600               mov byte ptr [esi], 0
// 0069f306  e875ffffff           call 0x69f280
// 0069f30b  8bc6                 mov eax, esi
// 0069f30d  5e                   pop esi
// 0069f30e  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ??0CManageState@CXTPResourceManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
