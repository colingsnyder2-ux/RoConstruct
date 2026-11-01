// from server: 100% by auto
// roc 2007-03 0050e180  unit: seg_00500000  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e180
//
// 0050e180  8b442404             mov eax, dword ptr [esp + 4]
// 0050e184  8a5009               mov dl, byte ptr [eax + 9]
// 0050e187  80fa08               cmp dl, 8
// 0050e18a  7344                 jae 0x50e1d0
// 0050e18c  8b4804               mov ecx, dword ptr [eax + 4]
// 0050e18f  8b442408             mov eax, dword ptr [esp + 8]
// 0050e193  03c8                 add ecx, eax
// 0050e195  80fa01               cmp dl, 1
// 0050e198  56                   push esi
// 0050e199  7507                 jne 0x50e1a2
// 0050e19b  be78658900           mov esi, 0x896578
// 0050e1a0  eb16                 jmp 0x50e1b8
// 0050e1a2  80fa02               cmp dl, 2
// 0050e1a5  7507                 jne 0x50e1ae
// 0050e1a7  be78668900           mov esi, 0x896678
// 0050e1ac  eb0a                 jmp 0x50e1b8
// 0050e1ae  80fa04               cmp dl, 4
// 0050e1b1  751c                 jne 0x50e1cf
// 0050e1b3  be78678900           mov esi, 0x896778
// 0050e1b8  3bc1                 cmp eax, ecx
// 0050e1ba  7313                 jae 0x50e1cf
// 0050e1bc  8d642400             lea esp, [esp]
// 0050e1c0  0fb610               movzx edx, byte ptr [eax]
// 0050e1c3  8a1432               mov dl, byte ptr [edx + esi]
// 0050e1c6  8810                 mov byte ptr [eax], dl
// 0050e1c8  83c001               add eax, 1
// 0050e1cb  3bc1                 cmp eax, ecx
// 0050e1cd  72f1                 jb 0x50e1c0
// 0050e1cf  5e                   pop esi
// 0050e1d0  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_do_packswap)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
