// from server: 100% by auto
// roc 2009-12 00403090  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403090
//
// 00403090  f6056895b70001       test byte ptr [0xb79568], 1
// 00403097  755d                 jne 0x4030f6
// 00403099  830d6895b70001       or dword ptr [0xb79568], 1
// 004030a0  b808000000           mov eax, 8
// 004030a5  66a34c95b700         mov word ptr [0xb7954c], ax
// 004030ab  b908400000           mov ecx, 0x4008
// 004030b0  ba13000000           mov edx, 0x13
// 004030b5  b811000000           mov eax, 0x11
// 004030ba  c7054895b70058f69900 mov dword ptr [0xb79548], 0x99f658
// 004030c4  c7055095b70054f69900 mov dword ptr [0xb79550], 0x99f654
// 004030ce  66890d5495b700       mov word ptr [0xb79554], cx
// 004030d5  c7055895b70050f69900 mov dword ptr [0xb79558], 0x99f650
// 004030df  6689155c95b700       mov word ptr [0xb7955c], dx
// 004030e6  c7056095b7004cf69900 mov dword ptr [0xb79560], 0x99f64c
// 004030f0  66a36495b700         mov word ptr [0xb79564], ax
// 004030f6  53                   push ebx
// 004030f7  8b1d14b29800         mov ebx, dword ptr [0x98b214]
// 004030fd  56                   push esi
// 004030fe  57                   push edi
// 004030ff  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00403103  33f6                 xor esi, esi
// 00403105  8b0cf54895b700       mov ecx, dword ptr [esi*8 + 0xb79548]
// 0040310c  51                   push ecx
// 0040310d  57                   push edi
// 0040310e  ffd3                 call ebx
// 00403110  85c0                 test eax, eax
// 00403112  740c                 je 0x403120
// 00403114  46                   inc esi
// 00403115  83fe04               cmp esi, 4
// 00403118  72eb                 jb 0x403105
// 0040311a  5f                   pop edi
// 0040311b  5e                   pop esi
// 0040311c  33c0                 xor eax, eax
// 0040311e  5b                   pop ebx
// 0040311f  c3                   ret 
// 00403120  668b14f54c95b700     mov dx, word ptr [esi*8 + 0xb7954c]
// 00403128  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040312c  5f                   pop edi
// 0040312d  5e                   pop esi
// 0040312e  668910               mov word ptr [eax], dx
// 00403131  b801000000           mov eax, 1
// 00403136  5b                   pop ebx
// 00403137  c3                   ret 
// library atl-9.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
