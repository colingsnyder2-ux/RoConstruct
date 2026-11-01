// from server: 100% by auto
// roc 2009-12 00600ea0  unit: G3D::_internal::DialogTemplate  size: 489 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00600ea0
//
// 00600ea0  55                   push ebp
// 00600ea1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00600ea5  85ed                 test ebp, ebp
// 00600ea7  0f84da010000         je 0x601087
// 00600ead  56                   push esi
// 00600eae  8b742410             mov esi, dword ptr [esp + 0x10]
// 00600eb2  85f6                 test esi, esi
// 00600eb4  0f84cc010000         je 0x601086
// 00600eba  f7456800040000       test dword ptr [ebp + 0x68], 0x400
// 00600ec1  0f85bf010000         jne 0x601086
// 00600ec7  57                   push edi
// 00600ec8  55                   push ebp
// 00600ec9  e8d2b90000           call 0x60c8a0
// 00600ece  bf00100000           mov edi, 0x1000
// 00600ed3  83c404               add esp, 4
// 00600ed6  857d68               test dword ptr [ebp + 0x68], edi
// 00600ed9  7421                 je 0x600efc
// 00600edb  83bd3002000000       cmp dword ptr [ebp + 0x230], 0
// 00600ee2  7418                 je 0x600efc
// 00600ee4  68e4309c00           push 0x9c30e4
// 00600ee9  55                   push ebp
// 00600eea  e851f30000           call 0x610240
// 00600eef  83c408               add esp, 8
// 00600ef2  c7853002000000000000 mov dword ptr [ebp + 0x230], 0
// 00600efc  0fb6461c             movzx eax, byte ptr [esi + 0x1c]
// 00600f00  0fb64e1b             movzx ecx, byte ptr [esi + 0x1b]
// 00600f04  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00600f08  50                   push eax
// 00600f09  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 00600f0d  51                   push ecx
// 00600f0e  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00600f12  52                   push edx
// 00600f13  8b5604               mov edx, dword ptr [esi + 4]
// 00600f16  50                   push eax
// 00600f17  8b06                 mov eax, dword ptr [esi]
// 00600f19  51                   push ecx
// 00600f1a  52                   push edx
// 00600f1b  50                   push eax
// 00600f1c  55                   push ebp
// 00600f1d  e8cecb0000           call 0x60daf0
// 00600f22  83c420               add esp, 0x20
// 00600f25  f6460801             test byte ptr [esi + 8], 1
// 00600f29  7412                 je 0x600f3d
// 00600f2b  d94628               fld dword ptr [esi + 0x28]
// 00600f2e  83ec08               sub esp, 8
// 00600f31  dd1c24               fstp qword ptr [esp]
// 00600f34  55                   push ebp
// 00600f35  e8a6d10000           call 0x60e0e0
// 00600f3a  83c40c               add esp, 0xc
// 00600f3d  f7460800080000       test dword ptr [esi + 8], 0x800
// 00600f44  740e                 je 0x600f54
// 00600f46  0fb64e2c             movzx ecx, byte ptr [esi + 0x2c]
// 00600f4a  51                   push ecx
// 00600f4b  55                   push ebp
// 00600f4c  e86fd20000           call 0x60e1c0
// 00600f51  83c408               add esp, 8
// 00600f54  857e08               test dword ptr [esi + 8], edi
// 00600f57  7420                 je 0x600f79
// 00600f59  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 00600f5f  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00600f65  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 00600f6b  52                   push edx
// 00600f6c  50                   push eax
// 00600f6d  6a00                 push 0
// 00600f6f  51                   push ecx
// 00600f70  55                   push ebp
// 00600f71  e8fad20000           call 0x60e270
// 00600f76  83c414               add esp, 0x14
// 00600f79  f6460802             test byte ptr [esi + 8], 2
// 00600f7d  7412                 je 0x600f91
// 00600f7f  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 00600f83  52                   push edx
// 00600f84  8d4644               lea eax, [esi + 0x44]
// 00600f87  50                   push eax
// 00600f88  55                   push ebp
// 00600f89  e832d60000           call 0x60e5c0
// 00600f8e  83c40c               add esp, 0xc
// 00600f91  f6460804             test byte ptr [esi + 8], 4
// 00600f95  745b                 je 0x600ff2
// 00600f97  d9869c000000         fld dword ptr [esi + 0x9c]
// 00600f9d  83ec40               sub esp, 0x40
// 00600fa0  dd5c2438             fstp qword ptr [esp + 0x38]
// 00600fa4  d98698000000         fld dword ptr [esi + 0x98]
// 00600faa  dd5c2430             fstp qword ptr [esp + 0x30]
// 00600fae  d98694000000         fld dword ptr [esi + 0x94]
// 00600fb4  dd5c2428             fstp qword ptr [esp + 0x28]
// 00600fb8  d98690000000         fld dword ptr [esi + 0x90]
// 00600fbe  dd5c2420             fstp qword ptr [esp + 0x20]
// 00600fc2  d9868c000000         fld dword ptr [esi + 0x8c]
// 00600fc8  dd5c2418             fstp qword ptr [esp + 0x18]
// 00600fcc  d98688000000         fld dword ptr [esi + 0x88]
// 00600fd2  dd5c2410             fstp qword ptr [esp + 0x10]
// 00600fd6  d98684000000         fld dword ptr [esi + 0x84]
// 00600fdc  dd5c2408             fstp qword ptr [esp + 8]
// 00600fe0  d98680000000         fld dword ptr [esi + 0x80]
// 00600fe6  dd1c24               fstp qword ptr [esp]
// 00600fe9  55                   push ebp
// 00600fea  e8b1d60000           call 0x60e6a0
// 00600fef  83c444               add esp, 0x44
// 00600ff2  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00600ff8  85c0                 test eax, eax
// 00600ffa  0f847e000000         je 0x60107e
// 00601000  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00601006  8d0c80               lea ecx, [eax + eax*4]
// 00601009  8d148f               lea edx, [edi + ecx*4]
// 0060100c  3bfa                 cmp edi, edx
// 0060100e  736e                 jae 0x60107e
// 00601010  57                   push edi
// 00601011  55                   push ebp
// 00601012  e8c92a0000           call 0x603ae0
// 00601017  83c408               add esp, 8
// 0060101a  83f801               cmp eax, 1
// 0060101d  7446                 je 0x601065
// 0060101f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00601022  84c9                 test cl, cl
// 00601024  743f                 je 0x601065
// 00601026  f6c106               test cl, 6
// 00601029  753a                 jne 0x601065
// 0060102b  f6470320             test byte ptr [edi + 3], 0x20
// 0060102f  750e                 jne 0x60103f
// 00601031  83f803               cmp eax, 3
// 00601034  7409                 je 0x60103f
// 00601036  f7456c00000100       test dword ptr [ebp + 0x6c], 0x10000
// 0060103d  7426                 je 0x601065
// 0060103f  837f0c00             cmp dword ptr [edi + 0xc], 0
// 00601043  750e                 jne 0x601053
// 00601045  68c0309c00           push 0x9c30c0
// 0060104a  55                   push ebp
// 0060104b  e8f0f10000           call 0x610240
// 00601050  83c408               add esp, 8
// 00601053  8b470c               mov eax, dword ptr [edi + 0xc]
// 00601056  8b4f08               mov ecx, dword ptr [edi + 8]
// 00601059  50                   push eax
// 0060105a  51                   push ecx
// 0060105b  57                   push edi
// 0060105c  55                   push ebp
// 0060105d  e80eca0000           call 0x60da70
// 00601062  83c410               add esp, 0x10
// 00601065  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0060106b  8d1480               lea edx, [eax + eax*4]
// 0060106e  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00601074  83c714               add edi, 0x14
// 00601077  8d0c90               lea ecx, [eax + edx*4]
// 0060107a  3bf9                 cmp edi, ecx
// 0060107c  7292                 jb 0x601010
// 0060107e  814d6800040000       or dword ptr [ebp + 0x68], 0x400
// 00601085  5f                   pop edi
// 00601086  5e                   pop esi
// 00601087  5d                   pop ebp
// 00601088  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_write_info_before_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
