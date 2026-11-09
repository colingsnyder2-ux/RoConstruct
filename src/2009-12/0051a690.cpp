// from server: 74% by atomic.potato
struct VPlayersRefPropDescriptor {
    char pad[0x20];
    void* field20;
    void SetValue(void* value, int arg);
};

extern "C" void* __cdecl sub_509730(void* p);

void VPlayersRefPropDescriptor::SetValue(void* value, int arg)
{
    void* v;
    if (value != 0) {
        v = sub_509730(value);
    } else {
        v = 0;
    }
    void* obj = field20;
    void** vtbl = *(void***)obj;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl[4];
    fn(obj, v, (void*)arg);
}
