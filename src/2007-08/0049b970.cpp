// from server: 100% by EspClaude
// from server: 74% by EspClaude
// roc 2007-08 0049b970  unit: RBX::Network::VClient::?$FactoryProduct  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049b970
//
// 0049b970  6aff                 push -1
// 0049b972  68248e7400           push 0x748e24
// 0049b977  64a100000000         mov eax, dword ptr fs:[0]
// 0049b97d  50                   push eax
// 0049b97e  51                   push ecx
// 0049b97f  56                   push esi
// 0049b980  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049b985  33c4                 xor eax, esp
// 0049b987  50                   push eax
// 0049b988  8d44240c             lea eax, [esp + 0xc]
// 0049b98c  64a300000000         mov dword ptr fs:[0], eax
// 0049b992  8bf1                 mov esi, ecx
// 0049b994  89742408             mov dword ptr [esp + 8], esi
// 0049b998  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0049b99c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0049b9a0  50                   push eax
// 0049b9a1  51                   push ecx
// 0049b9a2  e809d8ffff           call 0x4991b0
// 0049b9a7  50                   push eax
// 0049b9a8  8bce                 mov ecx, esi
// 0049b9aa  e801540d00           call 0x570db0
// 0049b9af  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0049b9b3  8b442420             mov eax, dword ptr [esp + 0x20]
// 0049b9b7  8d4e30               lea ecx, [esi + 0x30]
// 0049b9ba  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0049b9c2  c706ccc47900         mov dword ptr [esi], 0x79c4cc
// 0049b9c8  895628               mov dword ptr [esi + 0x28], edx
// 0049b9cb  89462c               mov dword ptr [esi + 0x2c], eax
// 0049b9ce  e8ed190d00           call 0x56d3c0
// 0049b9d3  8d4e38               lea ecx, [esi + 0x38]
// 0049b9d6  c644241401           mov byte ptr [esp + 0x14], 1
// 0049b9db  e8e0190d00           call 0x56d3c0
// 0049b9e0  8d4e40               lea ecx, [esi + 0x40]
// 0049b9e3  c644241402           mov byte ptr [esp + 0x14], 2
// 0049b9e8  e8d3190d00           call 0x56d3c0
// 0049b9ed  c644241403           mov byte ptr [esp + 0x14], 3
// 0049b9f2  e8d91d0d00           call 0x56d7d0
// 0049b9f7  6a08                 push 8
// 0049b9f9  894648               mov dword ptr [esi + 0x48], eax
// 0049b9fc  e8f5441900           call 0x62fef6
// 0049ba01  83c404               add esp, 4
// 0049ba04  85c0                 test eax, eax
// 0049ba06  740f                 je 0x49ba17
// 0049ba08  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0049ba0c  c70098717800         mov dword ptr [eax], 0x787198
// 0049ba12  894804               mov dword ptr [eax + 4], ecx
// 0049ba15  eb02                 jmp 0x49ba19
// 0049ba17  33c0                 xor eax, eax
// 0049ba19  89464c               mov dword ptr [esi + 0x4c], eax
// 0049ba1c  8b542434             mov edx, dword ptr [esp + 0x34]
// 0049ba20  8b442430             mov eax, dword ptr [esp + 0x30]
// 0049ba24  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0049ba28  52                   push edx
// 0049ba29  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0049ba2d  50                   push eax
// 0049ba2e  51                   push ecx
// 0049ba2f  52                   push edx
// 0049ba30  8bce                 mov ecx, esi
// 0049ba32  c644242404           mov byte ptr [esp + 0x24], 4
// 0049ba37  e8f4d9ffff           call 0x499430
// 0049ba3c  8bc6                 mov eax, esi
// 0049ba3e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049ba42  64890d00000000       mov dword ptr fs:[0], ecx
// 0049ba49  59                   pop ecx
// 0049ba4a  5e                   pop esi
// 0049ba4b  83c410               add esp, 0x10
// 0049ba4e  c22400               ret 0x24

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
    unsigned char storage[36];
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
    Value value3;
    Property property1;

    S(int, int, int, int, int, int, int, int, int);
    virtual ~S();
    void initialize(int, int, int, int);
};

S::S(int a1, int a2, int a3, int a4, int a5,
     int a6, int a7, int a8, int a9)
    : Base(getSettings(a3, a9)),
      first(a1),
      second(a2),
      property1(a8)
{
    initialize(a4, a5, a6, a7);
}
