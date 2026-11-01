// from server: 100% by auto
// roc 2009-06 00772f50  unit: CXTPPropertyGridToolBar  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772f50
//
// 00772f50  8b442408             mov eax, dword ptr [esp + 8]
// 00772f54  53                   push ebx
// 00772f55  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00772f59  c70000000000         mov dword ptr [eax], 0
// 00772f5f  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00772f62  83e801               sub eax, 1
// 00772f65  7556                 jne 0x772fbd
// 00772f67  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00772f6a  56                   push esi
// 00772f6b  57                   push edi
// 00772f6c  8b3d98ee8900         mov edi, dword ptr [0x89ee98]
// 00772f72  51                   push ecx
// 00772f73  ffd7                 call edi
// 00772f75  50                   push eax
// 00772f76  e8875dfaff           call 0x718d02
// 00772f7b  8bf0                 mov esi, eax
// 00772f7d  8b5620               mov edx, dword ptr [esi + 0x20]
// 00772f80  52                   push edx
// 00772f81  ffd7                 call edi
// 00772f83  50                   push eax
// 00772f84  e8795dfaff           call 0x718d02
// 00772f89  8b7620               mov esi, dword ptr [esi + 0x20]
// 00772f8c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00772f8f  8b4020               mov eax, dword ptr [eax + 0x20]
// 00772f92  56                   push esi
// 00772f93  51                   push ecx
// 00772f94  6838010000           push 0x138
// 00772f99  50                   push eax
// 00772f9a  ff1590ee8900         call dword ptr [0x89ee90]
// 00772fa0  5f                   pop edi
// 00772fa1  5e                   pop esi
// 00772fa2  85c0                 test eax, eax
// 00772fa4  7508                 jne 0x772fae
// 00772fa6  6a0f                 push 0xf
// 00772fa8  ff1574ec8900         call dword ptr [0x89ec74]
// 00772fae  8b5310               mov edx, dword ptr [ebx + 0x10]
// 00772fb1  50                   push eax
// 00772fb2  8d4b14               lea ecx, [ebx + 0x14]
// 00772fb5  51                   push ecx
// 00772fb6  52                   push edx
// 00772fb7  ff15b4ec8900         call dword ptr [0x89ecb4]
// 00772fbd  5b                   pop ebx
// 00772fbe  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnCustomDraw@CXTPPropertyGridToolBar@@IAEXPAUtagNMHDR@@PAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
