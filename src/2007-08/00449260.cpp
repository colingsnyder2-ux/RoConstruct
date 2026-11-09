// from server: 100% by auto
// roc 2007-08 00449260  unit: CRobloxApp  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00449260
//
// 00449260  83ec08               sub esp, 8
// 00449263  8b542410             mov edx, dword ptr [esp + 0x10]
// 00449267  56                   push esi
// 00449268  8d442404             lea eax, [esp + 4]
// 0044926c  50                   push eax
// 0044926d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00449271  8d4c240c             lea ecx, [esp + 0xc]
// 00449275  51                   push ecx
// 00449276  52                   push edx
// 00449277  50                   push eax
// 00449278  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00449280  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00449288  e8d3fcffff           call 0x448f60
// 0044928d  8bf0                 mov esi, eax
// 0044928f  85f6                 test esi, esi
// 00449291  7c47                 jl 0x4492da
// 00449293  8b442404             mov eax, dword ptr [esp + 4]
// 00449297  8b08                 mov ecx, dword ptr [eax]
// 00449299  8d542414             lea edx, [esp + 0x14]
// 0044929d  52                   push edx
// 0044929e  50                   push eax
// 0044929f  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004492a2  ffd0                 call eax
// 004492a4  8bf0                 mov esi, eax
// 004492a6  85f6                 test esi, esi
// 004492a8  7c30                 jl 0x4492da
// 004492aa  8b442414             mov eax, dword ptr [esp + 0x14]
// 004492ae  8b4814               mov ecx, dword ptr [eax + 0x14]
// 004492b1  8b5010               mov edx, dword ptr [eax + 0x10]
// 004492b4  51                   push ecx
// 004492b5  0fb7481a             movzx ecx, word ptr [eax + 0x1a]
// 004492b9  52                   push edx
// 004492ba  0fb75018             movzx edx, word ptr [eax + 0x18]
// 004492be  51                   push ecx
// 004492bf  52                   push edx
// 004492c0  50                   push eax
// 004492c1  ff1508ea7700         call dword ptr [0x77ea08]
// 004492c7  8b542414             mov edx, dword ptr [esp + 0x14]
// 004492cb  8bf0                 mov esi, eax
// 004492cd  8b442404             mov eax, dword ptr [esp + 4]
// 004492d1  8b08                 mov ecx, dword ptr [eax]
// 004492d3  52                   push edx
// 004492d4  50                   push eax
// 004492d5  8b4130               mov eax, dword ptr [ecx + 0x30]
// 004492d8  ffd0                 call eax
// 004492da  8b442404             mov eax, dword ptr [esp + 4]
// 004492de  85c0                 test eax, eax
// 004492e0  7408                 je 0x4492ea
// 004492e2  8b08                 mov ecx, dword ptr [eax]
// 004492e4  8b5108               mov edx, dword ptr [ecx + 8]
// 004492e7  50                   push eax
// 004492e8  ffd2                 call edx
// 004492ea  8b442408             mov eax, dword ptr [esp + 8]
// 004492ee  50                   push eax
// 004492ef  ff15b0e97700         call dword ptr [0x77e9b0]
// 004492f5  8bc6                 mov eax, esi
// 004492f7  5e                   pop esi
// 004492f8  83c408               add esp, 8
// 004492fb  c20800               ret 8
// library atl-8.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
