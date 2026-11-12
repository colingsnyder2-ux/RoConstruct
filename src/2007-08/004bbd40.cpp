// from server: 100% by colin
// roc 2007-08 004bbd40  unit: RakPeer  size: 277 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bbd40
//
// 004bbd40  83ec50               sub esp, 0x50
// 004bbd43  8b442454             mov eax, dword ptr [esp + 0x54]
// 004bbd47  8b08                 mov ecx, dword ptr [eax]
// 004bbd49  8b5004               mov edx, dword ptr [eax + 4]
// 004bbd4c  53                   push ebx
// 004bbd4d  894c2414             mov dword ptr [esp + 0x14], ecx
// 004bbd51  8b4808               mov ecx, dword ptr [eax + 8]
// 004bbd54  89542418             mov dword ptr [esp + 0x18], edx
// 004bbd58  8b500c               mov edx, dword ptr [eax + 0xc]
// 004bbd5b  33c0                 xor eax, eax
// 004bbd5d  56                   push esi
// 004bbd5e  89442428             mov dword ptr [esp + 0x28], eax
// 004bbd62  8944242c             mov dword ptr [esp + 0x2c], eax
// 004bbd66  89442430             mov dword ptr [esp + 0x30], eax
// 004bbd6a  89442434             mov dword ptr [esp + 0x34], eax
// 004bbd6e  8b442460             mov eax, dword ptr [esp + 0x60]
// 004bbd72  57                   push edi
// 004bbd73  894c2424             mov dword ptr [esp + 0x24], ecx
// 004bbd77  50                   push eax
// 004bbd78  8d4c2420             lea ecx, [esp + 0x20]
// 004bbd7c  51                   push ecx
// 004bbd7d  89542430             mov dword ptr [esp + 0x30], edx
// 004bbd81  e8cae0ffff           call 0x4b9e50
// 004bbd86  8b7c2474             mov edi, dword ptr [esp + 0x74]
// 004bbd8a  8b4704               mov eax, dword ptr [edi + 4]
// 004bbd8d  8b17                 mov edx, dword ptr [edi]
// 004bbd8f  8b4f08               mov ecx, dword ptr [edi + 8]
// 004bbd92  89442448             mov dword ptr [esp + 0x48], eax
// 004bbd96  33c0                 xor eax, eax
// 004bbd98  89542444             mov dword ptr [esp + 0x44], edx
// 004bbd9c  8b570c               mov edx, dword ptr [edi + 0xc]
// 004bbd9f  89442454             mov dword ptr [esp + 0x54], eax
// 004bbda3  89442458             mov dword ptr [esp + 0x58], eax
// 004bbda7  8944245c             mov dword ptr [esp + 0x5c], eax
// 004bbdab  89442460             mov dword ptr [esp + 0x60], eax
// 004bbdaf  8d442424             lea eax, [esp + 0x24]
// 004bbdb3  894c244c             mov dword ptr [esp + 0x4c], ecx
// 004bbdb7  50                   push eax
// 004bbdb8  8d4c2448             lea ecx, [esp + 0x48]
// 004bbdbc  89542454             mov dword ptr [esp + 0x54], edx
// 004bbdc0  51                   push ecx
// 004bbdc1  8bd0                 mov edx, eax
// 004bbdc3  52                   push edx
// 004bbdc4  e8a7f5ffff           call 0x4bb370
// 004bbdc9  8b442430             mov eax, dword ptr [esp + 0x30]
// 004bbdcd  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004bbdd1  8bb42484000000       mov esi, dword ptr [esp + 0x84]
// 004bbdd8  8b542438             mov edx, dword ptr [esp + 0x38]
// 004bbddc  89442420             mov dword ptr [esp + 0x20], eax
// 004bbde0  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 004bbde4  894c2424             mov dword ptr [esp + 0x24], ecx
// 004bbde8  8944242c             mov dword ptr [esp + 0x2c], eax
// 004bbdec  8b44247c             mov eax, dword ptr [esp + 0x7c]
// 004bbdf0  8b08                 mov ecx, dword ptr [eax]
// 004bbdf2  890e                 mov dword ptr [esi], ecx
// 004bbdf4  89542428             mov dword ptr [esp + 0x28], edx
// 004bbdf8  8b5004               mov edx, dword ptr [eax + 4]
// 004bbdfb  895604               mov dword ptr [esi + 4], edx
// 004bbdfe  8b4808               mov ecx, dword ptr [eax + 8]
// 004bbe01  894e08               mov dword ptr [esi + 8], ecx
// 004bbe04  8b500c               mov edx, dword ptr [eax + 0xc]
// 004bbe07  83c414               add esp, 0x14
// 004bbe0a  89560c               mov dword ptr [esi + 0xc], edx
// 004bbe0d  b903000000           mov ecx, 3
// 004bbe12  8b1488               mov edx, dword ptr [eax + ecx*4]
// 004bbe15  8b5c8c0c             mov ebx, dword ptr [esp + ecx*4 + 0xc]
// 004bbe19  3bd3                 cmp edx, ebx
// 004bbe1b  7723                 ja 0x4bbe40
// 004bbe1d  7205                 jb 0x4bbe24
// 004bbe1f  83e901               sub ecx, 1
// 004bbe22  79ee                 jns 0x4bbe12
// 004bbe24  8d4c240c             lea ecx, [esp + 0xc]
// 004bbe28  51                   push ecx
// 004bbe29  56                   push esi
// 004bbe2a  e851daffff           call 0x4b9880
// 004bbe2f  57                   push edi
// 004bbe30  56                   push esi
// 004bbe31  e8aadaffff           call 0x4b98e0
// 004bbe36  83c410               add esp, 0x10
// 004bbe39  5f                   pop edi
// 004bbe3a  5e                   pop esi
// 004bbe3b  5b                   pop ebx
// 004bbe3c  83c450               add esp, 0x50
// 004bbe3f  c3                   ret 
// 004bbe40  8d44240c             lea eax, [esp + 0xc]
// 004bbe44  50                   push eax
// 004bbe45  56                   push esi
// 004bbe46  e835daffff           call 0x4b9880
// 004bbe4b  83c408               add esp, 8
// 004bbe4e  5f                   pop edi
// 004bbe4f  5e                   pop esi
// 004bbe50  5b                   pop ebx
// 004bbe51  83c450               add esp, 0x50
// 004bbe54  c3                   ret 
// copied from an identical function in another client (function ??$SubMulMod@$$BY03I@big@@YAXAAY03I0000@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp