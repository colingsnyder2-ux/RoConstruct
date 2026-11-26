// from server: 100% by Xemicl
// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
struct Target { virtual void v0(); virtual void v1(); virtual void v2(); virtual void set(int, void* const&); };
void* conv(void*);
struct VModelInstance {
    char pad[0x2c];
    Target* field_2c;
    void method(int a, void* b);
};
void VModelInstance::method(int a, void* b) {
    void* r;
    if (b) r = conv(b); else r = 0;
    b = r;
    field_2c->set(a, b);
}
