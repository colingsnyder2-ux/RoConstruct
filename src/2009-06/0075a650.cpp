// from server: 100% by auto
// roc 2009-06 0075a650  unit: CXTPControls  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a650
//
// 0075a650  8b442404             mov eax, dword ptr [esp + 4]
// 0075a654  8b10                 mov edx, dword ptr [eax]
// 0075a656  895124               mov dword ptr [ecx + 0x24], edx
// 0075a659  8b5004               mov edx, dword ptr [eax + 4]
// 0075a65c  56                   push esi
// 0075a65d  8b711c               mov esi, dword ptr [ecx + 0x1c]
// 0075a660  895128               mov dword ptr [ecx + 0x28], edx
// 0075a663  8b10                 mov edx, dword ptr [eax]
// 0075a665  57                   push edi
// 0075a666  8b7920               mov edi, dword ptr [ecx + 0x20]
// 0075a669  3bd6                 cmp edx, esi
// 0075a66b  7505                 jne 0x75a672
// 0075a66d  397804               cmp dword ptr [eax + 4], edi
// 0075a670  7417                 je 0x75a689
// 0075a672  85d2                 test edx, edx
// 0075a674  7413                 je 0x75a689
// 0075a676  83780400             cmp dword ptr [eax + 4], 0
// 0075a67a  740d                 je 0x75a689
// 0075a67c  b801000000           mov eax, 1
// 0075a681  5f                   pop edi
// 0075a682  894118               mov dword ptr [ecx + 0x18], eax
// 0075a685  5e                   pop esi
// 0075a686  c20400               ret 4
// 0075a689  33c0                 xor eax, eax
// 0075a68b  5f                   pop edi
// 0075a68c  894118               mov dword ptr [ecx + 0x18], eax
// 0075a68f  5e                   pop esi
// 0075a690  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?SetScreenSize@CXTPDockState@@AAEXAAVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
