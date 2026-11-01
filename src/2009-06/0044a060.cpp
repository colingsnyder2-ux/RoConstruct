// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00452a00  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00452a00
//
// 00452a00  6aff                 push -1
// 00452a02  64a100000000         mov eax, dword ptr fs:[0]
// 00452a08  6868917d00           push 0x7d9168
// 00452a0d  50                   push eax
// 00452a0e  64892500000000       mov dword ptr fs:[0], esp
// 00452a15  83ec0c               sub esp, 0xc
// 00452a18  53                   push ebx
// 00452a19  55                   push ebp
// 00452a1a  56                   push esi
// 00452a1b  57                   push edi
// 00452a1c  686cdd9600           push 0x96dd6c
// 00452a21  6850084500           push 0x450850
// 00452a26  8bd9                 mov ebx, ecx
// 00452a28  e803491000           call 0x557330
// 00452a2d  83c408               add esp, 8
// 00452a30  e82bc9ffff           call 0x44f360
// 00452a35  8b8ba0010000         mov ecx, dword ptr [ebx + 0x1a0]
// 00452a3b  2b8b9c010000         sub ecx, dword ptr [ebx + 0x19c]
// 00452a41  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00452a47  8db390010000         lea esi, [ebx + 0x190]
// 00452a4d  8bf8                 mov edi, eax
// 00452a4f  8d4701               lea eax, [edi + 1]
// 00452a52  c1f903               sar ecx, 3
// 00452a55  3bc1                 cmp eax, ecx
// 00452a57  7620                 jbe 0x452a79
// 00452a59  83ec08               sub esp, 8
// 00452a5c  8bcc                 mov ecx, esp
// 00452a5e  c70100000000         mov dword ptr [ecx], 0
// 00452a64  89642418             mov dword ptr [esp + 0x18], esp
// 00452a68  c7410400000000       mov dword ptr [ecx + 4], 0
// 00452a6f  50                   push eax
// 00452a70  8bce                 mov ecx, esi
// 00452a72  e849fafbff           call 0x4124c0
// 00452a77  eb1d                 jmp 0x452a96
// 00452a79  8b5610               mov edx, dword ptr [esi + 0x10]
// 00452a7c  2b560c               sub edx, dword ptr [esi + 0xc]
// 00452a7f  c1fa03               sar edx, 3
// 00452a82  3bfa                 cmp edi, edx
// 00452a84  7202                 jb 0x452a88
// 00452a86  ffd5                 call ebp
// 00452a88  8b460c               mov eax, dword ptr [esi + 0xc]
// 00452a8b  8b04f8               mov eax, dword ptr [eax + edi*8]
// 00452a8e  85c0                 test eax, eax
// 00452a90  0f8597000000         jne 0x452b2d
// 00452a96  682ccc9600           push 0x96cc2c
// 00452a9b  68503a4100           push 0x413a50
// 00452aa0  e88b481000           call 0x557330
// 00452aa5  83c408               add esp, 8
// 00452aa8  e8f30cfcff           call 0x4137a0
// 00452aad  50                   push eax
// 00452aae  8d4c2418             lea ecx, [esp + 0x18]
// 00452ab2  51                   push ecx
// 00452ab3  8bcb                 mov ecx, ebx
// 00452ab5  e8d6ff1100           call 0x572a90
// 00452aba  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452abe  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00452ac6  85c9                 test ecx, ecx
// 00452ac8  7526                 jne 0x452af0
// 00452aca  8d4c2414             lea ecx, [esp + 0x14]
// 00452ace  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00452ad6  e885db1a00           call 0x600660
// 00452adb  33c0                 xor eax, eax
// 00452add  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00452ae1  64890d00000000       mov dword ptr fs:[0], ecx
// 00452ae8  5f                   pop edi
// 00452ae9  5e                   pop esi
// 00452aea  5d                   pop ebp
// 00452aeb  5b                   pop ebx
// 00452aec  83c418               add esp, 0x18
// 00452aef  c3                   ret 
// 00452af0  8b5610               mov edx, dword ptr [esi + 0x10]
// 00452af3  2b560c               sub edx, dword ptr [esi + 0xc]
// 00452af6  8bd9                 mov ebx, ecx
// 00452af8  c1fa03               sar edx, 3
// 00452afb  3bfa                 cmp edi, edx
// 00452afd  7206                 jb 0x452b05
// 00452aff  ffd5                 call ebp
// 00452b01  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00452b05  8b460c               mov eax, dword ptr [esi + 0xc]
// 00452b08  8d04f8               lea eax, [eax + edi*8]
// 00452b0b  8908                 mov dword ptr [eax], ecx
// 00452b0d  8d4c2418             lea ecx, [esp + 0x18]
// 00452b11  51                   push ecx
// 00452b12  8d4804               lea ecx, [eax + 4]
// 00452b15  e896fafaff           call 0x4025b0
// 00452b1a  8d4c2414             lea ecx, [esp + 0x14]
// 00452b1e  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00452b26  e835db1a00           call 0x600660
// 00452b2b  8bc3                 mov eax, ebx
// 00452b2d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00452b31  5f                   pop edi
// 00452b32  5e                   pop esi
// 00452b33  5d                   pop ebp
// 00452b34  64890d00000000       mov dword ptr fs:[0], ecx
// 00452b3b  5b                   pop ebx
// 00452b3c  83c418               add esp, 0x18
// 00452b3f  c3                   ret 

extern void (__cdecl *invalidParameter)();

extern void __cdecl registerValue(void (__cdecl*)(), void*);
extern void __cdecl initializeIndex();
extern void __cdecl initializeType();
extern unsigned char indexStorage;
extern unsigned char typeStorage;
extern unsigned int __cdecl func_0044f360();
extern void* __cdecl func_004137a0();

struct Control
{
    void* value;
    Control();
    Control& operator=(const Control&);
};

inline Control::Control() : value(0)
{
}

struct Result
{
    void* object;
    Control control;
    ~Result();
};

struct Entry
{
    void* object;
    Control control;

    Entry();
    Entry(const Entry&);
};

inline Entry::Entry() : object(0), control()
{
}

struct Entries
{
    unsigned char padding[12];
    Entry* first;
    Entry* last;
    Entry* limit;

    void resize(unsigned int, Entry);
    unsigned int size() const;
    Entry& at(unsigned int, void (__cdecl*)());
};

inline unsigned int Entries::size() const
{
    return static_cast<unsigned int>(last - first);
}

inline Entry& Entries::at(unsigned int index, void (__cdecl *handler)())
{
    if (index >= size())
        handler();
    return first[index];
}

struct S
{
    unsigned char padding[0x190];
    Entries entries;

    Result create(void*);
    void* get();
};

void* S::get()
{
    registerValue(initializeIndex, &indexStorage);
    unsigned int index = func_0044f360();
    void (__cdecl *handler)() = invalidParameter;

    if (index + 1 > entries.size())
        entries.resize(index + 1, Entry());
    else
    {
        void* object = entries.at(index, handler).object;
        if (object)
            return object;
    }

    registerValue(initializeType, &typeStorage);
    Result result = create(func_004137a0());

    if (!result.object)
        return 0;

    void* object = result.object;
    Entry& entry = entries.at(index, handler);
    entry.object = result.object;
    entry.control = result.control;
    return object;
}
