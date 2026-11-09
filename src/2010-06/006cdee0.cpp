// from server: 23% by atomic.potato
struct RBX_VArcHandles_EventDesc {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
};

extern "C" void* __stdcall sub_6cdc30(void*, void*);

void* __stdcall RBX_VArcHandles_EventDesc_ctor(RBX_VArcHandles_EventDesc* a1, void* a2, int a3)
{
    if (a3 != 4)
        return sub_6cdc30(a2, a1);
    if (a1)
    {
        a1->m_00 = 0;
        a1->m_04 = 0;
        a1->m_08 = 0;
        a1->m_0c = 0;
        a1->m_10 = 0;
        a1->m_14 = 0;
        a1->m_18 = 0;
        a1->m_1c = 0;
        a1->m_20 = 0;
        a1->m_24 = 0;
        a1->m_28 = 0;
        a1->m_2c = 0;
        a1->m_30 = 0;
        a1->m_34 = 0;
        a1->m_38 = 0;
        a1->m_3c = 0;
    }
    return a1;
}
