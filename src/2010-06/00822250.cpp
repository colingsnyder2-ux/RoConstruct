// from server: 100% by auto
// roc 2010-06 00822250  unit: CXTPResourceManager  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822250
//
// 00822250  8b442408             mov eax, dword ptr [esp + 8]
// 00822254  56                   push esi
// 00822255  8b355ca39e00         mov esi, dword ptr [0x9ea35c]
// 0082225b  57                   push edi
// 0082225c  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00822260  6a0e                 push 0xe
// 00822262  50                   push eax
// 00822263  57                   push edi
// 00822264  ffd6                 call esi
// 00822266  85c0                 test eax, eax
// 00822268  7505                 jne 0x82226f
// 0082226a  5f                   pop edi
// 0082226b  5e                   pop esi
// 0082226c  c21000               ret 0x10
// 0082226f  55                   push ebp
// 00822270  8b2d60a39e00         mov ebp, dword ptr [0x9ea360]
// 00822276  50                   push eax
// 00822277  57                   push edi
// 00822278  ffd5                 call ebp
// 0082227a  85c0                 test eax, eax
// 0082227c  7506                 jne 0x822284
// 0082227e  5d                   pop ebp
// 0082227f  5f                   pop edi
// 00822280  5e                   pop esi
// 00822281  c21000               ret 0x10
// 00822284  53                   push ebx
// 00822285  8b1deca29e00         mov ebx, dword ptr [0x9ea2ec]
// 0082228b  50                   push eax
// 0082228c  ffd3                 call ebx
// 0082228e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00822292  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00822296  6a00                 push 0
// 00822298  51                   push ecx
// 00822299  52                   push edx
// 0082229a  6a01                 push 1
// 0082229c  50                   push eax
// 0082229d  ff1534ba9e00         call dword ptr [0x9eba34]
// 008222a3  0fb7c0               movzx eax, ax
// 008222a6  6a03                 push 3
// 008222a8  50                   push eax
// 008222a9  57                   push edi
// 008222aa  ffd6                 call esi
// 008222ac  8bf0                 mov esi, eax
// 008222ae  85f6                 test esi, esi
// 008222b0  7408                 je 0x8222ba
// 008222b2  56                   push esi
// 008222b3  57                   push edi
// 008222b4  ffd5                 call ebp
// 008222b6  85c0                 test eax, eax
// 008222b8  7509                 jne 0x8222c3
// 008222ba  5b                   pop ebx
// 008222bb  5d                   pop ebp
// 008222bc  5f                   pop edi
// 008222bd  33c0                 xor eax, eax
// 008222bf  5e                   pop esi
// 008222c0  c21000               ret 0x10
// 008222c3  50                   push eax
// 008222c4  ffd3                 call ebx
// 008222c6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008222ca  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008222ce  6a00                 push 0
// 008222d0  51                   push ecx
// 008222d1  52                   push edx
// 008222d2  6800000300           push 0x30000
// 008222d7  6a01                 push 1
// 008222d9  56                   push esi
// 008222da  57                   push edi
// 008222db  8bd8                 mov ebx, eax
// 008222dd  ff1564a39e00         call dword ptr [0x9ea364]
// 008222e3  50                   push eax
// 008222e4  53                   push ebx
// 008222e5  ff15c8b99e00         call dword ptr [0x9eb9c8]
// 008222eb  5b                   pop ebx
// 008222ec  5d                   pop ebp
// 008222ed  5f                   pop edi
// 008222ee  5e                   pop esi
// 008222ef  c21000               ret 0x10
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?CreateIconFromResource@CXTPResourceManager@@UAEPAUHICON__@@PAUHINSTANCE__@@PBDVCSize@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
