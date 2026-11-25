// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 008f5f70  unit: RBX::TweenService  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008f5f70
//
// 008f5f70  6aff                 push -1
// 008f5f72  6888f6ac00           push 0xacf688
// 008f5f77  64a100000000         mov eax, dword ptr fs:[0]
// 008f5f7d  50                   push eax
// 008f5f7e  64892500000000       mov dword ptr fs:[0], esp
// 008f5f85  51                   push ecx
// 008f5f86  56                   push esi
// 008f5f87  8bf1                 mov esi, ecx
// 008f5f89  89742404             mov dword ptr [esp + 4], esi
// 008f5f8d  e81e02d9ff           call 0x6861b0
// 008f5f92  c706b4ffbe00         mov dword ptr [esi], 0xbeffb4
// 008f5f98  c74604acffbe00       mov dword ptr [esi + 4], 0xbeffac
// 008f5f9f  c74618a0ffbe00       mov dword ptr [esi + 0x18], 0xbeffa0
// 008f5fa6  c7461c94ffbe00       mov dword ptr [esi + 0x1c], 0xbeff94
// 008f5fad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008f5fb5  e876bfe8ff           call 0x781f30
// 008f5fba  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008f5fbe  894628               mov dword ptr [esi + 0x28], eax
// 008f5fc1  ff051c8ce400         inc dword ptr [0xe48c1c]
// 008f5fc7  8bc6                 mov eax, esi
// 008f5fc9  5e                   pop esi
// 008f5fca  64890d00000000       mov dword ptr fs:[0], ecx
// 008f5fd1  83c410               add esp, 0x10
// 008f5fd4  c3                   ret 


struct InstanceA {
    virtual void a0();
};

struct InstanceB {
    virtual void b0();
};

struct InstanceBase : InstanceA, InstanceB {
    InstanceBase();
    char pad[0x10];
};

struct __declspec(novtable) HeartbeatInstance {
    virtual void h0();
};

struct __declspec(novtable) IStepped {
    virtual void s0();
};

struct Holder {
    ~Holder();
    int p;
};

int fetchTweenToken();
extern int g_tweenServiceCount;

struct TweenService : InstanceBase, HeartbeatInstance, IStepped {
    int m20;
    Holder m24;
    int token;
    TweenService();
    virtual void a0();
    virtual void b0();
    virtual void h0();
    virtual void s0();
};

TweenService::TweenService()
    : token(fetchTweenToken())
{
    ++g_tweenServiceCount;
}
