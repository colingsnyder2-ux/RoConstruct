// from server: 100% by tajop
struct Ref {
    void* p;
    Ref(const Ref& o) : p(0) { set(o.p); }
    ~Ref();
    void set(void* v);
};

struct S {
    Ref r;
    int a;
    int b;
    int c;
    int d;
    S(int x, int y, const Ref& z);
    virtual ~S();
    void init(int x, int y);
};

S::S(int x, int y, const Ref& z) : r(z), a(0), b(0), c(0), d(0)
{
    init(x, y);
}
