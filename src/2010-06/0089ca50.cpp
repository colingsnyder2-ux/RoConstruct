// from server: 100% by auto
// roc 2010-06 0089ca50  unit: CXTPTabPaintManager::CColorSetVisualStudio  size: 198 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089ca50
//
// 0089ca50  56                   push esi
// 0089ca51  8bf1                 mov esi, ecx
// 0089ca53  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0089ca59  e8829cc3ff           call 0x4d66e0
// 0089ca5e  83f807               cmp eax, 7
// 0089ca61  0f8495000000         je 0x89cafc
// 0089ca67  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0089ca6d  e86e9cc3ff           call 0x4d66e0
// 0089ca72  83f804               cmp eax, 4
// 0089ca75  0f8481000000         je 0x89cafc
// 0089ca7b  57                   push edi
// 0089ca7c  e89f70f4ff           call 0x7e3b20
// 0089ca81  6a12                 push 0x12
// 0089ca83  8bc8                 mov ecx, eax
// 0089ca85  e82668f4ff           call 0x7e32b0
// 0089ca8a  8bf0                 mov esi, eax
// 0089ca8c  e88f70f4ff           call 0x7e3b20
// 0089ca91  6a0f                 push 0xf
// 0089ca93  8bc8                 mov ecx, eax
// 0089ca95  e81668f4ff           call 0x7e32b0
// 0089ca9a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089ca9e  83792000             cmp dword ptr [ecx + 0x20], 0
// 0089caa2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089caa6  7437                 je 0x89cadf
// 0089caa8  83792400             cmp dword ptr [ecx + 0x24], 0
// 0089caac  741b                 je 0x89cac9
// 0089caae  50                   push eax
// 0089caaf  56                   push esi
// 0089cab0  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0089cab4  56                   push esi
// 0089cab5  8bcf                 mov ecx, edi
// 0089cab7  e87cbcf0ff           call 0x7a8738
// 0089cabc  6a01                 push 1
// 0089cabe  6a01                 push 1
// 0089cac0  56                   push esi
// 0089cac1  ff1540bc9e00         call dword ptr [0x9ebc40]
// 0089cac7  eb16                 jmp 0x89cadf
// 0089cac9  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0089cacc  394a10               cmp dword ptr [edx + 0x10], ecx
// 0089cacf  750e                 jne 0x89cadf
// 0089cad1  56                   push esi
// 0089cad2  50                   push eax
// 0089cad3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0089cad7  50                   push eax
// 0089cad8  8bcf                 mov ecx, edi
// 0089cada  e859bcf0ff           call 0x7a8738
// 0089cadf  e83c70f4ff           call 0x7e3b20
// 0089cae4  6a31                 push 0x31
// 0089cae6  8bc8                 mov ecx, eax
// 0089cae8  e8c367f4ff           call 0x7e32b0
// 0089caed  8b17                 mov edx, dword ptr [edi]
// 0089caef  50                   push eax
// 0089caf0  8b4238               mov eax, dword ptr [edx + 0x38]
// 0089caf3  8bcf                 mov ecx, edi
// 0089caf5  ffd0                 call eax
// 0089caf7  5f                   pop edi
// 0089caf8  5e                   pop esi
// 0089caf9  c20c00               ret 0xc
// 0089cafc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089cb00  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0089cb04  8b442408             mov eax, dword ptr [esp + 8]
// 0089cb08  51                   push ecx
// 0089cb09  52                   push edx
// 0089cb0a  50                   push eax
// 0089cb0b  8bce                 mov ecx, esi
// 0089cb0d  e8eefdffff           call 0x89c900
// 0089cb12  5e                   pop esi
// 0089cb13  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillNavigateButton@CColorSetVisualStudio2003@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerNavigateButton@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerColors.cpp
