// from server: 45% by atomic.potato
struct VWorkspaceRefPropDescriptor {
    char pad0[0x2c];
    void* field_2c;
    void assign(void* a, void* b);
};

extern "C" void* __cdecl sub_725de0(void* p);

void VWorkspaceRefPropDescriptor::assign(void* a, void* b)
{
    void* v;
    if (a) {
        v = sub_725de0(a);
    } else {
        v = 0;
    }
    void* p = field_2c;
    void* fn = *(void**)p;
    fn = *(void**)((char*)fn + 0xc);
    ((void (__stdcall*)(void*, void*))fn)(b, v);
}
