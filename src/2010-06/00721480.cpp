// from server: 100% by auto
// roc 2010-06 00721480  unit: RBX::UniversalTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721480
//
// 00721480  56                   push esi
// 00721481  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00721485  57                   push edi
// 00721486  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0072148a  8bc6                 mov eax, esi
// 0072148c  8bcf                 mov ecx, edi
// 0072148e  e80df9ffff           call 0x720da0
// 00721493  8b4808               mov ecx, dword ptr [eax + 8]
// 00721496  83c1fe               add ecx, -2
// 00721499  83f906               cmp ecx, 6
// 0072149c  772a                 ja 0x7214c8
// 0072149e  ff248dd0147200       jmp dword ptr [ecx*4 + 0x7214d0]
// 007214a5  8b00                 mov eax, dword ptr [eax]
// 007214a7  5f                   pop edi
// 007214a8  5e                   pop esi
// 007214a9  c3                   ret 
// 007214aa  8bc6                 mov eax, esi
// 007214ac  8bcf                 mov ecx, edi
// 007214ae  e8edf8ffff           call 0x720da0
// 007214b3  8b4808               mov ecx, dword ptr [eax + 8]
// 007214b6  83e902               sub ecx, 2
// 007214b9  74ea                 je 0x7214a5
// 007214bb  83e905               sub ecx, 5
// 007214be  7508                 jne 0x7214c8
// 007214c0  8b00                 mov eax, dword ptr [eax]
// 007214c2  5f                   pop edi
// 007214c3  83c018               add eax, 0x18
// 007214c6  5e                   pop esi
// 007214c7  c3                   ret 
// 007214c8  5f                   pop edi
// 007214c9  33c0                 xor eax, eax
// 007214cb  5e                   pop esi
// 007214cc  c3                   ret 
// 007214cd  8d4900               lea ecx, [ecx]
// 007214d0  aa                   stosb byte ptr es:[edi], al
// 007214d1  1472                 adc al, 0x72
// 007214d3  00c8                 add al, cl
// 007214d5  1472                 adc al, 0x72
// 007214d7  00c8                 add al, cl
// 007214d9  1472                 adc al, 0x72
// 007214db  00a5147200a5         add byte ptr [ebp - 0x5aff8dec], ah
// 007214e1  1472                 adc al, 0x72
// 007214e3  00aa147200a5         add byte ptr [edx - 0x5aff8dec], ch
// 007214e9  1472                 adc al, 0x72
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
