// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006365c0  unit: RBX::VBrickColor::V?$Value::?$FactoryProduct  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006365c0
//
// 006365c0  6aff                 push -1
// 006365c2  68a8647c00           push 0x7c64a8
// 006365c7  64a100000000         mov eax, dword ptr fs:[0]
// 006365cd  50                   push eax
// 006365ce  64892500000000       mov dword ptr fs:[0], esp
// 006365d5  83ec1c               sub esp, 0x1c
// 006365d8  57                   push edi
// 006365d9  8bf9                 mov edi, ecx
// 006365db  6a01                 push 1
// 006365dd  8d4c240c             lea ecx, [esp + 0xc]
// 006365e1  e88a4bdeff           call 0x41b170
// 006365e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 006365ea  2b442414             sub eax, dword ptr [esp + 0x14]
// 006365ee  c744242800000000     mov dword ptr [esp + 0x28], 0
// 006365f6  c1f802               sar eax, 2
// 006365f9  85c0                 test eax, eax
// 006365fb  7706                 ja 0x636603
// 006365fd  ff1590288000         call dword ptr [0x802890]
// 00636603  56                   push esi
// 00636604  8b742418             mov esi, dword ptr [esp + 0x18]
// 00636608  8d4c2434             lea ecx, [esp + 0x34]
// 0063660c  51                   push ecx
// 0063660d  8d4c240c             lea ecx, [esp + 0xc]
// 00636611  e86a63f3ff           call 0x56c980
// 00636616  3bc6                 cmp eax, esi
// 00636618  7408                 je 0x636622
// 0063661a  8b16                 mov edx, dword ptr [esi]
// 0063661c  8b08                 mov ecx, dword ptr [eax]
// 0063661e  8910                 mov dword ptr [eax], edx
// 00636620  890e                 mov dword ptr [esi], ecx
// 00636622  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00636626  5e                   pop esi
// 00636627  85c9                 test ecx, ecx
// 00636629  7408                 je 0x636633
// 0063662b  8b01                 mov eax, dword ptr [ecx]
// 0063662d  8b10                 mov edx, dword ptr [eax]
// 0063662f  6a01                 push 1
// 00636631  ffd2                 call edx
// 00636633  8b0f                 mov ecx, dword ptr [edi]
// 00636635  8b01                 mov eax, dword ptr [ecx]
// 00636637  8b4004               mov eax, dword ptr [eax + 4]
// 0063663a  8d542408             lea edx, [esp + 8]
// 0063663e  52                   push edx
// 0063663f  ffd0                 call eax
// 00636641  8d4c2408             lea ecx, [esp + 8]
// 00636645  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0063664d  e8ce48deff           call 0x41af20
// 00636652  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00636656  5f                   pop edi
// 00636657  64890d00000000       mov dword ptr fs:[0], ecx
// 0063665e  83c428               add esp, 0x28
// 00636661  c23000               ret 0x30

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Value
{
    char storage[48];
};

struct Element
{
    virtual ~Element();
};

struct Holder
{
    Element* value;
    Holder(const Value&);
    ~Holder();
    void swap(Holder&);
};

struct Container
{
    unsigned int storage[3];
    Holder* first;
    Holder* last;
    Holder* limit;

    Container(unsigned int);
    ~Container();
};

struct Receiver
{
    virtual ~Receiver();
    virtual void assign(const Container&);
};

struct S
{
    Receiver* receiver;
    void f(Value value);
};

inline void Holder::swap(Holder& other)
{
    if (this != &other)
    {
        Element* p = value;
        value = other.value;
        other.value = p;
    }
}

inline Holder::~Holder()
{
    if (value)
        delete value;
}

void S::f(Value value)
{
    Container items(1);

    if (static_cast<unsigned int>(items.last - items.first) <= 0)
        _invalid_parameter_noinfo();

    Holder* first = items.first;
    Holder(value).swap(*first);

    receiver->assign(items);
}
