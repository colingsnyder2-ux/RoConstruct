// from server: 96% by atomic.potato
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

struct PasteVerb {
    void* m_handle;
    PasteVerb* assign(void* h);
};

PasteVerb* PasteVerb::assign(void* h) {
    if (m_handle != 0) {
        if (m_handle != (void*)-1) {
            CloseHandle(m_handle);
        }
    }
    m_handle = h;
    return this;
}
