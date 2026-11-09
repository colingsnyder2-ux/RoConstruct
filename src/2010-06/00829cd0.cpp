// from server: 100% by auto
// roc 2010-06 00829cd0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00829cd0
//
// 00829cd0  837c241800           cmp dword ptr [esp + 0x18], 0
// 00829cd5  56                   push esi
// 00829cd6  57                   push edi
// 00829cd7  8bf9                 mov edi, ecx
// 00829cd9  0f8588000000         jne 0x829d67
// 00829cdf  6aff                 push -1
// 00829ce1  6aff                 push -1
// 00829ce3  8d442418             lea eax, [esp + 0x18]
// 00829ce7  50                   push eax
// 00829ce8  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 00829cee  8b442424             mov eax, dword ptr [esp + 0x24]
// 00829cf2  83f802               cmp eax, 2
// 00829cf5  7409                 je 0x829d00
// 00829cf7  83f803               cmp eax, 3
// 00829cfa  7404                 je 0x829d00
// 00829cfc  33c9                 xor ecx, ecx
// 00829cfe  eb05                 jmp 0x829d05
// 00829d00  b901000000           mov ecx, 1
// 00829d05  83f802               cmp eax, 2
// 00829d08  7409                 je 0x829d13
// 00829d0a  83f803               cmp eax, 3
// 00829d0d  7404                 je 0x829d13
// 00829d0f  33c0                 xor eax, eax
// 00829d11  eb05                 jmp 0x829d18
// 00829d13  b801000000           mov eax, 1
// 00829d18  33d2                 xor edx, edx
// 00829d1a  85c9                 test ecx, ecx
// 00829d1c  0f94c2               sete dl
// 00829d1f  33c9                 xor ecx, ecx
// 00829d21  85c0                 test eax, eax
// 00829d23  0f94c1               sete cl
// 00829d26  8d149510000000       lea edx, [edx*4 + 0x10]
// 00829d2d  52                   push edx
// 00829d2e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00829d32  8d0c8d10000000       lea ecx, [ecx*4 + 0x10]
// 00829d39  51                   push ecx
// 00829d3a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00829d3e  83ec10               sub esp, 0x10
// 00829d41  8bc4                 mov eax, esp
// 00829d43  8910                 mov dword ptr [eax], edx
// 00829d45  8b542430             mov edx, dword ptr [esp + 0x30]
// 00829d49  894804               mov dword ptr [eax + 4], ecx
// 00829d4c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00829d50  895008               mov dword ptr [eax + 8], edx
// 00829d53  8b542424             mov edx, dword ptr [esp + 0x24]
// 00829d57  89480c               mov dword ptr [eax + 0xc], ecx
// 00829d5a  52                   push edx
// 00829d5b  8bcf                 mov ecx, edi
// 00829d5d  e8ae35f8ff           call 0x7ad310
// 00829d62  5f                   pop edi
// 00829d63  5e                   pop esi
// 00829d64  c21c00               ret 0x1c
// 00829d67  837c242400           cmp dword ptr [esp + 0x24], 0
// 00829d6c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00829d70  742c                 je 0x829d9e
// 00829d72  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00829d76  8b542414             mov edx, dword ptr [esp + 0x14]
// 00829d7a  6a14                 push 0x14
// 00829d7c  6a10                 push 0x10
// 00829d7e  83ec10               sub esp, 0x10
// 00829d81  8bc4                 mov eax, esp
// 00829d83  8908                 mov dword ptr [eax], ecx
// 00829d85  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00829d89  895004               mov dword ptr [eax + 4], edx
// 00829d8c  8b542434             mov edx, dword ptr [esp + 0x34]
// 00829d90  894808               mov dword ptr [eax + 8], ecx
// 00829d93  56                   push esi
// 00829d94  8bcf                 mov ecx, edi
// 00829d96  89500c               mov dword ptr [eax + 0xc], edx
// 00829d99  e87235f8ff           call 0x7ad310
// 00829d9e  6aff                 push -1
// 00829da0  6aff                 push -1
// 00829da2  8d442418             lea eax, [esp + 0x18]
// 00829da6  50                   push eax
// 00829da7  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 00829dad  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00829db1  8b542414             mov edx, dword ptr [esp + 0x14]
// 00829db5  6a0f                 push 0xf
// 00829db7  6a0f                 push 0xf
// 00829db9  83ec10               sub esp, 0x10
// 00829dbc  8bc4                 mov eax, esp
// 00829dbe  8908                 mov dword ptr [eax], ecx
// 00829dc0  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00829dc4  895004               mov dword ptr [eax + 4], edx
// 00829dc7  8b542434             mov edx, dword ptr [esp + 0x34]
// 00829dcb  894808               mov dword ptr [eax + 8], ecx
// 00829dce  56                   push esi
// 00829dcf  8bcf                 mov ecx, edi
// 00829dd1  89500c               mov dword ptr [eax + 0xc], edx
// 00829dd4  e83735f8ff           call 0x7ad310
// 00829dd9  5f                   pop edi
// 00829dda  5e                   pop esi
// 00829ddb  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawControlEditFrame@CXTPDefaultTheme@@MAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
