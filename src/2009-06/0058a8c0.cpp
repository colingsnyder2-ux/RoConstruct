// from server: 100% by auto
// roc 2009-06 0058a8c0  unit: seg_00580000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058a8c0
//
// 0058a8c0  83ec08               sub esp, 8
// 0058a8c3  56                   push esi
// 0058a8c4  8b742410             mov esi, dword ptr [esp + 0x10]
// 0058a8c8  85f6                 test esi, esi
// 0058a8ca  7456                 je 0x58a922
// 0058a8cc  8b442418             mov eax, dword ptr [esp + 0x18]
// 0058a8d0  8bc8                 mov ecx, eax
// 0058a8d2  c1e918               shr ecx, 0x18
// 0058a8d5  57                   push edi
// 0058a8d6  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0058a8da  884c2408             mov byte ptr [esp + 8], cl
// 0058a8de  8bd0                 mov edx, eax
// 0058a8e0  8bc8                 mov ecx, eax
// 0058a8e2  c1ea10               shr edx, 0x10
// 0058a8e5  8844240b             mov byte ptr [esp + 0xb], al
// 0058a8e9  6a08                 push 8
// 0058a8eb  8d44240c             lea eax, [esp + 0xc]
// 0058a8ef  8854240d             mov byte ptr [esp + 0xd], dl
// 0058a8f3  8b17                 mov edx, dword ptr [edi]
// 0058a8f5  50                   push eax
// 0058a8f6  c1e908               shr ecx, 8
// 0058a8f9  56                   push esi
// 0058a8fa  884c2416             mov byte ptr [esp + 0x16], cl
// 0058a8fe  89542418             mov dword ptr [esp + 0x18], edx
// 0058a902  e8d96cffff           call 0x5815e0
// 0058a907  8b0f                 mov ecx, dword ptr [edi]
// 0058a909  56                   push esi
// 0058a90a  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0058a910  e88b6fffff           call 0x5818a0
// 0058a915  6a04                 push 4
// 0058a917  57                   push edi
// 0058a918  56                   push esi
// 0058a919  e8a26fffff           call 0x5818c0
// 0058a91e  83c41c               add esp, 0x1c
// 0058a921  5f                   pop edi
// 0058a922  5e                   pop esi
// 0058a923  83c408               add esp, 8
// 0058a926  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_chunk_start)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
