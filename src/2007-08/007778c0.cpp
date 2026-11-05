// from server: 100% by colin
struct C {
    void* f();
    void g(int);
    void h(void*);
};

extern C obj_8bb8f8;

void func_007778c0()
{
    void* p = obj_8bb8f8.f();
    if (p != 0) {
        obj_8bb8f8.g(0);
        obj_8bb8f8.h(p);
    }
}
