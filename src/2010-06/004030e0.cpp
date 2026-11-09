// from server: 100% by auto
// roc 2010-06 004030e0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004030e0
//
// 004030e0  f60518fbbf0001       test byte ptr [0xbffb18], 1
// 004030e7  755d                 jne 0x403146
// 004030e9  830d18fbbf0001       or dword ptr [0xbffb18], 1
// 004030f0  b808000000           mov eax, 8
// 004030f5  66a3fcfabf00         mov word ptr [0xbffafc], ax
// 004030fb  b908400000           mov ecx, 0x4008
// 00403100  ba13000000           mov edx, 0x13
// 00403105  b811000000           mov eax, 0x11
// 0040310a  c705f8fabf000002a000 mov dword ptr [0xbffaf8], 0xa00200
// 00403114  c70500fbbf00fc01a000 mov dword ptr [0xbffb00], 0xa001fc
// 0040311e  66890d04fbbf00       mov word ptr [0xbffb04], cx
// 00403125  c70508fbbf00f801a000 mov dword ptr [0xbffb08], 0xa001f8
// 0040312f  6689150cfbbf00       mov word ptr [0xbffb0c], dx
// 00403136  c70510fbbf00f401a000 mov dword ptr [0xbffb10], 0xa001f4
// 00403140  66a314fbbf00         mov word ptr [0xbffb14], ax
// 00403146  53                   push ebx
// 00403147  8b1d84a39e00         mov ebx, dword ptr [0x9ea384]
// 0040314d  56                   push esi
// 0040314e  57                   push edi
// 0040314f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00403153  33f6                 xor esi, esi
// 00403155  8b0cf5f8fabf00       mov ecx, dword ptr [esi*8 + 0xbffaf8]
// 0040315c  51                   push ecx
// 0040315d  57                   push edi
// 0040315e  ffd3                 call ebx
// 00403160  85c0                 test eax, eax
// 00403162  740c                 je 0x403170
// 00403164  46                   inc esi
// 00403165  83fe04               cmp esi, 4
// 00403168  72eb                 jb 0x403155
// 0040316a  5f                   pop edi
// 0040316b  5e                   pop esi
// 0040316c  33c0                 xor eax, eax
// 0040316e  5b                   pop ebx
// 0040316f  c3                   ret 
// 00403170  668b14f5fcfabf00     mov dx, word ptr [esi*8 + 0xbffafc]
// 00403178  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040317c  5f                   pop edi
// 0040317d  5e                   pop esi
// 0040317e  668910               mov word ptr [eax], dx
// 00403181  b801000000           mov eax, 1
// 00403186  5b                   pop ebx
// 00403187  c3                   ret 
// library atl-9.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
