// from server: 100% by auto
// roc 2007-03 0065c9f0  unit: seg_00650000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065c9f0
//
// 0065c9f0  53                   push ebx
// 0065c9f1  8b1dc8ec7700         mov ebx, dword ptr [0x77ecc8]
// 0065c9f7  56                   push esi
// 0065c9f8  57                   push edi
// 0065c9f9  8bf9                 mov edi, ecx
// 0065c9fb  8b4720               mov eax, dword ptr [edi + 0x20]
// 0065c9fe  50                   push eax
// 0065c9ff  ffd3                 call ebx
// 0065ca01  50                   push eax
// 0065ca02  e8471cfcff           call 0x61e64e
// 0065ca07  8bf0                 mov esi, eax
// 0065ca09  85f6                 test esi, esi
// 0065ca0b  7453                 je 0x65ca60
// 0065ca0d  8bce                 mov ecx, esi
// 0065ca0f  e872e00d00           call 0x73aa86
// 0065ca14  a900000100           test eax, 0x10000
// 0065ca19  741c                 je 0x65ca37
// 0065ca1b  8bce                 mov ecx, esi
// 0065ca1d  e8a2e10d00           call 0x73abc4
// 0065ca22  a900000040           test eax, 0x40000000
// 0065ca27  740e                 je 0x65ca37
// 0065ca29  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0065ca2c  51                   push ecx
// 0065ca2d  ffd3                 call ebx
// 0065ca2f  50                   push eax
// 0065ca30  e8191cfcff           call 0x61e64e
// 0065ca35  8bf0                 mov esi, eax
// 0065ca37  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065ca3b  8b4720               mov eax, dword ptr [edi + 0x20]
// 0065ca3e  52                   push edx
// 0065ca3f  50                   push eax
// 0065ca40  8b4620               mov eax, dword ptr [esi + 0x20]
// 0065ca43  50                   push eax
// 0065ca44  ff1544ef7700         call dword ptr [0x77ef44]
// 0065ca4a  50                   push eax
// 0065ca4b  e8fe1bfcff           call 0x61e64e
// 0065ca50  8bc8                 mov ecx, eax
// 0065ca52  2bc7                 sub eax, edi
// 0065ca54  f7d8                 neg eax
// 0065ca56  5f                   pop edi
// 0065ca57  1bc0                 sbb eax, eax
// 0065ca59  5e                   pop esi
// 0065ca5a  23c1                 and eax, ecx
// 0065ca5c  5b                   pop ebx
// 0065ca5d  c20400               ret 4
// 0065ca60  5f                   pop edi
// 0065ca61  5e                   pop esi
// 0065ca62  33c0                 xor eax, eax
// 0065ca64  5b                   pop ebx
// 0065ca65  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?GetNextGridTabItem@CXTPPropertyGrid@@AAEPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
