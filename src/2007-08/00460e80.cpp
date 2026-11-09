// from server: 26% by colin
struct EventData {
    char pad0[4];
    int field4;
    char pad8[4];
    int fieldC;
    int field10;
    int field14;
    void destroy();
};

extern "C" void __stdcall sub_437B80(void*);

void EventData::destroy()
{
    if (fieldC) {
        sub_437B80(this);
        int a = field10;
        int b = field14;
        void* obj = (void*)field4;
        int* vt = (int*)fieldC;
        void (*fn)(void*, int, int) = (void (*)(void*, int, int))vt[2];
        fn(obj, a, b);
    }
}
