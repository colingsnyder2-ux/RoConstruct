// from server: 100% by colin
// roc 2008-06 00582230  unit: RBX::BoolPropertyVerb  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582230
//
// 00582230  83ec10               sub esp, 0x10
// 00582233  53                   push ebx
// 00582234  55                   push ebp
// 00582235  56                   push esi
// 00582236  57                   push edi
// 00582237  8bf9                 mov edi, ecx
// 00582239  8b7720               mov esi, dword ptr [edi + 0x20]
// 0058223c  e80fb0ffff           call 0x57d250
// 00582241  8b07                 mov eax, dword ptr [edi]
// 00582243  8b500c               mov edx, dword ptr [eax + 0xc]
// 00582246  8bcf                 mov ecx, edi
// 00582248  ffd2                 call edx
// 0058224a  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0058224d  84c0                 test al, al
// 0058224f  0f94c0               sete al
// 00582252  894c2410             mov dword ptr [esp + 0x10], ecx
// 00582256  8d5f14               lea ebx, [edi + 0x14]
// 00582259  6a01                 push 1
// 0058225b  8bcb                 mov ecx, ebx
// 0058225d  88442418             mov byte ptr [esp + 0x18], al
// 00582261  e85afaffff           call 0x581cc0
// 00582266  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 0058226c  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0058226f  396e0c               cmp dword ptr [esi + 0xc], ebp
// 00582272  7606                 jbe 0x58227a
// 00582274  ff1590288000         call dword ptr [0x802890]
// 0058227a  8b16                 mov edx, dword ptr [esi]
// 0058227c  6a01                 push 1
// 0058227e  8bcb                 mov ecx, ebx
// 00582280  8954241c             mov dword ptr [esp + 0x1c], edx
// 00582284  e837faffff           call 0x581cc0
// 00582289  8b9854010000         mov ebx, dword ptr [eax + 0x154]
// 0058228f  8b730c               mov esi, dword ptr [ebx + 0xc]
// 00582292  3b7310               cmp esi, dword ptr [ebx + 0x10]
// 00582295  7606                 jbe 0x58229d
// 00582297  ff1590288000         call dword ptr [0x802890]
// 0058229d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005822a1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005822a5  8b542418             mov edx, dword ptr [esp + 0x18]
// 005822a9  8b1b                 mov ebx, dword ptr [ebx]
// 005822ab  50                   push eax
// 005822ac  51                   push ecx
// 005822ad  55                   push ebp
// 005822ae  52                   push edx
// 005822af  56                   push esi
// 005822b0  8d44242c             lea eax, [esp + 0x2c]
// 005822b4  53                   push ebx
// 005822b5  50                   push eax
// 005822b6  e8f5d7ffff           call 0x57fab0
// 005822bb  8b4724               mov eax, dword ptr [edi + 0x24]
// 005822be  83c004               add eax, 4
// 005822c1  83c41c               add esp, 0x1c
// 005822c4  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005822c8  7205                 jb 0x5822cf
// 005822ca  8b4004               mov eax, dword ptr [eax + 4]
// 005822cd  eb03                 jmp 0x5822d2
// 005822cf  83c004               add eax, 4
// 005822d2  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 005822d5  51                   push ecx
// 005822d6  50                   push eax
// 005822d7  e8e4a20000           call 0x58c5c0
// 005822dc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005822e0  8b11                 mov edx, dword ptr [ecx]
// 005822e2  83c408               add esp, 8
// 005822e5  5f                   pop edi
// 005822e6  5e                   pop esi
// 005822e7  5d                   pop ebp
// 005822e8  5b                   pop ebx
// 005822e9  83c410               add esp, 0x10
// 005822ec  c744240401000000     mov dword ptr [esp + 4], 1
// 005822f4  8b02                 mov eax, dword ptr [edx]
// 005822f6  ffe0                 jmp eax

extern "C" void (__stdcall *_invalid_parameter_noinfo)();

struct Context;
extern bool __cdecl isLocked(Context*);
extern void __cdecl unlock(Context*);
static __declspec(noinline) void prepare(Context* c)
{
    if (isLocked(c))
        unlock(c);
}

struct Range {
    unsigned char* storage;
    unsigned char padding[8];
    unsigned first;
    unsigned last;
};

struct Object {
    unsigned char padding[0x154];
    Range* range;
};

struct Reference {
    Object* get(int);
    unsigned char padding[12];
};

struct String {
    unsigned unknown;
    union {
        char local[16];
        char* allocated;
    } text;
    unsigned length;
    unsigned capacity;
};

struct Property {
    unsigned unknown;
    String name;
};

struct Completion {
    virtual void finish(int);
};

struct Operation {
    Property* property;
    bool value;

    Operation(Property*, bool);
};

inline Operation::Operation(Property* p, bool v)
    : property(p), value(v)
{
}

struct Result {
    unsigned char* storage;
    unsigned index;
    Result();
};

struct Iterator {
    unsigned char* storage;
    unsigned index;
    Iterator(unsigned char* s, unsigned i) : storage(s), index(i) {}
};
extern Operation __cdecl apply(Iterator, Iterator, Operation);

namespace RBX {
    void __cdecl handle(const char*, Context*);
}

struct S {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual bool state();

    unsigned char padding[16];
    Reference reference;
    Context* context;
    Property* property;

    void run(Completion*);
};

void S::run(Completion* completion)
{
    prepare(context);

    Operation operation(property, !state());

    Range* endRange = reference.get(1)->range;
    unsigned end = endRange->last;
    if (endRange->first > end)
        _invalid_parameter_noinfo();
    Iterator last(endRange->storage, end);

    Range* beginRange = reference.get(1)->range;
    unsigned begin = beginRange->first;
    if (begin > beginRange->last)
        _invalid_parameter_noinfo();

    apply(Iterator(beginRange->storage, begin), last, operation);

    String* name = &property->name;
    const char* text;
    if (name->capacity >= 16)
        text = name->text.allocated;
    else
        text = name->text.local;

    RBX::handle(text, context);
    completion->finish(1);
}
