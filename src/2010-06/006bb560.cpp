// from server: 47% by atomic.potato
struct S {
    void* field_1c;
    int f(void*, void*);
};

extern "C" void* sub_6bb3b0(void*, void*);

int S::f(void* a, void* b)
{
    void* edi = field_1c;
    void* esi = *(void**)edi;
    void* temp;
    void* value = sub_6bb3b0(b, &temp);
    esi = (char*)esi + 16;
    typedef int (__fastcall *Fn)(void*, void*, void*);
    return ((Fn)*(void**)esi)(edi, a, value);
}
