// from server: 100% by auto
// roc 2009-12 0060c9c0  unit: seg_00600000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060c9c0
//
// 0060c9c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0060c9c4  85c9                 test ecx, ecx
// 0060c9c6  7435                 je 0x60c9fd
// 0060c9c8  8b8110010000         mov eax, dword ptr [ecx + 0x110]
// 0060c9ce  8bd0                 mov edx, eax
// 0060c9d0  c1ea18               shr edx, 0x18
// 0060c9d3  88542404             mov byte ptr [esp + 4], dl
// 0060c9d7  8bd0                 mov edx, eax
// 0060c9d9  c1ea10               shr edx, 0x10
// 0060c9dc  88542405             mov byte ptr [esp + 5], dl
// 0060c9e0  8bd0                 mov edx, eax
// 0060c9e2  88442407             mov byte ptr [esp + 7], al
// 0060c9e6  6a04                 push 4
// 0060c9e8  8d442408             lea eax, [esp + 8]
// 0060c9ec  50                   push eax
// 0060c9ed  c1ea08               shr edx, 8
// 0060c9f0  51                   push ecx
// 0060c9f1  88542412             mov byte ptr [esp + 0x12], dl
// 0060c9f5  e89669ffff           call 0x603390
// 0060c9fa  83c40c               add esp, 0xc
// 0060c9fd  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
