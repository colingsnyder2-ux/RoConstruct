// from server: 100% by tajop

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
