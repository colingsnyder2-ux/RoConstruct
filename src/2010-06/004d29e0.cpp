// from server: 27% by atomic.potato
struct S_func_0070b5e0 {
    void* f();
};

struct S_func_004d29e0 {
    void f();
};

void S_func_004d29e0::f()
{
    char buf[16];
    S_func_0070b5e0 tmp;
    tmp.f();
    char b = 0;
    char c = b;
    void* p = *(void**)((char*)this + 4);
    (*(void(__thiscall**)(void*))p)(p);
}
