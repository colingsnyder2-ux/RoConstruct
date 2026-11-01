// from server: 100% by auto
// roc 2009-06 0080c340  unit: CXTPTabPaintManager::CColorSetWinXP  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c340
//
// 0080c340  8b542408             mov edx, dword ptr [esp + 8]
// 0080c344  57                   push edi
// 0080c345  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0080c349  85d2                 test edx, edx
// 0080c34b  7e42                 jle 0x80c38f
// 0080c34d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0080c351  53                   push ebx
// 0080c352  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0080c356  55                   push ebp
// 0080c357  56                   push esi
// 0080c358  8954241c             mov dword ptr [esp + 0x1c], edx
// 0080c35c  8d642400             lea esp, [esp]
// 0080c360  8bc7                 mov eax, edi
// 0080c362  85db                 test ebx, ebx
// 0080c364  7e1c                 jle 0x80c382
// 0080c366  8d349500000000       lea esi, [edx*4]
// 0080c36d  8bd3                 mov edx, ebx
// 0080c36f  90                   nop 
// 0080c370  8b28                 mov ebp, dword ptr [eax]
// 0080c372  8929                 mov dword ptr [ecx], ebp
// 0080c374  83c104               add ecx, 4
// 0080c377  03c6                 add eax, esi
// 0080c379  83ea01               sub edx, 1
// 0080c37c  75f2                 jne 0x80c370
// 0080c37e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0080c382  83c704               add edi, 4
// 0080c385  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0080c38a  75d4                 jne 0x80c360
// 0080c38c  5e                   pop esi
// 0080c38d  5d                   pop ebp
// 0080c38e  5b                   pop ebx
// 0080c38f  5f                   pop edi
// 0080c390  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tab\XTPTabBaseTheme.cpp (function ?DrawRotatedBitsRight@CXTPTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tab/XTPTabBaseTheme.cpp
