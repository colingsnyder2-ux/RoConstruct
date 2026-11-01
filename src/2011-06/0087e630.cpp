// from server: 100% by auto
// roc 2011-06 0087e630  unit: CXTCaption  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087e630
//
// 0087e630  8b442404             mov eax, dword ptr [esp + 4]
// 0087e634  83ec10               sub esp, 0x10
// 0087e637  56                   push esi
// 0087e638  57                   push edi
// 0087e639  50                   push eax
// 0087e63a  8bf1                 mov esi, ecx
// 0087e63c  e877df1400           call 0x9cc5b8
// 0087e641  8bf8                 mov edi, eax
// 0087e643  85ff                 test edi, edi
// 0087e645  743b                 je 0x87e682
// 0087e647  56                   push esi
// 0087e648  8d4c240c             lea ecx, [esp + 0xc]
// 0087e64c  e83fe7fdff           call 0x85cd90
// 0087e651  8b16                 mov edx, dword ptr [esi]
// 0087e653  8b926c010000         mov edx, dword ptr [edx + 0x16c]
// 0087e659  8d442408             lea eax, [esp + 8]
// 0087e65d  50                   push eax
// 0087e65e  57                   push edi
// 0087e65f  8bce                 mov ecx, esi
// 0087e661  ffd2                 call edx
// 0087e663  8b06                 mov eax, dword ptr [esi]
// 0087e665  8b9070010000         mov edx, dword ptr [eax + 0x170]
// 0087e66b  57                   push edi
// 0087e66c  8bce                 mov ecx, esi
// 0087e66e  ffd2                 call edx
// 0087e670  8b06                 mov eax, dword ptr [esi]
// 0087e672  8b9074010000         mov edx, dword ptr [eax + 0x174]
// 0087e678  8d4c2408             lea ecx, [esp + 8]
// 0087e67c  51                   push ecx
// 0087e67d  57                   push edi
// 0087e67e  8bce                 mov ecx, esi
// 0087e680  ffd2                 call edx
// 0087e682  5f                   pop edi
// 0087e683  b801000000           mov eax, 1
// 0087e688  5e                   pop esi
// 0087e689  83c410               add esp, 0x10
// 0087e68c  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\Controls\Static\XTPCaption.cpp (function ?OnPrintClient@CXTPCaption@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Static/XTPCaption.cpp
