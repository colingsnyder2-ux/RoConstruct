// from server: 58% by EspClaude
// from server: 54% by pitbull
// roc 2007-08 0042f960  unit: RBX::VFillToolColor::?$Listener  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042f960
//
// 0042f960  6aff                 push -1
// 0042f962  6849d87300           push 0x73d849
// 0042f967  64a100000000         mov eax, dword ptr fs:[0]
// 0042f96d  50                   push eax
// 0042f96e  51                   push ecx
// 0042f96f  53                   push ebx
// 0042f970  55                   push ebp
// 0042f971  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042f976  33c4                 xor eax, esp
// 0042f978  50                   push eax
// 0042f979  8d442410             lea eax, [esp + 0x10]
// 0042f97d  64a300000000         mov dword ptr fs:[0], eax
// 0042f983  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0042f987  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0042f98b  8d4c240c             lea ecx, [esp + 0xc]
// 0042f98f  ff15acdd7700         call dword ptr [0x77ddac]
// 0042f995  56                   push esi
// 0042f996  57                   push edi
// 0042f997  8d442414             lea eax, [esp + 0x14]
// 0042f99b  685cab7800           push 0x78ab5c
// 0042f9a0  50                   push eax
// 0042f9a1  c744242800000000     mov dword ptr [esp + 0x28], 0
// 0042f9a9  ff1594dd7700         call dword ptr [0x77dd94]
// 0042f9af  83c410               add esp, 0x10
// 0042f9b2  6a00                 push 0
// 0042f9b4  8d4c2410             lea ecx, [esp + 0x10]
// 0042f9b8  ff1578d67700         call dword ptr [0x77d678]
// 0042f9be  8bc8                 mov ecx, eax
// 0042f9c0  ff1598dd7700         call dword ptr [0x77dd98]
// 0042f9c6  53                   push ebx
// 0042f9c7  55                   push ebp
// 0042f9c8  8bc8                 mov ecx, eax
// 0042f9ca  e8a1fdffff           call 0x42f770
// 0042f9cf  83c40c               add esp, 0xc
// 0042f9d2  84c0                 test al, al
// 0042f9d4  7467                 je 0x42fa3d
// 0042f9d6  56                   push esi
// 0042f9d7  57                   push edi
// 0042f9d8  8d4c2414             lea ecx, [esp + 0x14]
// 0042f9dc  6850ab7800           push 0x78ab50
// 0042f9e1  51                   push ecx
// 0042f9e2  ff1594dd7700         call dword ptr [0x77dd94]
// 0042f9e8  83c410               add esp, 0x10
// 0042f9eb  6a01                 push 1
// 0042f9ed  8d4c2410             lea ecx, [esp + 0x10]
// 0042f9f1  ff1578d67700         call dword ptr [0x77d678]
// 0042f9f7  8bc8                 mov ecx, eax
// 0042f9f9  ff1598dd7700         call dword ptr [0x77dd98]
// 0042f9ff  53                   push ebx
// 0042fa00  55                   push ebp
// 0042fa01  8bc8                 mov ecx, eax
// 0042fa03  e868fdffff           call 0x42f770
// 0042fa08  56                   push esi
// 0042fa09  57                   push edi
// 0042fa0a  8d542420             lea edx, [esp + 0x20]
// 0042fa0e  6844ab7800           push 0x78ab44
// 0042fa13  52                   push edx
// 0042fa14  ff1594dd7700         call dword ptr [0x77dd94]
// 0042fa1a  83c41c               add esp, 0x1c
// 0042fa1d  6a02                 push 2
// 0042fa1f  8d4c2410             lea ecx, [esp + 0x10]
// 0042fa23  ff1578d67700         call dword ptr [0x77d678]
// 0042fa29  8bc8                 mov ecx, eax
// 0042fa2b  ff1598dd7700         call dword ptr [0x77dd98]
// 0042fa31  53                   push ebx
// 0042fa32  55                   push ebp
// 0042fa33  8bc8                 mov ecx, eax
// 0042fa35  e836fdffff           call 0x42f770
// 0042fa3a  83c40c               add esp, 0xc
// 0042fa3d  8d4c240c             lea ecx, [esp + 0xc]
// 0042fa41  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0042fa47  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042fa4b  64890d00000000       mov dword ptr fs:[0], ecx
// 0042fa52  59                   pop ecx
// 0042fa53  5d                   pop ebp
// 0042fa54  5b                   pop ebx
// 0042fa55  83c410               add esp, 0x10
// 0042fa58  c3                   ret 

struct CStr {
    char* m_pszData;
    __declspec(dllimport) CStr();
    __declspec(dllimport) ~CStr();
    __declspec(dllimport) void __cdecl Format(const char* fmt, ...);
    __declspec(dllimport) CStr& MakeLower();
    __declspec(dllimport) operator const char*() const;
};

extern const char fmt0[];
extern const char fmt1[];
extern const char fmt2[];

bool loadNamed(const char* name, int a, int b, int index);

void __cdecl loadAll(int a, int b, const char* x, int y)
{
    CStr s;
    s.Format(fmt0, x, y);
    if (loadNamed(s.MakeLower(), a, b, 0)) {
        s.Format(fmt1, x, y);
        loadNamed(s.MakeLower(), a, b, 1);
        s.Format(fmt2, x, y);
        loadNamed(s.MakeLower(), a, b, 2);
    }
}
