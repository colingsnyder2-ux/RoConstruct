// roc 2012-06 00567eb0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567eb0
//
// 00567eb0  8b442404             mov eax, dword ptr [esp + 4]
// 00567eb4  803800               cmp byte ptr [eax], 0
// 00567eb7  56                   push esi
// 00567eb8  8bf1                 mov esi, ecx
// 00567eba  6a01                 push 1
// 00567ebc  7432                 je 0x567ef0
// 00567ebe  e8adfaffff           call 0x567970
// 00567ec3  8b06                 mov eax, dword ptr [esi]
// 00567ec5  8bc8                 mov ecx, eax
// 00567ec7  c1e803               shr eax, 3
// 00567eca  83e107               and ecx, 7
// 00567ecd  750d                 jne 0x567edc
// 00567ecf  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567ed2  c6040880             mov byte ptr [eax + ecx], 0x80
// 00567ed6  ff06                 inc dword ptr [esi]
// 00567ed8  5e                   pop esi
// 00567ed9  c20400               ret 4
// 00567edc  8b560c               mov edx, dword ptr [esi + 0xc]
// 00567edf  03c2                 add eax, edx
// 00567ee1  ba80000000           mov edx, 0x80
// 00567ee6  d3fa                 sar edx, cl
// 00567ee8  0810                 or byte ptr [eax], dl
// 00567eea  ff06                 inc dword ptr [esi]
// 00567eec  5e                   pop esi
// 00567eed  c20400               ret 4
// 00567ef0  e87bfaffff           call 0x567970
// 00567ef5  8b06                 mov eax, dword ptr [esi]
// 00567ef7  a807                 test al, 7
// 00567ef9  750a                 jne 0x567f05
// 00567efb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567efe  c1e803               shr eax, 3
// 00567f01  c6040800             mov byte ptr [eax + ecx], 0
// 00567f05  ff06                 inc dword ptr [esi]
// 00567f07  5e                   pop esi
// 00567f08  c20400               ret 4
// copied from an identical function in another client (function ??$Write@_N@BitStream@RakNet@@QAEXAB_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp