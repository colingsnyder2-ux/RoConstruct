// from server: 100% by auto
// roc 2010-06 008226a0  unit: CXTPResourceManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008226a0
//
// 008226a0  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008226a3  668b00               mov ax, word ptr [eax]
// 008226a6  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?GetResourcesLangID@CXTPResourceManager@@UAEGXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
