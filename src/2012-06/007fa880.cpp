// from server: 100% by tajop

struct Mgr_007fa880 { void* a; void (*destroy)(void*); };
struct Fn_007fa880 {
    int x;
    Mgr_007fa880* mgr;
    char buf[60];
    Fn_007fa880(const Fn_007fa880&);
    ~Fn_007fa880() { if (mgr) mgr->destroy(buf); }
};
struct Key_007fa880 { int v; };
struct Sub_007fa880 {
    int v;
    void set(int a, int b, const Fn_007fa880& f);
};
int make_007fa880();
int get_007fa880();
int conv_007fa880(const Key_007fa880& k);
struct S_007fa880 {
    char pad[0x1c];
    Sub_007fa880 sub;
    void f(Key_007fa880 k, Fn_007fa880 fn);
};
void S_007fa880::f(Key_007fa880 k, Fn_007fa880 fn)
{
    sub.v = make_007fa880();
    int b = get_007fa880();
    sub.set(conv_007fa880(k), b, fn);
}
