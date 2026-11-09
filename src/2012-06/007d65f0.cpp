// from server: 45% by atomic.potato
extern "C" void* __cdecl sub_54bbf0(void*);

struct VPlayersRefPropDescriptor {
    char pad[0x2c];
    void* field_2c;
    void __thiscall set(void* a, void* b);
};

void VPlayersRefPropDescriptor::set(void* a, void* b)
{
    void* v = a ? sub_54bbf0(a) : 0;
    void* p = v;
    void* obj = field_2c;
    void* fn = *(void**)(*(char**)obj + 0xc);
    ((void (__thiscall*)(void*, void*, void*))fn)(obj, b, p);
}
