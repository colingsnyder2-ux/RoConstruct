// from server: 100% by auto
// roc 2009-12 0086e2f0  unit: CXTPResourceManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e2f0
//
// 0086e2f0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086e2f4  8b01                 mov eax, dword ptr [ecx]
// 0086e2f6  8b402c               mov eax, dword ptr [eax + 0x2c]
// 0086e2f9  52                   push edx
// 0086e2fa  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086e2fe  52                   push edx
// 0086e2ff  0fb754240c           movzx edx, word ptr [esp + 0xc]
// 0086e304  52                   push edx
// 0086e305  ffd0                 call eax
// 0086e307  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadIconA@CXTPResourceManager@@UAEPAUHICON__@@HVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
