// from server: 100% by auto
// roc 2011-06 0056aa60  unit: seg_00560000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056aa60
//
// 0056aa60  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0056aa64  85c9                 test ecx, ecx
// 0056aa66  7435                 je 0x56aa9d
// 0056aa68  8b8110010000         mov eax, dword ptr [ecx + 0x110]
// 0056aa6e  8bd0                 mov edx, eax
// 0056aa70  c1ea18               shr edx, 0x18
// 0056aa73  88542404             mov byte ptr [esp + 4], dl
// 0056aa77  8bd0                 mov edx, eax
// 0056aa79  c1ea10               shr edx, 0x10
// 0056aa7c  88542405             mov byte ptr [esp + 5], dl
// 0056aa80  8bd0                 mov edx, eax
// 0056aa82  88442407             mov byte ptr [esp + 7], al
// 0056aa86  6a04                 push 4
// 0056aa88  8d442408             lea eax, [esp + 8]
// 0056aa8c  50                   push eax
// 0056aa8d  c1ea08               shr edx, 8
// 0056aa90  51                   push ecx
// 0056aa91  88542412             mov byte ptr [esp + 0x12], dl
// 0056aa95  e8a6fdfeff           call 0x55a840
// 0056aa9a  83c40c               add esp, 0xc
// 0056aa9d  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
