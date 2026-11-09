// from server: 100% by atomic.potato
typedef int (__stdcall *SetRectFn)(void*, int, int, int, int);
extern SetRectFn SetRectPtr;

struct CXTPControlGallery {
    char m_pad[0xc0];
    int m_fieldC0;
    int m_fieldC4;
    int Check();
    void Method(void* p, int v);
    void Target(void* p, int v);
};

void CXTPControlGallery::Target(void* p, int v) {
    if (this->Check()) {
        this->Method(p, v);
    } else {
        SetRectPtr(p, m_fieldC0 - 1, m_fieldC4, m_fieldC0 - 1, m_fieldC4);
    }
}
