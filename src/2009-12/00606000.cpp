// from server: 100% by auto
// roc 2009-12 00606000  unit: seg_00600000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00606000
//
// 00606000  8b442404             mov eax, dword ptr [esp + 4]
// 00606004  85c0                 test eax, eax
// 00606006  740b                 je 0x606013
// 00606008  81487000100002       or dword ptr [eax + 0x70], 0x2001000
// 0060600f  83606cbf             and dword ptr [eax + 0x6c], 0xffffffbf
// 00606013  c3                   ret 
// library libpng-1.2.22/pngrtran.c (function _png_set_expand)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngrtran.c
