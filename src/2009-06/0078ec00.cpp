// from server: 100% by auto
// roc 2009-06 0078ec00  unit: CXTPPropertyGridView  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078ec00
//
// 0078ec00  56                   push esi
// 0078ec01  57                   push edi
// 0078ec02  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0078ec06  8d44240c             lea eax, [esp + 0xc]
// 0078ec0a  50                   push eax
// 0078ec0b  8bf1                 mov esi, ecx
// 0078ec0d  c70700000000         mov dword ptr [edi], 0
// 0078ec13  e8b81ffdff           call 0x760bd0
// 0078ec18  85c0                 test eax, eax
// 0078ec1a  7f0a                 jg 0x78ec26
// 0078ec1c  5f                   pop edi
// 0078ec1d  b857000780           mov eax, 0x80070057
// 0078ec22  5e                   pop esi
// 0078ec23  c21400               ret 0x14
// 0078ec26  48                   dec eax
// 0078ec27  50                   push eax
// 0078ec28  8d4eac               lea ecx, [esi - 0x54]
// 0078ec2b  e8c0edffff           call 0x78d9f0
// 0078ec30  85c0                 test eax, eax
// 0078ec32  74e8                 je 0x78ec1c
// 0078ec34  6a01                 push 1
// 0078ec36  8bc8                 mov ecx, eax
// 0078ec38  e8e7d20b00           call 0x84bf24
// 0078ec3d  8907                 mov dword ptr [edi], eax
// 0078ec3f  5f                   pop edi
// 0078ec40  33c0                 xor eax, eax
// 0078ec42  5e                   pop esi
// 0078ec43  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChild@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
