// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 005641e0  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005641e0
//
// 005641e0  64a100000000         mov eax, dword ptr fs:[0]
// 005641e6  6aff                 push -1
// 005641e8  6818f37c00           push 0x7cf318
// 005641ed  50                   push eax
// 005641ee  64892500000000       mov dword ptr fs:[0], esp
// 005641f5  83ec10               sub esp, 0x10
// 005641f8  56                   push esi
// 005641f9  8bf1                 mov esi, ecx
// 005641fb  8b06                 mov eax, dword ptr [esi]
// 005641fd  8b4008               mov eax, dword ptr [eax + 8]
// 00564200  50                   push eax
// 00564201  b9e8be9200           mov ecx, 0x92bee8
// 00564206  ff1578288000         call dword ptr [0x802878]
// 0056420c  84c0                 test al, al
// 0056420e  741e                 je 0x56422e
// 00564210  83c604               add esi, 4
// 00564213  56                   push esi
// 00564214  e847fdffff           call 0x563f60
// 00564219  dd00                 fld qword ptr [eax]
// 0056421b  83c404               add esp, 4
// 0056421e  5e                   pop esi
// 0056421f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00564223  64890d00000000       mov dword ptr fs:[0], ecx
// 0056422a  83c41c               add esp, 0x1c
// 0056422d  c3                   ret 
// 0056422e  8b0e                 mov ecx, dword ptr [esi]
// 00564230  894c2404             mov dword ptr [esp + 4], ecx
// 00564234  8b4e04               mov ecx, dword ptr [esi + 4]
// 00564237  85c9                 test ecx, ecx
// 00564239  7409                 je 0x564244
// 0056423b  8b11                 mov edx, dword ptr [ecx]
// 0056423d  8b4208               mov eax, dword ptr [edx + 8]
// 00564240  ffd0                 call eax
// 00564242  eb02                 jmp 0x564246
// 00564244  33c0                 xor eax, eax
// 00564246  89442408             mov dword ptr [esp + 8], eax
// 0056424a  8d4c2404             lea ecx, [esp + 4]
// 0056424e  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00564256  e8f5ab0000           call 0x56ee50
// 0056425b  dd00                 fld qword ptr [eax]
// 0056425d  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00564261  dd5c240c             fstp qword ptr [esp + 0xc]
// 00564265  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0056426d  85c9                 test ecx, ecx
// 0056426f  7408                 je 0x564279
// 00564271  8b11                 mov edx, dword ptr [ecx]
// 00564273  8b02                 mov eax, dword ptr [edx]
// 00564275  6a01                 push 1
// 00564277  ffd0                 call eax
// 00564279  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056427d  dd44240c             fld qword ptr [esp + 0xc]
// 00564281  5e                   pop esi
// 00564282  64890d00000000       mov dword ptr fs:[0], ecx
// 00564289  83c41c               add esp, 0x1c
// 0056428c  c3                   ret 

struct TypeInfo {};
extern TypeInfo double_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);

struct Holder {
    virtual ~Holder();
    virtual const TypeInfo &type() const;
    virtual Holder *clone() const;
};

struct Any {
    Holder *content;
    Any(const Any &other);
};

inline Any::Any(const Any &other)
    : content(other.content ? other.content->clone() : 0)
{
}

extern const double *__cdecl double_value(const Any *);

struct Type {
    unsigned char padding[8];
    const TypeInfo *info;
};

struct S {
    Type *descriptor;
    Any value;

    S(const S &other);
    ~S();
    const double &convert();
    double get() const;
};

inline S::S(const S &other)
    : descriptor(other.descriptor), value(other.value)
{
}

inline S::~S()
{
    if (value.content)
        delete value.content;
}

double S::get() const
{
    const TypeInfo *typeInfo = descriptor->info;
    if (type_equal(&double_type, *typeInfo))
        return *double_value(&value);

    S temporary(*this);
    return temporary.convert();
}
