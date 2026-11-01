// from server: 100% by auto
// roc 2009-12 0060c910  unit: seg_00600000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060c910
//
// 0060c910  83ec08               sub esp, 8
// 0060c913  56                   push esi
// 0060c914  8b742410             mov esi, dword ptr [esp + 0x10]
// 0060c918  85f6                 test esi, esi
// 0060c91a  7456                 je 0x60c972
// 0060c91c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0060c920  8bc8                 mov ecx, eax
// 0060c922  c1e918               shr ecx, 0x18
// 0060c925  57                   push edi
// 0060c926  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0060c92a  884c2408             mov byte ptr [esp + 8], cl
// 0060c92e  8bd0                 mov edx, eax
// 0060c930  8bc8                 mov ecx, eax
// 0060c932  c1ea10               shr edx, 0x10
// 0060c935  8844240b             mov byte ptr [esp + 0xb], al
// 0060c939  6a08                 push 8
// 0060c93b  8d44240c             lea eax, [esp + 0xc]
// 0060c93f  8854240d             mov byte ptr [esp + 0xd], dl
// 0060c943  8b17                 mov edx, dword ptr [edi]
// 0060c945  50                   push eax
// 0060c946  c1e908               shr ecx, 8
// 0060c949  56                   push esi
// 0060c94a  884c2416             mov byte ptr [esp + 0x16], cl
// 0060c94e  89542418             mov dword ptr [esp + 0x18], edx
// 0060c952  e8396affff           call 0x603390
// 0060c957  8b0f                 mov ecx, dword ptr [edi]
// 0060c959  56                   push esi
// 0060c95a  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 0060c960  e8eb6cffff           call 0x603650
// 0060c965  6a04                 push 4
// 0060c967  57                   push edi
// 0060c968  56                   push esi
// 0060c969  e8026dffff           call 0x603670
// 0060c96e  83c41c               add esp, 0x1c
// 0060c971  5f                   pop edi
// 0060c972  5e                   pop esi
// 0060c973  83c408               add esp, 8
// 0060c976  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_chunk_start)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
