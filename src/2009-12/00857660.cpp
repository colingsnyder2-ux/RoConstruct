// from server: 100% by auto
// roc 2009-12 00857660  unit: CXTPTabClientWnd  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00857660
//
// 00857660  8b442404             mov eax, dword ptr [esp + 4]
// 00857664  85c0                 test eax, eax
// 00857666  7449                 je 0x8576b1
// 00857668  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 0085766b  8b5060               mov edx, dword ptr [eax + 0x60]
// 0085766e  8d4101               lea eax, [ecx + 1]
// 00857671  85c0                 test eax, eax
// 00857673  7c11                 jl 0x857686
// 00857675  3b425c               cmp eax, dword ptr [edx + 0x5c]
// 00857678  7d0c                 jge 0x857686
// 0085767a  56                   push esi
// 0085767b  8b7258               mov esi, dword ptr [edx + 0x58]
// 0085767e  8b0486               mov eax, dword ptr [esi + eax*4]
// 00857681  5e                   pop esi
// 00857682  85c0                 test eax, eax
// 00857684  7516                 jne 0x85769c
// 00857686  8d41ff               lea eax, [ecx - 1]
// 00857689  85c0                 test eax, eax
// 0085768b  7c24                 jl 0x8576b1
// 0085768d  3b425c               cmp eax, dword ptr [edx + 0x5c]
// 00857690  7d1f                 jge 0x8576b1
// 00857692  8b4a58               mov ecx, dword ptr [edx + 0x58]
// 00857695  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00857698  85c0                 test eax, eax
// 0085769a  7415                 je 0x8576b1
// 0085769c  8bc8                 mov ecx, eax
// 0085769e  e8dd8deeff           call 0x740480
// 008576a3  85c0                 test eax, eax
// 008576a5  740a                 je 0x8576b1
// 008576a7  89442404             mov dword ptr [esp + 4], eax
// 008576ab  ff2544cb9800         jmp dword ptr [0x98cb44]
// 008576b1  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?ActivateNextItem@CXTPTabClientWnd@@IAEXPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
