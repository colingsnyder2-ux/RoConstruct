// from server: 81% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a03b0  unit: RBX::Network::VClient::?$FactoryProduct  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a03b0
//
// 004a03b0  6aff                 push -1
// 004a03b2  68f4787c00           push 0x7c78f4
// 004a03b7  64a100000000         mov eax, dword ptr fs:[0]
// 004a03bd  50                   push eax
// 004a03be  64892500000000       mov dword ptr fs:[0], esp
// 004a03c5  51                   push ecx
// 004a03c6  8b442438             mov eax, dword ptr [esp + 0x38]
// 004a03ca  56                   push esi
// 004a03cb  8bf1                 mov esi, ecx
// 004a03cd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a03d1  50                   push eax
// 004a03d2  51                   push ecx
// 004a03d3  8974240c             mov dword ptr [esp + 0xc], esi
// 004a03d7  e854e7ffff           call 0x49eb30
// 004a03dc  50                   push eax
// 004a03dd  8bce                 mov ecx, esi
// 004a03df  e8ac530f00           call 0x595790
// 004a03e4  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a03e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a03ec  8d4e40               lea ecx, [esi + 0x40]
// 004a03ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004a03f7  c706e0308200         mov dword ptr [esi], 0x8230e0
// 004a03fd  895638               mov dword ptr [esi + 0x38], edx
// 004a0400  89463c               mov dword ptr [esi + 0x3c], eax
// 004a0403  e8b8460f00           call 0x594ac0
// 004a0408  8d4e48               lea ecx, [esi + 0x48]
// 004a040b  c644241001           mov byte ptr [esp + 0x10], 1
// 004a0410  e8ab460f00           call 0x594ac0
// 004a0415  c644241002           mov byte ptr [esp + 0x10], 2
// 004a041a  e8a1c70c00           call 0x56cbc0
// 004a041f  6a08                 push 8
// 004a0421  894650               mov dword ptr [esi + 0x50], eax
// 004a0424  e8f7042000           call 0x6a0920
// 004a0429  83c404               add esp, 4
// 004a042c  85c0                 test eax, eax
// 004a042e  740f                 je 0x4a043f
// 004a0430  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004a0434  c700cc068100         mov dword ptr [eax], 0x8106cc
// 004a043a  894804               mov dword ptr [eax + 4], ecx
// 004a043d  eb02                 jmp 0x4a0441
// 004a043f  33c0                 xor eax, eax
// 004a0441  894654               mov dword ptr [esi + 0x54], eax
// 004a0444  c644241003           mov byte ptr [esp + 0x10], 3
// 004a0449  e872c70c00           call 0x56cbc0
// 004a044e  6a08                 push 8
// 004a0450  894658               mov dword ptr [esi + 0x58], eax
// 004a0453  e8c8042000           call 0x6a0920
// 004a0458  83c404               add esp, 4
// 004a045b  85c0                 test eax, eax
// 004a045d  740f                 je 0x4a046e
// 004a045f  8b542438             mov edx, dword ptr [esp + 0x38]
// 004a0463  c700cc068100         mov dword ptr [eax], 0x8106cc
// 004a0469  895004               mov dword ptr [eax + 4], edx
// 004a046c  eb02                 jmp 0x4a0470
// 004a046e  33c0                 xor eax, eax
// 004a0470  89465c               mov dword ptr [esi + 0x5c], eax
// 004a0473  8b442434             mov eax, dword ptr [esp + 0x34]
// 004a0477  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004a047b  8b542428             mov edx, dword ptr [esp + 0x28]
// 004a047f  50                   push eax
// 004a0480  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a0484  51                   push ecx
// 004a0485  52                   push edx
// 004a0486  50                   push eax
// 004a0487  8bce                 mov ecx, esi
// 004a0489  c644242004           mov byte ptr [esp + 0x20], 4
// 004a048e  e8bde9ffff           call 0x49ee50
// 004a0493  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a0497  8bc6                 mov eax, esi
// 004a0499  5e                   pop esi
// 004a049a  64890d00000000       mov dword ptr fs:[0], ecx
// 004a04a1  83c410               add esp, 0x10
// 004a04a4  c22800               ret 0x28

typedef unsigned int size_t;

void *__cdecl operator new(size_t);
extern "C" void *__stdcall getSettings(int, int);
extern "C" void *__cdecl getType();

struct Base {
    unsigned char storage[52];
    Base(void *);
    virtual ~Base();
};

struct Value {
    void *type;
    void *data;
    Value();
    ~Value();
};

struct Holder {
    int value;
    Holder(int);
    virtual ~Holder();
};

inline Holder::Holder(int v) : value(v) {}

struct Property {
    void *type;
    Holder *holder;
    Property(int);
    ~Property();
};

inline Property::Property(int v)
    : type(getType()), holder(new Holder(v)) {}

struct S : Base {
    int first;
    int second;
    Value value1;
    Value value2;
    Property property1;
    Property property2;

    S(int, int, int, int, int, int, int, int, int, int);
    virtual ~S();
    void initialize(int, int, int, int);
};

S::S(int a1, int a2, int a3, int a4, int a5,
     int a6, int a7, int a8, int a9, int a10)
    : Base(getSettings(a3, a10)),
      first(a1),
      second(a2),
      property1(a7),
      property2(a9)
{
    initialize(a4, a5, a6, a8);
}
