// from server: 100% by EspClaude
// from server: 88% by EspClaude
// roc 2007-08 00404a50  unit: ATL::CRegObject  size: 274 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00404a50
//
// 00404a50  55                   push ebp
// 00404a51  8bec                 mov ebp, esp
// 00404a53  6aff                 push -1
// 00404a55  68e8927300           push 0x7392e8
// 00404a5a  64a100000000         mov eax, dword ptr fs:[0]
// 00404a60  50                   push eax
// 00404a61  83ec08               sub esp, 8
// 00404a64  a188518b00           mov eax, dword ptr [0x8b5188]
// 00404a69  33c5                 xor eax, ebp
// 00404a6b  8945f0               mov dword ptr [ebp - 0x10], eax
// 00404a6e  53                   push ebx
// 00404a6f  56                   push esi
// 00404a70  57                   push edi
// 00404a71  50                   push eax
// 00404a72  8d45f4               lea eax, [ebp - 0xc]
// 00404a75  64a300000000         mov dword ptr fs:[0], eax
// 00404a7b  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00404a7e  33f6                 xor esi, esi
// 00404a80  3bfe                 cmp edi, esi
// 00404a82  0f84b4000000         je 0x404b3c
// 00404a88  397510               cmp dword ptr [ebp + 0x10], esi
// 00404a8b  0f84ab000000         je 0x404b3c
// 00404a91  ff1564ab8b00         call dword ptr [0x8bab64]
// 00404a97  8bd8                 mov ebx, eax
// 00404a99  8975ec               mov dword ptr [ebp - 0x14], esi
// 00404a9c  57                   push edi
// 00404a9d  8975fc               mov dword ptr [ebp - 4], esi
// 00404aa0  ff1510d37700         call dword ptr [0x77d310]
// 00404aa6  56                   push esi
// 00404aa7  83c001               add eax, 1
// 00404aaa  99                   cdq 
// 00404aab  6a02                 push 2
// 00404aad  52                   push edx
// 00404aae  50                   push eax
// 00404aaf  e89cc12200           call 0x630c50
// 00404ab4  8bf0                 mov esi, eax
// 00404ab6  0500000080           add eax, 0x80000000
// 00404abb  83d200               adc edx, 0
// 00404abe  85d2                 test edx, edx
// 00404ac0  773d                 ja 0x404aff
// 00404ac2  7205                 jb 0x404ac9
// 00404ac4  83f8ff               cmp eax, -1
// 00404ac7  7736                 ja 0x404aff
// 00404ac9  81fe00040000         cmp esi, 0x400
// 00404acf  7f18                 jg 0x404ae9
// 00404ad1  56                   push esi
// 00404ad2  e8e9dfffff           call 0x402ac0
// 00404ad7  83c404               add esp, 4
// 00404ada  84c0                 test al, al
// 00404adc  740b                 je 0x404ae9
// 00404ade  8bc6                 mov eax, esi
// 00404ae0  e8cbc02200           call 0x630bb0
// 00404ae5  8bc4                 mov eax, esp
// 00404ae7  eb09                 jmp 0x404af2
// 00404ae9  56                   push esi
// 00404aea  8d4dec               lea ecx, [ebp - 0x14]
// 00404aed  e8eeeaffff           call 0x4035e0
// 00404af2  53                   push ebx
// 00404af3  56                   push esi
// 00404af4  57                   push edi
// 00404af5  50                   push eax
// 00404af6  e805cdffff           call 0x401800
// 00404afb  85c0                 test eax, eax
// 00404afd  750f                 jne 0x404b0e
// 00404aff  8d4dec               lea ecx, [ebp - 0x14]
// 00404b02  e849c6ffff           call 0x401150
// 00404b07  b80e000780           mov eax, 0x8007000e
// 00404b0c  eb33                 jmp 0x404b41
// 00404b0e  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00404b11  51                   push ecx
// 00404b12  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00404b15  50                   push eax
// 00404b16  83c104               add ecx, 4
// 00404b19  e8b2fdffff           call 0x4048d0
// 00404b1e  8bf0                 mov esi, eax
// 00404b20  f7de                 neg esi
// 00404b22  1bf6                 sbb esi, esi
// 00404b24  81e6f2fff87f         and esi, 0x7ff8fff2
// 00404b2a  8d4dec               lea ecx, [ebp - 0x14]
// 00404b2d  81c60e000780         add esi, 0x8007000e
// 00404b33  e818c6ffff           call 0x401150
// 00404b38  8bc6                 mov eax, esi
// 00404b3a  eb05                 jmp 0x404b41
// 00404b3c  b857000780           mov eax, 0x80070057
// 00404b41  8d65dc               lea esp, [ebp - 0x24]
// 00404b44  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00404b47  64890d00000000       mov dword ptr fs:[0], ecx
// 00404b4e  59                   pop ecx
// 00404b4f  5f                   pop edi
// 00404b50  5e                   pop esi
// 00404b51  5b                   pop ebx
// 00404b52  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 00404b55  33cd                 xor ecx, ebp
// 00404b57  e8c2be2200           call 0x630a1e
// 00404b5c  8be5                 mov esp, ebp
// 00404b5e  5d                   pop ebp
// 00404b5f  c20c00               ret 0xc

