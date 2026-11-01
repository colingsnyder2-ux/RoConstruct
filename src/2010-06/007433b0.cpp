// from server: 100% by auto
// roc 2010-06 007433b0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 345 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007433b0
//
// 007433b0  56                   push esi
// 007433b1  57                   push edi
// 007433b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007433b6  8bf1                 mov esi, ecx
// 007433b8  3bf7                 cmp esi, edi
// 007433ba  0f8442010000         je 0x743502
// 007433c0  8b470c               mov eax, dword ptr [edi + 0xc]
// 007433c3  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 007433c6  2bc8                 sub ecx, eax
// 007433c8  b867666666           mov eax, 0x66666667
// 007433cd  f7e9                 imul ecx
// 007433cf  55                   push ebp
// 007433d0  c1fa04               sar edx, 4
// 007433d3  8bea                 mov ebp, edx
// 007433d5  c1ed1f               shr ebp, 0x1f
// 007433d8  03ea                 add ebp, edx
// 007433da  750f                 jne 0x7433eb
// 007433dc  8bce                 mov ecx, esi
// 007433de  e82df7ffff           call 0x742b10
// 007433e3  5d                   pop ebp
// 007433e4  5f                   pop edi
// 007433e5  8bc6                 mov eax, esi
// 007433e7  5e                   pop esi
// 007433e8  c20400               ret 4
// 007433eb  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007433ee  53                   push ebx
// 007433ef  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007433f2  2bcb                 sub ecx, ebx
// 007433f4  b867666666           mov eax, 0x66666667
// 007433f9  f7e9                 imul ecx
// 007433fb  c1fa04               sar edx, 4
// 007433fe  8bca                 mov ecx, edx
// 00743400  c1e91f               shr ecx, 0x1f
// 00743403  03ca                 add ecx, edx
// 00743405  3be9                 cmp ebp, ecx
// 00743407  7750                 ja 0x743459
// 00743409  8b4710               mov eax, dword ptr [edi + 0x10]
// 0074340c  53                   push ebx
// 0074340d  50                   push eax
// 0074340e  8b470c               mov eax, dword ptr [edi + 0xc]
// 00743411  50                   push eax
// 00743412  e869e8ffff           call 0x741c80
// 00743417  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0074341b  51                   push ecx
// 0074341c  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0074341f  8d5608               lea edx, [esi + 8]
// 00743422  52                   push edx
// 00743423  51                   push ecx
// 00743424  50                   push eax
// 00743425  e8f67ff6ff           call 0x6ab420
// 0074342a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 0074342d  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00743430  b867666666           mov eax, 0x66666667
// 00743435  f7e9                 imul ecx
// 00743437  c1fa04               sar edx, 4
// 0074343a  83c41c               add esp, 0x1c
// 0074343d  8bc2                 mov eax, edx
// 0074343f  c1e81f               shr eax, 0x1f
// 00743442  03c2                 add eax, edx
// 00743444  8d1480               lea edx, [eax + eax*4]
// 00743447  8b460c               mov eax, dword ptr [esi + 0xc]
// 0074344a  5b                   pop ebx
// 0074344b  5d                   pop ebp
// 0074344c  8d0cd0               lea ecx, [eax + edx*8]
// 0074344f  5f                   pop edi
// 00743450  894e10               mov dword ptr [esi + 0x10], ecx
// 00743453  8bc6                 mov eax, esi
// 00743455  5e                   pop esi
// 00743456  c20400               ret 4
// 00743459  85db                 test ebx, ebx
// 0074345b  7504                 jne 0x743461
// 0074345d  33c0                 xor eax, eax
// 0074345f  eb16                 jmp 0x743477
// 00743461  8b5614               mov edx, dword ptr [esi + 0x14]
// 00743464  2bd3                 sub edx, ebx
// 00743466  b867666666           mov eax, 0x66666667
// 0074346b  f7ea                 imul edx
// 0074346d  c1fa04               sar edx, 4
// 00743470  8bc2                 mov eax, edx
// 00743472  c1e81f               shr eax, 0x1f
// 00743475  03c2                 add eax, edx
// 00743477  3be8                 cmp ebp, eax
// 00743479  7730                 ja 0x7434ab
// 0074347b  8b470c               mov eax, dword ptr [edi + 0xc]
// 0074347e  8d1489               lea edx, [ecx + ecx*4]
// 00743481  8d2cd0               lea ebp, [eax + edx*8]
// 00743484  53                   push ebx
// 00743485  55                   push ebp
// 00743486  50                   push eax
// 00743487  e8f4e7ffff           call 0x741c80
// 0074348c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0074348f  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00743492  83c40c               add esp, 0xc
// 00743495  50                   push eax
// 00743496  51                   push ecx
// 00743497  55                   push ebp
// 00743498  8bce                 mov ecx, esi
// 0074349a  e8d1ebffff           call 0x742070
// 0074349f  5b                   pop ebx
// 007434a0  5d                   pop ebp
// 007434a1  894610               mov dword ptr [esi + 0x10], eax
// 007434a4  5f                   pop edi
// 007434a5  8bc6                 mov eax, esi
// 007434a7  5e                   pop esi
// 007434a8  c20400               ret 4
// 007434ab  85db                 test ebx, ebx
// 007434ad  7418                 je 0x7434c7
// 007434af  8b4610               mov eax, dword ptr [esi + 0x10]
// 007434b2  50                   push eax
// 007434b3  53                   push ebx
// 007434b4  8bce                 mov ecx, esi
// 007434b6  e8b5f0ffff           call 0x742570
// 007434bb  8b560c               mov edx, dword ptr [esi + 0xc]
// 007434be  52                   push edx
// 007434bf  e8d6440600           call 0x7a799a
// 007434c4  83c404               add esp, 4
// 007434c7  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 007434ca  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 007434cd  b867666666           mov eax, 0x66666667
// 007434d2  f7e9                 imul ecx
// 007434d4  c1fa04               sar edx, 4
// 007434d7  8bc2                 mov eax, edx
// 007434d9  c1e81f               shr eax, 0x1f
// 007434dc  03c2                 add eax, edx
// 007434de  50                   push eax
// 007434df  8bce                 mov ecx, esi
// 007434e1  e88ad2ffff           call 0x740770
// 007434e6  84c0                 test al, al
// 007434e8  7416                 je 0x743500
// 007434ea  8b460c               mov eax, dword ptr [esi + 0xc]
// 007434ed  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 007434f0  8b570c               mov edx, dword ptr [edi + 0xc]
// 007434f3  50                   push eax
// 007434f4  51                   push ecx
// 007434f5  52                   push edx
// 007434f6  8bce                 mov ecx, esi
// 007434f8  e873ebffff           call 0x742070
// 007434fd  894610               mov dword ptr [esi + 0x10], eax
// 00743500  5b                   pop ebx
// 00743501  5d                   pop ebp
// 00743502  5f                   pop edi
// 00743503  8bc6                 mov eax, esi
// 00743505  5e                   pop esi
// 00743506  c20400               ret 4
// library ogre-1.6.4/OgreEdgeListBuilder.cpp (function ??4?$vector@UEdgeGroup@EdgeData@Ogre@@V?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreEdgeListBuilder.cpp
