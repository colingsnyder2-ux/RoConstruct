// from server: 100% by king_originala
struct Stopwatch {
    void start();
    void stop();
};

struct Context {
    char padding[0x58];
    Stopwatch stopwatch;
};

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual Context* getContext();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void update();
};

struct StopwatchScope {
    Stopwatch* stopwatch;

    StopwatchScope(Stopwatch* p) : stopwatch(p) {
        stopwatch->start();
    }

    ~StopwatchScope() {
        stopwatch->stop();
    }
};

struct CRobloxWnd {
    char padding0[0x8a];
    bool pending;
    char padding1[0x19];
    Interface* target;
    char padding2[8];
    Interface* source;

    void f();
};

void CRobloxWnd::f() {
    if (pending) {
        StopwatchScope scope(&source->getContext()->stopwatch);
        target->update();
        pending = false;
    }
}
