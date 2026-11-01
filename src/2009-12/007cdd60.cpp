// from server: 100% by auto
// roc 2009-12 007cdd60  unit: RBX::PartDropTool  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdd60
//
// 007cdd60  8b442404             mov eax, dword ptr [esp + 4]
// 007cdd64  8b4010               mov eax, dword ptr [eax + 0x10]
// 007cdd67  8b501c               mov edx, dword ptr [eax + 0x1c]
// 007cdd6a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007cdd6e  8911                 mov dword ptr [ecx], edx
// 007cdd70  8a54240c             mov dl, byte ptr [esp + 0xc]
// 007cdd74  89481c               mov dword ptr [eax + 0x1c], ecx
// 007cdd77  8a4014               mov al, byte ptr [eax + 0x14]
// 007cdd7a  2403                 and al, 3
// 007cdd7c  884105               mov byte ptr [ecx + 5], al
// 007cdd7f  885104               mov byte ptr [ecx + 4], dl
// 007cdd82  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_link)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
