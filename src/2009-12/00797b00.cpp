// roc 2009-12 00797b00  unit: lua_exception  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797b00
//
// 00797b00  56                   push esi
// 00797b01  8b742408             mov esi, dword ptr [esp + 8]
// 00797b05  66ff4634             inc word ptr [esi + 0x34]
// 00797b09  0fb74634             movzx eax, word ptr [esi + 0x34]
// 00797b0d  b9c8000000           mov ecx, 0xc8
// 00797b12  663bc1               cmp ax, cx
// 00797b15  7215                 jb 0x797b2c
// 00797b17  8bd1                 mov edx, ecx
// 00797b19  663bc2               cmp ax, dx
// 00797b1c  754f                 jne 0x797b6d
// 00797b1e  68e4a99e00           push 0x9ea9e4
// 00797b23  56                   push esi
// 00797b24  e817380000           call 0x79b340
// 00797b29  83c408               add esp, 8
// 00797b2c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00797b30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00797b34  52                   push edx
// 00797b35  50                   push eax
// 00797b36  56                   push esi
// 00797b37  e804feffff           call 0x797940
// 00797b3c  83c40c               add esp, 0xc
// 00797b3f  85c0                 test eax, eax
// 00797b41  750b                 jne 0x797b4e
// 00797b43  6a01                 push 1
// 00797b45  56                   push esi
// 00797b46  e8f56f0300           call 0x7ceb40
// 00797b4b  83c408               add esp, 8
// 00797b4e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00797b51  b9ffff0000           mov ecx, 0xffff
// 00797b56  66014e34             add word ptr [esi + 0x34], cx
// 00797b5a  8b5044               mov edx, dword ptr [eax + 0x44]
// 00797b5d  3b5040               cmp edx, dword ptr [eax + 0x40]
// 00797b60  7209                 jb 0x797b6b
// 00797b62  56                   push esi
// 00797b63  e8a8600300           call 0x7cdc10
// 00797b68  83c404               add esp, 4
// 00797b6b  5e                   pop esi
// 00797b6c  c3                   ret 
// 00797b6d  b9e1000000           mov ecx, 0xe1
// 00797b72  663bc1               cmp ax, cx
// 00797b75  72b5                 jb 0x797b2c
// 00797b77  6a05                 push 5
// 00797b79  56                   push esi
// 00797b7a  e8d1fcffff           call 0x797850
// library lua-5.1/ldo.c (function _luaD_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
