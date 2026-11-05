// from server: 28% by colin
struct EventData {
    char pad0[4];
    int field4;
    char pad8[4];
    int fieldC;
    int field10;
    void (__stdcall *dtor)(void*);
    void destroy();
};

void __stdcall sub_437b80(void*);

void EventData::destroy()
{
    if (fieldC != 0) {
        sub_437b80(this);
        int e = field10;
        int a = field4;
        int c = fieldC;
        void** vt = (void**)c;
        void (__stdcall *fn)(int, int) = (void (__stdcall *)(int, int))vt[2];
        fn(a, e);
    }
}
