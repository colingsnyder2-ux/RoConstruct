// from server: 100% by Espeon
// from server: 74% by king_originala
// roc 2008-06 0062c2e0  unit: RBX::FlagStandService  size: 466 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062c2e0
//
// 0062c2e0  6aff                 push -1
// 0062c2e2  6898a97d00           push 0x7da998
// 0062c2e7  64a100000000         mov eax, dword ptr fs:[0]
// 0062c2ed  50                   push eax
// 0062c2ee  64892500000000       mov dword ptr fs:[0], esp
// 0062c2f5  83ec20               sub esp, 0x20
// 0062c2f8  53                   push ebx
// 0062c2f9  8bd9                 mov ebx, ecx
// 0062c2fb  83bb4801000000       cmp dword ptr [ebx + 0x148], 0
// 0062c302  895c2404             mov dword ptr [esp + 4], ebx
// 0062c306  7514                 jne 0x62c31c
// 0062c308  33c0                 xor eax, eax
// 0062c30a  5b                   pop ebx
// 0062c30b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0062c30f  64890d00000000       mov dword ptr fs:[0], ecx
// 0062c316  83c42c               add esp, 0x2c
// 0062c319  c20400               ret 4
// 0062c31c  55                   push ebp
// 0062c31d  56                   push esi
// 0062c31e  57                   push edi
// 0062c31f  8d4c2418             lea ecx, [esp + 0x18]
// 0062c323  e8a8d0dfff           call 0x4293d0
// 0062c328  8b8344010000         mov eax, dword ptr [ebx + 0x144]
// 0062c32e  8b00                 mov eax, dword ptr [eax]
// 0062c330  8bbb30010000         mov edi, dword ptr [ebx + 0x130]
// 0062c336  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0062c33e  8be8                 mov ebp, eax
// 0062c340  8bb344010000         mov esi, dword ptr [ebx + 0x144]
// 0062c346  8b8330010000         mov eax, dword ptr [ebx + 0x130]
// 0062c34c  85ff                 test edi, edi
// 0062c34e  7404                 je 0x62c354
// 0062c350  3bf8                 cmp edi, eax
// 0062c352  740a                 je 0x62c35e
// 0062c354  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0062c35a  ffd3                 call ebx
// 0062c35c  eb06                 jmp 0x62c364
// 0062c35e  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0062c364  3bee                 cmp ebp, esi
// 0062c366  0f8491000000         je 0x62c3fd
// 0062c36c  85ff                 test edi, edi
// 0062c36e  757d                 jne 0x62c3ed
// 0062c370  ffd3                 call ebx
// 0062c372  33c0                 xor eax, eax
// 0062c374  3b6814               cmp ebp, dword ptr [eax + 0x14]
// 0062c377  7502                 jne 0x62c37b
// 0062c379  ffd3                 call ebx
// 0062c37b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0062c37e  8bb1fc030000         mov esi, dword ptr [ecx + 0x3fc]
// 0062c384  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0062c388  8d5d08               lea ebx, [ebp + 8]
// 0062c38b  8d542414             lea edx, [esp + 0x14]
// 0062c38f  52                   push edx
// 0062c390  e8ebbffeff           call 0x618380
// 0062c395  3b30                 cmp esi, dword ptr [eax]
// 0062c397  8b3590288000         mov esi, dword ptr [0x802890]
// 0062c39d  7533                 jne 0x62c3d2
// 0062c39f  85ff                 test edi, edi
// 0062c3a1  754e                 jne 0x62c3f1
// 0062c3a3  ffd6                 call esi
// 0062c3a5  33c0                 xor eax, eax
// 0062c3a7  3b6814               cmp ebp, dword ptr [eax + 0x14]
// 0062c3aa  7502                 jne 0x62c3ae
// 0062c3ac  ffd6                 call esi
// 0062c3ae  8b0b                 mov ecx, dword ptr [ebx]
// 0062c3b0  e84bf5ffff           call 0x62b900
// 0062c3b5  85c0                 test eax, eax
// 0062c3b7  7519                 jne 0x62c3d2
// 0062c3b9  85ff                 test edi, edi
// 0062c3bb  7538                 jne 0x62c3f5
// 0062c3bd  ffd6                 call esi
// 0062c3bf  33c0                 xor eax, eax
// 0062c3c1  3b6814               cmp ebp, dword ptr [eax + 0x14]
// 0062c3c4  7502                 jne 0x62c3c8
// 0062c3c6  ffd6                 call esi
// 0062c3c8  53                   push ebx
// 0062c3c9  8d4c241c             lea ecx, [esp + 0x1c]
// 0062c3cd  e8ce4fdfff           call 0x4213a0
// 0062c3d2  85ff                 test edi, edi
// 0062c3d4  7523                 jne 0x62c3f9
// 0062c3d6  ffd6                 call esi
// 0062c3d8  33c0                 xor eax, eax
// 0062c3da  3b6814               cmp ebp, dword ptr [eax + 0x14]
// 0062c3dd  7502                 jne 0x62c3e1
// 0062c3df  ffd6                 call esi
// 0062c3e1  8b6d00               mov ebp, dword ptr [ebp]
// 0062c3e4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0062c3e8  e953ffffff           jmp 0x62c340
// 0062c3ed  8b07                 mov eax, dword ptr [edi]
// 0062c3ef  eb83                 jmp 0x62c374
// 0062c3f1  8b07                 mov eax, dword ptr [edi]
// 0062c3f3  ebb2                 jmp 0x62c3a7
// 0062c3f5  8b07                 mov eax, dword ptr [edi]
// 0062c3f7  ebc8                 jmp 0x62c3c1
// 0062c3f9  8b07                 mov eax, dword ptr [edi]
// 0062c3fb  ebdd                 jmp 0x62c3da
// 0062c3fd  8b742428             mov esi, dword ptr [esp + 0x28]
// 0062c401  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062c405  2bf0                 sub esi, eax
// 0062c407  c1fe02               sar esi, 2
// 0062c40a  85f6                 test esi, esi
// 0062c40c  753f                 jne 0x62c44d
// 0062c40e  85c0                 test eax, eax
// 0062c410  7409                 je 0x62c41b
// 0062c412  50                   push eax
// 0062c413  e862420700           call 0x6a067a
// 0062c418  83c404               add esp, 4
// 0062c41b  33c0                 xor eax, eax
// 0062c41d  89442424             mov dword ptr [esp + 0x24], eax
// 0062c421  89442428             mov dword ptr [esp + 0x28], eax
// 0062c425  8944242c             mov dword ptr [esp + 0x2c], eax
// 0062c429  8b442418             mov eax, dword ptr [esp + 0x18]
// 0062c42d  50                   push eax
// 0062c42e  e847420700           call 0x6a067a
// 0062c433  83c404               add esp, 4
// 0062c436  5f                   pop edi
// 0062c437  5e                   pop esi
// 0062c438  5d                   pop ebp
// 0062c439  33c0                 xor eax, eax
// 0062c43b  5b                   pop ebx
// 0062c43c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0062c440  64890d00000000       mov dword ptr fs:[0], ecx
// 0062c447  83c42c               add esp, 0x2c
// 0062c44a  c20400               ret 4
// 0062c44d  ff15b0278000         call dword ptr [0x8027b0]
// 0062c453  33d2                 xor edx, edx
// 0062c455  f7f6                 div esi
// 0062c457  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0062c45b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062c45f  2bc8                 sub ecx, eax
// 0062c461  c1f902               sar ecx, 2
// 0062c464  8bf2                 mov esi, edx
// 0062c466  3bf1                 cmp esi, ecx
// 0062c468  7206                 jb 0x62c470
// 0062c46a  ffd3                 call ebx
// 0062c46c  8b442424             mov eax, dword ptr [esp + 0x24]
// 0062c470  8b34b0               mov esi, dword ptr [eax + esi*4]
// 0062c473  33ff                 xor edi, edi
// 0062c475  3bc7                 cmp eax, edi
// 0062c477  7409                 je 0x62c482
// 0062c479  50                   push eax
// 0062c47a  e8fb410700           call 0x6a067a
// 0062c47f  83c404               add esp, 4
// 0062c482  8b542418             mov edx, dword ptr [esp + 0x18]
// 0062c486  52                   push edx
// 0062c487  897c2428             mov dword ptr [esp + 0x28], edi
// 0062c48b  897c242c             mov dword ptr [esp + 0x2c], edi
// 0062c48f  897c2430             mov dword ptr [esp + 0x30], edi
// 0062c493  e8e2410700           call 0x6a067a
// 0062c498  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0062c49c  83c404               add esp, 4
// 0062c49f  5f                   pop edi
// 0062c4a0  8bc6                 mov eax, esi
// 0062c4a2  5e                   pop esi
// 0062c4a3  5d                   pop ebp
// 0062c4a4  5b                   pop ebx
// 0062c4a5  64890d00000000       mov dword ptr fs:[0], ecx
// 0062c4ac  83c42c               add esp, 0x2c
// 0062c4af  c20400               ret 4

