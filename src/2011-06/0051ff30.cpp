// from server: 74% by atomic.potato
struct ProfiledRakPeer {
    char pad0[8];
    unsigned short m_count;
    char pad1[0x274 - 0xA];
    void* m_entries;
    bool f(int index, int arg);
};

extern "C" void __stdcall sub_52E070(void* p, int arg);

bool ProfiledRakPeer::f(int index, int arg)
{
    if (index < (int)m_count) {
        char* entry = (char*)m_entries + index * 0x1760;
        if (entry[0] != 0) {
            sub_52E070(entry + 0x68, arg);
            return true;
        }
    }
    return false;
}
