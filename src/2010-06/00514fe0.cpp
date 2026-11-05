// from server: 73% by atomic.potato
extern "C" unsigned int __stdcall get_file_attributes(const char* path);

struct RakPeer {
    char pad0[0xa80];
    unsigned int m_field_a80;
    unsigned int m_field_a84;
    unsigned int m_field_a88;
    unsigned int m_field_a8c;
    unsigned int m_field_a90;
    unsigned int m_field_a94;
    unsigned int m_field_a98;
    unsigned int m_field_a9c;
    unsigned int m_field_aa0;
    unsigned int m_field_aa4;
    unsigned int m_field_aa8;
    unsigned int m_field_aac;
    unsigned int m_field_ab0;
    unsigned int m_field_ab4;
    unsigned int m_field_ab8;
    unsigned int m_field_abc;
    unsigned int m_field_ac0;
    unsigned int m_field_ac4;
    unsigned int m_field_ac8;
    unsigned int m_field_acc;
    unsigned int m_field_ad0;
    unsigned int m_field_ad4;
    unsigned int m_field_ad8;
    unsigned int m_field_adc;
    unsigned int m_field_ae0;
    unsigned int m_field_ae4;
    unsigned int m_field_ae8;
    unsigned int m_field_aec;
    void init();
};

void RakPeer::init()
{
    unsigned int* p;
    int i;
    int j;
    unsigned int v;
    unsigned int t;

    m_field_a80 = get_file_attributes(0);
    p = &m_field_a84;
    j = 3;
    do {
        get_file_attributes((const char*)1);
        get_file_attributes(0);
        *p = get_file_attributes(0);
        i = 0;
        do {
            t = get_file_attributes(0);
            get_file_attributes((const char*)1);
            get_file_attributes(0);
            v = get_file_attributes(0);
            v = (v - t) << 28;
            v &= 0xf0000000u;
            v >>= i;
            *p ^= v;
            i += 4;
        } while (i < 0x1c);
        p++;
        j--;
    } while (j != 0);
}
