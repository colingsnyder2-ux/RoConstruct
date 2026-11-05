// from server: 100% by auto
// roc 2010-06 0042ad60  unit: CSelectionPropGrid  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042ad60
//
// 0042ad60  56                   push esi
// 0042ad61  8bf1                 mov esi, ecx
// 0042ad63  8d4e54               lea ecx, [esi + 0x54]
// 0042ad66  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0042ad6c  8d4e50               lea ecx, [esi + 0x50]
// 0042ad6f  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0042ad75  8b464c               mov eax, dword ptr [esi + 0x4c]
// 0042ad78  85c0                 test eax, eax
// 0042ad7a  7408                 je 0x42ad84
// 0042ad7c  8b08                 mov ecx, dword ptr [eax]
// 0042ad7e  8b5108               mov edx, dword ptr [ecx + 8]
// 0042ad81  50                   push eax
// 0042ad82  ffd2                 call edx
// 0042ad84  8b4648               mov eax, dword ptr [esi + 0x48]
// 0042ad87  85c0                 test eax, eax
// 0042ad89  7408                 je 0x42ad93
// 0042ad8b  8b08                 mov ecx, dword ptr [eax]
// 0042ad8d  8b5108               mov edx, dword ptr [ecx + 8]
// 0042ad90  50                   push eax
// 0042ad91  ffd2                 call edx
// 0042ad93  8b4644               mov eax, dword ptr [esi + 0x44]
// 0042ad96  85c0                 test eax, eax
// 0042ad98  7408                 je 0x42ada2
// 0042ad9a  8b08                 mov ecx, dword ptr [eax]
// 0042ad9c  8b5108               mov edx, dword ptr [ecx + 8]
// 0042ad9f  50                   push eax
// 0042ada0  ffd2                 call edx
// 0042ada2  8bce                 mov ecx, esi
// 0042ada4  5e                   pop esi
// 0042ada5  e926933d00           jmp 0x8040d0
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarCustomProperties.cpp (function ??1CXTPPropExchangeXMLNode@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarCustomProperties.cpp
