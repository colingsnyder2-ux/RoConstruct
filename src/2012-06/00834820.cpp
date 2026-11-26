// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Target { virtual void v0(); virtual void v1(); virtual void v2(); virtual void call(int, int); };
struct Checker { bool check(int token); };
struct Impl { char pad[0x20]; Checker* checker; char pad2[4]; Target* target; };
struct AsyncResult {
    Impl* impl;
    int field4;
    void returnResult(int arg);
};
extern "C" int __cdecl getToken();
extern "C" void __cdecl failAssert(int, const char*);
extern unsigned char g_flag;
extern char (__cdecl *g_handler)(const char*, const char*, int);
extern const char g_expr[];
extern const char g_file[];
extern const char g_msg[];
void AsyncResult::returnResult(int arg)
{
    if (g_flag) {
        if (!impl->checker->check(getToken())) {
            if (!g_handler || !g_handler(g_expr, g_file, 0x133))
                failAssert(g_flag, g_msg);
        }
    }
    impl->target->call(field4, arg);
}
