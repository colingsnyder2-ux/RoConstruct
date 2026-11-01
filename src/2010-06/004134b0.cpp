// from server: 100% by auto
// roc 2010-06 004134b0  unit: CRbxChildFrame  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004134b0
//
// 004134b0  8b442408             mov eax, dword ptr [esp + 8]
// 004134b4  56                   push esi
// 004134b5  85c0                 test eax, eax
// 004134b7  7504                 jne 0x4134bd
// 004134b9  33f6                 xor esi, esi
// 004134bb  eb03                 jmp 0x4134c0
// 004134bd  8b7004               mov esi, dword ptr [eax + 4]
// 004134c0  8b442408             mov eax, dword ptr [esp + 8]
// 004134c4  85c0                 test eax, eax
// 004134c6  7504                 jne 0x4134cc
// 004134c8  33d2                 xor edx, edx
// 004134ca  eb03                 jmp 0x4134cf
// 004134cc  8b5004               mov edx, dword ptr [eax + 4]
// 004134cf  8b4104               mov eax, dword ptr [ecx + 4]
// 004134d2  56                   push esi
// 004134d3  52                   push edx
// 004134d4  50                   push eax
// 004134d5  e884473900           call 0x7a7c5e
// 004134da  8b8094000000         mov eax, dword ptr [eax + 0x94]
// 004134e0  8b08                 mov ecx, dword ptr [eax]
// 004134e2  e8d9fdffff           call 0x4132c0
// 004134e7  5e                   pop esi
// 004134e8  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPImageEditor.cpp (function ?Add@CImageList@@QAEHPAVCBitmap@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPImageEditor.cpp
