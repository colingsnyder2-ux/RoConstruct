// from server: 100% by atomic.potato
struct RecordToggleVerb {
    void* m_vt;
    char m_pad[4];
    int m_a;
    int m_b;
    void construct(int a, int b);
};

extern "C" bool __cdecl func_00880f30(int* out);

void RecordToggleVerb::construct(int a, int b)
{
    int tmp[2];
    tmp[0] = a;
    tmp[1] = b;
    if (!func_00880f30(tmp)) {
        int* p = &m_a;
        if (p != 0) {
            p[0] = tmp[0];
            p[1] = tmp[1];
        }
        m_vt = (void*)0xd6f268;
        return;
    }
    m_vt = 0;
}
