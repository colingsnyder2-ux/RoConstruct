// from server: 30% by atomic.potato
struct S_func_0057be80 {
    void __cdecl f(int a, int b);
};

extern "C" void* __cdecl sub_00579ea0(void*);
extern "C" void __cdecl sub_0056c8c0(void*, void*);

void S_func_0057be80::f(int a, int b)
{
    char* p = (char*)sub_00579ea0((char*)a + 4);
    int v0 = *(int*)p;
    int v1 = *(int*)(p + 4);
    sub_0056c8c0((void*)b, &v0);
}
