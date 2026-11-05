// from server: 40% by atomic.potato
struct T4_007063e0 {
    virtual void f0();
    virtual void f1(void*);
};

extern "C" void* __cdecl op_new(unsigned int);
extern "C" void __cdecl op_delete(void*);
extern "C" void __cdecl sub_4aa820(void*, int, void*);
extern "C" void __cdecl sub_80a058(void*);
extern "C" void* __cdecl sub_80a05e(unsigned int);

void T4_007063e0::f1(void* arg)
{
    void* p1 = 0;
    sub_4aa820(&p1, 2, (char*)this + 0);
    void* v1 = *(void**)((char*)&p1 + 4);
    void* n1 = sub_80a05e(8);
    if (n1) {
        *(void**)n1 = (void*)0xa8e758;
        *(void**)((char*)n1 + 4) = *(void**)v1;
    } else {
        n1 = 0;
    }
    void* old1 = *(void**)v1;
    if (&p1 != v1) {
        old1 = *(void**)v1;
        *(void**)v1 = n1;
    }
    if (old1) {
        (*(void (***)(int))old1)[0](1);
    }
    void* v2 = *(void**)((char*)&p1 + 4);
    void* n2 = sub_80a05e(8);
    if (n2) {
        *(void**)n2 = (void*)0xa5e9b0;
        *(float*)((char*)n2 + 4) = *(float*)v2;
    } else {
        n2 = 0;
    }
    void* old2 = *(void**)v2;
    if (&p1 != v2) {
        old2 = *(void**)v2;
        *(void**)v2 = n2;
    }
    if (old2) {
        (*(void (***)(int))old2)[0](1);
    }
    void* vt = *(void**)this;
    void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vt + 4);
    fn(this, (char*)&p1 + 4);
    void* start = *(void**)((char*)&p1 + 4);
    if (start) {
        void* end = *(void**)((char*)&p1 + 8);
        void* it = start;
        while (it != end) {
            void* o = *(void**)it;
            if (o) {
                (*(void (***)(int))o)[0](1);
            }
            it = (char*)it + 4;
        }
        sub_80a058(start);
    }
}
