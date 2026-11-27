// from server: 78% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
struct Other { float get() const; };
extern bool gFlag;
struct S {
    char pad[0x84];
    int* vb;
    float get() const;
};
float S::get() const {
    if (gFlag) { volatile float z = 0.0f; return z; }
    return ((Other*)((char*)this + 0x84 + *vb))->get();
}