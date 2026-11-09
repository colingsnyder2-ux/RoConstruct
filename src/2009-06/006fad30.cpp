// from server: 100% by auto
// roc 2009-06 006fad30  unit: RBX::GroupDragTool  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fad30
//
// 006fad30  56                   push esi
// 006fad31  57                   push edi
// 006fad32  e819f7ffff           call 0x6fa450
// 006fad37  8b06                 mov eax, dword ptr [esi]
// 006fad39  48                   dec eax
// 006fad3a  83c408               add esp, 8
// 006fad3d  83f80b               cmp eax, 0xb
// 006fad40  776a                 ja 0x6fadac
// 006fad42  0fb680e4ad6f00       movzx eax, byte ptr [eax + 0x6fade4]
// 006fad49  ff2485d0ad6f00       jmp dword ptr [eax*4 + 0x6fadd0]
// 006fad50  c70602000000         mov dword ptr [esi], 2
// 006fad56  eb54                 jmp 0x6fadac
// 006fad58  c70603000000         mov dword ptr [esi], 3
// 006fad5e  eb4c                 jmp 0x6fadac
// 006fad60  8bc6                 mov eax, esi
// 006fad62  8bcf                 mov ecx, edi
// 006fad64  e867f2ffff           call 0x6f9fd0
// 006fad69  eb41                 jmp 0x6fadac
// 006fad6b  56                   push esi
// 006fad6c  8bc7                 mov eax, edi
// 006fad6e  e8edf8ffff           call 0x6fa660
// 006fad73  83c404               add esp, 4
// 006fad76  833e0c               cmp dword ptr [esi], 0xc
// 006fad79  7515                 jne 0x6fad90
// 006fad7b  8b4608               mov eax, dword ptr [esi + 8]
// 006fad7e  a900010000           test eax, 0x100
// 006fad83  750b                 jne 0x6fad90
// 006fad85  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 006fad89  3bc1                 cmp eax, ecx
// 006fad8b  7c03                 jl 0x6fad90
// 006fad8d  ff4f24               dec dword ptr [edi + 0x24]
// 006fad90  8b5608               mov edx, dword ptr [esi + 8]
// 006fad93  6a00                 push 0
// 006fad95  52                   push edx
// 006fad96  6a00                 push 0
// 006fad98  6a13                 push 0x13
// 006fad9a  57                   push edi
// 006fad9b  e830f4ffff           call 0x6fa1d0
// 006fada0  83c414               add esp, 0x14
// 006fada3  894608               mov dword ptr [esi + 8], eax
// 006fada6  c7060b000000         mov dword ptr [esi], 0xb
// 006fadac  8b4614               mov eax, dword ptr [esi + 0x14]
// 006fadaf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006fadb2  894610               mov dword ptr [esi + 0x10], eax
// 006fadb5  57                   push edi
// 006fadb6  8bc1                 mov eax, ecx
// 006fadb8  894e14               mov dword ptr [esi + 0x14], ecx
// 006fadbb  e8a0edffff           call 0x6f9b60
// 006fadc0  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fadc3  57                   push edi
// 006fadc4  e897edffff           call 0x6f9b60
// 006fadc9  83c408               add esp, 8
// 006fadcc  c3                   ret 
// 006fadcd  8d4900               lea ecx, [ecx]
// 006fadd0  50                   push eax
// 006fadd1  ad                   lodsd eax, dword ptr [esi]
// 006fadd2  6f                   outsd dx, dword ptr [esi]
// 006fadd3  0058ad               add byte ptr [eax - 0x53], bl
// 006fadd6  6f                   outsd dx, dword ptr [esi]
// 006fadd7  0060ad               add byte ptr [eax - 0x53], ah
// 006fadda  6f                   outsd dx, dword ptr [esi]
// 006faddb  006bad               add byte ptr [ebx - 0x53], ch
// 006fadde  6f                   outsd dx, dword ptr [esi]
// 006faddf  00acad6f000001       add byte ptr [ebp + ebp*4 + 0x100006f], ch
// 006fade6  0001                 add byte ptr [ecx], al
// 006fade8  010404               add dword ptr [esp + eax], eax
// 006fadeb  0404                 add al, 4
// 006faded  0203                 add al, byte ptr [ebx]
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
