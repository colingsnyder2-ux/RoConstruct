// from server: 76% by colin
struct EventHandler {
    char pad0[4];
    void* m_callback;
    void* m_context;
    int m_fieldC;
    int m_refCount;

    int release(void*);
};

extern "C" void __cdecl sub_62FC62(void*);

int EventHandler::release(void* arg) {
    if (--m_refCount == 0) {
        if (m_callback) {
            m_context = ((void* (__cdecl*)(void*, int))m_callback)(m_context, 1);
        }
        m_callback = 0;
        m_fieldC = 0;
        sub_62FC62(this);
        return 0;
    }
    return m_refCount;
}
