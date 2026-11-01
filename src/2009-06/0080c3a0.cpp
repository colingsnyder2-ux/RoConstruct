// from server: 100% by auto
// roc 2009-06 0080c3a0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c3a0
//
// 0080c3a0  8b542408             mov edx, dword ptr [esp + 8]
// 0080c3a4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080c3a8  53                   push ebx
// 0080c3a9  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0080c3ad  8bc3                 mov eax, ebx
// 0080c3af  0fafc2               imul eax, edx
// 0080c3b2  57                   push edi
// 0080c3b3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0080c3b7  8d4c81fc             lea ecx, [ecx + eax*4 - 4]
// 0080c3bb  85d2                 test edx, edx
// 0080c3bd  7e33                 jle 0x80c3f2
// 0080c3bf  55                   push ebp
// 0080c3c0  89542418             mov dword ptr [esp + 0x18], edx
// 0080c3c4  56                   push esi
// 0080c3c5  8bc7                 mov eax, edi
// 0080c3c7  85db                 test ebx, ebx
// 0080c3c9  7e1b                 jle 0x80c3e6
// 0080c3cb  8d349500000000       lea esi, [edx*4]
// 0080c3d2  8bd3                 mov edx, ebx
// 0080c3d4  8b28                 mov ebp, dword ptr [eax]
// 0080c3d6  8929                 mov dword ptr [ecx], ebp
// 0080c3d8  83e904               sub ecx, 4
// 0080c3db  03c6                 add eax, esi
// 0080c3dd  83ea01               sub edx, 1
// 0080c3e0  75f2                 jne 0x80c3d4
// 0080c3e2  8b542418             mov edx, dword ptr [esp + 0x18]
// 0080c3e6  83c704               add edi, 4
// 0080c3e9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0080c3ee  75d5                 jne 0x80c3c5
// 0080c3f0  5e                   pop esi
// 0080c3f1  5d                   pop ebp
// 0080c3f2  5f                   pop edi
// 0080c3f3  5b                   pop ebx
// 0080c3f4  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tab\XTPTabBaseTheme.cpp (function ?DrawRotatedBitsLeft@CXTPTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tab/XTPTabBaseTheme.cpp
