// from server: 100% by EspClaude
// from server: 77% by EspClaude
// roc 2009-06 0069bba0  unit: RBX::Flag  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0069bba0
//
// 0069bba0  51                   push ecx
// 0069bba1  53                   push ebx
// 0069bba2  55                   push ebp
// 0069bba3  56                   push esi
// 0069bba4  57                   push edi
// 0069bba5  8bf9                 mov edi, ecx
// 0069bba7  8b774c               mov esi, dword ptr [edi + 0x4c]
// 0069bbaa  85f6                 test esi, esi
// 0069bbac  747d                 je 0x69bc2b
// 0069bbae  8b4610               mov eax, dword ptr [esi + 0x10]
// 0069bbb1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 0069bbb7  89442410             mov dword ptr [esp + 0x10], eax
// 0069bbbb  39460c               cmp dword ptr [esi + 0xc], eax
// 0069bbbe  7602                 jbe 0x69bbc2
// 0069bbc0  ffd3                 call ebx
// 0069bbc2  8b2e                 mov ebp, dword ptr [esi]
// 0069bbc4  8b774c               mov esi, dword ptr [edi + 0x4c]
// 0069bbc7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0069bbca  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0069bbcd  7602                 jbe 0x69bbd1
// 0069bbcf  ffd3                 call ebx
// 0069bbd1  8b36                 mov esi, dword ptr [esi]
// 0069bbd3  85f6                 test esi, esi
// 0069bbd5  7404                 je 0x69bbdb
// 0069bbd7  3bf5                 cmp esi, ebp
// 0069bbd9  7402                 je 0x69bbdd
// 0069bbdb  ffd3                 call ebx
// 0069bbdd  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 0069bbe1  7448                 je 0x69bc2b
// 0069bbe3  85f6                 test esi, esi
// 0069bbe5  753c                 jne 0x69bc23
// 0069bbe7  ffd3                 call ebx
// 0069bbe9  33c0                 xor eax, eax
// 0069bbeb  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0069bbee  7202                 jb 0x69bbf2
// 0069bbf0  ffd3                 call ebx
// 0069bbf2  8b07                 mov eax, dword ptr [edi]
// 0069bbf4  6a00                 push 0
// 0069bbf6  68b0c5a000           push 0xa0c5b0
// 0069bbfb  6840be9d00           push 0x9dbe40
// 0069bc00  6a00                 push 0
// 0069bc02  50                   push eax
// 0069bc03  e872e00700           call 0x719c7a
// 0069bc08  83c414               add esp, 0x14
// 0069bc0b  85c0                 test eax, eax
// 0069bc0d  751e                 jne 0x69bc2d
// 0069bc0f  85f6                 test esi, esi
// 0069bc11  7514                 jne 0x69bc27
// 0069bc13  ffd3                 call ebx
// 0069bc15  33c0                 xor eax, eax
// 0069bc17  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0069bc1a  7202                 jb 0x69bc1e
// 0069bc1c  ffd3                 call ebx
// 0069bc1e  83c708               add edi, 8
// 0069bc21  ebb0                 jmp 0x69bbd3
// 0069bc23  8b06                 mov eax, dword ptr [esi]
// 0069bc25  ebc4                 jmp 0x69bbeb
// 0069bc27  8b06                 mov eax, dword ptr [esi]
// 0069bc29  ebec                 jmp 0x69bc17
// 0069bc2b  33c0                 xor eax, eax
// 0069bc2d  5f                   pop edi
// 0069bc2e  5e                   pop esi
// 0069bc2f  5d                   pop ebp
// 0069bc30  5b                   pop ebx
// 0069bc31  59                   pop ecx
// 0069bc32  c3                   ret 

