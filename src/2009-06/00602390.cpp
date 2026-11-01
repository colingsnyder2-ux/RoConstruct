// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00578ef0  unit: RBX::VDataModel::?$SignalDesc  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00578ef0
//
// 00578ef0  51                   push ecx
// 00578ef1  56                   push esi
// 00578ef2  8bf1                 mov esi, ecx
// 00578ef4  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00578efa  6a00                 push 0
// 00578efc  e8bf900200           call 0x5a1fc0
// 00578f01  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00578f07  e8c420feff           call 0x55afd0
// 00578f0c  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00578f12  6a00                 push 0
// 00578f14  e8e7c20200           call 0x5a5200
// 00578f19  8b8e14020000         mov ecx, dword ptr [esi + 0x214]
// 00578f1f  e8ac20feff           call 0x55afd0
// 00578f24  8bce                 mov ecx, esi
// 00578f26  e85516f2ff           call 0x49a580
// 00578f2b  85c0                 test eax, eax
// 00578f2d  7407                 je 0x578f36
// 00578f2f  8bc8                 mov ecx, eax
// 00578f31  e89a20feff           call 0x55afd0
// 00578f36  8bce                 mov ecx, esi
// 00578f38  e8f37cf1ff           call 0x490c30
// 00578f3d  85c0                 test eax, eax
// 00578f3f  7407                 je 0x578f48
// 00578f41  8bc8                 mov ecx, eax
// 00578f43  e8d8930500           call 0x5d2320
// 00578f48  8bce                 mov ecx, esi
// 00578f4a  e8b19aedff           call 0x452a00
// 00578f4f  85c0                 test eax, eax
// 00578f51  7407                 je 0x578f5a
// 00578f53  8bc8                 mov ecx, eax
// 00578f55  e866340100           call 0x58c3c0
// 00578f5a  8bce                 mov ecx, esi
// 00578f5c  e81fa4f3ff           call 0x4b3380
// 00578f61  85c0                 test eax, eax
// 00578f63  7407                 je 0x578f6c
// 00578f65  8bc8                 mov ecx, eax
// 00578f67  e86420feff           call 0x55afd0
// 00578f6c  8bce                 mov ecx, esi
// 00578f6e  e81d4febff           call 0x42de90
// 00578f73  8bf0                 mov esi, eax
// 00578f75  85f6                 test esi, esi
// 00578f77  7422                 je 0x578f9b
// 00578f79  8bce                 mov ecx, esi
// 00578f7b  e800530300           call 0x5ae280
// 00578f80  8b0d946b9700         mov ecx, dword ptr [0x976b94]
// 00578f86  8d4614               lea eax, [esi + 0x14]
// 00578f89  8d742407             lea esi, [esp + 7]
// 00578f8d  c644240700           mov byte ptr [esp + 7], 0
// 00578f92  8b11                 mov edx, dword ptr [ecx]
// 00578f94  56                   push esi
// 00578f95  50                   push eax
// 00578f96  8b420c               mov eax, dword ptr [edx + 0xc]
// 00578f99  ffd0                 call eax
// 00578f9b  5e                   pop esi
// 00578f9c  59                   pop ecx
// 00578f9d  c3                   ret 

struct Object
{
    char padding[24];
    char value;

    void setFirst(int);
    void clear();
    void setSecond(int);
    void update();
    void stop();
    void finish();
};

struct Dispatcher
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void dispatch(void*, const bool&);
};

struct Pair
{
    void* v;
    bool f;
};

extern Dispatcher* dispatcher;

struct S
{
    char padding[0x20c];
    Object* first;
    char gap[12];
    Object* second;

    Object* getFirst();
    Object* getSecond();
    Object* getThird();
    Object* getFourth();
    Object* getLast();
    void f();
};

void S::f()
{
    first->setFirst(0);
    first->clear();
    first->setSecond(0);
    second->clear();

    Object* p = getFirst();
    if (p)
        p->clear();

    p = getSecond();
    if (p)
        p->update();

    p = getThird();
    if (p)
        p->stop();

    p = getFourth();
    if (p)
        p->clear();

    p = getLast();
    if (p)
    {
        p->finish();
        Pair pr = { &p->value, false };
        void* value = pr.v;
        bool flag = pr.f;
        dispatcher->dispatch(value, flag);
    }
}
