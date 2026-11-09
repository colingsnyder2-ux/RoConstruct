// from server: 72% by tester
struct EventDesc {
    char pad[8];
    void* obj;
    void* vtbl;
    void __cdecl invoke(float a, float b, float c, float d);
};

void EventDesc::invoke(float a, float b, float c, float d)
{
    if (obj != 0) {
        void** v = (void**)obj;
        void (*fn)(void*, float, float, float, float) = (void (*)(void*, float, float, float, float))v[0];
        fn(obj, d, c, b, a);
    }
}
