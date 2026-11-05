// from server: 100% by auto
// roc 2011-06 0053b2d0  unit: seg_00530000  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053b2d0
//
// 0053b2d0  51                   push ecx
// 0053b2d1  56                   push esi
// 0053b2d2  8bf1                 mov esi, ecx
// 0053b2d4  8b5658               mov edx, dword ptr [esi + 0x58]
// 0053b2d7  57                   push edi
// 0053b2d8  8b7e5c               mov edi, dword ptr [esi + 0x5c]
// 0053b2db  8bca                 mov ecx, edx
// 0053b2dd  83c104               add ecx, 4
// 0053b2e0  8bc7                 mov eax, edi
// 0053b2e2  83d000               adc eax, 0
// 0053b2e5  3b464c               cmp eax, dword ptr [esi + 0x4c]
// 0053b2e8  7c1e                 jl 0x53b308
// 0053b2ea  7f05                 jg 0x53b2f1
// 0053b2ec  3b4e48               cmp ecx, dword ptr [esi + 0x48]
// 0053b2ef  7617                 jbe 0x53b308
// 0053b2f1  8b4638               mov eax, dword ptr [esi + 0x38]
// 0053b2f4  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0053b2f7  6a00                 push 0
// 0053b2f9  03c2                 add eax, edx
// 0053b2fb  6a04                 push 4
// 0053b2fd  13cf                 adc ecx, edi
// 0053b2ff  51                   push ecx
// 0053b300  50                   push eax
// 0053b301  8bce                 mov ecx, esi
// 0053b303  e868820000           call 0x543570
// 0053b308  83465804             add dword ptr [esi + 0x58], 4
// 0053b30c  83565c00             adc dword ptr [esi + 0x5c], 0
// 0053b310  807e2800             cmp byte ptr [esi + 0x28], 0
// 0053b314  7431                 je 0x53b347
// 0053b316  8b5650               mov edx, dword ptr [esi + 0x50]
// 0053b319  8b4658               mov eax, dword ptr [esi + 0x58]
// 0053b31c  0fb64c10ff           movzx ecx, byte ptr [eax + edx - 1]
// 0053b321  03c2                 add eax, edx
// 0053b323  0fb650fe             movzx edx, byte ptr [eax - 2]
// 0053b327  884c2408             mov byte ptr [esp + 8], cl
// 0053b32b  0fb648fd             movzx ecx, byte ptr [eax - 3]
// 0053b32f  88542409             mov byte ptr [esp + 9], dl
// 0053b333  0fb650fc             movzx edx, byte ptr [eax - 4]
// 0053b337  884c240a             mov byte ptr [esp + 0xa], cl
// 0053b33b  8854240b             mov byte ptr [esp + 0xb], dl
// 0053b33f  8b442408             mov eax, dword ptr [esp + 8]
// 0053b343  5f                   pop edi
// 0053b344  5e                   pop esi
// 0053b345  59                   pop ecx
// 0053b346  c3                   ret 
// 0053b347  8b4650               mov eax, dword ptr [esi + 0x50]
// 0053b34a  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0053b34d  8b4408fc             mov eax, dword ptr [eax + ecx - 4]
// 0053b351  5f                   pop edi
// 0053b352  5e                   pop esi
// 0053b353  59                   pop ecx
// 0053b354  c3                   ret 
// library rbx2016-g3d/GImage_bmp.cpp (function ?readUInt32@BinaryInput@G3D@@QAEIXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_bmp.cpp
