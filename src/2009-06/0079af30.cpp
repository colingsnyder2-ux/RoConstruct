// from server: 100% by auto
// roc 2009-06 0079af30  unit: CXTPResourceManager  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079af30
//
// 0079af30  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0079af33  668b00               mov ax, word ptr [eax]
// 0079af36  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?GetResourcesLangID@CXTPResourceManager@@UAEGXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
