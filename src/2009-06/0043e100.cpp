// from server: 77% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00443820  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00443820
//
// 00443820  51                   push ecx
// 00443821  53                   push ebx
// 00443822  55                   push ebp
// 00443823  56                   push esi
// 00443824  57                   push edi
// 00443825  8bf9                 mov edi, ecx
// 00443827  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0044382d  85f6                 test esi, esi
// 0044382f  0f8483000000         je 0x4438b8
// 00443835  8b4610               mov eax, dword ptr [esi + 0x10]
// 00443838  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0044383e  89442410             mov dword ptr [esp + 0x10], eax
// 00443842  39460c               cmp dword ptr [esi + 0xc], eax
// 00443845  7602                 jbe 0x443849
// 00443847  ffd3                 call ebx
// 00443849  8b2e                 mov ebp, dword ptr [esi]
// 0044384b  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 00443851  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00443854  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00443857  7602                 jbe 0x44385b
// 00443859  ffd3                 call ebx
// 0044385b  8b36                 mov esi, dword ptr [esi]
// 0044385d  8d4900               lea ecx, [ecx]
// 00443860  85f6                 test esi, esi
// 00443862  7404                 je 0x443868
// 00443864  3bf5                 cmp esi, ebp
// 00443866  7402                 je 0x44386a
// 00443868  ffd3                 call ebx
// 0044386a  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 0044386e  7448                 je 0x4438b8
// 00443870  85f6                 test esi, esi
// 00443872  753c                 jne 0x4438b0
// 00443874  ffd3                 call ebx
// 00443876  33c0                 xor eax, eax
// 00443878  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0044387b  7202                 jb 0x44387f
// 0044387d  ffd3                 call ebx
// 0044387f  8b07                 mov eax, dword ptr [edi]
// 00443881  6a00                 push 0
// 00443883  68b4a99200           push 0x92a9b4
// 00443888  687c909200           push 0x92907c
// 0044388d  6a00                 push 0
// 0044388f  50                   push eax
// 00443890  e831df2500           call 0x6a17c6
// 00443895  83c414               add esp, 0x14
// 00443898  85c0                 test eax, eax
// 0044389a  751e                 jne 0x4438ba
// 0044389c  85f6                 test esi, esi
// 0044389e  7514                 jne 0x4438b4
// 004438a0  ffd3                 call ebx
// 004438a2  33c0                 xor eax, eax
// 004438a4  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004438a7  7202                 jb 0x4438ab
// 004438a9  ffd3                 call ebx
// 004438ab  83c708               add edi, 8
// 004438ae  ebb0                 jmp 0x443860
// 004438b0  8b06                 mov eax, dword ptr [esi]
// 004438b2  ebc4                 jmp 0x443878
// 004438b4  8b06                 mov eax, dword ptr [esi]
// 004438b6  ebec                 jmp 0x4438a4
// 004438b8  33c0                 xor eax, eax
// 004438ba  5f                   pop edi
// 004438bb  5e                   pop esi
// 004438bc  5d                   pop ebp
// 004438bd  5b                   pop ebx
// 004438be  59                   pop ecx
// 004438bf  c3                   ret 

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
