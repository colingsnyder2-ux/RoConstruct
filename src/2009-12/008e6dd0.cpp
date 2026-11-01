// from server: 100% by auto
// roc 2009-12 008e6dd0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6dd0
//
// 008e6dd0  8b442408             mov eax, dword ptr [esp + 8]
// 008e6dd4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008e6dd8  56                   push esi
// 008e6dd9  57                   push edi
// 008e6dda  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008e6dde  8d48ff               lea ecx, [eax - 1]
// 008e6de1  0fafcf               imul ecx, edi
// 008e6de4  8d348a               lea esi, [edx + ecx*4]
// 008e6de7  85c0                 test eax, eax
// 008e6de9  7e34                 jle 0x8e6e1f
// 008e6deb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008e6def  53                   push ebx
// 008e6df0  55                   push ebp
// 008e6df1  8bd8                 mov ebx, eax
// 008e6df3  8bc6                 mov eax, esi
// 008e6df5  85ff                 test edi, edi
// 008e6df7  7e16                 jle 0x8e6e0f
// 008e6df9  8bd7                 mov edx, edi
// 008e6dfb  eb03                 jmp 0x8e6e00
// 008e6dfd  8d4900               lea ecx, [ecx]
// 008e6e00  8b28                 mov ebp, dword ptr [eax]
// 008e6e02  8929                 mov dword ptr [ecx], ebp
// 008e6e04  83c104               add ecx, 4
// 008e6e07  83c004               add eax, 4
// 008e6e0a  83ea01               sub edx, 1
// 008e6e0d  75f1                 jne 0x8e6e00
// 008e6e0f  8d04bd00000000       lea eax, [edi*4]
// 008e6e16  2bf0                 sub esi, eax
// 008e6e18  83eb01               sub ebx, 1
// 008e6e1b  75d6                 jne 0x8e6df3
// 008e6e1d  5d                   pop ebp
// 008e6e1e  5b                   pop ebx
// 008e6e1f  5f                   pop edi
// 008e6e20  5e                   pop esi
// 008e6e21  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tab\XTPTabBaseTheme.cpp (function ?DrawRotatedBitsBottom@CXTPTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tab/XTPTabBaseTheme.cpp
