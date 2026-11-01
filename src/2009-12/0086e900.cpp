// from server: 100% by auto
// roc 2009-12 0086e900  unit: CXTPResourceManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e900
//
// 0086e900  51                   push ecx
// 0086e901  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0086e905  8d0424               lea eax, [esp]
// 0086e908  50                   push eax
// 0086e909  6850e88600           push 0x86e850
// 0086e90e  51                   push ecx
// 0086e90f  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0086e917  ff153cb39800         call dword ptr [0x98b33c]
// 0086e91d  668b0424             mov ax, word ptr [esp]
// 0086e921  59                   pop ecx
// 0086e922  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?GetResourceLanguage@CXTPResourceManager@@SAGPAUHINSTANCE__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
