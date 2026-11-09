// from server: 100% by auto
// roc 2010-06 00801d10  unit: CXTPPropertyGridToolBar  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00801d10
//
// 00801d10  8b442408             mov eax, dword ptr [esp + 8]
// 00801d14  53                   push ebx
// 00801d15  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00801d19  c70000000000         mov dword ptr [eax], 0
// 00801d1f  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00801d22  83e801               sub eax, 1
// 00801d25  7556                 jne 0x801d7d
// 00801d27  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00801d2a  56                   push esi
// 00801d2b  57                   push edi
// 00801d2c  8b3d4cba9e00         mov edi, dword ptr [0x9eba4c]
// 00801d32  51                   push ecx
// 00801d33  ffd7                 call edi
// 00801d35  50                   push eax
// 00801d36  e82f5ffaff           call 0x7a7c6a
// 00801d3b  8bf0                 mov esi, eax
// 00801d3d  8b5620               mov edx, dword ptr [esi + 0x20]
// 00801d40  52                   push edx
// 00801d41  ffd7                 call edi
// 00801d43  50                   push eax
// 00801d44  e8215ffaff           call 0x7a7c6a
// 00801d49  8b7620               mov esi, dword ptr [esi + 0x20]
// 00801d4c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00801d4f  8b4020               mov eax, dword ptr [eax + 0x20]
// 00801d52  56                   push esi
// 00801d53  51                   push ecx
// 00801d54  6838010000           push 0x138
// 00801d59  50                   push eax
// 00801d5a  ff1554ba9e00         call dword ptr [0x9eba54]
// 00801d60  5f                   pop edi
// 00801d61  5e                   pop esi
// 00801d62  85c0                 test eax, eax
// 00801d64  7508                 jne 0x801d6e
// 00801d66  6a0f                 push 0xf
// 00801d68  ff1520ba9e00         call dword ptr [0x9eba20]
// 00801d6e  8b5310               mov edx, dword ptr [ebx + 0x10]
// 00801d71  50                   push eax
// 00801d72  8d4b14               lea ecx, [ebx + 0x14]
// 00801d75  51                   push ecx
// 00801d76  52                   push edx
// 00801d77  ff151cba9e00         call dword ptr [0x9eba1c]
// 00801d7d  5b                   pop ebx
// 00801d7e  c20800               ret 8
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnCustomDraw@CXTPPropertyGridToolBar@@IAEXPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
