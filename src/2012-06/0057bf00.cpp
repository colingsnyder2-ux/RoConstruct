// from server: 73% by atomic.potato
struct P_579fc0
{
    int value;
};

extern "C" P_579fc0* __cdecl func_579fc0(void*);
extern "C" void __cdecl func_56c980(void*, void*, void*);

void func_0057bf00(void* a, void* b, void* c, void* d)
{
    P_579fc0* p = func_579fc0((char*)a + 4);
    void* value = (void*)p->value;
    func_56c980(c, b, value);
}
