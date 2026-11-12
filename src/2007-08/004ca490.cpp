// from server: 100% by EspClaude
// from server: 56% by colin
// roc 2007-08 004ca490  unit: seg_004c0000  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ca490
//
// 004ca490  83ec1c               sub esp, 0x1c
// 004ca493  56                   push esi
// 004ca494  8bf1                 mov esi, ecx
// 004ca496  68cc2f8900           push 0x892fcc
// 004ca49b  8d4c2428             lea ecx, [esp + 0x28]
// 004ca49f  e82c91fdff           call 0x4a35d0
// 004ca4a4  84c0                 test al, al
// 004ca4a6  7564                 jne 0x4ca50c
// 004ca4a8  8b442424             mov eax, dword ptr [esp + 0x24]
// 004ca4ac  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004ca4b0  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004ca4b4  89442404             mov dword ptr [esp + 4], eax
// 004ca4b8  8d442404             lea eax, [esp + 4]
// 004ca4bc  894c2408             mov dword ptr [esp + 8], ecx
// 004ca4c0  50                   push eax
// 004ca4c1  8d4c2414             lea ecx, [esp + 0x14]
// 004ca4c5  89542410             mov dword ptr [esp + 0x10], edx
// 004ca4c9  e8e290fdff           call 0x4a35b0
// 004ca4ce  68c0f98b00           push 0x8bf9c0
// 004ca4d3  8d4c2414             lea ecx, [esp + 0x14]
// 004ca4d7  83c610               add esi, 0x10
// 004ca4da  51                   push ecx
// 004ca4db  8bce                 mov ecx, esi
// 004ca4dd  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004ca4e5  e8a6feffff           call 0x4ca390
// 004ca4ea  8b00                 mov eax, dword ptr [eax]
// 004ca4ec  a3c0f98b00           mov dword ptr [0x8bf9c0], eax
// 004ca4f1  837e0800             cmp dword ptr [esi + 8], 0
// 004ca4f5  7505                 jne 0x4ca4fc
// 004ca4f7  b8bcf98b00           mov eax, 0x8bf9bc
// 004ca4fc  8b00                 mov eax, dword ptr [eax]
// 004ca4fe  85c0                 test eax, eax
// 004ca500  740a                 je 0x4ca50c
// 004ca502  8b400c               mov eax, dword ptr [eax + 0xc]
// 004ca505  5e                   pop esi
// 004ca506  83c41c               add esp, 0x1c
// 004ca509  c20c00               ret 0xc
// 004ca50c  33c0                 xor eax, eax
// 004ca50e  5e                   pop esi
// 004ca50f  83c41c               add esp, 0x1c
struct Name {
    int a, b, c;
    bool test(const char* s) const;          // thiscall 0x4a35d0, returns al
};

struct Key {
    int a, b, c;
    Key(const Name& n);                      // thiscall 0x4a35b0
};

struct Entry {
    Key key;
    int value;                               // stored 0 at entry+0xc
    Entry(const Name& n) : key(n), value(0) {}
};

struct Iter {
    int* node;
};

struct Table {
    int f0;
    int f4;
    int f8;                                  // tested at this+0x18
    Iter* insert(const Entry& e, Iter* where); // thiscall 0x4ca390
};

struct Owner {
    int pad[4];
    Table table;                             // at this+0x10
    int lookup(Name n);
};

extern const char g_str[];                   // 0x892fcc
extern Iter g_it;                            // 0x8bf9c0
extern int g_nil;                            // 0x8bf9bc

int Owner::lookup(Name n)
{
    if (!n.test(g_str)) {
        Name copy = n;
        Entry e(copy);
        Table* t = &table;
        g_it.node = t->insert(e, &g_it)->node;
        int* p = t->f8 ? g_it.node : &g_nil;
        int v = *p;
        if (v != 0)
            return *(int*)(v + 0xc);
    }
    return 0;
}
