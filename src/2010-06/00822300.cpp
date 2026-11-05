// from server: 100% by auto
// roc 2010-06 00822300  unit: CXTPResourceManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822300
//
// 00822300  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00822304  8b01                 mov eax, dword ptr [ecx]
// 00822306  8b402c               mov eax, dword ptr [eax + 0x2c]
// 00822309  52                   push edx
// 0082230a  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0082230e  52                   push edx
// 0082230f  0fb754240c           movzx edx, word ptr [esp + 0xc]
// 00822314  52                   push edx
// 00822315  ffd0                 call eax
// 00822317  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadIconA@CXTPResourceManager@@UAEPAUHICON__@@HVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
