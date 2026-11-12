// from server: 100% by auto
// roc 2008-06 004c0e40  unit: ProfiledRakPeer  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c0e40
//
// 004c0e40  83ec60               sub esp, 0x60
// 004c0e43  33c0                 xor eax, eax
// 004c0e45  89442434             mov dword ptr [esp + 0x34], eax
// 004c0e49  89442438             mov dword ptr [esp + 0x38], eax
// 004c0e4d  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c0e51  89442420             mov dword ptr [esp + 0x20], eax
// 004c0e55  89442424             mov dword ptr [esp + 0x24], eax
// 004c0e59  89442428             mov dword ptr [esp + 0x28], eax
// 004c0e5d  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c0e61  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c0e65  8b5004               mov edx, dword ptr [eax + 4]
// 004c0e68  b901000000           mov ecx, 1
// 004c0e6d  894c2430             mov dword ptr [esp + 0x30], ecx
// 004c0e71  8b08                 mov ecx, dword ptr [eax]
// 004c0e73  890c24               mov dword ptr [esp], ecx
// 004c0e76  8b4808               mov ecx, dword ptr [eax + 8]
// 004c0e79  89542404             mov dword ptr [esp + 4], edx
// 004c0e7d  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c0e80  33c0                 xor eax, eax
// 004c0e82  89442410             mov dword ptr [esp + 0x10], eax
// 004c0e86  89442414             mov dword ptr [esp + 0x14], eax
// 004c0e8a  89442418             mov dword ptr [esp + 0x18], eax
// 004c0e8e  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c0e92  8d442440             lea eax, [esp + 0x40]
// 004c0e96  894c2408             mov dword ptr [esp + 8], ecx
// 004c0e9a  50                   push eax
// 004c0e9b  8d4c2404             lea ecx, [esp + 4]
// 004c0e9f  89542410             mov dword ptr [esp + 0x10], edx
// 004c0ea3  51                   push ecx
// 004c0ea4  8d542428             lea edx, [esp + 0x28]
// 004c0ea8  52                   push edx
// 004c0ea9  e8f2d2ffff           call 0x4be1a0
// 004c0eae  8b442474             mov eax, dword ptr [esp + 0x74]
// 004c0eb2  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004c0eb6  8b542450             mov edx, dword ptr [esp + 0x50]
// 004c0eba  8908                 mov dword ptr [eax], ecx
// 004c0ebc  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004c0ec0  895004               mov dword ptr [eax + 4], edx
// 004c0ec3  8b542458             mov edx, dword ptr [esp + 0x58]
// 004c0ec7  894808               mov dword ptr [eax + 8], ecx
// 004c0eca  89500c               mov dword ptr [eax + 0xc], edx
// 004c0ecd  83c46c               add esp, 0x6c
// 004c0ed0  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$rModn@$$BY03I@big@@YAXAAY03I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
