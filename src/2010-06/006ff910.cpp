// from server: 35% by atomic.potato
extern "C" void __stdcall sub_00599fb0();
extern "C" void* __stdcall make_desc_005b6db0(const char*, int);

struct S_006ff910 {
    void* m_vt0;
    void* m_vt1;
    char pad_08[0x10];
    void* m_vt18;
    void* m_vt1c;
    void* m_field20;
    S_006ff910();
};

S_006ff910::S_006ff910()
{
    sub_00599fb0();
    m_vt0 = (void*)0xa4b57c;
    m_vt1 = (void*)0xa4b574;
    m_vt18 = (void*)0xa4b568;
    m_vt1c = (void*)0xa4b55c;
    m_field20 = make_desc_005b6db0((const char*)0, 0);
    *(int*)0xc18350 += 1;
}
