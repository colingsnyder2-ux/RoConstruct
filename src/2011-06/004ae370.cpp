// from server: 32% by atomic.potato
extern "C" {
int __stdcall G1_func_00a40a50();
void* __stdcall G1_func_004aaf60();
void __stdcall G1_func_005bd1e0();
}

struct VPlayerRefPropDescriptor {
    void* vfptr;
    void* field4;
    int get(void* out);
};

int VPlayerRefPropDescriptor::get(void* out)
{
    void* p = *(void**)this;
    int (*fn)(void*) = *(int (**)(void*))((char*)p + 8);
    if (G1_func_00a40a50()) {
        void* r = (void*)G1_func_004aaf60();
        *(int*)out = *(int*)r;
        return (int)out;
    }
    void* a = *(void**)((char*)this + 4);
    void* b = *(void**)this;
    void* saved = b;
    void* res;
    if (a) {
        int (*f2)(void*) = *(int (**)(void*))((char*)*(void**)a + 8);
        res = (void*)f2(a);
    } else {
        res = 0;
    }
    void* tmp = res;
    G1_func_005bd1e0();
    *(int*)out = *(int*)tmp;
    if (tmp) {
        int (*f3)(void*, int) = *(int (**)(void*, int))*(void**)tmp;
        f3(tmp, 1);
    }
    return (int)out;
}
