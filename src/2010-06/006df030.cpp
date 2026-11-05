// from server: 30% by atomic.potato
extern "C" void* __stdcall make_desc_005b69c0(const char*, int);
extern "C" void __stdcall sub_005f5da0();
extern "C" void __stdcall sub_006def60();
extern "C" void __stdcall sub_007a799a();

struct S_006df030 {
    void* f(void* a, void* b, void* c, void* d, void* e, void* g, void* h);
};

void* S_006df030::f(void* a, void* b, void* c, void* d, void* e, void* g, void* h)
{
    void* tmp;
    void* result;
    void* desc;
    void* obj;

    desc = make_desc_005b69c0((const char*)&tmp, 0);
    obj = *(void**)desc;
    *(void**)desc = 0;
    tmp = obj;
    result = make_desc_005b69c0((const char*)&tmp, 0);
    sub_005f5da0();
    sub_007a799a();
    *(void**)this = (void*)0xa47b74;
    return this;
}
