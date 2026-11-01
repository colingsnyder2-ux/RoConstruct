// from server: 100% by auto
// roc 2009-12 0086e690  unit: CXTPResourceManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e690
//
// 0086e690  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0086e693  668b00               mov ax, word ptr [eax]
// 0086e696  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?GetResourcesLangID@CXTPResourceManager@@UAEGXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
