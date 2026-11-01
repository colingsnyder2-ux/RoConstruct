// from server: 100% by auto
// roc 2010-06 008134e0  unit: CXTColorDialog  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008134e0
//
// 008134e0  53                   push ebx
// 008134e1  56                   push esi
// 008134e2  8bf1                 mov esi, ecx
// 008134e4  e85b9c1600           call 0x97d144
// 008134e9  8bd8                 mov ebx, eax
// 008134eb  8b06                 mov eax, dword ptr [esi]
// 008134ed  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 008134f3  8bce                 mov ecx, esi
// 008134f5  ffd2                 call edx
// 008134f7  6a00                 push 0
// 008134f9  8bce                 mov ecx, esi
// 008134fb  e85c9c1600           call 0x97d15c
// 00813500  8d86b0000000         lea eax, [esi + 0xb0]
// 00813506  85c0                 test eax, eax
// 00813508  7449                 je 0x813553
// 0081350a  83782000             cmp dword ptr [eax + 0x20], 0
// 0081350e  7443                 je 0x813553
// 00813510  8b4620               mov eax, dword ptr [esi + 0x20]
// 00813513  57                   push edi
// 00813514  8b3d54ba9e00         mov edi, dword ptr [0x9eba54]
// 0081351a  6a00                 push 0
// 0081351c  6a00                 push 0
// 0081351e  6a31                 push 0x31
// 00813520  50                   push eax
// 00813521  ffd7                 call edi
// 00813523  50                   push eax
// 00813524  e87b4ff9ff           call 0x7a84a4
// 00813529  85c0                 test eax, eax
// 0081352b  7514                 jne 0x813541
// 0081352d  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 00813533  6a01                 push 1
// 00813535  50                   push eax
// 00813536  6a30                 push 0x30
// 00813538  51                   push ecx
// 00813539  ffd7                 call edi
// 0081353b  5f                   pop edi
// 0081353c  5e                   pop esi
// 0081353d  8bc3                 mov eax, ebx
// 0081353f  5b                   pop ebx
// 00813540  c3                   ret 
// 00813541  8b4004               mov eax, dword ptr [eax + 4]
// 00813544  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 0081354a  6a01                 push 1
// 0081354c  50                   push eax
// 0081354d  6a30                 push 0x30
// 0081354f  51                   push ecx
// 00813550  ffd7                 call edi
// 00813552  5f                   pop edi
// 00813553  5e                   pop esi
// 00813554  8bc3                 mov eax, ebx
// 00813556  5b                   pop ebx
// 00813557  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorDialog.cpp (function ?OnInitDialog@CXTColorDialog@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorDialog.cpp
