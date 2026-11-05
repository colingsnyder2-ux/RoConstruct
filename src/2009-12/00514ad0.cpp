// from server: 71% by atomic.potato
extern "C" void __stdcall G1_func_00514ae0(void*, void*);

struct S
{
    char padding[0x15c];
    void* field_15c;
    int f();
};

void* G1_global_00b7e4c4;

int S::f()
{
    if (field_15c)
    {
        void* p = (char*)field_15c + 0x1c;
        G1_func_00514ae0(*(void**)G1_global_00b7e4c4, p);
        return 1;
    }
    return 0;
}