// from server: 100% by colin
// roc 2008-06 0062bf20  unit: RBX::P8FlagStand::?$GetSetImpl  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062bf20
//
// 0062bf20  51                   push ecx
// 0062bf21  53                   push ebx
// 0062bf22  55                   push ebp
// 0062bf23  56                   push esi
// 0062bf24  57                   push edi
// 0062bf25  8bf9                 mov edi, ecx
// 0062bf27  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0062bf2d  85f6                 test esi, esi
// 0062bf2f  0f8483000000         je 0x62bfb8
// 0062bf35  8b4610               mov eax, dword ptr [esi + 0x10]
// 0062bf38  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0062bf3e  89442410             mov dword ptr [esp + 0x10], eax
// 0062bf42  39460c               cmp dword ptr [esi + 0xc], eax
// 0062bf45  7602                 jbe 0x62bf49
// 0062bf47  ffd3                 call ebx
// 0062bf49  8b2e                 mov ebp, dword ptr [esi]
// 0062bf4b  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0062bf51  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0062bf54  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0062bf57  7602                 jbe 0x62bf5b
// 0062bf59  ffd3                 call ebx
// 0062bf5b  8b36                 mov esi, dword ptr [esi]
// 0062bf5d  8d4900               lea ecx, [ecx]
// 0062bf60  85f6                 test esi, esi
// 0062bf62  7404                 je 0x62bf68
// 0062bf64  3bf5                 cmp esi, ebp
// 0062bf66  7402                 je 0x62bf6a
// 0062bf68  ffd3                 call ebx
// 0062bf6a  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 0062bf6e  7448                 je 0x62bfb8
// 0062bf70  85f6                 test esi, esi
// 0062bf72  753c                 jne 0x62bfb0
// 0062bf74  ffd3                 call ebx
// 0062bf76  33c0                 xor eax, eax
// 0062bf78  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0062bf7b  7202                 jb 0x62bf7f
// 0062bf7d  ffd3                 call ebx
// 0062bf7f  8b07                 mov eax, dword ptr [edi]
// 0062bf81  6a00                 push 0
// 0062bf83  6840be9400           push 0x94be40
// 0062bf88  687c909200           push 0x92907c
// 0062bf8d  6a00                 push 0
// 0062bf8f  50                   push eax
// 0062bf90  e831580700           call 0x6a17c6
// 0062bf95  83c414               add esp, 0x14
// 0062bf98  85c0                 test eax, eax
// 0062bf9a  751e                 jne 0x62bfba
// 0062bf9c  85f6                 test esi, esi
// 0062bf9e  7514                 jne 0x62bfb4
// 0062bfa0  ffd3                 call ebx
// 0062bfa2  33c0                 xor eax, eax
// 0062bfa4  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0062bfa7  7202                 jb 0x62bfab
// 0062bfa9  ffd3                 call ebx
// 0062bfab  83c708               add edi, 8
// 0062bfae  ebb0                 jmp 0x62bf60
// 0062bfb0  8b06                 mov eax, dword ptr [esi]
// 0062bfb2  ebc4                 jmp 0x62bf78
// 0062bfb4  8b06                 mov eax, dword ptr [esi]
// 0062bfb6  ebec                 jmp 0x62bfa4
// 0062bfb8  33c0                 xor eax, eax
// 0062bfba  5f                   pop edi
// 0062bfbb  5e                   pop esi
// 0062bfbc  5d                   pop ebp
// 0062bfbd  5b                   pop ebx
// 0062bfbe  59                   pop ecx
// 0062bfbf  c3                   ret 


extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

extern char instance_type;
extern char properties_type;

struct Entry {
    void* object;
    void* other;
};

struct Storage;

struct Owner {
    Storage* storage;
};

struct Storage {
    Owner* owner;
    unsigned char padding[8];
    Entry* begin;
    Entry* end;
};

struct S {
    unsigned char padding[0x4c];
    Storage* storage;
    void* f();
};

void* S::f()
{
    Storage* s = storage;
    if (s) {
        Entry* last = s->end;
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        if (s->begin > last)
            invalid();

        Owner* lastOwner = s->owner;
        s = storage;
        Entry* current = s->begin;
        if (current > s->end)
            invalid();

        Owner* owner = s->owner;
        for (;;) {
            if (!owner || owner != lastOwner)
                invalid();

            if (current == last)
                break;

            if (!owner)
                invalid();
            Storage* container = owner ? owner->storage : 0;

            if (current >= container->end)
                invalid();

            void* result = __RTDynamicCast(
                current->object, 0, &instance_type, &properties_type, 0);
            if (result)
                return result;

            if (!owner)
                invalid();
            container = owner ? owner->storage : 0;

            if (current >= container->end)
                invalid();

            ++current;
        }
    }
    return 0;
}
