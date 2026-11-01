// from server: 76% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a4530  unit: RBX::Network::VServer::?$FactoryProduct  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a4530
//
// 004a4530  6aff                 push -1
// 004a4532  689ee37c00           push 0x7ce39e
// 004a4537  64a100000000         mov eax, dword ptr fs:[0]
// 004a453d  50                   push eax
// 004a453e  64892500000000       mov dword ptr fs:[0], esp
// 004a4545  51                   push ecx
// 004a4546  8b442430             mov eax, dword ptr [esp + 0x30]
// 004a454a  56                   push esi
// 004a454b  8bf1                 mov esi, ecx
// 004a454d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a4551  50                   push eax
// 004a4552  51                   push ecx
// 004a4553  8974240c             mov dword ptr [esp + 0xc], esi
// 004a4557  e844a6ffff           call 0x49eba0
// 004a455c  50                   push eax
// 004a455d  8bce                 mov ecx, esi
// 004a455f  e82c120f00           call 0x595790
// 004a4564  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a4568  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a456c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004a4574  c706d8398200         mov dword ptr [esi], 0x8239d8
// 004a457a  895638               mov dword ptr [esi + 0x38], edx
// 004a457d  89463c               mov dword ptr [esi + 0x3c], eax
// 004a4580  e83b860c00           call 0x56cbc0
// 004a4585  6a08                 push 8
// 004a4587  894640               mov dword ptr [esi + 0x40], eax
// 004a458a  e891c31f00           call 0x6a0920
// 004a458f  83c404               add esp, 4
// 004a4592  85c0                 test eax, eax
// 004a4594  740f                 je 0x4a45a5
// 004a4596  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a459a  c700cc068100         mov dword ptr [eax], 0x8106cc
// 004a45a0  894804               mov dword ptr [eax + 4], ecx
// 004a45a3  eb02                 jmp 0x4a45a7
// 004a45a5  33c0                 xor eax, eax
// 004a45a7  894644               mov dword ptr [esi + 0x44], eax
// 004a45aa  c644241001           mov byte ptr [esp + 0x10], 1
// 004a45af  e80c860c00           call 0x56cbc0
// 004a45b4  6a08                 push 8
// 004a45b6  894648               mov dword ptr [esi + 0x48], eax
// 004a45b9  e862c31f00           call 0x6a0920
// 004a45be  83c404               add esp, 4
// 004a45c1  85c0                 test eax, eax
// 004a45c3  740f                 je 0x4a45d4
// 004a45c5  8b542430             mov edx, dword ptr [esp + 0x30]
// 004a45c9  c700cc068100         mov dword ptr [eax], 0x8106cc
// 004a45cf  895004               mov dword ptr [eax + 4], edx
// 004a45d2  eb02                 jmp 0x4a45d6
// 004a45d4  33c0                 xor eax, eax
// 004a45d6  89464c               mov dword ptr [esi + 0x4c], eax
// 004a45d9  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004a45dd  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a45e1  50                   push eax
// 004a45e2  51                   push ecx
// 004a45e3  8bce                 mov ecx, esi
// 004a45e5  c644241802           mov byte ptr [esp + 0x18], 2
// 004a45ea  e8c128f7ff           call 0x416eb0
// 004a45ef  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a45f3  8bc6                 mov eax, esi
// 004a45f5  5e                   pop esi
// 004a45f6  64890d00000000       mov dword ptr fs:[0], ecx
// 004a45fd  83c410               add esp, 0x10
// 004a4600  c22000               ret 0x20

void* __cdecl getBaseToken();
void* __cdecl getSharedToken();
void* __cdecl operator new(unsigned int);

struct Holder {
    virtual ~Holder();
    void* value;

    Holder(void* p);
};

inline Holder::Holder(void* p) : value(p) {}

struct Shared {
    void* token;
    Holder* holder;

    Shared(void* p);
    ~Shared();
};

inline Shared::Shared(void* p)
    : token(getSharedToken()), holder(new Holder(p)) {}

struct Base {
    virtual ~Base();
    unsigned char storage[0x34];

    Base(void* token, void* a, void* b);
    void finish(void* a, void* b);
};

struct Product : Base {
    void* first;
    void* second;
    Shared left;
    Shared right;

    Product(void* a, void* b, void* c, void* d,
            void* e, void* f, void* g, void* h);
    virtual ~Product();
};

Product::Product(void* a, void* b, void* c, void* d,
                 void* e, void* f, void* g, void* h)
    : Base(getBaseToken(), c, h),
      first(a),
      second(b),
      left(e),
      right(g)
{
    finish(d, f);
}
