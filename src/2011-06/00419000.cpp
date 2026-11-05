// from server: 0% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl sub_418BD0(void* dst, void* src);

struct VValue {
    void* field0;
    void __thiscall construct(void* a, char b, int c, void* d, int e);
};

void VValue::construct(void* a, char b, int c, void* d, int e)
{
    void* p;
    field0 = 0;
    p = operator_new(0x38);
    if (p) {
        *(char*)p = 0;
        sub_418BD0(p, a);
    } else {
        p = 0;
    }
    field0 = p;
    if (b && d) {
        void* f = *(void**)d;
        if (f) {
            ((void (__stdcall*)(void*, int))f)(&e, 2);
        }
    }
}
