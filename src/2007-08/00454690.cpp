// from server: 30% by colin
struct EventData {
    char pad0[4];
    int field4;
    char pad8[4];
    void* fieldC;
    char pad10[4];
    void destroy();
};

extern "C" void __stdcall sub_437B80(void*);
extern "C" void __stdcall sub_4A6C60(void*, void*);

void EventData::destroy()
{
    if (fieldC) {
        sub_437B80(this);
        sub_4A6C60(&fieldC, this + 0x10);
        void** vtbl = *(void***)fieldC;
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[2];
        fn(fieldC, field4);
    }
}
