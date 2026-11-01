// from server: 100% by auto
// roc 2009-06 0079ab90  unit: CXTPResourceManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079ab90
//
// 0079ab90  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079ab94  8b01                 mov eax, dword ptr [ecx]
// 0079ab96  8b402c               mov eax, dword ptr [eax + 0x2c]
// 0079ab99  52                   push edx
// 0079ab9a  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079ab9e  52                   push edx
// 0079ab9f  0fb754240c           movzx edx, word ptr [esp + 0xc]
// 0079aba4  52                   push edx
// 0079aba5  ffd0                 call eax
// 0079aba7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?LoadIconA@CXTPResourceManager@@UAEPAUHICON__@@HVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
