// from server: 100% by Yeetserama
// roc 2011-06 004431a0  unit: MVCXTPPropertyGridItem::?$XItem  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004431a0
//
// 004431a0  6aff                 push -1
// 004431a2  68a2179d00           push 0x9d17a2
// 004431a7  64a100000000         mov eax, dword ptr fs:[0]
// 004431ad  50                   push eax
// 004431ae  64892500000000       mov dword ptr fs:[0], esp
// 004431b5  83ec24               sub esp, 0x24
// 004431b8  53                   push ebx
// 004431b9  8d442404             lea eax, [esp + 4]
// 004431bd  50                   push eax
// 004431be  e82dffffff           call 0x4430f0
// 004431c3  8bc8                 mov ecx, eax
// 004431c5  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004431cd  ff15c82da400         call dword ptr [0xa42dc8]
// 004431d3  50                   push eax
// 004431d4  8d4c2410             lea ecx, [esp + 0x10]
// 004431d8  ff15c404a400         call dword ptr [0xa404c4]
// 004431de  8d4c2408             lea ecx, [esp + 8]
// 004431e2  51                   push ecx
// 004431e3  8d542410             lea edx, [esp + 0x10]
// 004431e7  52                   push edx
// 004431e8  c644243801           mov byte ptr [esp + 0x38], 1
// 004431ed  e80ed22000           call 0x650400
// 004431f2  83c408               add esp, 8
// 004431f5  8d4c240c             lea ecx, [esp + 0xc]
// 004431f9  8ad8                 mov bl, al
// 004431fb  c644243000           mov byte ptr [esp + 0x30], 0
// 00443200  ff15d004a400         call dword ptr [0xa404d0]
// 00443206  8d4c2404             lea ecx, [esp + 4]
// 0044320a  ff15082ea400         call dword ptr [0xa42e08]
// 00443210  84db                 test bl, bl
// 00443212  5b                   pop ebx
// 00443213  7413                 je 0x443228
// 00443215  d9442404             fld dword ptr [esp + 4]
// 00443219  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044321d  64890d00000000       mov dword ptr fs:[0], ecx
// 00443224  83c430               add esp, 0x30
// 00443227  c3                   ret 
// 00443228  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044322c  d9ee                 fldz 
// 0044322e  64890d00000000       mov dword ptr fs:[0], ecx
// 00443235  83c430               add esp, 0x30
// 00443238  c3                   ret 
// copied from an identical function in another client (function ?number@X_00437ed0@ns_ROCX000002@@QAEMXZ)

namespace ns_ROCX000002 {
struct Str_00437ed0 {
    int words[8];
};

struct X_00437ed0 {
    char pad[0xa4];
    Str_00437ed0 value;
    Str_00437ed0* copy(Str_00437ed0* out);
    float number();
};

struct StringHandle {
    int value;
    StringHandle(X_00437ed0* owner, Str_00437ed0*& copied);
    __declspec(dllimport) ~StringHandle() throw();
};

struct NarrowString {
    unsigned char data[28];
    NarrowString(const char* text);
    ~NarrowString() throw();
};

extern const char* (__thiscall* string_text)(Str_00437ed0*);
extern void (__thiscall* release_string)(Str_00437ed0*);
extern void (__thiscall* construct_narrow)(NarrowString*, const char*);
extern void (__thiscall* destroy_narrow)(NarrowString*);
extern bool __cdecl parse_number(const NarrowString*, float*);

inline StringHandle::StringHandle(
    X_00437ed0* owner, Str_00437ed0*& copied)
{
    copied = owner->copy(reinterpret_cast<Str_00437ed0*>(this));
}

inline NarrowString::NarrowString(const char* text)
{
    construct_narrow(this, text);
}

inline NarrowString::~NarrowString() throw()
{
    destroy_narrow(this);
}

float X_00437ed0::number()
{
    float result;
    bool valid;
    {
        Str_00437ed0* copied;
        StringHandle text(this, copied);
        NarrowString narrow(string_text(copied));
        valid = parse_number(&narrow, &result);
    }
    if (valid)
        return result;
    return 0.0f;
}
}
