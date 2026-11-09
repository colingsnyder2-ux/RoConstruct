// from server: 100% by auto
// roc 2010-06 0089bcb0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089bcb0
//
// 0089bcb0  8b542408             mov edx, dword ptr [esp + 8]
// 0089bcb4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089bcb8  53                   push ebx
// 0089bcb9  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0089bcbd  8bc3                 mov eax, ebx
// 0089bcbf  0fafc2               imul eax, edx
// 0089bcc2  57                   push edi
// 0089bcc3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0089bcc7  8d4c81fc             lea ecx, [ecx + eax*4 - 4]
// 0089bccb  85d2                 test edx, edx
// 0089bccd  7e33                 jle 0x89bd02
// 0089bccf  55                   push ebp
// 0089bcd0  89542418             mov dword ptr [esp + 0x18], edx
// 0089bcd4  56                   push esi
// 0089bcd5  8bc7                 mov eax, edi
// 0089bcd7  85db                 test ebx, ebx
// 0089bcd9  7e1b                 jle 0x89bcf6
// 0089bcdb  8d349500000000       lea esi, [edx*4]
// 0089bce2  8bd3                 mov edx, ebx
// 0089bce4  8b28                 mov ebp, dword ptr [eax]
// 0089bce6  8929                 mov dword ptr [ecx], ebp
// 0089bce8  83e904               sub ecx, 4
// 0089bceb  03c6                 add eax, esi
// 0089bced  83ea01               sub edx, 1
// 0089bcf0  75f2                 jne 0x89bce4
// 0089bcf2  8b542418             mov edx, dword ptr [esp + 0x18]
// 0089bcf6  83c704               add edi, 4
// 0089bcf9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0089bcfe  75d5                 jne 0x89bcd5
// 0089bd00  5e                   pop esi
// 0089bd01  5d                   pop ebp
// 0089bd02  5f                   pop edi
// 0089bd03  5b                   pop ebx
// 0089bd04  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTabBaseTheme.cpp (function ?DrawRotatedBitsLeft@CXTTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTabBaseTheme.cpp
