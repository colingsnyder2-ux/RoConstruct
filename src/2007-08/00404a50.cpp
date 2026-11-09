// from server: 88% by EspClaude
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

        converted = convertWide(storage, text, size, 3);
    }

    if (!converted)
        return (int)0x8007000e;

    return object->processor.process(converted, output)
        ? 0 : (int)0x8007000e;
}
