// from server: 92% by Intel
struct X_00812800 {
    void* f_0;
    void* f_4;
    char pad_8[20];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    char pad_84[44];
    void* f_ac;
    X_00812800* base();
    X_00812800* run() {
        f_ac = (void*)0xbc6954;
        f_0 = (void*)0xbc671c;
        f_4 = (void*)0xbc6710;
        f_18 = (void*)0xbc6704;
        f_1c = (void*)0xbc66f8;
        f_80 = (void*)0xbc66cc;
        return base();
    }
};
X_00812800* func_00812800(X_00812800* x) { return x->run(); }
