// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct Obj { Obj* f4(); };
extern "C" __declspec(noinline) void __cdecl reg_fn(void*, void*);
extern "C" __declspec(noinline) void* __cdecl make_fn(void);
extern "C" __declspec(noinline) Obj* __stdcall init_fn(void*);
extern "C" __declspec(noinline) void __cdecl final_fn(int);
extern void* type_tag; extern int g_value; extern int final_arg;
extern void fn_a(); extern void fn_b();
void func_007f5510(){ void* local; reg_fn(&fn_a,&fn_b); local=make_fn(); Obj* o=init_fn(&local)->f4(); *(void**)o=&type_tag; g_value=0x29a; final_fn((int)&final_arg); }
