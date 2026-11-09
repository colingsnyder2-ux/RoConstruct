// from server: 61% by atomic.potato
extern "C" void call_98b6f0(void*);
extern "C" void call_520680(void*, int);
extern "C" void call_98b6e4(void*);

struct VCWorkspace_CComObject
{
    int f(int, void*, int);
};

int VCWorkspace_CComObject::f(int, void* source, int)
{
    call_98b6f0(source);
    call_520680(this, 0);
    call_98b6e4((char*)source + 8);
    return 0;
}
