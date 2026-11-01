// from server: 100% by auto
// roc 2009-12 0052efa0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052efa0
//
// 0052efa0  56                   push esi
// 0052efa1  6a01                 push 1
// 0052efa3  8bf1                 mov esi, ecx
// 0052efa5  e8a6fdffff           call 0x52ed50
// 0052efaa  8b06                 mov eax, dword ptr [esi]
// 0052efac  8bc8                 mov ecx, eax
// 0052efae  c1e803               shr eax, 3
// 0052efb1  83e107               and ecx, 7
// 0052efb4  750b                 jne 0x52efc1
// 0052efb6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0052efb9  c6040880             mov byte ptr [eax + ecx], 0x80
// 0052efbd  ff06                 inc dword ptr [esi]
// 0052efbf  5e                   pop esi
// 0052efc0  c3                   ret 
// 0052efc1  8b560c               mov edx, dword ptr [esi + 0xc]
// 0052efc4  03c2                 add eax, edx
// 0052efc6  ba80000000           mov edx, 0x80
// 0052efcb  d3fa                 sar edx, cl
// 0052efcd  0810                 or byte ptr [eax], dl
// 0052efcf  ff06                 inc dword ptr [esi]
// 0052efd1  5e                   pop esi
// 0052efd2  c3                   ret 
// library raknet-4.081/BitStream.cpp (function ?Write1@BitStream@RakNet@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp
