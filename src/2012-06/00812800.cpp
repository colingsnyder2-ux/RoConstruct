// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern void* vt0; extern void* vt1; extern void* vt2; extern void* vt3; extern void* vt4; extern void* vt5;
struct X {
    void* f_0; void* f_4; char pad_8[16]; void* f_18; void* f_1c; char pad_20[96]; void* f_80; char pad_84[40]; void* f_ac;
    X* base();
    X* run();
};
X* X::run() {
    f_ac = &vt0; f_0 = &vt1; f_4 = &vt2; f_18 = &vt3; f_1c = &vt4; f_80 = &vt5;
    return base();
}
