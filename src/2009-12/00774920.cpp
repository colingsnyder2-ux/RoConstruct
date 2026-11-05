// from server: 86% by atomic.potato
struct VerbWidget {
    char pad[0xac];
    void* field_ac;
    void method(int arg);
};

void VerbWidget::method(int arg) {
    if (field_ac != 0) {
        void** vtbl = *(void***)field_ac;
        typedef bool (__thiscall *Fn0)(void*);
        Fn0 fn0 = (Fn0)vtbl[2];
        if (fn0(field_ac)) {
            void** vtbl2 = *(void***)field_ac;
            int* p = (int*)arg;
            int v = *(int*)((char*)p + 0x14);
            typedef void (__thiscall *Fn1)(void*, int);
            Fn1 fn1 = (Fn1)vtbl2[4];
            fn1(field_ac, v);
        }
    }
}
