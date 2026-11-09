// from server: 100% by auto
// roc 2009-12 0052eb60  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052eb60
//
// 0052eb60  53                   push ebx
// 0052eb61  56                   push esi
// 0052eb62  8bd1                 mov edx, ecx
// 0052eb64  8b7208               mov esi, dword ptr [edx + 8]
// 0052eb67  8bce                 mov ecx, esi
// 0052eb69  83e107               and ecx, 7
// 0052eb6c  bb80000000           mov ebx, 0x80
// 0052eb71  57                   push edi
// 0052eb72  8b7a0c               mov edi, dword ptr [edx + 0xc]
// 0052eb75  8bc6                 mov eax, esi
// 0052eb77  d3fb                 sar ebx, cl
// 0052eb79  c1e803               shr eax, 3
// 0052eb7c  841c38               test byte ptr [eax + edi], bl
// 0052eb7f  5f                   pop edi
// 0052eb80  0f95c0               setne al
// 0052eb83  46                   inc esi
// 0052eb84  897208               mov dword ptr [edx + 8], esi
// 0052eb87  5e                   pop esi
// 0052eb88  5b                   pop ebx
// 0052eb89  c3                   ret 
// library raknet-4.081/BitStream.cpp (function ?ReadBit@BitStream@RakNet@@QAE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
