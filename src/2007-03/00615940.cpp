// from server: 100% by auto
// roc 2007-03 00615940  unit: seg_00610000  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615940
//
// 00615940  83ec18               sub esp, 0x18
// 00615943  d9ee                 fldz 
// 00615945  83c8ff               or eax, 0xffffffff
// 00615948  89442414             mov dword ptr [esp + 0x14], eax
// 0061594c  dd5c2408             fstp qword ptr [esp + 8]
// 00615950  89442410             mov dword ptr [esp + 0x10], eax
// 00615954  8b442420             mov eax, dword ptr [esp + 0x20]
// 00615958  83e800               sub eax, 0
// 0061595b  53                   push ebx
// 0061595c  57                   push edi
// 0061595d  c744240805000000     mov dword ptr [esp + 8], 5
// 00615965  7443                 je 0x6159aa
// 00615967  83e801               sub eax, 1
// 0061596a  7429                 je 0x615995
// 0061596c  83e801               sub eax, 1
// 0061596f  755f                 jne 0x6159d0
// 00615971  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00615975  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00615979  53                   push ebx
// 0061597a  57                   push edi
// 0061597b  e8c0f8ffff           call 0x615240
// 00615980  8d442410             lea eax, [esp + 0x10]
// 00615984  50                   push eax
// 00615985  6a14                 push 0x14
// 00615987  e874feffff           call 0x615800
// 0061598c  83c410               add esp, 0x10
// 0061598f  5f                   pop edi
// 00615990  5b                   pop ebx
// 00615991  83c418               add esp, 0x18
// 00615994  c3                   ret 
// 00615995  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00615999  56                   push esi
// 0061599a  8b742430             mov esi, dword ptr [esp + 0x30]
// 0061599e  e87dfdffff           call 0x615720
// 006159a3  5e                   pop esi
// 006159a4  5f                   pop edi
// 006159a5  5b                   pop ebx
// 006159a6  83c418               add esp, 0x18
// 006159a9  c3                   ret 
// 006159aa  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 006159ae  833b04               cmp dword ptr [ebx], 4
// 006159b1  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006159b5  750a                 jne 0x6159c1
// 006159b7  53                   push ebx
// 006159b8  57                   push edi
// 006159b9  e882f8ffff           call 0x615240
// 006159be  83c408               add esp, 8
// 006159c1  8d4c2408             lea ecx, [esp + 8]
// 006159c5  51                   push ecx
// 006159c6  6a12                 push 0x12
// 006159c8  e833feffff           call 0x615800
// 006159cd  83c408               add esp, 8
// 006159d0  5f                   pop edi
// 006159d1  5b                   pop ebx
// 006159d2  83c418               add esp, 0x18
// 006159d5  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_prefix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
