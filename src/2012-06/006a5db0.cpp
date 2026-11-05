// from server: 100% by tajop
struct Ptr {
    int p;
    Ptr() : p(0) {}
    ~Ptr();
};

struct Holder {
    int a;
    int b;
    Holder() : a(0), b(0) {}
    ~Holder();
};

extern long g_once;
void g_once_init();
void call_once(long& flag, void (*f)());

struct ThreadRef {
    Ptr liveThreadRef;
    ThreadRef();
};

ThreadRef::ThreadRef() {
    call_once(g_once, g_once_init);
    static Holder holder;
}
