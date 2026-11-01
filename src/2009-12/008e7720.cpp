// from server: 100% by auto
// roc 2009-12 008e7720  unit: CXTPTabPaintManager::CColorSetDefault  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e7720
//
// 008e7720  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e7724  8b4004               mov eax, dword ptr [eax + 4]
// 008e7727  56                   push esi
// 008e7728  85c0                 test eax, eax
// 008e772a  741f                 je 0x8e774b
// 008e772c  8b11                 mov edx, dword ptr [ecx]
// 008e772e  50                   push eax
// 008e772f  8b4224               mov eax, dword ptr [edx + 0x24]
// 008e7732  ffd0                 call eax
// 008e7734  8bf0                 mov esi, eax
// 008e7736  56                   push esi
// 008e7737  8d4c2410             lea ecx, [esp + 0x10]
// 008e773b  51                   push ecx
// 008e773c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e7740  e8b9cef0ff           call 0x7f45fe
// 008e7745  8bc6                 mov eax, esi
// 008e7747  5e                   pop esi
// 008e7748  c21800               ret 0x18
// 008e774b  8b717c               mov esi, dword ptr [ecx + 0x7c]
// 008e774e  83feff               cmp esi, -1
// 008e7751  7503                 jne 0x8e7756
// 008e7753  8b7178               mov esi, dword ptr [ecx + 0x78]
// 008e7756  56                   push esi
// 008e7757  8d4c2410             lea ecx, [esp + 0x10]
// 008e775b  51                   push ecx
// 008e775c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e7760  e899cef0ff           call 0x7f45fe
// 008e7765  8bc6                 mov eax, esi
// 008e7767  5e                   pop esi
// 008e7768  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillClient@CXTPTabPaintManagerColorSet@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
