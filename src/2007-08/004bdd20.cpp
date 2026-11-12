// from server: 100% by colin
// roc 2007-08 004bdd20  unit: RakPeer  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bdd20
//
// 004bdd20  83ec60               sub esp, 0x60
// 004bdd23  33c0                 xor eax, eax
// 004bdd25  89442434             mov dword ptr [esp + 0x34], eax
// 004bdd29  89442438             mov dword ptr [esp + 0x38], eax
// 004bdd2d  8944243c             mov dword ptr [esp + 0x3c], eax
// 004bdd31  89442420             mov dword ptr [esp + 0x20], eax
// 004bdd35  89442424             mov dword ptr [esp + 0x24], eax
// 004bdd39  89442428             mov dword ptr [esp + 0x28], eax
// 004bdd3d  8944242c             mov dword ptr [esp + 0x2c], eax
// 004bdd41  8b442464             mov eax, dword ptr [esp + 0x64]
// 004bdd45  8b5004               mov edx, dword ptr [eax + 4]
// 004bdd48  b901000000           mov ecx, 1
// 004bdd4d  894c2430             mov dword ptr [esp + 0x30], ecx
// 004bdd51  8b08                 mov ecx, dword ptr [eax]
// 004bdd53  890c24               mov dword ptr [esp], ecx
// 004bdd56  8b4808               mov ecx, dword ptr [eax + 8]
// 004bdd59  89542404             mov dword ptr [esp + 4], edx
// 004bdd5d  8b500c               mov edx, dword ptr [eax + 0xc]
// 004bdd60  33c0                 xor eax, eax
// 004bdd62  89442410             mov dword ptr [esp + 0x10], eax
// 004bdd66  89442414             mov dword ptr [esp + 0x14], eax
// 004bdd6a  89442418             mov dword ptr [esp + 0x18], eax
// 004bdd6e  8944241c             mov dword ptr [esp + 0x1c], eax
// 004bdd72  8d442440             lea eax, [esp + 0x40]
// 004bdd76  894c2408             mov dword ptr [esp + 8], ecx
// 004bdd7a  50                   push eax
// 004bdd7b  8d4c2404             lea ecx, [esp + 4]
// 004bdd7f  89542410             mov dword ptr [esp + 0x10], edx
// 004bdd83  51                   push ecx
// 004bdd84  8d542428             lea edx, [esp + 0x28]
// 004bdd88  52                   push edx
// 004bdd89  e8e2d5ffff           call 0x4bb370
// 004bdd8e  8b442474             mov eax, dword ptr [esp + 0x74]
// 004bdd92  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004bdd96  8b542450             mov edx, dword ptr [esp + 0x50]
// 004bdd9a  8908                 mov dword ptr [eax], ecx
// 004bdd9c  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004bdda0  895004               mov dword ptr [eax + 4], edx
// 004bdda3  8b542458             mov edx, dword ptr [esp + 0x58]
// 004bdda7  894808               mov dword ptr [eax + 8], ecx
// 004bddaa  89500c               mov dword ptr [eax + 0xc], edx
// 004bddad  83c46c               add esp, 0x6c
// 004bddb0  c3                   ret 
// copied from an identical function in another client (function ??$rModn@$$BY03I@big@@YAXAAY03I0@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp