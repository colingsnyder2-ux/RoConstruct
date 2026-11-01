// from server: 100% by auto
// roc 2009-12 008e6e90  unit: CXTPTabPaintManager::CColorSetWinXP  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6e90
//
// 008e6e90  8b542408             mov edx, dword ptr [esp + 8]
// 008e6e94  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e6e98  53                   push ebx
// 008e6e99  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008e6e9d  8bc3                 mov eax, ebx
// 008e6e9f  0fafc2               imul eax, edx
// 008e6ea2  57                   push edi
// 008e6ea3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008e6ea7  8d4c81fc             lea ecx, [ecx + eax*4 - 4]
// 008e6eab  85d2                 test edx, edx
// 008e6ead  7e33                 jle 0x8e6ee2
// 008e6eaf  55                   push ebp
// 008e6eb0  89542418             mov dword ptr [esp + 0x18], edx
// 008e6eb4  56                   push esi
// 008e6eb5  8bc7                 mov eax, edi
// 008e6eb7  85db                 test ebx, ebx
// 008e6eb9  7e1b                 jle 0x8e6ed6
// 008e6ebb  8d349500000000       lea esi, [edx*4]
// 008e6ec2  8bd3                 mov edx, ebx
// 008e6ec4  8b28                 mov ebp, dword ptr [eax]
// 008e6ec6  8929                 mov dword ptr [ecx], ebp
// 008e6ec8  83e904               sub ecx, 4
// 008e6ecb  03c6                 add eax, esi
// 008e6ecd  83ea01               sub edx, 1
// 008e6ed0  75f2                 jne 0x8e6ec4
// 008e6ed2  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e6ed6  83c704               add edi, 4
// 008e6ed9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 008e6ede  75d5                 jne 0x8e6eb5
// 008e6ee0  5e                   pop esi
// 008e6ee1  5d                   pop ebp
// 008e6ee2  5f                   pop edi
// 008e6ee3  5b                   pop ebx
// 008e6ee4  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tab\XTPTabBaseTheme.cpp (function ?DrawRotatedBitsLeft@CXTPTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tab/XTPTabBaseTheme.cpp
