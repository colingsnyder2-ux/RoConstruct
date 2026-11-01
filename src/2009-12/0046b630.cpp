// from server: 67% by atomic.potato
extern "C" void __stdcall sub_7f3b06(void*);
extern "C" void __stdcall sub_7f385a(void*);

struct CArray {
    void* vtable;
    void* data;
    void Destroy();
    ~CArray();
};

void CArray::Destroy() {
    if (data) {
        sub_7f3b06(data);
    }
}

CArray::~CArray() {
    vtable = (void*)0x9af9cc;
    Destroy();
    if (this) {
        sub_7f385a(this);
    }
}
