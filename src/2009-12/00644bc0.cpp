// from server: 55% by atomic.potato
struct VFaces_PropertyDescriptor {
    char pad[0x1c];
    void* field_1c;
    int get(void* a2, void* a3);
};

extern "C" int __cdecl sub_6b2b60(void* a1, void* a2);

int VFaces_PropertyDescriptor::get(void* a2, void* a3)
{
    void* v = 0;
    void* p = field_1c;
    void* vt = *(void**)p;
    int (*fn)(void*, void*, void**) = *(int (**)(void*, void*, void**))((char*)vt + 0xc);
    fn(p, a2, &v);
    sub_6b2b60(v, &v);
    return (int)v;
}
