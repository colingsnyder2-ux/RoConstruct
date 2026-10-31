// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00582180  unit: RBX::BoolPropertyVerb  size: 170 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582180
//
// 00582180  83ec14               sub esp, 0x14
// 00582183  53                   push ebx
// 00582184  55                   push ebp
// 00582185  56                   push esi
// 00582186  8bd9                 mov ebx, ecx
// 00582188  57                   push edi
// 00582189  8d7b14               lea edi, [ebx + 0x14]
// 0058218c  6a01                 push 1
// 0058218e  8bcf                 mov ecx, edi
// 00582190  e82bfbffff           call 0x581cc0
// 00582195  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 0058219b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0058219e  89442410             mov dword ptr [esp + 0x10], eax
// 005821a2  39460c               cmp dword ptr [esi + 0xc], eax
// 005821a5  7606                 jbe 0x5821ad
// 005821a7  ff1590288000         call dword ptr [0x802890]
// 005821ad  8b06                 mov eax, dword ptr [esi]
// 005821af  8b6b24               mov ebp, dword ptr [ebx + 0x24]
// 005821b2  6a01                 push 1
// 005821b4  8bcf                 mov ecx, edi
// 005821b6  89442418             mov dword ptr [esp + 0x18], eax
// 005821ba  e801fbffff           call 0x581cc0
// 005821bf  8b8054010000         mov eax, dword ptr [eax + 0x154]
// 005821c5  8b5810               mov ebx, dword ptr [eax + 0x10]
// 005821c8  39580c               cmp dword ptr [eax + 0xc], ebx
// 005821cb  7606                 jbe 0x5821d3
// 005821cd  ff1590288000         call dword ptr [0x802890]
// 005821d3  6a01                 push 1
// 005821d5  8bcf                 mov ecx, edi
// 005821d7  e8e4faffff           call 0x581cc0
// 005821dc  8bb054010000         mov esi, dword ptr [eax + 0x154]
// 005821e2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005821e5  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005821e8  7606                 jbe 0x5821f0
// 005821ea  ff1590288000         call dword ptr [0x802890]
// 005821f0  8b36                 mov esi, dword ptr [esi]
// 005821f2  55                   push ebp
// 005821f3  b810f85700           mov eax, 0x57f810
// 005821f8  50                   push eax
// 005821f9  53                   push ebx
// 005821fa  57                   push edi
// 005821fb  897c2430             mov dword ptr [esp + 0x30], edi
// 005821ff  e85cccffff           call 0x57ee60
// 00582204  83c410               add esp, 0x10
// 00582207  8bf8                 mov edi, eax
// 00582209  85f6                 test esi, esi
// 0058220b  7406                 je 0x582213
// 0058220d  3b742414             cmp esi, dword ptr [esp + 0x14]
// 00582211  7406                 je 0x582219
// 00582213  ff1590288000         call dword ptr [0x802890]
// 00582219  33c0                 xor eax, eax
// 0058221b  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 0058221f  5f                   pop edi
// 00582220  5e                   pop esi
// 00582221  5d                   pop ebp
// 00582222  0f95c0               setne al
// 00582225  5b                   pop ebx
// 00582226  83c414               add esp, 0x14
// 00582229  c3                   ret 

extern "C" void (__cdecl* invalid_parameter_noinfo)();

struct Container {
    void* owner;
    unsigned char padding[8];
    unsigned* first;
    unsigned* last;
};

struct Object {
    unsigned char padding[0x154];
    Container* container;
};

struct Access {
    Object* get(int);
};

struct Predicate {
    bool (__cdecl* function)(unsigned, void*);
    void* argument;
};

bool __cdecl predicate(unsigned, void*);
unsigned* __cdecl find_match(unsigned*, unsigned*, Predicate);

struct S {
    unsigned char padding[0x14];
    Access access;
    unsigned char reserved[0x0f];
    void* context;

    bool f();
};

bool S::f()
{
    unsigned* volatile iteratorStorage[3];
    struct Saved {
        unsigned* end;
        void* owner;
    } saved;

    Container* c = access.get(1)->container;
    saved.end = c->last;
    if (c->first > saved.end)
        invalid_parameter_noinfo();

    saved.owner = c->owner;
    void* argument = context;

    c = access.get(1)->container;
    unsigned* end = c->last;
    if (c->first > end)
        invalid_parameter_noinfo();

    c = access.get(1)->container;
    unsigned* begin = c->first;
    if (begin > c->last)
        invalid_parameter_noinfo();

    void* owner = c->owner;
    Predicate test = { predicate, argument };
    iteratorStorage[2] = begin;
    unsigned* result = find_match(begin, end, test);

    if (!owner || owner != saved.owner)
        invalid_parameter_noinfo();

    return result != saved.end;
}
