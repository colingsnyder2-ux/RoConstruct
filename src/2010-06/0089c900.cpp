// from server: 100% by auto
// roc 2010-06 0089c900  unit: CXTPTabPaintManager::CColorSetDefault  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089c900
//
// 0089c900  56                   push esi
// 0089c901  57                   push edi
// 0089c902  e81972f4ff           call 0x7e3b20
// 0089c907  6a10                 push 0x10
// 0089c909  8bc8                 mov ecx, eax
// 0089c90b  e8a069f4ff           call 0x7e32b0
// 0089c910  8bf0                 mov esi, eax
// 0089c912  e80972f4ff           call 0x7e3b20
// 0089c917  6a14                 push 0x14
// 0089c919  8bc8                 mov ecx, eax
// 0089c91b  e89069f4ff           call 0x7e32b0
// 0089c920  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089c924  83792000             cmp dword ptr [ecx + 0x20], 0
// 0089c928  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089c92c  7437                 je 0x89c965
// 0089c92e  83792400             cmp dword ptr [ecx + 0x24], 0
// 0089c932  741b                 je 0x89c94f
// 0089c934  50                   push eax
// 0089c935  56                   push esi
// 0089c936  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0089c93a  56                   push esi
// 0089c93b  8bcf                 mov ecx, edi
// 0089c93d  e8f6bdf0ff           call 0x7a8738
// 0089c942  6a01                 push 1
// 0089c944  6a01                 push 1
// 0089c946  56                   push esi
// 0089c947  ff1540bc9e00         call dword ptr [0x9ebc40]
// 0089c94d  eb16                 jmp 0x89c965
// 0089c94f  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0089c952  394a10               cmp dword ptr [edx + 0x10], ecx
// 0089c955  750e                 jne 0x89c965
// 0089c957  56                   push esi
// 0089c958  50                   push eax
// 0089c959  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0089c95d  50                   push eax
// 0089c95e  8bcf                 mov ecx, edi
// 0089c960  e8d3bdf0ff           call 0x7a8738
// 0089c965  e8b671f4ff           call 0x7e3b20
// 0089c96a  6a12                 push 0x12
// 0089c96c  8bc8                 mov ecx, eax
// 0089c96e  e83d69f4ff           call 0x7e32b0
// 0089c973  8b17                 mov edx, dword ptr [edi]
// 0089c975  50                   push eax
// 0089c976  8b4238               mov eax, dword ptr [edx + 0x38]
// 0089c979  8bcf                 mov ecx, edi
// 0089c97b  ffd0                 call eax
// 0089c97d  5f                   pop edi
// 0089c97e  5e                   pop esi
// 0089c97f  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillNavigateButton@CColorSetDefault@CXTPTabPaintManager@@UAEXPAVCDC@@PAVCXTPTabManagerNavigateButton@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabPaintManagerColors.cpp
