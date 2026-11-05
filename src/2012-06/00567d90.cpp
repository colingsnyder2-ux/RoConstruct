// roc 2012-06 00567d90  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567d90
//
// 00567d90  53                   push ebx
// 00567d91  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00567d95  56                   push esi
// 00567d96  53                   push ebx
// 00567d97  8bf1                 mov esi, ecx
// 00567d99  e8d2fbffff           call 0x567970
// 00567d9e  8b06                 mov eax, dword ptr [esi]
// 00567da0  8bd0                 mov edx, eax
// 00567da2  83e207               and edx, 7
// 00567da5  89542410             mov dword ptr [esp + 0x10], edx
// 00567da9  7526                 jne 0x567dd1
// 00567dab  f6c307               test bl, 7
// 00567dae  7521                 jne 0x567dd1
// 00567db0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00567db4  8bcb                 mov ecx, ebx
// 00567db6  c1e903               shr ecx, 3
// 00567db9  51                   push ecx
// 00567dba  c1e803               shr eax, 3
// 00567dbd  03460c               add eax, dword ptr [esi + 0xc]
// 00567dc0  52                   push edx
// 00567dc1  50                   push eax
// 00567dc2  e895b84100           call 0x98365c
// 00567dc7  83c40c               add esp, 0xc
// 00567dca  011e                 add dword ptr [esi], ebx
// 00567dcc  5e                   pop esi
// 00567dcd  5b                   pop ebx
// 00567dce  c20c00               ret 0xc
// 00567dd1  55                   push ebp
// 00567dd2  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00567dd6  85db                 test ebx, ebx
// 00567dd8  7678                 jbe 0x567e52
// 00567dda  57                   push edi
// 00567ddb  eb03                 jmp 0x567de0
// 00567ddd  8d4900               lea ecx, [ecx]
// 00567de0  8a4500               mov al, byte ptr [ebp]
// 00567de3  45                   inc ebp
// 00567de4  83fb08               cmp ebx, 8
// 00567de7  730d                 jae 0x567df6
// 00567de9  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 00567dee  7406                 je 0x567df6
// 00567df0  b108                 mov cl, 8
// 00567df2  2acb                 sub cl, bl
// 00567df4  d2e0                 shl al, cl
// 00567df6  8b0e                 mov ecx, dword ptr [esi]
// 00567df8  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00567dfb  c1e903               shr ecx, 3
// 00567dfe  85d2                 test edx, edx
// 00567e00  7505                 jne 0x567e07
// 00567e02  880439               mov byte ptr [ecx + edi], al
// 00567e05  eb34                 jmp 0x567e3b
// 00567e07  03f9                 add edi, ecx
// 00567e09  8ac8                 mov cl, al
// 00567e0b  884c2414             mov byte ptr [esp + 0x14], cl
// 00567e0f  8aca                 mov cl, dl
// 00567e11  8ad0                 mov dl, al
// 00567e13  d2ea                 shr dl, cl
// 00567e15  b908000000           mov ecx, 8
// 00567e1a  2b4c2418             sub ecx, dword ptr [esp + 0x18]
// 00567e1e  0817                 or byte ptr [edi], dl
// 00567e20  83f908               cmp ecx, 8
// 00567e23  7312                 jae 0x567e37
// 00567e25  3bcb                 cmp ecx, ebx
// 00567e27  730e                 jae 0x567e37
// 00567e29  8b16                 mov edx, dword ptr [esi]
// 00567e2b  d2e0                 shl al, cl
// 00567e2d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00567e30  c1ea03               shr edx, 3
// 00567e33  88440a01             mov byte ptr [edx + ecx + 1], al
// 00567e37  8b542418             mov edx, dword ptr [esp + 0x18]
// 00567e3b  83fb08               cmp ebx, 8
// 00567e3e  720f                 jb 0x567e4f
// 00567e40  830608               add dword ptr [esi], 8
// 00567e43  83eb08               sub ebx, 8
// 00567e46  7598                 jne 0x567de0
// 00567e48  5f                   pop edi
// 00567e49  5d                   pop ebp
// 00567e4a  5e                   pop esi
// 00567e4b  5b                   pop ebx
// 00567e4c  c20c00               ret 0xc
// 00567e4f  011e                 add dword ptr [esi], ebx
// 00567e51  5f                   pop edi
// 00567e52  5d                   pop ebp
// 00567e53  5e                   pop esi
// 00567e54  5b                   pop ebx
// 00567e55  c20c00               ret 0xc
// copied from an identical function in another client (function ?WriteBits@BitStream@RakNet@@QAEXPBEI_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp