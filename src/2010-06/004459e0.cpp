// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004459e0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004459e0* base();
    X_004459e0* run() {
    f_0 = (void*)0xa0afcc;
    f_4 = (void*)0xa0afc4;
    f_18 = (void*)0xa0afb8;
    f_1c = (void*)0xa0afac;
        return base();
    }
};
X_004459e0* func_004459e0(X_004459e0* x) { return x->run(); }
