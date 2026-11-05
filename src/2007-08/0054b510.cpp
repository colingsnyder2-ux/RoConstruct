// from server: 100% by colin
// roc 2007-08 0054b510  unit: UString_sink::?$stream_buffer  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054b510
//
// 0054b510  51                   push ecx
// 0054b511  56                   push esi
// 0054b512  8bf1                 mov esi, ecx
// 0054b514  8b4620               mov eax, dword ptr [esi + 0x20]
// 0054b517  833800               cmp dword ptr [eax], 0
// 0054b51a  7507                 jne 0x54b523
// 0054b51c  8b16                 mov edx, dword ptr [esi]
// 0054b51e  8b4254               mov eax, dword ptr [edx + 0x54]
// 0054b521  ffd0                 call eax
// 0054b523  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0054b526  8b01                 mov eax, dword ptr [ecx]
// 0054b528  8b5630               mov edx, dword ptr [esi + 0x30]
// 0054b52b  8b0a                 mov ecx, dword ptr [edx]
// 0054b52d  03c8                 add ecx, eax
// 0054b52f  3bc1                 cmp eax, ecx
// 0054b531  730b                 jae 0x54b53e
// 0054b533  8b5620               mov edx, dword ptr [esi + 0x20]
// 0054b536  8b02                 mov eax, dword ptr [edx]
// 0054b538  0fb600               movzx eax, byte ptr [eax]
// 0054b53b  5e                   pop esi
// 0054b53c  59                   pop ecx
// 0054b53d  c3                   ret 
// 0054b53e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0054b541  8b01                 mov eax, dword ptr [ecx]
// 0054b543  8b5610               mov edx, dword ptr [esi + 0x10]
// 0054b546  8bc8                 mov ecx, eax
// 0054b548  2b0a                 sub ecx, dword ptr [edx]
// 0054b54a  53                   push ebx
// 0054b54b  394e54               cmp dword ptr [esi + 0x54], ecx
// 0054b54e  8d5e54               lea ebx, [esi + 0x54]
// 0054b551  894c2408             mov dword ptr [esp + 8], ecx
// 0054b555  57                   push edi
// 0054b556  8bcb                 mov ecx, ebx
// 0054b558  7c04                 jl 0x54b55e
// 0054b55a  8d4c240c             lea ecx, [esp + 0xc]
// 0054b55e  8b39                 mov edi, dword ptr [ecx]
// 0054b560  85ff                 test edi, edi
// 0054b562  7416                 je 0x54b57a
// 0054b564  2bc7                 sub eax, edi
// 0054b566  57                   push edi
// 0054b567  50                   push eax
// 0054b568  8b464c               mov eax, dword ptr [esi + 0x4c]
// 0054b56b  2bc7                 sub eax, edi
// 0054b56d  0303                 add eax, dword ptr [ebx]
// 0054b56f  57                   push edi
// 0054b570  50                   push eax
// 0054b571  ff1548e77700         call dword ptr [0x77e748]
// 0054b577  83c410               add esp, 0x10
// 0054b57a  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0054b57d  8b13                 mov edx, dword ptr [ebx]
// 0054b57f  8d0411               lea eax, [ecx + edx]
// 0054b582  8b5610               mov edx, dword ptr [esi + 0x10]
// 0054b585  8bc8                 mov ecx, eax
// 0054b587  2bcf                 sub ecx, edi
// 0054b589  890a                 mov dword ptr [edx], ecx
// 0054b58b  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0054b58e  8901                 mov dword ptr [ecx], eax
// 0054b590  8bd0                 mov edx, eax
// 0054b592  2bd0                 sub edx, eax
// 0054b594  8b4630               mov eax, dword ptr [esi + 0x30]
// 0054b597  8910                 mov dword ptr [eax], edx
// 0054b599  8b1b                 mov ebx, dword ptr [ebx]
// 0054b59b  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 0054b59e  8b564c               mov edx, dword ptr [esi + 0x4c]
// 0054b5a1  8b4648               mov eax, dword ptr [esi + 0x48]
// 0054b5a4  2bcb                 sub ecx, ebx
// 0054b5a6  51                   push ecx
// 0054b5a7  03d3                 add edx, ebx
// 0054b5a9  52                   push edx
// 0054b5aa  50                   push eax
// 0054b5ab  83c640               add esi, 0x40
// 0054b5ae  56                   push esi
// 0054b5af  e88cfeffff           call 0x54b440
// 0054b5b4  5f                   pop edi
// 0054b5b5  5b                   pop ebx
// copied from an identical function in another client (function ?underflow@?$indirect_streambuf@V?$reference_wrapper@V?$basic_ostream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uoutput_seekable@iostreams@2@@detail@iostreams@boost@@MAEHXZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp