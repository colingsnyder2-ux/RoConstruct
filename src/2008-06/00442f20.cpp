// from server: 100% by king_originala
struct RBXImage {
    void* vtable;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    unsigned char field1C;
    unsigned char field1D;
    int field20;
    void* destroy(unsigned int flags);
};

extern void* image_vtable[];
extern "C" int (__stdcall *DeleteObject)(void*);
extern "C" void __cdecl operator_delete(void*);

void* RBXImage::destroy(unsigned int flags) {
    void* p = this->field4;
    this->vtable = image_vtable;
    if (p != 0) {
        this->field4 = 0;
        this->field8 = 0;
        this->fieldC = 0;
        this->field10 = 0;
        this->field18 = 0;
        this->field14 = 0;
        this->field20 = -1;
        this->field1D = 0;
        this->field1C = 0;
        DeleteObject(p);
    }
    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
