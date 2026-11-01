// from server: 100% by auto
// roc 2010-06 00821fc0  unit: CSelectionCaption  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00821fc0
//
// 00821fc0  53                   push ebx
// 00821fc1  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 00821fc7  56                   push esi
// 00821fc8  57                   push edi
// 00821fc9  6a00                 push 0
// 00821fcb  6a00                 push 0
// 00821fcd  8bf1                 mov esi, ecx
// 00821fcf  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 00821fd5  68f3000000           push 0xf3
// 00821fda  50                   push eax
// 00821fdb  ffd3                 call ebx
// 00821fdd  8b8e8c010000         mov ecx, dword ptr [esi + 0x18c]
// 00821fe3  8b11                 mov edx, dword ptr [ecx]
// 00821fe5  8b4268               mov eax, dword ptr [edx + 0x68]
// 00821fe8  ffd0                 call eax
// 00821fea  8b8e8c010000         mov ecx, dword ptr [esi + 0x18c]
// 00821ff0  85c9                 test ecx, ecx
// 00821ff2  7413                 je 0x822007
// 00821ff4  8b11                 mov edx, dword ptr [ecx]
// 00821ff6  8b4204               mov eax, dword ptr [edx + 4]
// 00821ff9  6a01                 push 1
// 00821ffb  ffd0                 call eax
// 00821ffd  c7868c01000000000000 mov dword ptr [esi + 0x18c], 0
// 00822007  8b4638               mov eax, dword ptr [esi + 0x38]
// 0082200a  85c0                 test eax, eax
// 0082200c  750a                 jne 0x822018
// 0082200e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00822011  51                   push ecx
// 00822012  ff154cba9e00         call dword ptr [0x9eba4c]
// 00822018  50                   push eax
// 00822019  e84c5cf8ff           call 0x7a7c6a
// 0082201e  8bf8                 mov edi, eax
// 00822020  85ff                 test edi, edi
// 00822022  7403                 je 0x822027
// 00822024  8b4720               mov eax, dword ptr [edi + 0x20]
// 00822027  50                   push eax
// 00822028  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0082202e  85c0                 test eax, eax
// 00822030  741d                 je 0x82204f
// 00822032  8b5720               mov edx, dword ptr [edi + 0x20]
// 00822035  6a00                 push 0
// 00822037  6a00                 push 0
// 00822039  683f270000           push 0x273f
// 0082203e  52                   push edx
// 0082203f  ffd3                 call ebx
// 00822041  8b4620               mov eax, dword ptr [esi + 0x20]
// 00822044  6a01                 push 1
// 00822046  6a00                 push 0
// 00822048  50                   push eax
// 00822049  ff1578ba9e00         call dword ptr [0x9eba78]
// 0082204f  5f                   pop edi
// 00822050  5e                   pop esi
// 00822051  5b                   pop ebx
// 00822052  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ?OnPushPinCancel@CXTCaption@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
