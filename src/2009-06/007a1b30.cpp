// from server: 100% by auto
// roc 2009-06 007a1b30  unit: XTPPaintThemes::CXTPDefaultTheme  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a1b30
//
// 007a1b30  837c241800           cmp dword ptr [esp + 0x18], 0
// 007a1b35  56                   push esi
// 007a1b36  57                   push edi
// 007a1b37  8bf9                 mov edi, ecx
// 007a1b39  0f8588000000         jne 0x7a1bc7
// 007a1b3f  6aff                 push -1
// 007a1b41  6aff                 push -1
// 007a1b43  8d442418             lea eax, [esp + 0x18]
// 007a1b47  50                   push eax
// 007a1b48  ff15bced8900         call dword ptr [0x89edbc]
// 007a1b4e  8b442424             mov eax, dword ptr [esp + 0x24]
// 007a1b52  83f802               cmp eax, 2
// 007a1b55  7409                 je 0x7a1b60
// 007a1b57  83f803               cmp eax, 3
// 007a1b5a  7404                 je 0x7a1b60
// 007a1b5c  33c9                 xor ecx, ecx
// 007a1b5e  eb05                 jmp 0x7a1b65
// 007a1b60  b901000000           mov ecx, 1
// 007a1b65  83f802               cmp eax, 2
// 007a1b68  7409                 je 0x7a1b73
// 007a1b6a  83f803               cmp eax, 3
// 007a1b6d  7404                 je 0x7a1b73
// 007a1b6f  33c0                 xor eax, eax
// 007a1b71  eb05                 jmp 0x7a1b78
// 007a1b73  b801000000           mov eax, 1
// 007a1b78  33d2                 xor edx, edx
// 007a1b7a  85c9                 test ecx, ecx
// 007a1b7c  0f94c2               sete dl
// 007a1b7f  33c9                 xor ecx, ecx
// 007a1b81  85c0                 test eax, eax
// 007a1b83  0f94c1               sete cl
// 007a1b86  8d149510000000       lea edx, [edx*4 + 0x10]
// 007a1b8d  52                   push edx
// 007a1b8e  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a1b92  8d0c8d10000000       lea ecx, [ecx*4 + 0x10]
// 007a1b99  51                   push ecx
// 007a1b9a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007a1b9e  83ec10               sub esp, 0x10
// 007a1ba1  8bc4                 mov eax, esp
// 007a1ba3  8910                 mov dword ptr [eax], edx
// 007a1ba5  8b542430             mov edx, dword ptr [esp + 0x30]
// 007a1ba9  894804               mov dword ptr [eax + 4], ecx
// 007a1bac  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007a1bb0  895008               mov dword ptr [eax + 8], edx
// 007a1bb3  8b542424             mov edx, dword ptr [esp + 0x24]
// 007a1bb7  89480c               mov dword ptr [eax + 0xc], ecx
// 007a1bba  52                   push edx
// 007a1bbb  8bcf                 mov ecx, edi
// 007a1bbd  e8be0df8ff           call 0x722980
// 007a1bc2  5f                   pop edi
// 007a1bc3  5e                   pop esi
// 007a1bc4  c21c00               ret 0x1c
// 007a1bc7  837c242400           cmp dword ptr [esp + 0x24], 0
// 007a1bcc  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007a1bd0  742c                 je 0x7a1bfe
// 007a1bd2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a1bd6  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a1bda  6a14                 push 0x14
// 007a1bdc  6a10                 push 0x10
// 007a1bde  83ec10               sub esp, 0x10
// 007a1be1  8bc4                 mov eax, esp
// 007a1be3  8908                 mov dword ptr [eax], ecx
// 007a1be5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007a1be9  895004               mov dword ptr [eax + 4], edx
// 007a1bec  8b542434             mov edx, dword ptr [esp + 0x34]
// 007a1bf0  894808               mov dword ptr [eax + 8], ecx
// 007a1bf3  56                   push esi
// 007a1bf4  8bcf                 mov ecx, edi
// 007a1bf6  89500c               mov dword ptr [eax + 0xc], edx
// 007a1bf9  e8820df8ff           call 0x722980
// 007a1bfe  6aff                 push -1
// 007a1c00  6aff                 push -1
// 007a1c02  8d442418             lea eax, [esp + 0x18]
// 007a1c06  50                   push eax
// 007a1c07  ff15bced8900         call dword ptr [0x89edbc]
// 007a1c0d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a1c11  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a1c15  6a0f                 push 0xf
// 007a1c17  6a0f                 push 0xf
// 007a1c19  83ec10               sub esp, 0x10
// 007a1c1c  8bc4                 mov eax, esp
// 007a1c1e  8908                 mov dword ptr [eax], ecx
// 007a1c20  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007a1c24  895004               mov dword ptr [eax + 4], edx
// 007a1c27  8b542434             mov edx, dword ptr [esp + 0x34]
// 007a1c2b  894808               mov dword ptr [eax + 8], ecx
// 007a1c2e  56                   push esi
// 007a1c2f  8bcf                 mov ecx, edi
// 007a1c31  89500c               mov dword ptr [eax + 0xc], edx
// 007a1c34  e8470df8ff           call 0x722980
// 007a1c39  5f                   pop edi
// 007a1c3a  5e                   pop esi
// 007a1c3b  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawControlEditFrame@CXTPDefaultTheme@@MAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
