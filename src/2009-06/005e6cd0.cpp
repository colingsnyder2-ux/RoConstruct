// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e760  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e760
//
// 0056e760  83ec08               sub esp, 8
// 0056e763  56                   push esi
// 0056e764  57                   push edi
// 0056e765  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056e769  8bf1                 mov esi, ecx
// 0056e76b  8bcf                 mov ecx, edi
// 0056e76d  e89ee00000           call 0x57c810
// 0056e772  84c0                 test al, al
// 0056e774  7525                 jne 0x56e79b
// 0056e776  8d442408             lea eax, [esp + 8]
// 0056e77a  50                   push eax
// 0056e77b  8d4f10               lea ecx, [edi + 0x10]
// 0056e77e  e8edde0000           call 0x57c670
// 0056e783  84c0                 test al, al
// 0056e785  7414                 je 0x56e79b
// 0056e787  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e78a  8b11                 mov edx, dword ptr [ecx]
// 0056e78c  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e78f  8d442408             lea eax, [esp + 8]
// 0056e793  50                   push eax
// 0056e794  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056e798  50                   push eax
// 0056e799  ffd2                 call edx
// 0056e79b  5f                   pop edi
// 0056e79c  5e                   pop esi
// 0056e79d  83c408               add esp, 8
// 0056e7a0  c20c00               ret 0xc

struct S {
    int reserved;
    int type;
    union {
        double number;
        float single;
        const char *text;
    } value;
    bool toNumber(double *);
};

struct Value {
    char reserved[16];
    S data;
    bool check();
};

struct Setter;

struct SetterTable {
    void *reserved[3];
    void (__thiscall *set)(Setter *, void *, const double *);
};

struct Setter {
    SetterTable *table;
};

struct Descriptor {
    char reserved[24];
    Setter *setter;
    void apply(void *, Value *, void *);
};

void Descriptor::apply(void *object, Value *value, void *)
{
    double number;
    if (!value->check() && value->data.toNumber(&number))
        setter->table->set(setter, object, &number);
}