// from server: 100% by king_originala
// roc 2008-06 00403f40  unit: ATL::CRegObject  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403f40
//
// 00403f40  55                   push ebp
// 00403f41  8bec                 mov ebp, esp
// 00403f43  64a100000000         mov eax, dword ptr fs:[0]
// 00403f49  6aff                 push -1
// 00403f4b  6898f27b00           push 0x7bf298
// 00403f50  50                   push eax
// 00403f51  64892500000000       mov dword ptr fs:[0], esp
// 00403f58  56                   push esi
// 00403f59  57                   push edi
// 00403f5a  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 00403f5d  85ff                 test edi, edi
// 00403f5f  0f84b5000000         je 0x40401a
// 00403f65  837d1000             cmp dword ptr [ebp + 0x10], 0
// 00403f69  0f84ab000000         je 0x40401a
// 00403f6f  c7450c00000000       mov dword ptr [ebp + 0xc], 0
// 00403f76  57                   push edi
// 00403f77  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00403f7e  ff15e8228000         call dword ptr [0x8022e8]
// 00403f84  6a00                 push 0
// 00403f86  40                   inc eax
// 00403f87  99                   cdq 
// 00403f88  6a02                 push 2
// 00403f8a  52                   push edx
// 00403f8b  50                   push eax
// 00403f8c  e83fd72900           call 0x6a16d0
// 00403f91  8bf0                 mov esi, eax
// 00403f93  0500000080           add eax, 0x80000000
// 00403f98  83d200               adc edx, 0
// 00403f9b  85d2                 test edx, edx
// 00403f9d  773e                 ja 0x403fdd
// 00403f9f  7205                 jb 0x403fa6
// 00403fa1  83f8ff               cmp eax, -1
// 00403fa4  7737                 ja 0x403fdd
// 00403fa6  81fe00040000         cmp esi, 0x400
// 00403fac  7f18                 jg 0x403fc6
// 00403fae  56                   push esi
// 00403faf  e85ce6ffff           call 0x402610
// 00403fb4  83c404               add esp, 4
// 00403fb7  84c0                 test al, al
// 00403fb9  740b                 je 0x403fc6
// 00403fbb  8bc6                 mov eax, esi
// 00403fbd  e89ed52900           call 0x6a1560
// 00403fc2  8bc4                 mov eax, esp
// 00403fc4  eb09                 jmp 0x403fcf
// 00403fc6  56                   push esi
// 00403fc7  8d4d0c               lea ecx, [ebp + 0xc]
// 00403fca  e881efffff           call 0x402f50
// 00403fcf  6a03                 push 3
// 00403fd1  56                   push esi
// 00403fd2  57                   push edi
// 00403fd3  50                   push eax
// 00403fd4  e8c7d7ffff           call 0x4017a0
// 00403fd9  85c0                 test eax, eax
// 00403fdb  750f                 jne 0x403fec
// 00403fdd  8d4d0c               lea ecx, [ebp + 0xc]
// 00403fe0  e86bd1ffff           call 0x401150
// 00403fe5  b80e000780           mov eax, 0x8007000e
// 00403fea  eb33                 jmp 0x40401f
// 00403fec  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00403fef  51                   push ecx
// 00403ff0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00403ff3  50                   push eax
// 00403ff4  83c104               add ecx, 4
// 00403ff7  e8d4fdffff           call 0x403dd0
// 00403ffc  8bf0                 mov esi, eax
// 00403ffe  f7de                 neg esi
// 00404000  1bf6                 sbb esi, esi
// 00404002  81e6f2fff87f         and esi, 0x7ff8fff2
// 00404008  8d4d0c               lea ecx, [ebp + 0xc]
// 0040400b  81c60e000780         add esi, 0x8007000e
// 00404011  e83ad1ffff           call 0x401150
// 00404016  8bc6                 mov eax, esi
// 00404018  eb05                 jmp 0x40401f
// 0040401a  b857000780           mov eax, 0x80070057
// 0040401f  8d65ec               lea esp, [ebp - 0x14]
// 00404022  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00404025  64890d00000000       mov dword ptr fs:[0], ecx
// 0040402c  5f                   pop edi
// 0040402d  5e                   pop esi
// 0040402e  8be5                 mov esp, ebp
// 00404030  5d                   pop ebp
// 00404031  c20c00               ret 0xc

extern "C" int (__stdcall * const lstrlenW)(const wchar_t *);
extern "C" void * __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

extern unsigned int (__stdcall *g_pfnGetThreadACP)();
extern bool __cdecl stackAvailable(int);
extern char * __stdcall convertWide(char *, const wchar_t *, int, unsigned int);

struct Buffer
{
    void *head;
    ~Buffer() throw();
    char *allocate(int);
};

struct Processor
{
    int process(char *, void *);
};

struct Object
{
    unsigned int reserved;
    Processor processor;
};

int __stdcall convertAndProcess(Object *object, const wchar_t *text, void *output)
{
    if (!text || !output)
        return (int)0x80070057;

    unsigned int acp = g_pfnGetThreadACP();
    Buffer buffer = { 0 };
    __int64 bytes = (__int64)(lstrlenW(text) + 1) * 2;
    char *converted = 0;

    if (bytes <= 2147483647i64 && bytes >= -2147483648i64)
    {
        int size = (int)bytes;
        char *storage;
        if (size <= 1024 && stackAvailable(size))
            storage = (char *)_alloca(size);
        else
            storage = buffer.allocate(size);

        converted = convertWide(storage, text, size, acp);
    }

    if (!converted)
        return (int)0x8007000e;

    return object->processor.process(converted, output)
        ? 0 : (int)0x8007000e;
}
