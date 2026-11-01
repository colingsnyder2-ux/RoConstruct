// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066a630  unit: RBX::GroupDragTool  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066a630
//
// 0066a630  6aff                 push -1
// 0066a632  68bec47d00           push 0x7dc4be
// 0066a637  64a100000000         mov eax, dword ptr fs:[0]
// 0066a63d  50                   push eax
// 0066a63e  64892500000000       mov dword ptr fs:[0], esp
// 0066a645  51                   push ecx
// 0066a646  55                   push ebp
// 0066a647  56                   push esi
// 0066a648  57                   push edi
// 0066a649  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0066a64d  8bf1                 mov esi, ecx
// 0066a64f  57                   push edi
// 0066a650  89742410             mov dword ptr [esp + 0x10], esi
// 0066a654  e897b3faff           call 0x6159f0
// 0066a659  c7062cd08400         mov dword ptr [esi], 0x84d02c
// 0066a65f  c7460414d08400       mov dword ptr [esi + 4], 0x84d014
// 0066a666  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0066a66e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0066a675  d9ee                 fldz 
// 0066a677  d95620               fst dword ptr [esi + 0x20]
// 0066a67a  6a2c                 push 0x2c
// 0066a67c  d95624               fst dword ptr [esi + 0x24]
// 0066a67f  c644241c01           mov byte ptr [esp + 0x1c], 1
// 0066a684  c6462800             mov byte ptr [esi + 0x28], 0
// 0066a688  d9562c               fst dword ptr [esi + 0x2c]
// 0066a68b  d95630               fst dword ptr [esi + 0x30]
// 0066a68e  d95e34               fstp dword ptr [esi + 0x34]
// 0066a691  e88a620300           call 0x6a0920
// 0066a696  83c404               add esp, 4
// 0066a699  8944242c             mov dword ptr [esp + 0x2c], eax
// 0066a69d  c644241802           mov byte ptr [esp + 0x18], 2
// 0066a6a2  85c0                 test eax, eax
// 0066a6a4  7416                 je 0x66a6bc
// 0066a6a6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066a6aa  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066a6ae  57                   push edi
// 0066a6af  51                   push ecx
// 0066a6b0  52                   push edx
// 0066a6b1  8bc8                 mov ecx, eax
// 0066a6b3  e8783ffaff           call 0x60e630
// 0066a6b8  8be8                 mov ebp, eax
// 0066a6ba  eb02                 jmp 0x66a6be
// 0066a6bc  33ed                 xor ebp, ebp
// 0066a6be  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0066a6c1  c644241801           mov byte ptr [esp + 0x18], 1
// 0066a6c6  3bef                 cmp ebp, edi
// 0066a6c8  7414                 je 0x66a6de
// 0066a6ca  85ff                 test edi, edi
// 0066a6cc  7410                 je 0x66a6de
// 0066a6ce  8bcf                 mov ecx, edi
// 0066a6d0  e82b40faff           call 0x60e700
// 0066a6d5  57                   push edi
// 0066a6d6  e89f5f0300           call 0x6a067a
// 0066a6db  83c404               add esp, 4
// 0066a6de  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066a6e2  896e1c               mov dword ptr [esi + 0x1c], ebp
// 0066a6e5  5f                   pop edi
// 0066a6e6  8bc6                 mov eax, esi
// 0066a6e8  5e                   pop esi
// 0066a6e9  5d                   pop ebp
// 0066a6ea  64890d00000000       mov dword ptr fs:[0], ecx
// 0066a6f1  83c410               add esp, 0x10
// 0066a6f4  c21000               ret 0x10

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Item {
    char storage[44];
    Item(int, int, int);
    ~Item();
};

struct Base {
    int words[7];
    int f(int);
    ~Base();
    Base(int);
};

Base::Base(int value) {
    f(value);
    words[0] = 0x84d02c;
    words[1] = 0x84d014;
}

struct Owner {
    Item* pointer;
    Owner();
    ~Owner();
    void reset(Item*);
};

Owner::Owner() : pointer(0) {}

Owner::~Owner() {
    delete pointer;
}

void Owner::reset(Item* value) {
    if (value != pointer && pointer)
        delete pointer;
    pointer = value;
}

struct S : Base {
    Owner item;
    float x;
    float y;
    volatile bool flag;
    volatile float a;
    float b;
    float c;

    S(int, int, int, int);
};

S::S(int first, int unused, int third, int fourth)
    : Base(fourth), x(0.0f), y(0.0f), flag(false),
      a(0.0f), b(0.0f), c(0.0f)
{
    item.reset(new Item(first, third, fourth));
}
