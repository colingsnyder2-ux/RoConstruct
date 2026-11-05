// from server: 28% by atomic.potato
extern "C" void* __cdecl sub_7A79A0(unsigned int);

struct C6C3D30 {
    void f();
};

struct C5BA540 {
    void f(void*, void*);
};

struct VDebrisService {
    void* __cdecl FactoryProduct_Creator(void* a2);
};

void* VDebrisService::FactoryProduct_Creator(void* a2)
{
    void* p = sub_7A79A0(0xB4);
    void* q = 0;
    if (p) {
        ((C6C3D30*)p)->f();
        q = p;
    }
    ((C5BA540*)this)->f(q, a2);
    return this;
}
