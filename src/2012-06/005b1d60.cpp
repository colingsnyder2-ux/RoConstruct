// from server: 59% by atomic.potato
struct Vbase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
};

struct Vderived : Vbase {
    int pad[7];
    Vbase* ptr;
    virtual void dtor();
};

extern "C" void __stdcall exception_dtor(Vbase* p);

void Vderived::dtor()
{
    *(int*)((char*)this + 0x20) = 0xb43c34;
    *(int*)((char*)this) = 0xb7e5b0;
    *(int*)((char*)this + 0xc) = 0xb7e5a8;
    *(int*)((char*)this + 0xc) = 0xb43e60;
    Vbase* p = *(Vbase**)((char*)this + 0x10);
    if (p) {
        (*(void(**)(Vbase*))(*(int*)p + 0x10))(p);
    }
    *(int*)((char*)this) = 0xb42e94;
    exception_dtor((Vbase*)this);
}
