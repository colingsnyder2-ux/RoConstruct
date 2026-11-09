// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d3220 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006d3220* base();
    X_006d3220* run() {
    f_0 = (void*)0xaa63a4;
    f_4 = (void*)0xaa639c;
    f_18 = (void*)0xaa6390;
    f_1c = (void*)0xaa6384;
    f_90 = (void*)0xaa635c;
        return base();
    }
};
X_006d3220* func_006d3220(X_006d3220* x) { return x->run(); }
