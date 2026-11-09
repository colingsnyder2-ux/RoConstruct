// from server: 100% by auto
// roc 2010-06 007e9580  unit: CXTPControls  size: 272 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9580
//
// 007e9580  837c240800           cmp dword ptr [esp + 8], 0
// 007e9585  53                   push ebx
// 007e9586  55                   push ebp
// 007e9587  56                   push esi
// 007e9588  57                   push edi
// 007e9589  8bf1                 mov esi, ecx
// 007e958b  0f84f8000000         je 0x7e9689
// 007e9591  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007e9595  6a00                 push 0
// 007e9597  56                   push esi
// 007e9598  685cbda500           push 0xa5bd5c
// 007e959d  57                   push edi
// 007e959e  e89db40100           call 0x804a40
// 007e95a3  6a01                 push 1
// 007e95a5  8d4604               lea eax, [esi + 4]
// 007e95a8  50                   push eax
// 007e95a9  688068a100           push 0xa16880
// 007e95ae  57                   push edi
// 007e95af  e81cb50100           call 0x804ad0
// 007e95b4  6a00                 push 0
// 007e95b6  8d4e08               lea ecx, [esi + 8]
// 007e95b9  51                   push ecx
// 007e95ba  6850bda500           push 0xa5bd50
// 007e95bf  57                   push edi
// 007e95c0  e80bb50100           call 0x804ad0
// 007e95c5  8d5614               lea edx, [esi + 0x14]
// 007e95c8  52                   push edx
// 007e95c9  6844bda500           push 0xa5bd44
// 007e95ce  57                   push edi
// 007e95cf  e89cb40100           call 0x804a70
// 007e95d4  6a00                 push 0
// 007e95d6  8d4618               lea eax, [esi + 0x18]
// 007e95d9  50                   push eax
// 007e95da  6834bda500           push 0xa5bd34
// 007e95df  57                   push edi
// 007e95e0  e85bb40100           call 0x804a40
// 007e95e5  83c44c               add esp, 0x4c
// 007e95e8  33c9                 xor ecx, ecx
// 007e95ea  51                   push ecx
// 007e95eb  33c0                 xor eax, eax
// 007e95ed  50                   push eax
// 007e95ee  8d4e0c               lea ecx, [esi + 0xc]
// 007e95f1  51                   push ecx
// 007e95f2  6828bda500           push 0xa5bd28
// 007e95f7  57                   push edi
// 007e95f8  e8c3b50100           call 0x804bc0
// 007e95fd  83c404               add esp, 4
// 007e9600  8bc4                 mov eax, esp
// 007e9602  33c9                 xor ecx, ecx
// 007e9604  33d2                 xor edx, edx
// 007e9606  8908                 mov dword ptr [eax], ecx
// 007e9608  895004               mov dword ptr [eax + 4], edx
// 007e960b  8d561c               lea edx, [esi + 0x1c]
// 007e960e  52                   push edx
// 007e960f  33db                 xor ebx, ebx
// 007e9611  681cbda500           push 0xa5bd1c
// 007e9616  33ed                 xor ebp, ebp
// 007e9618  895808               mov dword ptr [eax + 8], ebx
// 007e961b  57                   push edi
// 007e961c  89680c               mov dword ptr [eax + 0xc], ebp
// 007e961f  e8ccb50100           call 0x804bf0
// 007e9624  33c9                 xor ecx, ecx
// 007e9626  51                   push ecx
// 007e9627  33c0                 xor eax, eax
// 007e9629  50                   push eax
// 007e962a  8d4630               lea eax, [esi + 0x30]
// 007e962d  50                   push eax
// 007e962e  6810bda500           push 0xa5bd10
// 007e9633  57                   push edi
// 007e9634  e887b50100           call 0x804bc0
// 007e9639  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 007e963d  83c430               add esp, 0x30
// 007e9640  833906               cmp dword ptr [ecx], 6
// 007e9643  7644                 jbe 0x7e9689
// 007e9645  55                   push ebp
// 007e9646  8d5e3c               lea ebx, [esi + 0x3c]
// 007e9649  53                   push ebx
// 007e964a  6804bda500           push 0xa5bd04
// 007e964f  57                   push edi
// 007e9650  e87bb40100           call 0x804ad0
// 007e9655  83c410               add esp, 0x10
// 007e9658  392b                 cmp dword ptr [ebx], ebp
// 007e965a  742d                 je 0x7e9689
// 007e965c  33c9                 xor ecx, ecx
// 007e965e  51                   push ecx
// 007e965f  33c0                 xor eax, eax
// 007e9661  50                   push eax
// 007e9662  8d5640               lea edx, [esi + 0x40]
// 007e9665  52                   push edx
// 007e9666  68e8bca500           push 0xa5bce8
// 007e966b  57                   push edi
// 007e966c  e84fb50100           call 0x804bc0
// 007e9671  33c9                 xor ecx, ecx
// 007e9673  51                   push ecx
// 007e9674  33c0                 xor eax, eax
// 007e9676  50                   push eax
// 007e9677  83c648               add esi, 0x48
// 007e967a  56                   push esi
// 007e967b  68ccbca500           push 0xa5bccc
// 007e9680  57                   push edi
// 007e9681  e83ab50100           call 0x804bc0
// 007e9686  83c428               add esp, 0x28
// 007e9689  5f                   pop edi
// 007e968a  5e                   pop esi
// 007e968b  5d                   pop ebp
// 007e968c  5b                   pop ebx
// 007e968d  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPDockState.cpp (function ?DoPropExchange@CToolBarInfo@CXTPToolBar@@QAEXPAVCXTPPropExchange@@PAVCXTPDockState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockState.cpp
