// from server: 100% by colin
// from server: 96% by king_originala
// roc 2008-06 00643e00  unit: RBX::HUMAN::HumanoidState  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00643e00
//
// 00643e00  6aff                 push -1
// 00643e02  6846ac7d00           push 0x7dac46
// 00643e07  64a100000000         mov eax, dword ptr fs:[0]
// 00643e0d  50                   push eax
// 00643e0e  64892500000000       mov dword ptr fs:[0], esp
// 00643e15  51                   push ecx
// 00643e16  d9ee                 fldz 
// 00643e18  53                   push ebx
// 00643e19  56                   push esi
// 00643e1a  8bf1                 mov esi, ecx
// 00643e1c  c74604403a8400       mov dword ptr [esi + 4], 0x843a40
// 00643e23  d9560c               fst dword ptr [esi + 0xc]
// 00643e26  33db                 xor ebx, ebx
// 00643e28  57                   push edi
// 00643e29  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00643e2d  c70600ad8400         mov dword ptr [esi], 0x84ad00
// 00643e33  c74604f8ac8400       mov dword ptr [esi + 4], 0x84acf8
// 00643e3a  897e08               mov dword ptr [esi + 8], edi
// 00643e3d  885e10               mov byte ptr [esi + 0x10], bl
// 00643e40  885e11               mov byte ptr [esi + 0x11], bl
// 00643e43  8974240c             mov dword ptr [esp + 0xc], esi
// 00643e47  895e18               mov dword ptr [esi + 0x18], ebx
// 00643e4a  895e1c               mov dword ptr [esi + 0x1c], ebx
// 00643e4d  895e14               mov dword ptr [esi + 0x14], ebx
// 00643e50  895e24               mov dword ptr [esi + 0x24], ebx
// 00643e53  895c2418             mov dword ptr [esp + 0x18], ebx
// 00643e57  895e28               mov dword ptr [esi + 0x28], ebx
// 00643e5a  d9562c               fst dword ptr [esi + 0x2c]
// 00643e5d  d95630               fst dword ptr [esi + 0x30]
// 00643e60  8d4e40               lea ecx, [esi + 0x40]
// 00643e63  d95634               fst dword ptr [esi + 0x34]
// 00643e66  c644241801           mov byte ptr [esp + 0x18], 1
// 00643e6b  d95638               fst dword ptr [esi + 0x38]
// 00643e6e  d95e3c               fstp dword ptr [esi + 0x3c]
// 00643e71  e85a44e3ff           call 0x4782d0
// 00643e76  8d4e70               lea ecx, [esi + 0x70]
// 00643e79  e85244e3ff           call 0x4782d0
// 00643e7e  53                   push ebx
// 00643e7f  8bcf                 mov ecx, edi
// 00643e81  e8ea83f9ff           call 0x5dc270
// 00643e86  53                   push ebx
// 00643e87  8bcf                 mov ecx, edi
// 00643e89  e8a283f9ff           call 0x5dc230
// 00643e8e  53                   push ebx
// 00643e8f  8bce                 mov ecx, esi
// 00643e91  e81af3ffff           call 0x6431b0
// 00643e96  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00643e9a  5f                   pop edi
// 00643e9b  8bc6                 mov eax, esi
// 00643e9d  5e                   pop esi
// 00643e9e  5b                   pop ebx
// 00643e9f  64890d00000000       mov dword ptr fs:[0], ecx
// 00643ea6  83c410               add esp, 0x10
// 00643ea9  c20400               ret 4

struct Object
{
    void func_005dc270(bool value);
    void func_005dc230(bool value);
};

struct __declspec(novtable) A
{
    virtual void a();
};

struct B
{
    virtual void b();
};

struct Storage
{
    void* first;
    void* last;
    void* end;

    Storage();
    ~Storage();
};

__forceinline Storage::Storage()
{
    last = 0;
    end = 0;
    first = 0;
}

struct Count
{
    void* pi;
    Count() : pi(0) {}
    ~Count();
};

struct Reference
{
    void* object;
    Count control;

    Reference() : object(0) {}
};

struct Item
{
    char data[0x30];

    Item();
};

struct HumanoidState : A, B
{
    Object* object;
    float value;
    bool flag1;
    bool flag2;
    Storage storage;
    unsigned int unused;
    Reference reference;
    float a;
    float b;
    float c;
    float d;
    float e;
    Item item1;
    Item item2;

    HumanoidState(Object* object);
    void func_006431b0(bool value);
};

HumanoidState::HumanoidState(Object* p)
    : object(p), value(0.0f), flag1(false), flag2(false), storage(), reference(),
      a(0.0f), b(0.0f), c(0.0f), d(0.0f), e(0.0f),
      item1(), item2()
{
    p->func_005dc270(false);
    p->func_005dc230(false);
    func_006431b0(false);
}
