// from server: 61% by atomic.potato
struct RefPropDescriptor {
    char pad[0x2c];
    void* field_2c;
    void set(void* a, void* b);
};

extern "C" void* __cdecl sub_8ddea0(void* p);

void RefPropDescriptor::set(void* a, void* b)
{
    void* v;
    if (a != 0) {
        v = sub_8ddea0(a);
    } else {
        v = 0;
    }
    void* p = field_2c;
    void* fn = *(void**)p;
    fn = *(void**)((char*)fn + 0xc);
    ((void (__stdcall*)(void*, void**))fn)(b, &v);
}
