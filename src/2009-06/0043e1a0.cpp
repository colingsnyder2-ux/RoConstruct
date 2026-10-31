// from server: 77% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004438c0  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004438c0
//
// 004438c0  51                   push ecx
// 004438c1  53                   push ebx
// 004438c2  55                   push ebp
// 004438c3  56                   push esi
// 004438c4  57                   push edi
// 004438c5  8bf9                 mov edi, ecx
// 004438c7  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 004438cd  85f6                 test esi, esi
// 004438cf  0f8483000000         je 0x443958
// 004438d5  8b4610               mov eax, dword ptr [esi + 0x10]
// 004438d8  8b1d90288000         mov ebx, dword ptr [0x802890]
// 004438de  89442410             mov dword ptr [esp + 0x10], eax
// 004438e2  39460c               cmp dword ptr [esi + 0xc], eax
// 004438e5  7602                 jbe 0x4438e9
// 004438e7  ffd3                 call ebx
// 004438e9  8b2e                 mov ebp, dword ptr [esi]
// 004438eb  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 004438f1  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004438f4  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004438f7  7602                 jbe 0x4438fb
// 004438f9  ffd3                 call ebx
// 004438fb  8b36                 mov esi, dword ptr [esi]
// 004438fd  8d4900               lea ecx, [ecx]
// 00443900  85f6                 test esi, esi
// 00443902  7404                 je 0x443908
// 00443904  3bf5                 cmp esi, ebp
// 00443906  7402                 je 0x44390a
// 00443908  ffd3                 call ebx
// 0044390a  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 0044390e  7448                 je 0x443958
// 00443910  85f6                 test esi, esi
// 00443912  753c                 jne 0x443950
// 00443914  ffd3                 call ebx
// 00443916  33c0                 xor eax, eax
// 00443918  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0044391b  7202                 jb 0x44391f
// 0044391d  ffd3                 call ebx
// 0044391f  8b07                 mov eax, dword ptr [edi]
// 00443921  6a00                 push 0
// 00443923  68e4a99200           push 0x92a9e4
// 00443928  687c909200           push 0x92907c
// 0044392d  6a00                 push 0
// 0044392f  50                   push eax
// 00443930  e891de2500           call 0x6a17c6
// 00443935  83c414               add esp, 0x14
// 00443938  85c0                 test eax, eax
// 0044393a  751e                 jne 0x44395a
// 0044393c  85f6                 test esi, esi
// 0044393e  7514                 jne 0x443954
// 00443940  ffd3                 call ebx
// 00443942  33c0                 xor eax, eax
// 00443944  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00443947  7202                 jb 0x44394b
// 00443949  ffd3                 call ebx
// 0044394b  83c708               add edi, 8
// 0044394e  ebb0                 jmp 0x443900
// 00443950  8b06                 mov eax, dword ptr [esi]
// 00443952  ebc4                 jmp 0x443918
// 00443954  8b06                 mov eax, dword ptr [esi]
// 00443956  ebec                 jmp 0x443944
// 00443958  33c0                 xor eax, eax
// 0044395a  5f                   pop edi
// 0044395b  5e                   pop esi
// 0044395c  5d                   pop ebp
// 0044395d  5b                   pop ebx
// 0044395e  59                   pop ecx
// 0044395f  c3                   ret 

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
    unsigned char padding[0x108];
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
