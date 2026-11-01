// from server: 100% by colin
extern "C" void __cdecl free(void*);

struct FillToolColor {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    FillToolColor* destroy(char);
};

FillToolColor* FillToolColor::destroy(char flags) {
    if (field10) {
        free(field10);
    }
    void* p = field4;
    field10 = 0;
    field14 = 0;
    field18 = 0;
    free(p);
    if (flags & 1) {
        free(this);
    }
    return this;
}
