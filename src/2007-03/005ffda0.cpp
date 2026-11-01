// from server: 100% by auto
// roc 2007-03 005ffda0  unit: seg_005f0000  size: 218 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffda0
//
// 005ffda0  83ec18               sub esp, 0x18
// 005ffda3  53                   push ebx
// 005ffda4  55                   push ebp
// 005ffda5  56                   push esi
// 005ffda6  8bf1                 mov esi, ecx
// 005ffda8  8bd8                 mov ebx, eax
// 005ffdaa  57                   push edi
// 005ffdab  8bc6                 mov eax, esi
// 005ffdad  e86edbffff           call 0x5fd920
// 005ffdb2  837e102e             cmp dword ptr [esi + 0x10], 0x2e
// 005ffdb6  757f                 jne 0x5ffe37
// 005ffdb8  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 005ffdbb  53                   push ebx
// 005ffdbc  55                   push ebp
// 005ffdbd  e87e540100           call 0x615240
// 005ffdc2  56                   push esi
// 005ffdc3  e8d8250000           call 0x6023a0
// 005ffdc8  83c40c               add esp, 0xc
// 005ffdcb  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 005ffdd2  7424                 je 0x5ffdf8
// 005ffdd4  681d010000           push 0x11d
// 005ffdd9  56                   push esi
// 005ffdda  e891100000           call 0x600e70
// 005ffddf  50                   push eax
// 005ffde0  8b4634               mov eax, dword ptr [esi + 0x34]
// 005ffde3  6828047c00           push 0x7c0428
// 005ffde8  50                   push eax
// 005ffde9  e8528affff           call 0x5f8840
// 005ffdee  50                   push eax
// 005ffdef  56                   push esi
// 005ffdf0  e87b110000           call 0x600f70
// 005ffdf5  83c41c               add esp, 0x1c
// 005ffdf8  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005ffdfb  56                   push esi
// 005ffdfc  e89f250000           call 0x6023a0
// 005ffe01  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 005ffe04  57                   push edi
// 005ffe05  51                   push ecx
// 005ffe06  e8154a0100           call 0x614820
// 005ffe0b  8d54241c             lea edx, [esp + 0x1c]
// 005ffe0f  52                   push edx
// 005ffe10  83c9ff               or ecx, 0xffffffff
// 005ffe13  53                   push ebx
// 005ffe14  55                   push ebp
// 005ffe15  894c2438             mov dword ptr [esp + 0x38], ecx
// 005ffe19  894c243c             mov dword ptr [esp + 0x3c], ecx
// 005ffe1d  c744242804000000     mov dword ptr [esp + 0x28], 4
// 005ffe25  89442430             mov dword ptr [esp + 0x30], eax
// 005ffe29  e8b2590100           call 0x6157e0
// 005ffe2e  83c418               add esp, 0x18
// 005ffe31  837e102e             cmp dword ptr [esi + 0x10], 0x2e
// 005ffe35  7481                 je 0x5ffdb8
// 005ffe37  837e103a             cmp dword ptr [esi + 0x10], 0x3a
// 005ffe3b  7533                 jne 0x5ffe70
// 005ffe3d  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 005ffe40  53                   push ebx
// 005ffe41  55                   push ebp
// 005ffe42  e8f9530100           call 0x615240
// 005ffe47  56                   push esi
// 005ffe48  e853250000           call 0x6023a0
// 005ffe4d  8d7c241c             lea edi, [esp + 0x1c]
// 005ffe51  e80ad7ffff           call 0x5fd560
// 005ffe56  8bc7                 mov eax, edi
// 005ffe58  50                   push eax
// 005ffe59  53                   push ebx
// 005ffe5a  55                   push ebp
// 005ffe5b  e880590100           call 0x6157e0
// 005ffe60  83c418               add esp, 0x18
// 005ffe63  5f                   pop edi
// 005ffe64  5e                   pop esi
// 005ffe65  5d                   pop ebp
// 005ffe66  b801000000           mov eax, 1
// 005ffe6b  5b                   pop ebx
// 005ffe6c  83c418               add esp, 0x18
// 005ffe6f  c3                   ret 
// 005ffe70  5f                   pop edi
// 005ffe71  5e                   pop esi
// 005ffe72  5d                   pop ebp
// 005ffe73  33c0                 xor eax, eax
// 005ffe75  5b                   pop ebx
// 005ffe76  83c418               add esp, 0x18
// 005ffe79  c3                   ret 
// library lua-5.1.1/lparser.c (function _funcname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
