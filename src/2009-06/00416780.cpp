// from server: 100% by EspClaude
// roc 2009-06 00416780  unit: CopyVerb  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00416780
//
// 00416780  64a100000000         mov eax, dword ptr fs:[0]
// 00416786  6aff                 push -1
// 00416788  68789d8600           push 0x869d78
// 0041678d  50                   push eax
// 0041678e  64892500000000       mov dword ptr fs:[0], esp
// 00416795  83ec0c               sub esp, 0xc
// 00416798  56                   push esi
// 00416799  8b742420             mov esi, dword ptr [esp + 0x20]
// 0041679d  85f6                 test esi, esi
// 0041679f  742c                 je 0x4167cd
// 004167a1  8b0e                 mov ecx, dword ptr [esi]
// 004167a3  85c9                 test ecx, ecx
// 004167a5  7409                 je 0x4167b0
// 004167a7  8b01                 mov eax, dword ptr [ecx]
// 004167a9  8b5004               mov edx, dword ptr [eax + 4]
// 004167ac  ffd2                 call edx
// 004167ae  eb05                 jmp 0x4167b5
// 004167b0  b8d4c29d00           mov eax, 0x9dc2d4
// 004167b5  68f4f29d00           push 0x9df2f4
// 004167ba  8bc8                 mov ecx, eax
// 004167bc  ff15a4e98900         call dword ptr [0x89e9a4]
// 004167c2  84c0                 test al, al
// 004167c4  7407                 je 0x4167cd
// 004167c6  8b06                 mov eax, dword ptr [esi]
// 004167c8  83c008               add eax, 8
// 004167cb  7529                 jne 0x4167f6
// 004167cd  6850d38a00           push 0x8ad350
// 004167d2  8d4c2408             lea ecx, [esp + 8]
// 004167d6  ff1570e98900         call dword ptr [0x89e970]
// 004167dc  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 004167e4  8d442404             lea eax, [esp + 4]
// 004167e8  50                   push eax
// 004167e9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004167f1  e8ca3affff           call 0x40a2c0
// 004167f6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004167fa  5e                   pop esi
// 004167fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00416802  83c418               add esp, 0x18
// 00416805  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000005_00563f60@ns_ROCX000005@@YAPAXPAUAny@1@@Z)

namespace ns_ROCX000005 {
struct TypeInfo {};

extern TypeInfo empty_type;
extern TypeInfo string_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);

struct Holder
{
    virtual ~Holder();
    virtual const TypeInfo &type() const;
};

struct Any
{
    Holder *content;
};

extern void (__thiscall *construct_bad_cast)(void *, const char *);
extern void (__thiscall *destroy_bad_cast)(void *);
extern unsigned long bad_any_cast_vtable;
extern const char bad_cast_message[];
__declspec(noreturn) void __cdecl raise_bad_cast(const void *);

struct BadAnyCast
{
    unsigned long data[3];
    BadAnyCast();
    ~BadAnyCast();
};

inline BadAnyCast::BadAnyCast()
{
    construct_bad_cast(this, bad_cast_message);
    data[0] = reinterpret_cast<unsigned long>(&bad_any_cast_vtable);
}

inline BadAnyCast::~BadAnyCast()
{
    destroy_bad_cast(this);
}

void *__cdecl fn_ROCX000005_00563f60(Any *value)
{
    void *result;
    if (value &&
        type_equal(value->content ? &value->content->type() : &empty_type,
                   string_type) &&
        (result = reinterpret_cast<char *>(value->content) + 8) != 0)
        return result;

    BadAnyCast error;
    raise_bad_cast(&error);
}
}
