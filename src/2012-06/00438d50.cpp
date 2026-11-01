// from server: 100% by auto
// roc 2012-06 00438d50  unit: boost::detail::thread_data_base  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00438d50
//
// 00438d50  56                   push esi
// 00438d51  8bf1                 mov esi, ecx
// 00438d53  8d4e54               lea ecx, [esi + 0x54]
// 00438d56  ff15d047b200         call dword ptr [0xb247d0]
// 00438d5c  8d4e50               lea ecx, [esi + 0x50]
// 00438d5f  ff15d047b200         call dword ptr [0xb247d0]
// 00438d65  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00438d68  85c0                 test eax, eax
// 00438d6a  7408                 je 0x438d74
// 00438d6c  8b08                 mov ecx, dword ptr [eax]
// 00438d6e  8b5108               mov edx, dword ptr [ecx + 8]
// 00438d71  50                   push eax
// 00438d72  ffd2                 call edx
// 00438d74  8b4648               mov eax, dword ptr [esi + 0x48]
// 00438d77  85c0                 test eax, eax
// 00438d79  7408                 je 0x438d83
// 00438d7b  8b08                 mov ecx, dword ptr [eax]
// 00438d7d  8b5108               mov edx, dword ptr [ecx + 8]
// 00438d80  50                   push eax
// 00438d81  ffd2                 call edx
// 00438d83  8b4644               mov eax, dword ptr [esi + 0x44]
// 00438d86  85c0                 test eax, eax
// 00438d88  7408                 je 0x438d92
// 00438d8a  8b08                 mov ecx, dword ptr [eax]
// 00438d8c  8b5108               mov edx, dword ptr [ecx + 8]
// 00438d8f  50                   push eax
// 00438d90  ffd2                 call edx
// 00438d92  8bce                 mov ecx, esi
// 00438d94  5e                   pop esi
// 00438d95  e926ec5900           jmp 0x9d79c0
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarCustomProperties.cpp (function ??1CXTPPropExchangeXMLNode@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarCustomProperties.cpp