extern "C" {
    extern __declspec(dllimport) void __cdecl invalid_parameter();
    extern int (__cdecl* random_number)();
    void __cdecl release(void*);
}

struct Color {
    unsigned int value;
};

struct Flag {
    Color getTeamColor() const;
};

struct Stand {
    char padding[0x3fc];
    unsigned int color;
    void* get();
};

struct Link {
    Link* next;
    Link* previous;
    Stand* value;
};

struct Owner {
    char padding[0x14];
    Link* head;
};

struct Proxy {
    Owner* owner;
};

struct Candidates {
    void* proxy;
    unsigned int reserved[2];
    Stand** first;
    Stand** last;
    Stand** limit;

    Candidates();
    ~Candidates();
    void append(Stand* const*);
};

inline Candidates::~Candidates()
{
    if (first)
        release(first);
    first = 0;
    last = 0;
    limit = 0;
    release(proxy);
}

struct Iterator { Proxy* owner; Link* node; };

struct Service {
    char padding[0x130];
    Proxy* volatile proxy;
    char reserved[0x10];
    Link* head;
    unsigned int count;

    Stand* choose(Flag*);
    Iterator begin() { Iterator i; i.node = head->next; i.owner = proxy; return i; }
};

Stand* Service::choose(Flag* flag)
{
    if (count == 0)
        return 0;

    Candidates candidates;
    Iterator iterator = begin();
    Link* current = iterator.node;
    Proxy* owner = iterator.owner;

    for (;;) {
        Link* end = head;
        Proxy* endOwner = proxy;

        if (!owner || owner != endOwner)
            invalid_parameter();

        if (current == end)
            break;

        Owner* container;
        if (!owner) invalid_parameter();
    container = owner ? owner->owner : 0;

        if (current == container->head)
            invalid_parameter();

        unsigned int color = current->value->color;
        Stand** value = &current->value;

        if (color == flag->getTeamColor().value) {
            if (!owner) invalid_parameter();
    container = owner ? owner->owner : 0;

            if (current == container->head)
                invalid_parameter();

            if (!(*value)->get()) {
                if (!owner) invalid_parameter();
    container = owner ? owner->owner : 0;

                if (current == container->head)
                    invalid_parameter();

                candidates.append(value);
            }
        }

        if (!owner) invalid_parameter();
    container = owner ? owner->owner : 0;

        if (current == container->head)
            invalid_parameter();

        current = current->next;
    }

    unsigned int size =
        static_cast<unsigned int>(candidates.last - candidates.first);
    if (size == 0)
        return 0;

    unsigned int index = static_cast<unsigned int>(random_number()) % size;
    if (index >= static_cast<unsigned int>(candidates.last - candidates.first))
        invalid_parameter();

    return candidates.first[index];
}
