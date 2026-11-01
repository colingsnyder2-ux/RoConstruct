// from server: 100% by auto
// roc 2009-06 0079aae0  unit: CXTPResourceManager  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079aae0
//
// 0079aae0  8b442408             mov eax, dword ptr [esp + 8]
// 0079aae4  56                   push esi
// 0079aae5  8b35c0e18900         mov esi, dword ptr [0x89e1c0]
// 0079aaeb  57                   push edi
// 0079aaec  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0079aaf0  6a0e                 push 0xe
// 0079aaf2  50                   push eax
// 0079aaf3  57                   push edi
// 0079aaf4  ffd6                 call esi
// 0079aaf6  85c0                 test eax, eax
// 0079aaf8  7505                 jne 0x79aaff
// 0079aafa  5f                   pop edi
// 0079aafb  5e                   pop esi
// 0079aafc  c21000               ret 0x10
// 0079aaff  55                   push ebp
// 0079ab00  8b2dbce18900         mov ebp, dword ptr [0x89e1bc]
// 0079ab06  50                   push eax
// 0079ab07  57                   push edi
// 0079ab08  ffd5                 call ebp
// 0079ab0a  85c0                 test eax, eax
// 0079ab0c  7506                 jne 0x79ab14
// 0079ab0e  5d                   pop ebp
// 0079ab0f  5f                   pop edi
// 0079ab10  5e                   pop esi
// 0079ab11  c21000               ret 0x10
// 0079ab14  53                   push ebx
// 0079ab15  8b1d50e28900         mov ebx, dword ptr [0x89e250]
// 0079ab1b  50                   push eax
// 0079ab1c  ffd3                 call ebx
// 0079ab1e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079ab22  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0079ab26  6a00                 push 0
// 0079ab28  51                   push ecx
// 0079ab29  52                   push edx
// 0079ab2a  6a01                 push 1
// 0079ab2c  50                   push eax
// 0079ab2d  ff1560ec8900         call dword ptr [0x89ec60]
// 0079ab33  0fb7c0               movzx eax, ax
// 0079ab36  6a03                 push 3
// 0079ab38  50                   push eax
// 0079ab39  57                   push edi
// 0079ab3a  ffd6                 call esi
// 0079ab3c  8bf0                 mov esi, eax
// 0079ab3e  85f6                 test esi, esi
// 0079ab40  7408                 je 0x79ab4a
// 0079ab42  56                   push esi
// 0079ab43  57                   push edi
// 0079ab44  ffd5                 call ebp
// 0079ab46  85c0                 test eax, eax
// 0079ab48  7509                 jne 0x79ab53
// 0079ab4a  5b                   pop ebx
// 0079ab4b  5d                   pop ebp
// 0079ab4c  5f                   pop edi
// 0079ab4d  33c0                 xor eax, eax
// 0079ab4f  5e                   pop esi
// 0079ab50  c21000               ret 0x10
// 0079ab53  50                   push eax
// 0079ab54  ffd3                 call ebx
// 0079ab56  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079ab5a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0079ab5e  6a00                 push 0
// 0079ab60  51                   push ecx
// 0079ab61  52                   push edx
// 0079ab62  6800000300           push 0x30000
// 0079ab67  6a01                 push 1
// 0079ab69  56                   push esi
// 0079ab6a  57                   push edi
// 0079ab6b  8bd8                 mov ebx, eax
// 0079ab6d  ff15b8e18900         call dword ptr [0x89e1b8]
// 0079ab73  50                   push eax
// 0079ab74  53                   push ebx
// 0079ab75  ff1524ef8900         call dword ptr [0x89ef24]
// 0079ab7b  5b                   pop ebx
// 0079ab7c  5d                   pop ebp
// 0079ab7d  5f                   pop edi
// 0079ab7e  5e                   pop esi
// 0079ab7f  c21000               ret 0x10
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?CreateIconFromResource@CXTPResourceManager@@UAEPAUHICON__@@PAUHINSTANCE__@@PBDVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
