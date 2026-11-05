// from server: 100% by auto
// roc 2009-12 007cdd90  unit: RBX::PartDropTool  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdd90
//
// 007cdd90  8b442408             mov eax, dword ptr [esp + 8]
// 007cdd94  56                   push esi
// 007cdd95  57                   push edi
// 007cdd96  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007cdd9a  8b7710               mov esi, dword ptr [edi + 0x10]
// 007cdd9d  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 007cdda0  8908                 mov dword ptr [eax], ecx
// 007cdda2  89461c               mov dword ptr [esi + 0x1c], eax
// 007cdda5  8a4805               mov cl, byte ptr [eax + 5]
// 007cdda8  f6c107               test cl, 7
// 007cddab  753e                 jne 0x7cddeb
// 007cddad  807e1501             cmp byte ptr [esi + 0x15], 1
// 007cddb1  752a                 jne 0x7cdddd
// 007cddb3  8b5008               mov edx, dword ptr [eax + 8]
// 007cddb6  80c904               or cl, 4
// 007cddb9  884805               mov byte ptr [eax + 5], cl
// 007cddbc  837a0804             cmp dword ptr [edx + 8], 4
// 007cddc0  7c29                 jl 0x7cddeb
// 007cddc2  8b12                 mov edx, dword ptr [edx]
// 007cddc4  f6420503             test byte ptr [edx + 5], 3
// 007cddc8  7421                 je 0x7cddeb
// 007cddca  f6c104               test cl, 4
// 007cddcd  741c                 je 0x7cddeb
// 007cddcf  52                   push edx
// 007cddd0  50                   push eax
// 007cddd1  57                   push edi
// 007cddd2  e829ffffff           call 0x7cdd00
// 007cddd7  83c40c               add esp, 0xc
// 007cddda  5f                   pop edi
// 007cdddb  5e                   pop esi
// 007cdddc  c3                   ret 
// 007cdddd  8a5614               mov dl, byte ptr [esi + 0x14]
// 007cdde0  80e203               and dl, 3
// 007cdde3  80e1f8               and cl, 0xf8
// 007cdde6  0ad1                 or dl, cl
// 007cdde8  885005               mov byte ptr [eax + 5], dl
// 007cddeb  5f                   pop edi
// 007cddec  5e                   pop esi
// 007cdded  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_linkupval)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
