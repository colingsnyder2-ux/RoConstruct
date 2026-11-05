// from server: 91% by atomic.potato
extern "C" void __cdecl release_resource(void*);

struct S
{
    int pad0;
    int pad4;
    void* resource;
    int padC;
    int pad10;
    void f(void*);
};

void S::f(void*)
{
    if (resource)
        release_resource(resource);
    resource = 0;
    padC = 0;
    pad10 = 0;
}
