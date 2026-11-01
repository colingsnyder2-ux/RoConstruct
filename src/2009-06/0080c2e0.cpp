// from server: 100% by auto
// roc 2009-06 0080c2e0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080c2e0
//
// 0080c2e0  8b442408             mov eax, dword ptr [esp + 8]
// 0080c2e4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0080c2e8  56                   push esi
// 0080c2e9  57                   push edi
// 0080c2ea  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080c2ee  8d48ff               lea ecx, [eax - 1]
// 0080c2f1  0fafcf               imul ecx, edi
// 0080c2f4  8d348a               lea esi, [edx + ecx*4]
// 0080c2f7  85c0                 test eax, eax
// 0080c2f9  7e34                 jle 0x80c32f
// 0080c2fb  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0080c2ff  53                   push ebx
// 0080c300  55                   push ebp
// 0080c301  8bd8                 mov ebx, eax
// 0080c303  8bc6                 mov eax, esi
// 0080c305  85ff                 test edi, edi
// 0080c307  7e16                 jle 0x80c31f
// 0080c309  8bd7                 mov edx, edi
// 0080c30b  eb03                 jmp 0x80c310
// 0080c30d  8d4900               lea ecx, [ecx]
// 0080c310  8b28                 mov ebp, dword ptr [eax]
// 0080c312  8929                 mov dword ptr [ecx], ebp
// 0080c314  83c104               add ecx, 4
// 0080c317  83c004               add eax, 4
// 0080c31a  83ea01               sub edx, 1
// 0080c31d  75f1                 jne 0x80c310
// 0080c31f  8d04bd00000000       lea eax, [edi*4]
// 0080c326  2bf0                 sub esi, eax
// 0080c328  83eb01               sub ebx, 1
// 0080c32b  75d6                 jne 0x80c303
// 0080c32d  5d                   pop ebp
// 0080c32e  5b                   pop ebx
// 0080c32f  5f                   pop edi
// 0080c330  5e                   pop esi
// 0080c331  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tab\XTPTabBaseTheme.cpp (function ?DrawRotatedBitsBottom@CXTPTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tab/XTPTabBaseTheme.cpp
