// from server: 100% by auto
// roc 2009-06 006b92b0  unit: RBX::UniversalTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b92b0
//
// 006b92b0  56                   push esi
// 006b92b1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b92b5  57                   push edi
// 006b92b6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b92ba  8bc6                 mov eax, esi
// 006b92bc  8bcf                 mov ecx, edi
// 006b92be  e80df9ffff           call 0x6b8bd0
// 006b92c3  8b4808               mov ecx, dword ptr [eax + 8]
// 006b92c6  83c1fe               add ecx, -2
// 006b92c9  83f906               cmp ecx, 6
// 006b92cc  772a                 ja 0x6b92f8
// 006b92ce  ff248d00936b00       jmp dword ptr [ecx*4 + 0x6b9300]
// 006b92d5  8b00                 mov eax, dword ptr [eax]
// 006b92d7  5f                   pop edi
// 006b92d8  5e                   pop esi
// 006b92d9  c3                   ret 
// 006b92da  8bc6                 mov eax, esi
// 006b92dc  8bcf                 mov ecx, edi
// 006b92de  e8edf8ffff           call 0x6b8bd0
// 006b92e3  8b4808               mov ecx, dword ptr [eax + 8]
// 006b92e6  83e902               sub ecx, 2
// 006b92e9  74ea                 je 0x6b92d5
// 006b92eb  83e905               sub ecx, 5
// 006b92ee  7508                 jne 0x6b92f8
// 006b92f0  8b00                 mov eax, dword ptr [eax]
// 006b92f2  5f                   pop edi
// 006b92f3  83c018               add eax, 0x18
// 006b92f6  5e                   pop esi
// 006b92f7  c3                   ret 
// 006b92f8  5f                   pop edi
// 006b92f9  33c0                 xor eax, eax
// 006b92fb  5e                   pop esi
// 006b92fc  c3                   ret 
// 006b92fd  8d4900               lea ecx, [ecx]
// 006b9300  da926b00f892         ficom dword ptr [edx - 0x6d07ff95]
// 006b9306  6b00f8               imul eax, dword ptr [eax], -8
// 006b9309  92                   xchg edx, eax
// 006b930a  6b00d5               imul eax, dword ptr [eax], -0x2b
// 006b930d  92                   xchg edx, eax
// 006b930e  6b00d5               imul eax, dword ptr [eax], -0x2b
// 006b9311  92                   xchg edx, eax
// 006b9312  6b00da               imul eax, dword ptr [eax], -0x26
// 006b9315  92                   xchg edx, eax
// 006b9316  6b00d5               imul eax, dword ptr [eax], -0x2b
// 006b9319  92                   xchg edx, eax
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
