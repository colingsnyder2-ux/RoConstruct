// from server: 51% by atomic.potato
extern "C" void *__cdecl msvc_string_assign(void *, const char *);

struct S_func_00665310
{
    char pad0[2748];
    void *f();
};

void *S_func_00665310::f()
{
    return msvc_string_assign((char *)this + 0xACC, "[[[progress]]]");
}
