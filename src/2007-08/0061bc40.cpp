// from server: 100% by colin
struct RBX_KeyButton {
    char pad0[0x18];
    int m_id;
    bool m_active;
    void* processEvent(int, int);
};

void* __stdcall sub_006006A0(void*, int);

void* RBX_KeyButton::processEvent(int a, int b)
{
    int* ev = (int*)b;
    if (ev[0] == 9 && ev[2] == m_id)
        m_active = true;
    if (ev[0] == 10 && ev[2] == m_id)
        m_active = false;
    sub_006006A0((void*)a, b);
    return (void*)a;
}
