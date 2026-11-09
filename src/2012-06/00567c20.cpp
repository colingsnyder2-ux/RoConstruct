// roc 2012-06 00567c20  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567c20
//
// 00567c20  51                   push ecx
// 00567c21  53                   push ebx
// 00567c22  55                   push ebp
// 00567c23  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00567c27  56                   push esi
// 00567c28  57                   push edi
// 00567c29  55                   push ebp
// 00567c2a  8bf1                 mov esi, ecx
// 00567c2c  e83ffdffff           call 0x567970
// 00567c31  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00567c35  8b4f08               mov ecx, dword ptr [edi + 8]
// 00567c38  f6c107               test cl, 7
// 00567c3b  754a                 jne 0x567c87
// 00567c3d  8b06                 mov eax, dword ptr [esi]
// 00567c3f  a807                 test al, 7
// 00567c41  7544                 jne 0x567c87
// 00567c43  8b570c               mov edx, dword ptr [edi + 0xc]
// 00567c46  c1e903               shr ecx, 3
// 00567c49  8bdd                 mov ebx, ebp
// 00567c4b  c1eb03               shr ebx, 3
// 00567c4e  c1e803               shr eax, 3
// 00567c51  03460c               add eax, dword ptr [esi + 0xc]
// 00567c54  53                   push ebx
// 00567c55  03d1                 add edx, ecx
// 00567c57  52                   push edx
// 00567c58  50                   push eax
// 00567c59  894c2428             mov dword ptr [esp + 0x28], ecx
// 00567c5d  e8fab94100           call 0x98365c
// 00567c62  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00567c66  8d140b               lea edx, [ebx + ecx]
// 00567c69  03d2                 add edx, edx
// 00567c6b  8d04dd00000000       lea eax, [ebx*8]
// 00567c72  03d2                 add edx, edx
// 00567c74  2be8                 sub ebp, eax
// 00567c76  03d2                 add edx, edx
// 00567c78  8d04dd00000000       lea eax, [ebx*8]
// 00567c7f  83c40c               add esp, 0xc
// 00567c82  895708               mov dword ptr [edi + 8], edx
// 00567c85  0106                 add dword ptr [esi], eax
// 00567c87  85ed                 test ebp, ebp
// 00567c89  0f867f000000         jbe 0x567d0e
// 00567c8f  90                   nop 
// 00567c90  8b4f08               mov ecx, dword ptr [edi + 8]
// 00567c93  4d                   dec ebp
// 00567c94  8d5101               lea edx, [ecx + 1]
// 00567c97  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00567c9b  3b17                 cmp edx, dword ptr [edi]
// 00567c9d  776f                 ja 0x567d0e
// 00567c9f  8b06                 mov eax, dword ptr [esi]
// 00567ca1  8b5f0c               mov ebx, dword ptr [edi + 0xc]
// 00567ca4  8bd0                 mov edx, eax
// 00567ca6  83e207               and edx, 7
// 00567ca9  89542410             mov dword ptr [esp + 0x10], edx
// 00567cad  8bd1                 mov edx, ecx
// 00567caf  b880000000           mov eax, 0x80
// 00567cb4  7527                 jne 0x567cdd
// 00567cb6  83e107               and ecx, 7
// 00567cb9  d3f8                 sar eax, cl
// 00567cbb  c1ea03               shr edx, 3
// 00567cbe  84041a               test byte ptr [edx + ebx], al
// 00567cc1  8b06                 mov eax, dword ptr [esi]
// 00567cc3  740c                 je 0x567cd1
// 00567cc5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567cc8  c1e803               shr eax, 3
// 00567ccb  c6040880             mov byte ptr [eax + ecx], 0x80
// 00567ccf  eb30                 jmp 0x567d01
// 00567cd1  8b560c               mov edx, dword ptr [esi + 0xc]
// 00567cd4  c1e803               shr eax, 3
// 00567cd7  c6041000             mov byte ptr [eax + edx], 0
// 00567cdb  eb24                 jmp 0x567d01
// 00567cdd  83e107               and ecx, 7
// 00567ce0  d3f8                 sar eax, cl
// 00567ce2  c1ea03               shr edx, 3
// 00567ce5  84041a               test byte ptr [edx + ebx], al
// 00567ce8  8b06                 mov eax, dword ptr [esi]
// 00567cea  7415                 je 0x567d01
// 00567cec  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567cef  c1e803               shr eax, 3
// 00567cf2  03c1                 add eax, ecx
// 00567cf4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00567cf8  ba80000000           mov edx, 0x80
// 00567cfd  d3fa                 sar edx, cl
// 00567cff  0810                 or byte ptr [eax], dl
// 00567d01  ff4708               inc dword ptr [edi + 8]
// 00567d04  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00567d08  ff06                 inc dword ptr [esi]
// 00567d0a  85ed                 test ebp, ebp
// 00567d0c  7782                 ja 0x567c90
// 00567d0e  5f                   pop edi
// 00567d0f  5e                   pop esi
// 00567d10  5d                   pop ebp
// 00567d11  5b                   pop ebx
// 00567d12  59                   pop ecx
// 00567d13  c20800               ret 8
// copied from an identical function in another client (function ?Write@BitStream@RakNet@@QAEXPAV12@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp