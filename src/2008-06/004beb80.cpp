// from server: 100% by auto
// roc 2008-06 004beb80  unit: ProfiledRakPeer  size: 277 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004beb80
//
// 004beb80  83ec50               sub esp, 0x50
// 004beb83  8b442454             mov eax, dword ptr [esp + 0x54]
// 004beb87  8b08                 mov ecx, dword ptr [eax]
// 004beb89  8b5004               mov edx, dword ptr [eax + 4]
// 004beb8c  53                   push ebx
// 004beb8d  894c2414             mov dword ptr [esp + 0x14], ecx
// 004beb91  8b4808               mov ecx, dword ptr [eax + 8]
// 004beb94  89542418             mov dword ptr [esp + 0x18], edx
// 004beb98  8b500c               mov edx, dword ptr [eax + 0xc]
// 004beb9b  33c0                 xor eax, eax
// 004beb9d  56                   push esi
// 004beb9e  89442428             mov dword ptr [esp + 0x28], eax
// 004beba2  8944242c             mov dword ptr [esp + 0x2c], eax
// 004beba6  89442430             mov dword ptr [esp + 0x30], eax
// 004bebaa  89442434             mov dword ptr [esp + 0x34], eax
// 004bebae  8b442460             mov eax, dword ptr [esp + 0x60]
// 004bebb2  57                   push edi
// 004bebb3  894c2424             mov dword ptr [esp + 0x24], ecx
// 004bebb7  50                   push eax
// 004bebb8  8d4c2420             lea ecx, [esp + 0x20]
// 004bebbc  51                   push ecx
// 004bebbd  89542430             mov dword ptr [esp + 0x30], edx
// 004bebc1  e8cae0ffff           call 0x4bcc90
// 004bebc6  8b7c2474             mov edi, dword ptr [esp + 0x74]
// 004bebca  8b4704               mov eax, dword ptr [edi + 4]
// 004bebcd  8b17                 mov edx, dword ptr [edi]
// 004bebcf  8b4f08               mov ecx, dword ptr [edi + 8]
// 004bebd2  89442448             mov dword ptr [esp + 0x48], eax
// 004bebd6  33c0                 xor eax, eax
// 004bebd8  89542444             mov dword ptr [esp + 0x44], edx
// 004bebdc  8b570c               mov edx, dword ptr [edi + 0xc]
// 004bebdf  89442454             mov dword ptr [esp + 0x54], eax
// 004bebe3  89442458             mov dword ptr [esp + 0x58], eax
// 004bebe7  8944245c             mov dword ptr [esp + 0x5c], eax
// 004bebeb  89442460             mov dword ptr [esp + 0x60], eax
// 004bebef  8d442424             lea eax, [esp + 0x24]
// 004bebf3  894c244c             mov dword ptr [esp + 0x4c], ecx
// 004bebf7  50                   push eax
// 004bebf8  8d4c2448             lea ecx, [esp + 0x48]
// 004bebfc  89542454             mov dword ptr [esp + 0x54], edx
// 004bec00  51                   push ecx
// 004bec01  8bd0                 mov edx, eax
// 004bec03  52                   push edx
// 004bec04  e897f5ffff           call 0x4be1a0
// 004bec09  8b442430             mov eax, dword ptr [esp + 0x30]
// 004bec0d  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004bec11  8bb42484000000       mov esi, dword ptr [esp + 0x84]
// 004bec18  8b542438             mov edx, dword ptr [esp + 0x38]
// 004bec1c  89442420             mov dword ptr [esp + 0x20], eax
// 004bec20  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004bec24  894c2424             mov dword ptr [esp + 0x24], ecx
// 004bec28  8944242c             mov dword ptr [esp + 0x2c], eax
// 004bec2c  8b44247c             mov eax, dword ptr [esp + 0x7c]
// 004bec30  8b08                 mov ecx, dword ptr [eax]
// 004bec32  890e                 mov dword ptr [esi], ecx
// 004bec34  89542428             mov dword ptr [esp + 0x28], edx
// 004bec38  8b5004               mov edx, dword ptr [eax + 4]
// 004bec3b  895604               mov dword ptr [esi + 4], edx
// 004bec3e  8b4808               mov ecx, dword ptr [eax + 8]
// 004bec41  894e08               mov dword ptr [esi + 8], ecx
// 004bec44  8b500c               mov edx, dword ptr [eax + 0xc]
// 004bec47  83c414               add esp, 0x14
// 004bec4a  89560c               mov dword ptr [esi + 0xc], edx
// 004bec4d  b903000000           mov ecx, 3
// 004bec52  8b1488               mov edx, dword ptr [eax + ecx*4]
// 004bec55  8b5c8c0c             mov ebx, dword ptr [esp + ecx*4 + 0xc]
// 004bec59  3bd3                 cmp edx, ebx
// 004bec5b  7723                 ja 0x4bec80
// 004bec5d  7205                 jb 0x4bec64
// 004bec5f  83e901               sub ecx, 1
// 004bec62  79ee                 jns 0x4bec52
// 004bec64  8d4c240c             lea ecx, [esp + 0xc]
// 004bec68  51                   push ecx
// 004bec69  56                   push esi
// 004bec6a  e851daffff           call 0x4bc6c0
// 004bec6f  57                   push edi
// 004bec70  56                   push esi
// 004bec71  e8aadaffff           call 0x4bc720
// 004bec76  83c410               add esp, 0x10
// 004bec79  5f                   pop edi
// 004bec7a  5e                   pop esi
// 004bec7b  5b                   pop ebx
// 004bec7c  83c450               add esp, 0x50
// 004bec7f  c3                   ret 
// 004bec80  8d44240c             lea eax, [esp + 0xc]
// 004bec84  50                   push eax
// 004bec85  56                   push esi
// 004bec86  e835daffff           call 0x4bc6c0
// 004bec8b  83c408               add esp, 8
// 004bec8e  5f                   pop edi
// 004bec8f  5e                   pop esi
// 004bec90  5b                   pop ebx
// 004bec91  83c450               add esp, 0x50
// 004bec94  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$SubMulMod@$$BY03I@big@@YAXAAY03I0000@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
