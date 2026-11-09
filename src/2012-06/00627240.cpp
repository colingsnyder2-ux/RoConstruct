// from server: 100% by auto
// roc 2012-06 00627240  unit: seg_00620000  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00627240
//
// 00627240  51                   push ecx
// 00627241  56                   push esi
// 00627242  8bf1                 mov esi, ecx
// 00627244  8b5658               mov edx, dword ptr [esi + 0x58]
// 00627247  57                   push edi
// 00627248  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0062724b  8bca                 mov ecx, edx
// 0062724d  83c104               add ecx, 4
// 00627250  8bc7                 mov eax, edi
// 00627252  83d000               adc eax, 0
// 00627255  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 00627258  7c1e                 jl 0x627278
// 0062725a  7f05                 jg 0x627261
// 0062725c  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0062725f  7617                 jbe 0x627278
// 00627261  8b4638               mov eax, dword ptr [esi + 0x38]
// 00627264  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00627267  6a00                 push 0
// 00627269  03c2                 add eax, edx
// 0062726b  6a04                 push 4
// 0062726d  13cf                 adc ecx, edi
// 0062726f  51                   push ecx
// 00627270  50                   push eax
// 00627271  8bce                 mov ecx, esi
// 00627273  e868810000           call 0x62f3e0
// 00627278  83465804             add dword ptr [esi + 0x58], 4
// 0062727c  83565c00             adc dword ptr [esi + 0x5c], 0
// 00627280  807e2800             cmp byte ptr [esi + 0x28], 0
// 00627284  7431                 je 0x6272b7
// 00627286  8b5650               mov edx, dword ptr [esi + 0x50]
// 00627289  8b4658               mov eax, dword ptr [esi + 0x58]
// 0062728c  0fb64c10ff           movzx ecx, byte ptr [eax + edx - 1]
// 00627291  03c2                 add eax, edx
// 00627293  0fb650fe             movzx edx, byte ptr [eax - 2]
// 00627297  884c2408             mov byte ptr [esp + 8], cl
// 0062729b  0fb648fd             movzx ecx, byte ptr [eax - 3]
// 0062729f  88542409             mov byte ptr [esp + 9], dl
// 006272a3  0fb650fc             movzx edx, byte ptr [eax - 4]
// 006272a7  884c240a             mov byte ptr [esp + 0xa], cl
// 006272ab  8854240b             mov byte ptr [esp + 0xb], dl
// 006272af  8b442408             mov eax, dword ptr [esp + 8]
// 006272b3  5f                   pop edi
// 006272b4  5e                   pop esi
// 006272b5  59                   pop ecx
// 006272b6  c3                   ret 
// 006272b7  8b4650               mov eax, dword ptr [esi + 0x50]
// 006272ba  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 006272bd  8b4408fc             mov eax, dword ptr [eax + ecx - 4]
// 006272c1  5f                   pop edi
// 006272c2  5e                   pop esi
// 006272c3  59                   pop ecx
// 006272c4  c3                   ret 
// library rbx2016-g3d/GImage_bmp.cpp (function ?readUInt32@BinaryInput@G3D@@QAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_bmp.cpp
