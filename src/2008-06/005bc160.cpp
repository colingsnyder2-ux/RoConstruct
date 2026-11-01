// from server: 100% by EspClaude
// from server: 67% by king_originala
// roc 2008-06 005bc160  unit: RBX::Soundscape::VSoundChannel::?$BoundFuncDesc  size: 348 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bc160
//
// 005bc160  6aff                 push -1
// 005bc162  68293d7d00           push 0x7d3d29
// 005bc167  64a100000000         mov eax, dword ptr fs:[0]
// 005bc16d  50                   push eax
// 005bc16e  64892500000000       mov dword ptr fs:[0], esp
// 005bc175  83ec24               sub esp, 0x24
// 005bc178  53                   push ebx
// 005bc179  56                   push esi
// 005bc17a  8bf1                 mov esi, ecx
// 005bc17c  8974240c             mov dword ptr [esp + 0xc], esi
// 005bc180  e83bfdffff           call 0x5bbec0
// 005bc185  8d44240b             lea eax, [esp + 0xb]
// 005bc189  33db                 xor ebx, ebx
// 005bc18b  50                   push eax
// 005bc18c  8d54240f             lea edx, [esp + 0xf]
// 005bc190  8d8e3c010000         lea ecx, [esi + 0x13c]
// 005bc196  52                   push edx
// 005bc197  895c243c             mov dword ptr [esp + 0x3c], ebx
// 005bc19b  c706d47a8300         mov dword ptr [esi], 0x837ad4
// 005bc1a1  c74610c87a8300       mov dword ptr [esi + 0x10], 0x837ac8
// 005bc1a8  c74614c07a8300       mov dword ptr [esi + 0x14], 0x837ac0
// 005bc1af  c74620b87a8300       mov dword ptr [esi + 0x20], 0x837ab8
// 005bc1b6  c74624a87a8300       mov dword ptr [esi + 0x24], 0x837aa8
// 005bc1bd  c74644987a8300       mov dword ptr [esi + 0x44], 0x837a98
// 005bc1c4  c74664887a8300       mov dword ptr [esi + 0x64], 0x837a88
// 005bc1cb  c78684000000787a8300 mov dword ptr [esi + 0x84], 0x837a78
// 005bc1d5  c786a4000000687a8300 mov dword ptr [esi + 0xa4], 0x837a68
// 005bc1df  c786c4000000587a8300 mov dword ptr [esi + 0xc4], 0x837a58
// 005bc1e9  c786300100004c7a8300 mov dword ptr [esi + 0x130], 0x837a4c
// 005bc1f3  899e34010000         mov dword ptr [esi + 0x134], ebx
// 005bc1f9  899e38010000         mov dword ptr [esi + 0x138], ebx
// 005bc1ff  e88ccffcff           call 0x589190
// 005bc204  d9e8                 fld1 
// 005bc206  d9965c010000         fst dword ptr [esi + 0x15c]
// 005bc20c  d90590748200         fld dword ptr [0x827490]
// 005bc212  d99e60010000         fstp dword ptr [esi + 0x160]
// 005bc218  d99e64010000         fstp dword ptr [esi + 0x164]
// 005bc21e  899e68010000         mov dword ptr [esi + 0x168], ebx
// 005bc224  899e6c010000         mov dword ptr [esi + 0x16c], ebx
// 005bc22a  c644243402           mov byte ptr [esp + 0x34], 2
// 005bc22f  899e70010000         mov dword ptr [esi + 0x170], ebx
// 005bc235  e896c1f4ff           call 0x5083d0
// 005bc23a  dd9e78010000         fstp qword ptr [esi + 0x178]
// 005bc240  8d44240b             lea eax, [esp + 0xb]
// 005bc244  50                   push eax
// 005bc245  8d54240f             lea edx, [esp + 0xf]
// 005bc249  8d8e80010000         lea ecx, [esi + 0x180]
// 005bc24f  52                   push edx
// 005bc250  e88b580b00           call 0x671ae0
// 005bc255  8d44240b             lea eax, [esp + 0xb]
// 005bc259  50                   push eax
// 005bc25a  8d54240f             lea edx, [esp + 0xf]
// 005bc25e  8d8ea0010000         lea ecx, [esi + 0x1a0]
// 005bc264  52                   push edx
// 005bc265  c644243c03           mov byte ptr [esp + 0x3c], 3
// 005bc26a  e871580b00           call 0x671ae0
// 005bc26f  68907e8300           push 0x837e90
// 005bc274  8d4c2414             lea ecx, [esp + 0x14]
// 005bc278  c644243804           mov byte ptr [esp + 0x38], 4
// 005bc27d  889ec0010000         mov byte ptr [esi + 0x1c0], bl
// 005bc283  ff1558248000         call dword ptr [0x802458]
// 005bc289  8d442410             lea eax, [esp + 0x10]
// 005bc28d  50                   push eax
// 005bc28e  8bce                 mov ecx, esi
// 005bc290  c644243805           mov byte ptr [esp + 0x38], 5
// 005bc295  e8f6ecf9ff           call 0x55af90
// 005bc29a  8d4c2410             lea ecx, [esp + 0x10]
// 005bc29e  c644243404           mov byte ptr [esp + 0x34], 4
// 005bc2a3  ff1568248000         call dword ptr [0x802468]
// 005bc2a9  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005bc2ad  8bc6                 mov eax, esi
// 005bc2af  5e                   pop esi
// 005bc2b0  5b                   pop ebx
// 005bc2b1  64890d00000000       mov dword ptr fs:[0], ecx
// 005bc2b8  83c430               add esp, 0x30
// 005bc2bb  c3                   ret 

#include <map>
#include <set>

struct B0 { virtual void v0(); char pad[12]; };
struct B1 { virtual void v1(); };
struct B2 { virtual void v2(); char pad[8]; };
struct B3 { virtual void v3(); };
struct B4 { virtual void v4(); char pad[28]; };
struct B5 { virtual void v5(); char pad[28]; };
struct B6 { virtual void v6(); char pad[28]; };
struct B7 { virtual void v7(); char pad[28]; };
struct B8 { virtual void v8(); char pad[28]; };
struct B9 { virtual void v9(); char pad[104]; };
struct B10 { virtual void v10(); };

struct Base : B0, B1, B2, B3, B4, B5, B6, B7, B8, B9, B10 {
    Base();
    ~Base();
};

struct Empty { Empty() {} };

struct Pair {
    void* object;
    void* control;
    Pair() : object(0), control(0) {}
};

struct Container {
    std::map<int, int> inner;
    Container() {}
    ~Container();
};

struct Triple {
    unsigned int a, b;
    Triple() : a(0), b(0) {}
    ~Triple();
};

struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char data[28];
    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

extern float initialValue;
extern double __cdecl currentTime();

struct S : Base {
    void* object;
    void* control;
    std::map<int, int> container;
    float first;
    float second;
    float third;
    Triple ab;
    unsigned int c;
    double time;
    std::set<int> collection1;
    std::set<int> collection2;
    bool enabled;

    S();
    void setName(const String&);

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

S::S()
    : Base(),
      object(0),
      control(0),
      container(),
      first(1.0f),
      second(initialValue),
      third(1.0f),
      ab(),
      c(0),
      time(currentTime()),
      collection1(),
      collection2(),
      enabled(false)
{
    String name("Soundscape");
    setName(name);
}
