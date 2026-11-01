// from server: 100% by auto
// roc 2009-12 00869c20  unit: CXTPPropertyGridView  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00869c20
//
// 00869c20  56                   push esi
// 00869c21  57                   push edi
// 00869c22  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00869c26  8d44240c             lea eax, [esp + 0xc]
// 00869c2a  50                   push eax
// 00869c2b  8bf1                 mov esi, ecx
// 00869c2d  c70700000000         mov dword ptr [edi], 0
// 00869c33  e8681dfdff           call 0x83b9a0
// 00869c38  85c0                 test eax, eax
// 00869c3a  7f0a                 jg 0x869c46
// 00869c3c  5f                   pop edi
// 00869c3d  b857000780           mov eax, 0x80070057
// 00869c42  5e                   pop esi
// 00869c43  c21400               ret 0x14
// 00869c46  48                   dec eax
// 00869c47  50                   push eax
// 00869c48  8d4eac               lea ecx, [esi - 0x54]
// 00869c4b  e8b0edffff           call 0x868a00
// 00869c50  85c0                 test eax, eax
// 00869c52  74e8                 je 0x869c3c
// 00869c54  6a01                 push 1
// 00869c56  8bc8                 mov ecx, eax
// 00869c58  e8d9c70b00           call 0x926436
// 00869c5d  8907                 mov dword ptr [edi], eax
// 00869c5f  5f                   pop edi
// 00869c60  33c0                 xor eax, eax
// 00869c62  5e                   pop esi
// 00869c63  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChild@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
