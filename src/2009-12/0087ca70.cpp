// from server: 100% by auto
// roc 2009-12 0087ca70  unit: XTPPaintThemes::CXTPDefaultTheme  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087ca70
//
// 0087ca70  837c241800           cmp dword ptr [esp + 0x18], 0
// 0087ca75  56                   push esi
// 0087ca76  57                   push edi
// 0087ca77  8bf9                 mov edi, ecx
// 0087ca79  0f8588000000         jne 0x87cb07
// 0087ca7f  6aff                 push -1
// 0087ca81  6aff                 push -1
// 0087ca83  8d442418             lea eax, [esp + 0x18]
// 0087ca87  50                   push eax
// 0087ca88  ff1558ca9800         call dword ptr [0x98ca58]
// 0087ca8e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0087ca92  83f802               cmp eax, 2
// 0087ca95  7409                 je 0x87caa0
// 0087ca97  83f803               cmp eax, 3
// 0087ca9a  7404                 je 0x87caa0
// 0087ca9c  33c9                 xor ecx, ecx
// 0087ca9e  eb05                 jmp 0x87caa5
// 0087caa0  b901000000           mov ecx, 1
// 0087caa5  83f802               cmp eax, 2
// 0087caa8  7409                 je 0x87cab3
// 0087caaa  83f803               cmp eax, 3
// 0087caad  7404                 je 0x87cab3
// 0087caaf  33c0                 xor eax, eax
// 0087cab1  eb05                 jmp 0x87cab8
// 0087cab3  b801000000           mov eax, 1
// 0087cab8  33d2                 xor edx, edx
// 0087caba  85c9                 test ecx, ecx
// 0087cabc  0f94c2               sete dl
// 0087cabf  33c9                 xor ecx, ecx
// 0087cac1  85c0                 test eax, eax
// 0087cac3  0f94c1               sete cl
// 0087cac6  8d149510000000       lea edx, [edx*4 + 0x10]
// 0087cacd  52                   push edx
// 0087cace  8b542414             mov edx, dword ptr [esp + 0x14]
// 0087cad2  8d0c8d10000000       lea ecx, [ecx*4 + 0x10]
// 0087cad9  51                   push ecx
// 0087cada  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0087cade  83ec10               sub esp, 0x10
// 0087cae1  8bc4                 mov eax, esp
// 0087cae3  8910                 mov dword ptr [eax], edx
// 0087cae5  8b542430             mov edx, dword ptr [esp + 0x30]
// 0087cae9  894804               mov dword ptr [eax + 4], ecx
// 0087caec  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0087caf0  895008               mov dword ptr [eax + 8], edx
// 0087caf3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0087caf7  89480c               mov dword ptr [eax + 0xc], ecx
// 0087cafa  52                   push edx
// 0087cafb  8bcf                 mov ecx, edi
// 0087cafd  e83e0df8ff           call 0x7fd840
// 0087cb02  5f                   pop edi
// 0087cb03  5e                   pop esi
// 0087cb04  c21c00               ret 0x1c
// 0087cb07  837c242400           cmp dword ptr [esp + 0x24], 0
// 0087cb0c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0087cb10  742c                 je 0x87cb3e
// 0087cb12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0087cb16  8b542414             mov edx, dword ptr [esp + 0x14]
// 0087cb1a  6a14                 push 0x14
// 0087cb1c  6a10                 push 0x10
// 0087cb1e  83ec10               sub esp, 0x10
// 0087cb21  8bc4                 mov eax, esp
// 0087cb23  8908                 mov dword ptr [eax], ecx
// 0087cb25  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0087cb29  895004               mov dword ptr [eax + 4], edx
// 0087cb2c  8b542434             mov edx, dword ptr [esp + 0x34]
// 0087cb30  894808               mov dword ptr [eax + 8], ecx
// 0087cb33  56                   push esi
// 0087cb34  8bcf                 mov ecx, edi
// 0087cb36  89500c               mov dword ptr [eax + 0xc], edx
// 0087cb39  e8020df8ff           call 0x7fd840
// 0087cb3e  6aff                 push -1
// 0087cb40  6aff                 push -1
// 0087cb42  8d442418             lea eax, [esp + 0x18]
// 0087cb46  50                   push eax
// 0087cb47  ff1558ca9800         call dword ptr [0x98ca58]
// 0087cb4d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0087cb51  8b542414             mov edx, dword ptr [esp + 0x14]
// 0087cb55  6a0f                 push 0xf
// 0087cb57  6a0f                 push 0xf
// 0087cb59  83ec10               sub esp, 0x10
// 0087cb5c  8bc4                 mov eax, esp
// 0087cb5e  8908                 mov dword ptr [eax], ecx
// 0087cb60  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0087cb64  895004               mov dword ptr [eax + 4], edx
// 0087cb67  8b542434             mov edx, dword ptr [esp + 0x34]
// 0087cb6b  894808               mov dword ptr [eax + 8], ecx
// 0087cb6e  56                   push esi
// 0087cb6f  8bcf                 mov ecx, edi
// 0087cb71  89500c               mov dword ptr [eax + 0xc], edx
// 0087cb74  e8c70cf8ff           call 0x7fd840
// 0087cb79  5f                   pop edi
// 0087cb7a  5e                   pop esi
// 0087cb7b  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawControlEditFrame@CXTPDefaultTheme@@MAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
