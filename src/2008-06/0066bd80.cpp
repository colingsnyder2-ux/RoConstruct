// from server: 100% by auto
// roc 2008-06 0066bd80  unit: RBX::GroupDragTool  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066bd80
//
// 0066bd80  56                   push esi
// 0066bd81  57                   push edi
// 0066bd82  e819f7ffff           call 0x66b4a0
// 0066bd87  8b06                 mov eax, dword ptr [esi]
// 0066bd89  48                   dec eax
// 0066bd8a  83c408               add esp, 8
// 0066bd8d  83f80b               cmp eax, 0xb
// 0066bd90  776a                 ja 0x66bdfc
// 0066bd92  0fb68034be6600       movzx eax, byte ptr [eax + 0x66be34]
// 0066bd99  ff248520be6600       jmp dword ptr [eax*4 + 0x66be20]
// 0066bda0  c70602000000         mov dword ptr [esi], 2
// 0066bda6  eb54                 jmp 0x66bdfc
// 0066bda8  c70603000000         mov dword ptr [esi], 3
// 0066bdae  eb4c                 jmp 0x66bdfc
// 0066bdb0  8bc6                 mov eax, esi
// 0066bdb2  8bcf                 mov ecx, edi
// 0066bdb4  e877f2ffff           call 0x66b030
// 0066bdb9  eb41                 jmp 0x66bdfc
// 0066bdbb  56                   push esi
// 0066bdbc  8bc7                 mov eax, edi
// 0066bdbe  e8edf8ffff           call 0x66b6b0
// 0066bdc3  83c404               add esp, 4
// 0066bdc6  833e0c               cmp dword ptr [esi], 0xc
// 0066bdc9  7515                 jne 0x66bde0
// 0066bdcb  8b4608               mov eax, dword ptr [esi + 8]
// 0066bdce  a900010000           test eax, 0x100
// 0066bdd3  750b                 jne 0x66bde0
// 0066bdd5  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 0066bdd9  3bc1                 cmp eax, ecx
// 0066bddb  7c03                 jl 0x66bde0
// 0066bddd  ff4f24               dec dword ptr [edi + 0x24]
// 0066bde0  8b5608               mov edx, dword ptr [esi + 8]
// 0066bde3  6a00                 push 0
// 0066bde5  52                   push edx
// 0066bde6  6a00                 push 0
// 0066bde8  6a13                 push 0x13
// 0066bdea  57                   push edi
// 0066bdeb  e840f4ffff           call 0x66b230
// 0066bdf0  83c414               add esp, 0x14
// 0066bdf3  894608               mov dword ptr [esi + 8], eax
// 0066bdf6  c7060b000000         mov dword ptr [esi], 0xb
// 0066bdfc  8b4614               mov eax, dword ptr [esi + 0x14]
// 0066bdff  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0066be02  894610               mov dword ptr [esi + 0x10], eax
// 0066be05  57                   push edi
// 0066be06  8bc1                 mov eax, ecx
// 0066be08  894e14               mov dword ptr [esi + 0x14], ecx
// 0066be0b  e8b0edffff           call 0x66abc0
// 0066be10  8b4610               mov eax, dword ptr [esi + 0x10]
// 0066be13  57                   push edi
// 0066be14  e8a7edffff           call 0x66abc0
// 0066be19  83c408               add esp, 8
// 0066be1c  c3                   ret 
// 0066be1d  8d4900               lea ecx, [ecx]
// 0066be20  a0bd6600a8           mov al, byte ptr [0xa80066bd]
// 0066be25  bd6600b0bd           mov ebp, 0xbdb00066
// 0066be2a  6600bbbd6600fc       add byte ptr [ebx - 0x3ff9943], bh
// 0066be31  bd66000001           mov ebp, 0x1000066
// 0066be36  0001                 add byte ptr [ecx], al
// 0066be38  010404               add dword ptr [esp + eax], eax
// 0066be3b  0404                 add al, 4
// 0066be3d  0203                 add al, byte ptr [ebx]
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
