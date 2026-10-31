// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0049fc50  unit: RBX::Network::VClient::?$SignalDesc  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049fc50
//
// 0049fc50  6aff                 push -1
// 0049fc52  64a100000000         mov eax, dword ptr fs:[0]
// 0049fc58  6868917d00           push 0x7d9168
// 0049fc5d  50                   push eax
// 0049fc5e  64892500000000       mov dword ptr fs:[0], esp
// 0049fc65  83ec0c               sub esp, 0xc
// 0049fc68  53                   push ebx
// 0049fc69  55                   push ebp
// 0049fc6a  56                   push esi
// 0049fc6b  57                   push edi
// 0049fc6c  68ac0b9700           push 0x970bac
// 0049fc71  6800f24900           push 0x49f200
// 0049fc76  8bd9                 mov ebx, ecx
// 0049fc78  e8b3760b00           call 0x557330
// 0049fc7d  83c408               add esp, 8
// 0049fc80  e8abf3ffff           call 0x49f030
// 0049fc85  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 0049fc8b  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 0049fc91  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0049fc97  8db390010000         lea esi, [ebx + 0x190]
// 0049fc9d  8bf8                 mov edi, eax
// 0049fc9f  8d4701               lea eax, [edi + 1]
// 0049fca2  c1f903               sar ecx, 3
// 0049fca5  3bc1                 cmp eax, ecx
// 0049fca7  7620                 jbe 0x49fcc9
// 0049fca9  83ec08               sub esp, 8
// 0049fcac  8bcc                 mov ecx, esp
// 0049fcae  c70100000000         mov dword ptr [ecx], 0
// 0049fcb4  89642418             mov dword ptr [esp + 0x18], esp
// 0049fcb8  c7410400000000       mov dword ptr [ecx + 4], 0
// 0049fcbf  50                   push eax
// 0049fcc0  8bce                 mov ecx, esi
// 0049fcc2  e8f927f7ff           call 0x4124c0
// 0049fcc7  eb1d                 jmp 0x49fce6
// 0049fcc9  8b5610               mov edx, dword ptr [esi + 0x10]
// 0049fccc  2b560c               sub edx, dword ptr [esi + 0xc]
// 0049fccf  c1fa03               sar edx, 3
// 0049fcd2  3bfa                 cmp edi, edx
// 0049fcd4  7202                 jb 0x49fcd8
// 0049fcd6  ffd5                 call ebp
// 0049fcd8  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049fcdb  8b04f8               mov eax, dword ptr [eax + edi*8]
// 0049fcde  85c0                 test eax, eax
// 0049fce0  0f8597000000         jne 0x49fd7d
// 0049fce6  6888029700           push 0x970288
// 0049fceb  68f0684900           push 0x4968f0
// 0049fcf0  e83b760b00           call 0x557330
// 0049fcf5  83c408               add esp, 8
// 0049fcf8  e8d364ffff           call 0x4961d0
// 0049fcfd  50                   push eax
// 0049fcfe  8d4c2418             lea ecx, [esp + 0x18]
// 0049fd02  51                   push ecx
// 0049fd03  8bcb                 mov ecx, ebx
// 0049fd05  e8862d0d00           call 0x572a90
// 0049fd0a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049fd0e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0049fd16  85c9                 test ecx, ecx
// 0049fd18  7526                 jne 0x49fd40
// 0049fd1a  8d4c2414             lea ecx, [esp + 0x14]
// 0049fd1e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0049fd26  e835091600           call 0x600660
// 0049fd2b  33c0                 xor eax, eax
// 0049fd2d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049fd31  64890d00000000       mov dword ptr fs:[0], ecx
// 0049fd38  5f                   pop edi
// 0049fd39  5e                   pop esi
// 0049fd3a  5d                   pop ebp
// 0049fd3b  5b                   pop ebx
// 0049fd3c  83c418               add esp, 0x18
// 0049fd3f  c3                   ret 
// 0049fd40  8b5610               mov edx, dword ptr [esi + 0x10]
// 0049fd43  2b560c               sub edx, dword ptr [esi + 0xc]
// 0049fd46  8bd9                 mov ebx, ecx
// 0049fd48  c1fa03               sar edx, 3
// 0049fd4b  3bfa                 cmp edi, edx
// 0049fd4d  7206                 jb 0x49fd55
// 0049fd4f  ffd5                 call ebp
// 0049fd51  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049fd55  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049fd58  8d04f8               lea eax, [eax + edi*8]
// 0049fd5b  8908                 mov dword ptr [eax], ecx
// 0049fd5d  8d4c2418             lea ecx, [esp + 0x18]
// 0049fd61  51                   push ecx
// 0049fd62  8d4804               lea ecx, [eax + 4]
// 0049fd65  e84628f6ff           call 0x4025b0
// 0049fd6a  8d4c2414             lea ecx, [esp + 0x14]
// 0049fd6e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 0049fd76  e8e5081600           call 0x600660
// 0049fd7b  8bc3                 mov eax, ebx
// 0049fd7d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049fd81  5f                   pop edi
// 0049fd82  5e                   pop esi
// 0049fd83  5d                   pop ebp
// 0049fd84  64890d00000000       mov dword ptr fs:[0], ecx
// 0049fd8b  5b                   pop ebx
// 0049fd8c  83c418               add esp, 0x18
// 0049fd8f  c3                   ret 

extern "C" void __cdecl register_value(void (__cdecl *)(), void *);
extern void __cdecl initialize_first();
extern void __cdecl initialize_second();
extern unsigned char first_storage;
extern unsigned char second_storage;
extern void * __cdecl func_0049f030();
extern void * __cdecl func_004961d0();
extern void (__cdecl *invalid_parameter_handler)();

struct Control {
    void *value;

    Control() : value(0) {}
    Control &operator=(const Control &);
};

struct Value {
    void *object;
    Control control;

    Value() : object(0) {}
    Value(const Value &);
    ~Value();
};

struct Vector {
    unsigned char prefix[12];
    Value *first;
    Value *last;
    Value *limit;

    void resize(unsigned, Value);

    unsigned size() const {
        return static_cast<unsigned>(last - first);
    }

    Value &at(unsigned index, void (__cdecl *handler)()) {
        if (index >= size())
            handler();
        return first[index];
    }
};

struct S {
    unsigned char prefix[0x190];
    Vector values;

    Value create(void *);
    void *f();
};

void *S::f()
{
    register_value(initialize_first, &first_storage);
    unsigned index = reinterpret_cast<unsigned>(func_0049f030());
    void (__cdecl *handler)() = invalid_parameter_handler;

    if (index + 1 > values.size()) {
        values.resize(index + 1, Value());
    } else {
        void *existing = values.at(index, handler).object;
        if (existing)
            return existing;
    }

    register_value(initialize_second, &second_storage);
    Value value = create(func_004961d0());
    if (!value.object)
        return 0;

    void *result = value.object;
    Value &entry = values.at(index, handler);
    entry.object = value.object;
    entry.control = value.control;
    return result;
}
