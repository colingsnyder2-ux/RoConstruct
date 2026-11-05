// from server: 75% by atomic.potato
struct S_00523d70 {
    void* m_vt;
    int m_val;
    S_00523d70* ctor(int* src);
};

extern "C" void __cdecl init_00523d70(void*);

S_00523d70* S_00523d70::ctor(int* src)
{
    if (!(*(unsigned char*)0xe1e214 & 1)) {
        *(unsigned int*)0xe1e214 |= 1;
        *(unsigned int*)0xe1e208 = 0xd7c3fc;
        *(unsigned int*)0xe1e210 = 0x5708d0;
        *(unsigned int*)0xe1e20c = 0x59a790;
        init_00523d70((void*)0xb130d0);
    }
    void* vt = m_vt;
    if (vt == (void*)0xe1e208) {
        m_val = *src;
        return this;
    }
    if (vt) {
        ((void (__stdcall*)(int*))((void**)vt)[1])(&m_val);
        m_vt = 0;
    }
    int* p = &m_val;
    if (p) {
        m_val = *src;
    }
    m_vt = (void*)0xe1e208;
    return this;
}
