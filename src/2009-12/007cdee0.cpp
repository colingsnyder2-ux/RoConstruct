// from server: 100% by auto
// roc 2009-12 007cdee0  unit: RBX::PartDropTool  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdee0
//
// 007cdee0  8b442404             mov eax, dword ptr [esp + 4]
// 007cdee4  8b4808               mov ecx, dword ptr [eax + 8]
// 007cdee7  83ec08               sub esp, 8
// 007cdeea  83f903               cmp ecx, 3
// 007cdeed  7431                 je 0x7cdf20
// 007cdeef  83f904               cmp ecx, 4
// 007cdef2  752a                 jne 0x7cdf1e
// 007cdef4  8b10                 mov edx, dword ptr [eax]
// 007cdef6  8d0c24               lea ecx, [esp]
// 007cdef9  51                   push ecx
// 007cdefa  83c210               add edx, 0x10
// 007cdefd  52                   push edx
// 007cdefe  e88dc2fcff           call 0x79a190
// 007cdf03  83c408               add esp, 8
// 007cdf06  85c0                 test eax, eax
// 007cdf08  7414                 je 0x7cdf1e
// 007cdf0a  8b442410             mov eax, dword ptr [esp + 0x10]
// 007cdf0e  dd0424               fld qword ptr [esp]
// 007cdf11  dd18                 fstp qword ptr [eax]
// 007cdf13  c7400803000000       mov dword ptr [eax + 8], 3
// 007cdf1a  83c408               add esp, 8
// 007cdf1d  c3                   ret 
// 007cdf1e  33c0                 xor eax, eax
// 007cdf20  83c408               add esp, 8
// 007cdf23  c3                   ret 
// library lua-5.1/lvm.c (function _luaV_tonumber)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
