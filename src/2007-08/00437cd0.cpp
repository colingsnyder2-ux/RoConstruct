// from server: 35% by colin
struct EventData {
    char pad0[0xc];
    void* field_c;
    int field_10;
    char field_14[0x1c];
    int field_30;
    int field_34;
    int field_4;
    void method_437b80();
    void method_437cd0();
};

extern "C" void __stdcall sub_77e69c(void*, void*);

void EventData::method_437cd0()
{
    if (field_c != 0) {
        method_437b80();
        int a = field_10;
        char buf[0x28];
        sub_77e69c(buf + 4, &field_14);
        *(int*)(buf + 0x20) = field_30;
        *(int*)(buf + 0x24) = field_34;
        void* p = field_c;
        void** vt = *(void***)p;
        void (*fn)(void*, int) = (void (*)(void*, int))vt[2];
        fn(p, field_4);
    }
}
