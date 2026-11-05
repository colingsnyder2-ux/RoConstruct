// from server: 55% by atomic.potato
struct S_func_00964370 {
    virtual ~S_func_00964370();
    void f();
};

void S_func_00964370::f()
{
    S_func_00964370* p = this;
    S_func_00964370** link = (S_func_00964370**)((char*)this + 4);
    while (link != 0 && *link != 0) {
        S_func_00964370* node = *link;
        *link = *(S_func_00964370**)((char*)node + 4);
        *(S_func_00964370**)((char*)node + 4) = node;
        void (**vt)(void*) = *(void (***)(void*))node;
        vt[0]((void*)node);
    }
    if (p != 0) {
        void (**vt)(void*) = *(void (***)(void*))p;
        vt[0]((void*)p);
    }
}
