// from server: 100% by auto
// roc 2009-12 007d1800  unit: seg_007d0000  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1800
//
// 007d1800  53                   push ebx
// 007d1801  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007d1805  56                   push esi
// 007d1806  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007d180a  8bc6                 mov eax, esi
// 007d180c  99                   cdq 
// 007d180d  57                   push edi
// 007d180e  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007d1812  8b0f                 mov ecx, dword ptr [edi]
// 007d1814  2bc2                 sub eax, edx
// 007d1816  d1f8                 sar eax, 1
// 007d1818  3bc8                 cmp ecx, eax
// 007d181a  7c14                 jl 0x7d1830
// 007d181c  3bce                 cmp ecx, esi
// 007d181e  7c1d                 jl 0x7d183d
// 007d1820  8b442424             mov eax, dword ptr [esp + 0x24]
// 007d1824  50                   push eax
// 007d1825  53                   push ebx
// 007d1826  e8159bfcff           call 0x79b340
// 007d182b  83c408               add esp, 8
// 007d182e  eb0d                 jmp 0x7d183d
// 007d1830  8d3409               lea esi, [ecx + ecx]
// 007d1833  83fe04               cmp esi, 4
// 007d1836  7d05                 jge 0x7d183d
// 007d1838  be04000000           mov esi, 4
// 007d183d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d1841  33d2                 xor edx, edx
// 007d1843  b8fdffffff           mov eax, 0xfffffffd
// 007d1848  f7f1                 div ecx
// 007d184a  55                   push ebp
// 007d184b  8d6e01               lea ebp, [esi + 1]
// 007d184e  3be8                 cmp ebp, eax
// 007d1850  5d                   pop ebp
// 007d1851  7720                 ja 0x7d1873
// 007d1853  8b07                 mov eax, dword ptr [edi]
// 007d1855  8bd6                 mov edx, esi
// 007d1857  0fafc1               imul eax, ecx
// 007d185a  0fafd1               imul edx, ecx
// 007d185d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007d1861  52                   push edx
// 007d1862  50                   push eax
// 007d1863  51                   push ecx
// 007d1864  53                   push ebx
// 007d1865  e846ffffff           call 0x7d17b0
// 007d186a  83c410               add esp, 0x10
// 007d186d  8937                 mov dword ptr [edi], esi
// 007d186f  5f                   pop edi
// 007d1870  5e                   pop esi
// 007d1871  5b                   pop ebx
// 007d1872  c3                   ret 
// 007d1873  6888ed9e00           push 0x9eed88
// 007d1878  53                   push ebx
// 007d1879  e8c29afcff           call 0x79b340
// 007d187e  83c408               add esp, 8
// 007d1881  8937                 mov dword ptr [edi], esi
// 007d1883  5f                   pop edi
// 007d1884  5e                   pop esi
// 007d1885  33c0                 xor eax, eax
// 007d1887  5b                   pop ebx
// 007d1888  c3                   ret 
// library lua-5.1/lmem.c (function _luaM_growaux_)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lmem.c
