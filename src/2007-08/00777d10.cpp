// from server: 100% by colin
struct C {
    void* f();
    void g(int);
    void h(void*);
};

extern C obj_8bbea4;

void func_00777d10()
{
    void* p = obj_8bbea4.f();
    if (p != 0) {
        obj_8bbea4.g(0);
        obj_8bbea4.h(p);
    }
}
