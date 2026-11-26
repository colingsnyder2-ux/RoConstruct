// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Iter {
    void* cur;
    Iter() : cur(0) {}
    ~Iter();
};
struct E { int x; };
struct HC {
    bool next(Iter* it);
    void handle(E* e);
    void process(void* arg);
};
extern unsigned char g_flag;
extern void __cdecl assertFail(int, const char*, int);
extern void __cdecl visit(void* item, void* arg);
extern const char g_msg[];
void HC::process(void* arg)
{
    Iter it;
    if (g_flag)
        assertFail(g_flag, g_msg, 0);
    for (;;) {
        try {
            while (next(&it))
                visit(it.cur, arg);
            break;
        } catch (E& e) {
            handle(&e);
        }
    }
}
