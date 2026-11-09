// from server: 74% by atomic.potato
extern "C" void* __cdecl sub_4C8390(void*);

struct VPlayersRefPropDescriptor {
    char pad[0x20];
    void* field20;
    void __thiscall set(void* a, void* b);
};

void VPlayersRefPropDescriptor::set(void* a, void* b)
{
    void* v;
    if (a) {
        v = sub_4C8390(a);
    } else {
        v = 0;
    }
    void* p = field20;
    void** vt = *(void***)p;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[4];
    fn(p, v, b);
}
