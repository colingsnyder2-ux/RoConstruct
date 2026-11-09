// from server: 100% by Intel
// from server: 95% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 00420fb0  unit: CInstanceExplorer  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00420fb0
//
// 00420fb0  6aff                 push -1
// 00420fb2  6872e87b00           push 0x7be872
// 00420fb7  64a100000000         mov eax, dword ptr fs:[0]
// 00420fbd  50                   push eax
// 00420fbe  64892500000000       mov dword ptr fs:[0], esp
// 00420fc5  83ec08               sub esp, 8
// 00420fc8  55                   push ebp
// 00420fc9  56                   push esi
// 00420fca  57                   push edi
// 00420fcb  8be9                 mov ebp, ecx
// 00420fcd  6a5c                 push 0x5c
// 00420fcf  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00420fd7  e814722a00           call 0x6c81f0
// 00420fdc  8bf0                 mov esi, eax
// 00420fde  8974240c             mov dword ptr [esp + 0xc], esi
// 00420fe2  c644241c01           mov byte ptr [esp + 0x1c], 1
// 00420fe7  85f6                 test esi, esi
// 00420fe9  7422                 je 0x42100d
// 00420feb  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00420fef  83ec08               sub esp, 8
// 00420ff2  8bc4                 mov eax, esp
// 00420ff4  89642418             mov dword ptr [esp + 0x18], esp
// 00420ff8  51                   push ecx
// 00420ff9  50                   push eax
// 00420ffa  e8417a1f00           call 0x618a40
// 00420fff  83c408               add esp, 8
// 00421002  8bce                 mov ecx, esi
// 00421004  e8a7fdffff           call 0x420db0
// 00421009  8bf8                 mov edi, eax
// 0042100b  eb02                 jmp 0x42100f
// 0042100d  33ff                 xor edi, edi
// 0042100f  8b9588fcffff         mov edx, dword ptr [ebp - 0x378]
// 00421015  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0042101b  8db588fcffff         lea esi, [ebp - 0x378]
// 00421021  8bce                 mov ecx, esi
// 00421023  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00421028  ffd0                 call eax
// 0042102a  8b10                 mov edx, dword ptr [eax]
// 0042102c  8bc8                 mov ecx, eax
// 0042102e  8b824c010000         mov eax, dword ptr [edx + 0x14c]
// 00421034  57                   push edi
// 00421035  ffd0                 call eax
// 00421037  80bec803000000       cmp byte ptr [esi + 0x3c8], 0
// 0042103e  7518                 jne 0x421058
// 00421040  8b16                 mov edx, dword ptr [esi]
// 00421042  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 00421048  8bce                 mov ecx, esi
// 0042104a  ffd0                 call eax
// 0042104c  8b10                 mov edx, dword ptr [eax]
// 0042104e  8bc8                 mov ecx, eax
// 00421050  8b8260010000         mov eax, dword ptr [edx + 0x160]
// 00421056  ffd0                 call eax
// 00421058  8d4c2428             lea ecx, [esp + 0x28]
// 0042105c  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00421064  e8f71b0000           call 0x422c60
// 00421069  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042106d  5f                   pop edi
// 0042106e  5e                   pop esi
// 0042106f  64890d00000000       mov dword ptr fs:[0], ecx
// 00421076  5d                   pop ebp
// 00421077  83c414               add esp, 0x14
// 0042107a  c21400               ret 0x14

struct Shared
{
    void* object;
    void* control;
    Shared(const Shared&);
    ~Shared();
};

struct Argument
{
    void* object;
    unsigned char storage[12];
    ~Argument();
};

extern Shared __cdecl convert(void*);

struct Item
{
    unsigned char storage[0x5c];

    static void* __stdcall operator new(unsigned int);
    static void __stdcall operator delete(void*);
    Item(Shared);
};

struct View;
struct Owner;

struct ViewTable
{
    void* reserved0[81];
    void (__thiscall *attach)(View*, Item*);
    void* reserved1[2];
    void (__thiscall *refresh)(View*);
};

struct View
{
    ViewTable* table;
};

struct OwnerTable
{
    void* reserved[99];
    View* (__thiscall *getView)(Owner*);
};

struct Owner
{
    OwnerTable* table;
    unsigned char storage[0x308];
    unsigned char disabled;
};

struct CInstanceExplorer
{
    void update(int, Argument);
};

void CInstanceExplorer::update(int, Argument argument)
{
    Item* item = new Item(convert(argument.object));
    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x2cc);

    View* view = owner->table->getView(owner);
    view->table->attach(view, item);

    if (!owner->disabled)
    {
        view = owner->table->getView(owner);
        view->table->refresh(view);
    }
}
