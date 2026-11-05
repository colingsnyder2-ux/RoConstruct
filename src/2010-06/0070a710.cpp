// from server: 86% by atomic.potato
struct VerbWidget_0070a710 {
    char pad_0[0xac];
    void* f_ac;
    void method(int arg);
};

void VerbWidget_0070a710::method(int arg) {
    if (f_ac != 0) {
        void** vtbl = *(void***)f_ac;
        typedef bool (__thiscall *Fn0)(void*);
        Fn0 fn0 = (Fn0)vtbl[2];
        if (fn0(f_ac)) {
            void** vtbl2 = *(void***)f_ac;
            int v = *(int*)((char*)arg + 0x14);
            typedef void (__thiscall *Fn1)(void*, int);
            Fn1 fn1 = (Fn1)vtbl2[4];
            fn1(f_ac, v);
        }
    }
}
