// from server: 100% by auto
// roc 2010-06 0056f990  unit: G3D::LineSegment  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056f990
//
// 0056f990  83ec08               sub esp, 8
// 0056f993  56                   push esi
// 0056f994  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056f998  c644240449           mov byte ptr [esp + 4], 0x49
// 0056f99d  c644240545           mov byte ptr [esp + 5], 0x45
// 0056f9a2  c64424064e           mov byte ptr [esp + 6], 0x4e
// 0056f9a7  c644240744           mov byte ptr [esp + 7], 0x44
// 0056f9ac  c644240800           mov byte ptr [esp + 8], 0
// 0056f9b1  85f6                 test esi, esi
// 0056f9b3  7442                 je 0x56f9f7
// 0056f9b5  6a00                 push 0
// 0056f9b7  8d442408             lea eax, [esp + 8]
// 0056f9bb  50                   push eax
// 0056f9bc  56                   push esi
// 0056f9bd  e86ee8ffff           call 0x56e230
// 0056f9c2  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056f9c8  8bd0                 mov edx, eax
// 0056f9ca  8bc8                 mov ecx, eax
// 0056f9cc  c1e918               shr ecx, 0x18
// 0056f9cf  c1ea10               shr edx, 0x10
// 0056f9d2  884c241c             mov byte ptr [esp + 0x1c], cl
// 0056f9d6  8854241d             mov byte ptr [esp + 0x1d], dl
// 0056f9da  6a04                 push 4
// 0056f9dc  8d542420             lea edx, [esp + 0x20]
// 0056f9e0  8bc8                 mov ecx, eax
// 0056f9e2  52                   push edx
// 0056f9e3  c1e908               shr ecx, 8
// 0056f9e6  56                   push esi
// 0056f9e7  884c242a             mov byte ptr [esp + 0x2a], cl
// 0056f9eb  8844242b             mov byte ptr [esp + 0x2b], al
// 0056f9ef  e80c53ffff           call 0x564d00
// 0056f9f4  83c418               add esp, 0x18
// 0056f9f7  834e6810             or dword ptr [esi + 0x68], 0x10
// 0056f9fb  5e                   pop esi
// 0056f9fc  83c408               add esp, 8
// 0056f9ff  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IEND)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
