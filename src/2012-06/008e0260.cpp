// from server: 100% by atomic.potato
extern "C" void __stdcall Dispatch(unsigned long);

struct BoundFuncDesc {
    void setValue(unsigned char value);
};

void BoundFuncDesc::setValue(unsigned char value) {
    unsigned char* p = reinterpret_cast<unsigned char*>(this) + 0x3cc;
    if (*p == value)
        return;
    *p = value;
    Dispatch(0xe55760);
}
