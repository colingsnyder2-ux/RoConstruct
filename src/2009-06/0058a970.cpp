// from server: 100% by auto
// roc 2009-06 0058a970  unit: seg_00580000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058a970
//
// 0058a970  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0058a974  85c9                 test ecx, ecx
// 0058a976  7435                 je 0x58a9ad
// 0058a978  8b8110010000         mov eax, dword ptr [ecx + 0x110]
// 0058a97e  8bd0                 mov edx, eax
// 0058a980  c1ea18               shr edx, 0x18
// 0058a983  88542404             mov byte ptr [esp + 4], dl
// 0058a987  8bd0                 mov edx, eax
// 0058a989  c1ea10               shr edx, 0x10
// 0058a98c  88542405             mov byte ptr [esp + 5], dl
// 0058a990  8bd0                 mov edx, eax
// 0058a992  88442407             mov byte ptr [esp + 7], al
// 0058a996  6a04                 push 4
// 0058a998  8d442408             lea eax, [esp + 8]
// 0058a99c  50                   push eax
// 0058a99d  c1ea08               shr edx, 8
// 0058a9a0  51                   push ecx
// 0058a9a1  88542412             mov byte ptr [esp + 0x12], dl
// 0058a9a5  e8366cffff           call 0x5815e0
// 0058a9aa  83c40c               add esp, 0xc
// 0058a9ad  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
