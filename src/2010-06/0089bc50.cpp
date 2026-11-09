// from server: 100% by auto
// roc 2010-06 0089bc50  unit: CXTPTabPaintManager::CColorSetWinXP  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089bc50
//
// 0089bc50  8b542408             mov edx, dword ptr [esp + 8]
// 0089bc54  57                   push edi
// 0089bc55  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0089bc59  85d2                 test edx, edx
// 0089bc5b  7e42                 jle 0x89bc9f
// 0089bc5d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0089bc61  53                   push ebx
// 0089bc62  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0089bc66  55                   push ebp
// 0089bc67  56                   push esi
// 0089bc68  8954241c             mov dword ptr [esp + 0x1c], edx
// 0089bc6c  8d642400             lea esp, [esp]
// 0089bc70  8bc7                 mov eax, edi
// 0089bc72  85db                 test ebx, ebx
// 0089bc74  7e1c                 jle 0x89bc92
// 0089bc76  8d349500000000       lea esi, [edx*4]
// 0089bc7d  8bd3                 mov edx, ebx
// 0089bc7f  90                   nop 
// 0089bc80  8b28                 mov ebp, dword ptr [eax]
// 0089bc82  8929                 mov dword ptr [ecx], ebp
// 0089bc84  83c104               add ecx, 4
// 0089bc87  03c6                 add eax, esi
// 0089bc89  83ea01               sub edx, 1
// 0089bc8c  75f2                 jne 0x89bc80
// 0089bc8e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0089bc92  83c704               add edi, 4
// 0089bc95  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0089bc9a  75d4                 jne 0x89bc70
// 0089bc9c  5e                   pop esi
// 0089bc9d  5d                   pop ebp
// 0089bc9e  5b                   pop ebx
// 0089bc9f  5f                   pop edi
// 0089bca0  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTabBaseTheme.cpp (function ?DrawRotatedBitsRight@CXTTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTabBaseTheme.cpp
