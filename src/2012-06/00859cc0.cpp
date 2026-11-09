// roc 2012-06 00859cc0  unit: UString_sink::?$stream_buffer  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859cc0
//
// 00859cc0  51                   push ecx
// 00859cc1  56                   push esi
// 00859cc2  8bf1                 mov esi, ecx
// 00859cc4  8b4620               mov eax, dword ptr [esi + 0x20]
// 00859cc7  833800               cmp dword ptr [eax], 0
// 00859cca  7507                 jne 0x859cd3
// 00859ccc  8b16                 mov edx, dword ptr [esi]
// 00859cce  8b4254               mov eax, dword ptr [edx + 0x54]
// 00859cd1  ffd0                 call eax
// 00859cd3  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00859cd6  8b01                 mov eax, dword ptr [ecx]
// 00859cd8  8b5630               mov edx, dword ptr [esi + 0x30]
// 00859cdb  8b0a                 mov ecx, dword ptr [edx]
// 00859cdd  03c8                 add ecx, eax
// 00859cdf  3bc1                 cmp eax, ecx
// 00859ce1  730b                 jae 0x859cee
// 00859ce3  8b5620               mov edx, dword ptr [esi + 0x20]
// 00859ce6  8b02                 mov eax, dword ptr [edx]
// 00859ce8  0fb600               movzx eax, byte ptr [eax]
// 00859ceb  5e                   pop esi
// 00859cec  59                   pop ecx
// 00859ced  c3                   ret 
// 00859cee  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00859cf1  8b01                 mov eax, dword ptr [ecx]
// 00859cf3  8b5610               mov edx, dword ptr [esi + 0x10]
// 00859cf6  8bc8                 mov ecx, eax
// 00859cf8  2b0a                 sub ecx, dword ptr [edx]
// 00859cfa  53                   push ebx
// 00859cfb  394e54               cmp dword ptr [esi + 0x54], ecx
// 00859cfe  8d5e54               lea ebx, [esi + 0x54]
// 00859d01  894c2408             mov dword ptr [esp + 8], ecx
// 00859d05  57                   push edi
// 00859d06  8bcb                 mov ecx, ebx
// 00859d08  7c04                 jl 0x859d0e
// 00859d0a  8d4c240c             lea ecx, [esp + 0xc]
// 00859d0e  8b39                 mov edi, dword ptr [ecx]
// 00859d10  85ff                 test edi, edi
// 00859d12  7416                 je 0x859d2a
// 00859d14  2bc7                 sub eax, edi
// 00859d16  57                   push edi
// 00859d17  50                   push eax
// 00859d18  8b464c               mov eax, dword ptr [esi + 0x4c]
// 00859d1b  2bc7                 sub eax, edi
// 00859d1d  0303                 add eax, dword ptr [ebx]
// 00859d1f  57                   push edi
// 00859d20  50                   push eax
// 00859d21  ff15c02ab200         call dword ptr [0xb22ac0]
// 00859d27  83c410               add esp, 0x10
// 00859d2a  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00859d2d  8b13                 mov edx, dword ptr [ebx]
// 00859d2f  8d0411               lea eax, [ecx + edx]
// 00859d32  8b5610               mov edx, dword ptr [esi + 0x10]
// 00859d35  8bc8                 mov ecx, eax
// 00859d37  2bcf                 sub ecx, edi
// 00859d39  890a                 mov dword ptr [edx], ecx
// 00859d3b  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00859d3e  8901                 mov dword ptr [ecx], eax
// 00859d40  8bd0                 mov edx, eax
// 00859d42  2bd0                 sub edx, eax
// 00859d44  8b4630               mov eax, dword ptr [esi + 0x30]
// 00859d47  8910                 mov dword ptr [eax], edx
// 00859d49  8b1b                 mov ebx, dword ptr [ebx]
// 00859d4b  8b4e50               mov ecx, dword ptr [esi + 0x50]
// 00859d4e  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00859d51  8b4648               mov eax, dword ptr [esi + 0x48]
// 00859d54  2bcb                 sub ecx, ebx
// 00859d56  51                   push ecx
// 00859d57  03d3                 add edx, ebx
// 00859d59  52                   push edx
// 00859d5a  50                   push eax
// 00859d5b  83c640               add esi, 0x40
// 00859d5e  56                   push esi
// 00859d5f  e88cfeffff           call 0x859bf0
// 00859d64  5f                   pop edi
// 00859d65  5b                   pop ebx
// copied from an identical function in another client (function ?underflow@?$indirect_streambuf@V?$reference_wrapper@V?$basic_ostream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uoutput_seekable@iostreams@2@@detail@iostreams@boost@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp