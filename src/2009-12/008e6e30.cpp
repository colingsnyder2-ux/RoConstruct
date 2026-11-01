// from server: 100% by auto
// roc 2009-12 008e6e30  unit: CXTPTabPaintManager::CColorSetWinXP  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6e30
//
// 008e6e30  8b542408             mov edx, dword ptr [esp + 8]
// 008e6e34  57                   push edi
// 008e6e35  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008e6e39  85d2                 test edx, edx
// 008e6e3b  7e42                 jle 0x8e6e7f
// 008e6e3d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008e6e41  53                   push ebx
// 008e6e42  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 008e6e46  55                   push ebp
// 008e6e47  56                   push esi
// 008e6e48  8954241c             mov dword ptr [esp + 0x1c], edx
// 008e6e4c  8d642400             lea esp, [esp]
// 008e6e50  8bc7                 mov eax, edi
// 008e6e52  85db                 test ebx, ebx
// 008e6e54  7e1c                 jle 0x8e6e72
// 008e6e56  8d349500000000       lea esi, [edx*4]
// 008e6e5d  8bd3                 mov edx, ebx
// 008e6e5f  90                   nop 
// 008e6e60  8b28                 mov ebp, dword ptr [eax]
// 008e6e62  8929                 mov dword ptr [ecx], ebp
// 008e6e64  83c104               add ecx, 4
// 008e6e67  03c6                 add eax, esi
// 008e6e69  83ea01               sub edx, 1
// 008e6e6c  75f2                 jne 0x8e6e60
// 008e6e6e  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e6e72  83c704               add edi, 4
// 008e6e75  836c241c01           sub dword ptr [esp + 0x1c], 1
// 008e6e7a  75d4                 jne 0x8e6e50
// 008e6e7c  5e                   pop esi
// 008e6e7d  5d                   pop ebp
// 008e6e7e  5b                   pop ebx
// 008e6e7f  5f                   pop edi
// 008e6e80  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tab\XTPTabBaseTheme.cpp (function ?DrawRotatedBitsRight@CXTPTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tab/XTPTabBaseTheme.cpp
