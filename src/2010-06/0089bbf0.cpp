// from server: 100% by auto
// roc 2010-06 0089bbf0  unit: CXTPTabPaintManager::CColorSetWinXP  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089bbf0
//
// 0089bbf0  8b442408             mov eax, dword ptr [esp + 8]
// 0089bbf4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0089bbf8  56                   push esi
// 0089bbf9  57                   push edi
// 0089bbfa  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089bbfe  8d48ff               lea ecx, [eax - 1]
// 0089bc01  0fafcf               imul ecx, edi
// 0089bc04  8d348a               lea esi, [edx + ecx*4]
// 0089bc07  85c0                 test eax, eax
// 0089bc09  7e34                 jle 0x89bc3f
// 0089bc0b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0089bc0f  53                   push ebx
// 0089bc10  55                   push ebp
// 0089bc11  8bd8                 mov ebx, eax
// 0089bc13  8bc6                 mov eax, esi
// 0089bc15  85ff                 test edi, edi
// 0089bc17  7e16                 jle 0x89bc2f
// 0089bc19  8bd7                 mov edx, edi
// 0089bc1b  eb03                 jmp 0x89bc20
// 0089bc1d  8d4900               lea ecx, [ecx]
// 0089bc20  8b28                 mov ebp, dword ptr [eax]
// 0089bc22  8929                 mov dword ptr [ecx], ebp
// 0089bc24  83c104               add ecx, 4
// 0089bc27  83c004               add eax, 4
// 0089bc2a  83ea01               sub edx, 1
// 0089bc2d  75f1                 jne 0x89bc20
// 0089bc2f  8d04bd00000000       lea eax, [edi*4]
// 0089bc36  2bf0                 sub esi, eax
// 0089bc38  83eb01               sub ebx, 1
// 0089bc3b  75d6                 jne 0x89bc13
// 0089bc3d  5d                   pop ebp
// 0089bc3e  5b                   pop ebx
// 0089bc3f  5f                   pop edi
// 0089bc40  5e                   pop esi
// 0089bc41  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTTabBaseTheme.cpp (function ?DrawRotatedBitsBottom@CXTTabBaseTheme@@CAXHHPAI0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTabBaseTheme.cpp
