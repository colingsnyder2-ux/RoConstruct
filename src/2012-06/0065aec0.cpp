// from server: 100% by auto
// roc 2012-06 0065aec0  unit: seg_00650000  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065aec0
//
// 0065aec0  83ec08               sub esp, 8
// 0065aec3  53                   push ebx
// 0065aec4  56                   push esi
// 0065aec5  57                   push edi
// 0065aec6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0065aeca  6a08                 push 8
// 0065aecc  8d442410             lea eax, [esp + 0x10]
// 0065aed0  50                   push eax
// 0065aed1  57                   push edi
// 0065aed2  e8192fffff           call 0x64ddf0
// 0065aed7  0fb6742418           movzx esi, byte ptr [esp + 0x18]
// 0065aedc  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 0065aee1  0fb654241a           movzx edx, byte ptr [esp + 0x1a]
// 0065aee6  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 0065aeeb  c1e608               shl esi, 8
// 0065aeee  03f1                 add esi, ecx
// 0065aef0  c1e608               shl esi, 8
// 0065aef3  03f2                 add esi, edx
// 0065aef5  c1e608               shl esi, 8
// 0065aef8  03f0                 add esi, eax
// 0065aefa  83c40c               add esp, 0xc
// 0065aefd  81feffffff7f         cmp esi, 0x7fffffff
// 0065af03  760e                 jbe 0x65af13
// 0065af05  688ca0b800           push 0xb8a08c
// 0065af0a  57                   push edi
// 0065af0b  e8a032ffff           call 0x64e1b0
// 0065af10  83c408               add esp, 8
// 0065af13  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065af17  8d9f1c010000         lea ebx, [edi + 0x11c]
// 0065af1d  57                   push edi
// 0065af1e  890b                 mov dword ptr [ebx], ecx
// 0065af20  e84b2ffeff           call 0x63de70
// 0065af25  6a04                 push 4
// 0065af27  53                   push ebx
// 0065af28  57                   push edi
// 0065af29  e8622ffeff           call 0x63de90
// 0065af2e  53                   push ebx
// 0065af2f  57                   push edi
// 0065af30  e8ebf2ffff           call 0x65a220
// 0065af35  83c418               add esp, 0x18
// 0065af38  5f                   pop edi
// 0065af39  8bc6                 mov eax, esi
// 0065af3b  5e                   pop esi
// 0065af3c  5b                   pop ebx
// 0065af3d  83c408               add esp, 8
// 0065af40  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_read_chunk_header)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
