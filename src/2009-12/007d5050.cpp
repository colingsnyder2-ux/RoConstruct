// from server: 100% by auto
// roc 2009-12 007d5050  unit: seg_007d0000  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5050
//
// 007d5050  83ec18               sub esp, 0x18
// 007d5053  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d5056  6a0c                 push 0xc
// 007d5058  8d442410             lea eax, [esp + 0x10]
// 007d505c  50                   push eax
// 007d505d  51                   push ecx
// 007d505e  c744240c1b4c7561     mov dword ptr [esp + 0xc], 0x61754c1b
// 007d5066  c644241051           mov byte ptr [esp + 0x10], 0x51
// 007d506b  c644241100           mov byte ptr [esp + 0x11], 0
// 007d5070  c644241201           mov byte ptr [esp + 0x12], 1
// 007d5075  c644241304           mov byte ptr [esp + 0x13], 4
// 007d507a  c644241404           mov byte ptr [esp + 0x14], 4
// 007d507f  c644241504           mov byte ptr [esp + 0x15], 4
// 007d5084  c644241608           mov byte ptr [esp + 0x16], 8
// 007d5089  c644241700           mov byte ptr [esp + 0x17], 0
// 007d508e  e80dc1ffff           call 0x7d11a0
// 007d5093  83c40c               add esp, 0xc
// 007d5096  85c0                 test eax, eax
// 007d5098  7423                 je 0x7d50bd
// 007d509a  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d509d  8b06                 mov eax, dword ptr [esi]
// 007d509f  6858f09e00           push 0x9ef058
// 007d50a4  52                   push edx
// 007d50a5  683cf09e00           push 0x9ef03c
// 007d50aa  50                   push eax
// 007d50ab  e8d054fcff           call 0x79a580
// 007d50b0  8b0e                 mov ecx, dword ptr [esi]
// 007d50b2  6a03                 push 3
// 007d50b4  51                   push ecx
// 007d50b5  e89627fcff           call 0x797850
// 007d50ba  83c418               add esp, 0x18
// 007d50bd  b80c000000           mov eax, 0xc
// 007d50c2  33c9                 xor ecx, ecx
// 007d50c4  8b140c               mov edx, dword ptr [esp + ecx]
// 007d50c7  3b540c0c             cmp edx, dword ptr [esp + ecx + 0xc]
// 007d50cb  750f                 jne 0x7d50dc
// 007d50cd  83e804               sub eax, 4
// 007d50d0  83c104               add ecx, 4
// 007d50d3  83f804               cmp eax, 4
// 007d50d6  73ec                 jae 0x7d50c4
// 007d50d8  83c418               add esp, 0x18
// 007d50db  c3                   ret 
// 007d50dc  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d50df  8b0e                 mov ecx, dword ptr [esi]
// 007d50e1  68a0f09e00           push 0x9ef0a0
// 007d50e6  50                   push eax
// 007d50e7  683cf09e00           push 0x9ef03c
// 007d50ec  51                   push ecx
// 007d50ed  e88e54fcff           call 0x79a580
// 007d50f2  8b16                 mov edx, dword ptr [esi]
// 007d50f4  6a03                 push 3
// 007d50f6  52                   push edx
// 007d50f7  e85427fcff           call 0x797850
// 007d50fc  83c418               add esp, 0x18
// 007d50ff  83c418               add esp, 0x18
// 007d5102  c3                   ret 
// library lua-5.1/lundump.c (function _LoadHeader)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
