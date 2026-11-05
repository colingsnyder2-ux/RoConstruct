// from server: 69% by Intel
struct IUnknown {
    virtual void QueryInterface() = 0;
    virtual unsigned long AddRef() = 0;
    virtual unsigned long Release() = 0;
};

struct SomeClass {
    IUnknown* field_8;
    long method(int* outPtr);
};

long SomeClass::method(int* outPtr) {
    if (!outPtr) {
        return 0x80004003;
    }

    IUnknown* pUnk = field_8;
    *outPtr = reinterpret_cast<int>(pUnk);

    if (pUnk) {
        pUnk->AddRef();
    }

    return 0;
}
