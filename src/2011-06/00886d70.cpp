// from server: 100% by auto
// roc 2011-06 00886d70  unit: XTPPaintThemes::CXTPDefaultTheme  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00886d70
//
// 00886d70  837c241800           cmp dword ptr [esp + 0x18], 0
// 00886d75  56                   push esi
// 00886d76  57                   push edi
// 00886d77  8bf9                 mov edi, ecx
// 00886d79  0f8588000000         jne 0x886e07
// 00886d7f  6aff                 push -1
// 00886d81  6aff                 push -1
// 00886d83  8d442418             lea eax, [esp + 0x18]
// 00886d87  50                   push eax
// 00886d88  ff15e41ba400         call dword ptr [0xa41be4]
// 00886d8e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00886d92  83f802               cmp eax, 2
// 00886d95  7409                 je 0x886da0
// 00886d97  83f803               cmp eax, 3
// 00886d9a  7404                 je 0x886da0
// 00886d9c  33c9                 xor ecx, ecx
// 00886d9e  eb05                 jmp 0x886da5
// 00886da0  b901000000           mov ecx, 1
// 00886da5  83f802               cmp eax, 2
// 00886da8  7409                 je 0x886db3
// 00886daa  83f803               cmp eax, 3
// 00886dad  7404                 je 0x886db3
// 00886daf  33c0                 xor eax, eax
// 00886db1  eb05                 jmp 0x886db8
// 00886db3  b801000000           mov eax, 1
// 00886db8  33d2                 xor edx, edx
// 00886dba  85c9                 test ecx, ecx
// 00886dbc  0f94c2               sete dl
// 00886dbf  33c9                 xor ecx, ecx
// 00886dc1  85c0                 test eax, eax
// 00886dc3  0f94c1               sete cl
// 00886dc6  8d149510000000       lea edx, [edx*4 + 0x10]
// 00886dcd  52                   push edx
// 00886dce  8b542414             mov edx, dword ptr [esp + 0x14]
// 00886dd2  8d0c8d10000000       lea ecx, [ecx*4 + 0x10]
// 00886dd9  51                   push ecx
// 00886dda  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00886dde  83ec10               sub esp, 0x10
// 00886de1  8bc4                 mov eax, esp
// 00886de3  8910                 mov dword ptr [eax], edx
// 00886de5  8b542430             mov edx, dword ptr [esp + 0x30]
// 00886de9  894804               mov dword ptr [eax + 4], ecx
// 00886dec  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00886df0  895008               mov dword ptr [eax + 8], edx
// 00886df3  8b542424             mov edx, dword ptr [esp + 0x24]
// 00886df7  89480c               mov dword ptr [eax + 0xc], ecx
// 00886dfa  52                   push edx
// 00886dfb  8bcf                 mov ecx, edi
// 00886dfd  e8ae89f8ff           call 0x80f7b0
// 00886e02  5f                   pop edi
// 00886e03  5e                   pop esi
// 00886e04  c21c00               ret 0x1c
// 00886e07  837c242400           cmp dword ptr [esp + 0x24], 0
// 00886e0c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00886e10  742c                 je 0x886e3e
// 00886e12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00886e16  8b542414             mov edx, dword ptr [esp + 0x14]
// 00886e1a  6a14                 push 0x14
// 00886e1c  6a10                 push 0x10
// 00886e1e  83ec10               sub esp, 0x10
// 00886e21  8bc4                 mov eax, esp
// 00886e23  8908                 mov dword ptr [eax], ecx
// 00886e25  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00886e29  895004               mov dword ptr [eax + 4], edx
// 00886e2c  8b542434             mov edx, dword ptr [esp + 0x34]
// 00886e30  894808               mov dword ptr [eax + 8], ecx
// 00886e33  56                   push esi
// 00886e34  8bcf                 mov ecx, edi
// 00886e36  89500c               mov dword ptr [eax + 0xc], edx
// 00886e39  e87289f8ff           call 0x80f7b0
// 00886e3e  6aff                 push -1
// 00886e40  6aff                 push -1
// 00886e42  8d442418             lea eax, [esp + 0x18]
// 00886e46  50                   push eax
// 00886e47  ff15e41ba400         call dword ptr [0xa41be4]
// 00886e4d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00886e51  8b542414             mov edx, dword ptr [esp + 0x14]
// 00886e55  6a0f                 push 0xf
// 00886e57  6a0f                 push 0xf
// 00886e59  83ec10               sub esp, 0x10
// 00886e5c  8bc4                 mov eax, esp
// 00886e5e  8908                 mov dword ptr [eax], ecx
// 00886e60  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00886e64  895004               mov dword ptr [eax + 4], edx
// 00886e67  8b542434             mov edx, dword ptr [esp + 0x34]
// 00886e6b  894808               mov dword ptr [eax + 8], ecx
// 00886e6e  56                   push esi
// 00886e6f  8bcf                 mov ecx, edi
// 00886e71  89500c               mov dword ptr [eax + 0xc], edx
// 00886e74  e83789f8ff           call 0x80f7b0
// 00886e79  5f                   pop edi
// 00886e7a  5e                   pop esi
// 00886e7b  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawControlEditFrame@CXTPDefaultTheme@@MAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
