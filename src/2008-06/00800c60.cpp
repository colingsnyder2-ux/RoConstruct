// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { void f4(void*); };
extern "C" void reg_fn(void*, void*);
extern "C" void* make_fn(void);
extern "C" Obj* init_fn();
extern void (*g_cb)(void);
extern void fn_a();
extern void fn_b();
extern void fn_c();
void func_00800c60()
{
    g_cb = &fn_c;
    reg_fn(&fn_a, &fn_b);
    void* local = make_fn();
    init_fn()->f4(&local);
}
