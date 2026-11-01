// from server: 100% by king_originala
struct Controller {
    virtual void setEnabled(int);
};

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
        char padding[0x3a4];
        Controller* controller;
    };

    class ServiceProvider {
    public:
        void update(int);
    };

    void handle(int, int);
}

RBX::ServiceProvider* __cdecl func_005807b0(RBX::Instance*);

struct S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int);

    char padding0[0x14];
    RBX::Instance* owner;
    char padding1[8];
    int target;
    char padding2[8];
    union {
        char local[16];
        char* heap;
    } text;
    unsigned int length;
    unsigned int capacity;

    int f(int);
};

int S::f(int argument)
{
    v3(argument);
    if (target) {
        v16(target);
        func_005807b0(owner)->update(8);
        RBX::handle(
            reinterpret_cast<int>(capacity >= 16 ? text.heap : text.local),
            reinterpret_cast<int>(owner));
        owner->controller->setEnabled(1);
    }
    return 0;
}
