// from server: 44% by colin
struct COleException {
    void* m_pException;
    COleException(void* p);
};

extern "C" void __stdcall sub_725810(void* p);
extern "C" void __stdcall sub_630B9E(void* p1, void* p2);
extern "C" void __stdcall sub_726120(void* p1, void* p2);

COleException::COleException(void* p) {
    if (p == 0) {
        char buf[16];
        sub_725810(buf);
        sub_630B9E(buf, (void*)0x843A78);
    }
    sub_726120(this, p);
}
