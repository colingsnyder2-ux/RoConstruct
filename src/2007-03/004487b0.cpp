// from server: 100% by auto
// roc 2007-03 004487b0  unit: seg_00440000  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004487b0
//
// 004487b0  83ec08               sub esp, 8
// 004487b3  8b542410             mov edx, dword ptr [esp + 0x10]
// 004487b7  56                   push esi
// 004487b8  8d442404             lea eax, [esp + 4]
// 004487bc  50                   push eax
// 004487bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 004487c1  8d4c240c             lea ecx, [esp + 0xc]
// 004487c5  51                   push ecx
// 004487c6  52                   push edx
// 004487c7  50                   push eax
// 004487c8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004487d0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004487d8  e8d3fcffff           call 0x4484b0
// 004487dd  8bf0                 mov esi, eax
// 004487df  85f6                 test esi, esi
// 004487e1  7c47                 jl 0x44882a
// 004487e3  8b442404             mov eax, dword ptr [esp + 4]
// 004487e7  8b08                 mov ecx, dword ptr [eax]
// 004487e9  8d542414             lea edx, [esp + 0x14]
// 004487ed  52                   push edx
// 004487ee  50                   push eax
// 004487ef  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004487f2  ffd0                 call eax
// 004487f4  8bf0                 mov esi, eax
// 004487f6  85f6                 test esi, esi
// 004487f8  7c30                 jl 0x44882a
// 004487fa  8b442414             mov eax, dword ptr [esp + 0x14]
// 004487fe  8b4814               mov ecx, dword ptr [eax + 0x14]
// 00448801  8b5010               mov edx, dword ptr [eax + 0x10]
// 00448804  51                   push ecx
// 00448805  0fb7481a             movzx ecx, word ptr [eax + 0x1a]
// 00448809  52                   push edx
// 0044880a  0fb75018             movzx edx, word ptr [eax + 0x18]
// 0044880e  51                   push ecx
// 0044880f  52                   push edx
// 00448810  50                   push eax
// 00448811  ff15e0ea7700         call dword ptr [0x77eae0]
// 00448817  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044881b  8bf0                 mov esi, eax
// 0044881d  8b442404             mov eax, dword ptr [esp + 4]
// 00448821  8b08                 mov ecx, dword ptr [eax]
// 00448823  52                   push edx
// 00448824  50                   push eax
// 00448825  8b4130               mov eax, dword ptr [ecx + 0x30]
// 00448828  ffd0                 call eax
// 0044882a  8b442404             mov eax, dword ptr [esp + 4]
// 0044882e  85c0                 test eax, eax
// 00448830  7408                 je 0x44883a
// 00448832  8b08                 mov ecx, dword ptr [eax]
// 00448834  8b5108               mov edx, dword ptr [ecx + 8]
// 00448837  50                   push eax
// 00448838  ffd2                 call edx
// 0044883a  8b442408             mov eax, dword ptr [esp + 8]
// 0044883e  50                   push eax
// 0044883f  ff1588ea7700         call dword ptr [0x77ea88]
// 00448845  8bc6                 mov eax, esi
// 00448847  5e                   pop esi
// 00448848  83c408               add esp, 8
// 0044884b  c20800               ret 8
// library atl-8.0/atl.cpp (function _AtlUnRegisterTypeLib@8)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
