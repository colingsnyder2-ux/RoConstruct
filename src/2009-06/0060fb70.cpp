// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00582830  unit: CopyVerb  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00582830
//
// 00582830  6a01                 push 1
// 00582832  83c114               add ecx, 0x14
// 00582835  e886f4ffff           call 0x581cc0
// 0058283a  8b8054010000         mov eax, dword ptr [eax + 0x154]
// 00582840  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00582843  2b480c               sub ecx, dword ptr [eax + 0xc]
// 00582846  33d2                 xor edx, edx
// 00582848  c1f903               sar ecx, 3
// 0058284b  3bd1                 cmp edx, ecx
// 0058284d  1bc0                 sbb eax, eax
// 0058284f  f7d8                 neg eax
// 00582851  c3                   ret 

struct Entry {
    unsigned int data[2];
};

struct Entries {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Object {
    char padding[0x154];
    Entries* entries;
};

struct Handle {
    Object* get(int);
};

struct CopyVerb {
    char padding[0x14];
    Handle handle;
    int f();
};

int CopyVerb::f()
{
    Entries* p = handle.get(1)->entries;
    return (unsigned int)(p->last - p->first) > 0;
}
