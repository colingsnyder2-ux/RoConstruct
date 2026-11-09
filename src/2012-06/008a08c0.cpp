// from server: 61% by atomic.potato
struct VMouseRefPropDescriptor {
    char pad[0x2c];
    void* field2c;
    void sub_8a08c0(void* a, void* b);
};

extern "C" void* __cdecl sub_8a0870(void* p);

void VMouseRefPropDescriptor::sub_8a08c0(void* a, void* b)
{
    void* v;
    if (a)
        v = sub_8a0870(a);
    else
        v = 0;
    void* p = field2c;
    void* f = *(void**)(*(char**)p + 0xc);
    ((void (__stdcall*)(void*, void**))f)(b, &v);
}
