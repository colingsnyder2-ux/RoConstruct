// from server: 100% by auto
// roc 2007-03 005f9900  unit: seg_005f0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9900
//
// 005f9900  8b442404             mov eax, dword ptr [esp + 4]
// 005f9904  8b4010               mov eax, dword ptr [eax + 0x10]
// 005f9907  8b501c               mov edx, dword ptr [eax + 0x1c]
// 005f990a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005f990e  8911                 mov dword ptr [ecx], edx
// 005f9910  8a54240c             mov dl, byte ptr [esp + 0xc]
// 005f9914  89481c               mov dword ptr [eax + 0x1c], ecx
// 005f9917  8a4014               mov al, byte ptr [eax + 0x14]
// 005f991a  2403                 and al, 3
// 005f991c  884105               mov byte ptr [ecx + 5], al
// 005f991f  885104               mov byte ptr [ecx + 4], dl
// 005f9922  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_link)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
