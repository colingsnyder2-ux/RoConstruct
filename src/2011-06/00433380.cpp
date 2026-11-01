// from server: 100% by auto
// roc 2011-06 00433380  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00433380
//
// 00433380  56                   push esi
// 00433381  8bf1                 mov esi, ecx
// 00433383  8d4e54               lea ecx, [esi + 0x54]
// 00433386  ff15082ea400         call dword ptr [0xa42e08]
// 0043338c  8d4e50               lea ecx, [esi + 0x50]
// 0043338f  ff15082ea400         call dword ptr [0xa42e08]
// 00433395  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00433398  85c0                 test eax, eax
// 0043339a  7408                 je 0x4333a4
// 0043339c  8b08                 mov ecx, dword ptr [eax]
// 0043339e  8b5108               mov edx, dword ptr [ecx + 8]
// 004333a1  50                   push eax
// 004333a2  ffd2                 call edx
// 004333a4  8b4648               mov eax, dword ptr [esi + 0x48]
// 004333a7  85c0                 test eax, eax
// 004333a9  7408                 je 0x4333b3
// 004333ab  8b08                 mov ecx, dword ptr [eax]
// 004333ad  8b5108               mov edx, dword ptr [ecx + 8]
// 004333b0  50                   push eax
// 004333b1  ffd2                 call edx
// 004333b3  8b4644               mov eax, dword ptr [esi + 0x44]
// 004333b6  85c0                 test eax, eax
// 004333b8  7408                 je 0x4333c2
// 004333ba  8b08                 mov ecx, dword ptr [eax]
// 004333bc  8b5108               mov edx, dword ptr [ecx + 8]
// 004333bf  50                   push eax
// 004333c0  ffd2                 call edx
// 004333c2  8bce                 mov ecx, esi
// 004333c4  5e                   pop esi
// 004333c5  e9e6c14200           jmp 0x85f5b0
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarCustomProperties.cpp (function ??1CXTPPropExchangeXMLNode@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarCustomProperties.cpp
