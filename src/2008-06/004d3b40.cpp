// from server: 100% by auto
// roc 2008-06 004d3b40  unit: seg_004d0000  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d3b40
//
// 004d3b40  6aff                 push -1
// 004d3b42  68ee9b7c00           push 0x7c9bee
// 004d3b47  64a100000000         mov eax, dword ptr fs:[0]
// 004d3b4d  50                   push eax
// 004d3b4e  64892500000000       mov dword ptr fs:[0], esp
// 004d3b55  51                   push ecx
// 004d3b56  56                   push esi
// 004d3b57  8bf1                 mov esi, ecx
// 004d3b59  89742404             mov dword ptr [esp + 4], esi
// 004d3b5d  c74424100b000000     mov dword ptr [esp + 0x10], 0xb
// 004d3b65  e816ecffff           call 0x4d2780
// 004d3b6a  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d3b70  e86bb7ffff           call 0x4cf2e0
// 004d3b75  83be9807000000       cmp dword ptr [esi + 0x798], 0
// 004d3b7c  c644241009           mov byte ptr [esp + 0x10], 9
// 004d3b81  760f                 jbe 0x4d3b92
// 004d3b83  8b8690070000         mov eax, dword ptr [esi + 0x790]
// 004d3b89  50                   push eax
// 004d3b8a  e8ebca1c00           call 0x6a067a
// 004d3b8f  83c404               add esp, 4
// 004d3b92  8d8e28050000         lea ecx, [esi + 0x528]
// 004d3b98  c644241008           mov byte ptr [esp + 0x10], 8
// 004d3b9d  e86e98faff           call 0x47d410
// 004d3ba2  83bec004000000       cmp dword ptr [esi + 0x4c0], 0
// 004d3ba9  c644241007           mov byte ptr [esp + 0x10], 7
// 004d3bae  760f                 jbe 0x4d3bbf
// 004d3bb0  8b86b4040000         mov eax, dword ptr [esi + 0x4b4]
// 004d3bb6  50                   push eax
// 004d3bb7  e8beca1c00           call 0x6a067a
// 004d3bbc  83c404               add esp, 4
// 004d3bbf  8d8ec0000000         lea ecx, [esi + 0xc0]
// 004d3bc5  c644241006           mov byte ptr [esp + 0x10], 6
// 004d3bca  e8d115fdff           call 0x4a51a0
// 004d3bcf  8d8ea4000000         lea ecx, [esi + 0xa4]
// 004d3bd5  c644241005           mov byte ptr [esp + 0x10], 5
// 004d3bda  e82168feff           call 0x4ba400
// 004d3bdf  68f0dd4c00           push 0x4cddf0
// 004d3be4  6a04                 push 4
// 004d3be6  6a10                 push 0x10
// 004d3be8  8d4664               lea eax, [esi + 0x64]
// 004d3beb  50                   push eax
// 004d3bec  c644242004           mov byte ptr [esp + 0x20], 4
// 004d3bf1  e865da1c00           call 0x6a165b
// 004d3bf6  837e6000             cmp dword ptr [esi + 0x60], 0
// 004d3bfa  c644241003           mov byte ptr [esp + 0x10], 3
// 004d3bff  760c                 jbe 0x4d3c0d
// 004d3c01  8b4654               mov eax, dword ptr [esi + 0x54]
// 004d3c04  50                   push eax
// 004d3c05  e870ca1c00           call 0x6a067a
// 004d3c0a  83c404               add esp, 4
// 004d3c0d  8d4e38               lea ecx, [esi + 0x38]
// 004d3c10  c644241002           mov byte ptr [esp + 0x10], 2
// 004d3c15  e856e9ffff           call 0x4d2570
// 004d3c1a  8d4e1c               lea ecx, [esi + 0x1c]
// 004d3c1d  c644241001           mov byte ptr [esp + 0x10], 1
// 004d3c22  e8b9e8ffff           call 0x4d24e0
// 004d3c27  837e1800             cmp dword ptr [esi + 0x18], 0
// 004d3c2b  c644241000           mov byte ptr [esp + 0x10], 0
// 004d3c30  760c                 jbe 0x4d3c3e
// 004d3c32  8b460c               mov eax, dword ptr [esi + 0xc]
// 004d3c35  50                   push eax
// 004d3c36  e83fca1c00           call 0x6a067a
// 004d3c3b  83c404               add esp, 4
// 004d3c3e  837e0800             cmp dword ptr [esi + 8], 0
// 004d3c42  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004d3c4a  760b                 jbe 0x4d3c57
// 004d3c4c  8b0e                 mov ecx, dword ptr [esi]
// 004d3c4e  51                   push ecx
// 004d3c4f  e826ca1c00           call 0x6a067a
// 004d3c54  83c404               add esp, 4
// 004d3c57  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004d3c5b  5e                   pop esi
// 004d3c5c  64890d00000000       mov dword ptr fs:[0], ecx
// 004d3c63  83c410               add esp, 0x10
// 004d3c66  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1ReliabilityLayer@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
