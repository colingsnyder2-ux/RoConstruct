// from server: 100% by auto
// roc 2010-06 007e9690  unit: CXTPControls  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9690
//
// 007e9690  8b442404             mov eax, dword ptr [esp + 4]
// 007e9694  8b10                 mov edx, dword ptr [eax]
// 007e9696  895124               mov dword ptr [ecx + 0x24], edx
// 007e9699  8b5004               mov edx, dword ptr [eax + 4]
// 007e969c  56                   push esi
// 007e969d  8b711c               mov esi, dword ptr [ecx + 0x1c]
// 007e96a0  895128               mov dword ptr [ecx + 0x28], edx
// 007e96a3  8b10                 mov edx, dword ptr [eax]
// 007e96a5  57                   push edi
// 007e96a6  8b7920               mov edi, dword ptr [ecx + 0x20]
// 007e96a9  3bd6                 cmp edx, esi
// 007e96ab  7505                 jne 0x7e96b2
// 007e96ad  397804               cmp dword ptr [eax + 4], edi
// 007e96b0  7417                 je 0x7e96c9
// 007e96b2  85d2                 test edx, edx
// 007e96b4  7413                 je 0x7e96c9
// 007e96b6  83780400             cmp dword ptr [eax + 4], 0
// 007e96ba  740d                 je 0x7e96c9
// 007e96bc  b801000000           mov eax, 1
// 007e96c1  5f                   pop edi
// 007e96c2  894118               mov dword ptr [ecx + 0x18], eax
// 007e96c5  5e                   pop esi
// 007e96c6  c20400               ret 4
// 007e96c9  33c0                 xor eax, eax
// 007e96cb  5f                   pop edi
// 007e96cc  894118               mov dword ptr [ecx + 0x18], eax
// 007e96cf  5e                   pop esi
// 007e96d0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPDockState.cpp (function ?SetScreenSize@CXTPDockState@@AAEXAAVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockState.cpp
