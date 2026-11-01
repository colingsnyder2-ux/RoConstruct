// from server: 100% by auto
// roc 2010-06 008919c0  unit: CXTColorBase  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008919c0
//
// 008919c0  56                   push esi
// 008919c1  8bf1                 mov esi, ecx
// 008919c3  e8a865f1ff           call 0x7a7f70
// 008919c8  f644240801           test byte ptr [esp + 8], 1
// 008919cd  742d                 je 0x8919fc
// 008919cf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008919d3  8b06                 mov eax, dword ptr [esi]
// 008919d5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008919d9  8b804c010000         mov eax, dword ptr [eax + 0x14c]
// 008919df  51                   push ecx
// 008919e0  52                   push edx
// 008919e1  8bce                 mov ecx, esi
// 008919e3  ffd0                 call eax
// 008919e5  ff1580ba9e00         call dword ptr [0x9eba80]
// 008919eb  50                   push eax
// 008919ec  e87962f1ff           call 0x7a7c6a
// 008919f1  3bc6                 cmp eax, esi
// 008919f3  7407                 je 0x8919fc
// 008919f5  8bce                 mov ecx, esi
// 008919f7  e84663f1ff           call 0x7a7d42
// 008919fc  5e                   pop esi
// 008919fd  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPageCustom.cpp (function ?OnMouseMove@CXTColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPageCustom.cpp
