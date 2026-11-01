// from server: 100% by auto
// roc 2009-12 00835470  unit: CXTPControls  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00835470
//
// 00835470  8b442404             mov eax, dword ptr [esp + 4]
// 00835474  8b10                 mov edx, dword ptr [eax]
// 00835476  895124               mov dword ptr [ecx + 0x24], edx
// 00835479  8b5004               mov edx, dword ptr [eax + 4]
// 0083547c  56                   push esi
// 0083547d  8b711c               mov esi, dword ptr [ecx + 0x1c]
// 00835480  895128               mov dword ptr [ecx + 0x28], edx
// 00835483  8b10                 mov edx, dword ptr [eax]
// 00835485  57                   push edi
// 00835486  8b7920               mov edi, dword ptr [ecx + 0x20]
// 00835489  3bd6                 cmp edx, esi
// 0083548b  7505                 jne 0x835492
// 0083548d  397804               cmp dword ptr [eax + 4], edi
// 00835490  7417                 je 0x8354a9
// 00835492  85d2                 test edx, edx
// 00835494  7413                 je 0x8354a9
// 00835496  83780400             cmp dword ptr [eax + 4], 0
// 0083549a  740d                 je 0x8354a9
// 0083549c  b801000000           mov eax, 1
// 008354a1  5f                   pop edi
// 008354a2  894118               mov dword ptr [ecx + 0x18], eax
// 008354a5  5e                   pop esi
// 008354a6  c20400               ret 4
// 008354a9  33c0                 xor eax, eax
// 008354ab  5f                   pop edi
// 008354ac  894118               mov dword ptr [ecx + 0x18], eax
// 008354af  5e                   pop esi
// 008354b0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?SetScreenSize@CXTPDockState@@AAEXAAVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
