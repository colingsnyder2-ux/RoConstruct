// from server: 100% by auto
// roc 2010-06 007213c0  unit: RBX::UniversalTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007213c0
//
// 007213c0  8b442408             mov eax, dword ptr [esp + 8]
// 007213c4  56                   push esi
// 007213c5  57                   push edi
// 007213c6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007213ca  8bcf                 mov ecx, edi
// 007213cc  e8cff9ffff           call 0x720da0
// 007213d1  8bf0                 mov esi, eax
// 007213d3  8b4608               mov eax, dword ptr [esi + 8]
// 007213d6  83c0fd               add eax, -3
// 007213d9  83f804               cmp eax, 4
// 007213dc  7733                 ja 0x721411
// 007213de  ff248518147200       jmp dword ptr [eax*4 + 0x721418]
// 007213e5  8b06                 mov eax, dword ptr [esi]
// 007213e7  8b400c               mov eax, dword ptr [eax + 0xc]
// 007213ea  5f                   pop edi
// 007213eb  5e                   pop esi
// 007213ec  c3                   ret 
// 007213ed  8b0e                 mov ecx, dword ptr [esi]
// 007213ef  8b4110               mov eax, dword ptr [ecx + 0x10]
// 007213f2  5f                   pop edi
// 007213f3  5e                   pop esi
// 007213f4  c3                   ret 
// 007213f5  8b16                 mov edx, dword ptr [esi]
// 007213f7  52                   push edx
// 007213f8  e893c30500           call 0x77d790
// 007213fd  83c404               add esp, 4
// 00721400  5f                   pop edi
// 00721401  5e                   pop esi
// 00721402  c3                   ret 
// 00721403  56                   push esi
// 00721404  57                   push edi
// 00721405  e8769d0500           call 0x77b180
// 0072140a  83c408               add esp, 8
// 0072140d  85c0                 test eax, eax
// 0072140f  75d4                 jne 0x7213e5
// 00721411  5f                   pop edi
// 00721412  33c0                 xor eax, eax
// 00721414  5e                   pop esi
// 00721415  c3                   ret 
// 00721416  8bff                 mov edi, edi
// 00721418  031472               add edx, dword ptr [edx + esi*2]
// 0072141b  00e5                 add ch, ah
// 0072141d  137200               adc esi, dword ptr [edx]
// 00721420  f5                   cmc 
// 00721421  137200               adc esi, dword ptr [edx]
// 00721424  111472               adc dword ptr [edx + esi*2], edx
// 00721427  00ed                 add ch, ch
// 00721429  137200               adc esi, dword ptr [edx]
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
