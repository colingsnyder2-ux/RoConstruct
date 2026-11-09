// from server: 100% by atomic.potato
struct Inner {
    ~Inner();
};

struct Holder {
    Inner* m_ptr;
    void Release();
};

void Holder::Release() {
    if (m_ptr) {
        delete m_ptr;
        m_ptr = 0;
    }
}
