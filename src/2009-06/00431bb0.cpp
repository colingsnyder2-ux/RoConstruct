// from server: 100% by EspClaude
// roc 2009-06 00431bb0  unit: MVCXTPPropertyGridItem::?$XItem  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00431bb0
//
// 00431bb0  6aff                 push -1
// 00431bb2  68c2f88400           push 0x84f8c2
// 00431bb7  64a100000000         mov eax, dword ptr fs:[0]
// 00431bbd  50                   push eax
// 00431bbe  64892500000000       mov dword ptr fs:[0], esp
// 00431bc5  83ec24               sub esp, 0x24
// 00431bc8  53                   push ebx
// 00431bc9  8d442404             lea eax, [esp + 4]
// 00431bcd  50                   push eax
// 00431bce  e87dfaffff           call 0x431650
// 00431bd3  8bc8                 mov ecx, eax
// 00431bd5  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00431bdd  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00431be3  50                   push eax
// 00431be4  8d4c2410             lea ecx, [esp + 0x10]
// 00431be8  ff15b4e48900         call dword ptr [0x89e4b4]
// 00431bee  8d4c2408             lea ecx, [esp + 8]
// 00431bf2  51                   push ecx
// 00431bf3  8d542410             lea edx, [esp + 0x10]
// 00431bf7  52                   push edx
// 00431bf8  c644243801           mov byte ptr [esp + 0x38], 1
// 00431bfd  e8de992100           call 0x64b5e0
// 00431c02  83c408               add esp, 8
// 00431c05  8d4c240c             lea ecx, [esp + 0xc]
// 00431c09  8ad8                 mov bl, al
// 00431c0b  c644243000           mov byte ptr [esp + 0x30], 0
// 00431c10  ff15c4e48900         call dword ptr [0x89e4c4]
// 00431c16  8d4c2404             lea ecx, [esp + 4]
// 00431c1a  ff1510fd8900         call dword ptr [0x89fd10]
// 00431c20  84db                 test bl, bl
// 00431c22  5b                   pop ebx
// 00431c23  7413                 je 0x431c38
// 00431c25  d9442404             fld dword ptr [esp + 4]
// 00431c29  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00431c2d  64890d00000000       mov dword ptr fs:[0], ecx
// 00431c34  83c430               add esp, 0x30
// 00431c37  c3                   ret 
// 00431c38  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00431c3c  d9ee                 fldz 
// 00431c3e  64890d00000000       mov dword ptr fs:[0], ecx
// 00431c45  83c430               add esp, 0x30
// 00431c48  c3                   ret 
// copied from an identical function in another client (function ?number@X_00437ed0@ns_ROCX000000@@QAEMXZ)

namespace ns_ROCX000000 {
// from server: 94% by king_originala
// roc 2008-06 004380c0  unit: MVCXTPPropertyGridItem::?$XItem  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004380c0
//
// 004380c0  6aff                 push -1
// 004380c2  6882037c00           push 0x7c0382
// 004380c7  64a100000000         mov eax, dword ptr fs:[0]
// 004380cd  50                   push eax
// 004380ce  64892500000000       mov dword ptr fs:[0], esp
// 004380d5  83ec24               sub esp, 0x24
// 004380d8  53                   push ebx
// 004380d9  8d442404             lea eax, [esp + 4]
// 004380dd  50                   push eax
// 004380de  e8edfdffff           call 0x437ed0
// 004380e3  8bc8                 mov ecx, eax
// 004380e5  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004380ed  ff15e03e8000         call dword ptr [0x803ee0]
// 004380f3  50                   push eax
// 004380f4  8d4c2410             lea ecx, [esp + 0x10]
// 004380f8  ff1558248000         call dword ptr [0x802458]
// 004380fe  8d4c2408             lea ecx, [esp + 8]
// 00438102  51                   push ecx
// 00438103  8d542410             lea edx, [esp + 0x10]
// 00438107  52                   push edx
// 00438108  c644243801           mov byte ptr [esp + 0x38], 1
// 0043810d  e87e661800           call 0x5be790
// 00438112  83c408               add esp, 8
// 00438115  8d4c240c             lea ecx, [esp + 0xc]
// 00438119  8ad8                 mov bl, al
// 0043811b  c644243000           mov byte ptr [esp + 0x30], 0
// 00438120  ff1568248000         call dword ptr [0x802468]
// 00438126  8d4c2404             lea ecx, [esp + 4]
// 0043812a  ff15143f8000         call dword ptr [0x803f14]
// 00438130  84db                 test bl, bl
// 00438132  5b                   pop ebx
// 00438133  7413                 je 0x438148
// 00438135  d9442404             fld dword ptr [esp + 4]
// 00438139  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043813d  64890d00000000       mov dword ptr fs:[0], ecx
// 00438144  83c430               add esp, 0x30
// 00438147  c3                   ret 
// 00438148  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043814c  d9ee                 fldz 
// 0043814e  64890d00000000       mov dword ptr fs:[0], ecx
// 00438155  83c430               add esp, 0x30
// 00438158  c3                   ret 

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
