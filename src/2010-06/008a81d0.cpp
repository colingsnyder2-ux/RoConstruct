// from server: 100% by auto
// roc 2010-06 008a81d0  unit: CXTButtonTheme  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a81d0
//
// 008a81d0  53                   push ebx
// 008a81d1  56                   push esi
// 008a81d2  57                   push edi
// 008a81d3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008a81d7  8bf1                 mov esi, ecx
// 008a81d9  8b06                 mov eax, dword ptr [esi]
// 008a81db  8b5014               mov edx, dword ptr [eax + 0x14]
// 008a81de  57                   push edi
// 008a81df  ffd2                 call edx
// 008a81e1  8a5c2410             mov bl, byte ptr [esp + 0x10]
// 008a81e5  85c0                 test eax, eax
// 008a81e7  747c                 je 0x8a8265
// 008a81e9  55                   push ebp
// 008a81ea  8bcf                 mov ecx, edi
// 008a81ec  bd01000000           mov ebp, 1
// 008a81f1  e81a16ffff           call 0x899810
// 008a81f6  3c01                 cmp al, 1
// 008a81f8  7505                 jne 0x8a81ff
// 008a81fa  bd05000000           mov ebp, 5
// 008a81ff  83bfa000000000       cmp dword ptr [edi + 0xa0], 0
// 008a8206  750b                 jne 0x8a8213
// 008a8208  ff1584bc9e00         call dword ptr [0x9ebc84]
// 008a820e  3b4720               cmp eax, dword ptr [edi + 0x20]
// 008a8211  7505                 jne 0x8a8218
// 008a8213  bd02000000           mov ebp, 2
// 008a8218  f6c301               test bl, 1
// 008a821b  7506                 jne 0x8a8223
// 008a821d  837f7c00             cmp dword ptr [edi + 0x7c], 0
// 008a8221  7405                 je 0x8a8228
// 008a8223  bd03000000           mov ebp, 3
// 008a8228  f6c304               test bl, 4
// 008a822b  7405                 je 0x8a8232
// 008a822d  bd04000000           mov ebp, 4
// 008a8232  8b4634               mov eax, dword ptr [esi + 0x34]
// 008a8235  83f8ff               cmp eax, -1
// 008a8238  7503                 jne 0x8a823d
// 008a823a  8b4630               mov eax, dword ptr [esi + 0x30]
// 008a823d  8d4c2418             lea ecx, [esp + 0x18]
// 008a8241  51                   push ecx
// 008a8242  68db0e0000           push 0xedb
// 008a8247  55                   push ebp
// 008a8248  6a01                 push 1
// 008a824a  8d4e74               lea ecx, [esi + 0x74]
// 008a824d  89442428             mov dword ptr [esp + 0x28], eax
// 008a8251  e85a77f7ff           call 0x81f9b0
// 008a8256  5d                   pop ebp
// 008a8257  85c0                 test eax, eax
// 008a8259  7c0a                 jl 0x8a8265
// 008a825b  8b442414             mov eax, dword ptr [esp + 0x14]
// 008a825f  5f                   pop edi
// 008a8260  5e                   pop esi
// 008a8261  5b                   pop ebx
// 008a8262  c20800               ret 8
// 008a8265  f6c304               test bl, 4
// 008a8268  7411                 je 0x8a827b
// 008a826a  8b4640               mov eax, dword ptr [esi + 0x40]
// 008a826d  83f8ff               cmp eax, -1
// 008a8270  7514                 jne 0x8a8286
// 008a8272  8b463c               mov eax, dword ptr [esi + 0x3c]
// 008a8275  5f                   pop edi
// 008a8276  5e                   pop esi
// 008a8277  5b                   pop ebx
// 008a8278  c20800               ret 8
// 008a827b  8b4634               mov eax, dword ptr [esi + 0x34]
// 008a827e  83f8ff               cmp eax, -1
// 008a8281  7503                 jne 0x8a8286
// 008a8283  8b4630               mov eax, dword ptr [esi + 0x30]
// 008a8286  5f                   pop edi
// 008a8287  5e                   pop esi
// 008a8288  5b                   pop ebx
// 008a8289  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetTextColor@CXTButtonTheme@@MAEKIPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
