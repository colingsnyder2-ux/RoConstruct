// from server: 16% by atomic.potato
struct S_func_00750fa0 {
    char pad0[0x1c];
    void* m_field1c;
    char pad20[0x20];
    void* m_field40;
    void* m_field44;
    void* m_field48;
    void* m_field4c;
    void* m_field50;
    void* m_field54;
    void* m_field58;
    void* m_field5c;
    void* m_field60;
    void* m_field64;
    void* m_field68;
    void* m_field6c;
    void* m_field70;
    void* m_field74;
    float m_field78;
    float m_field7c;
    void* m_field80;
    void construct(int a, int b, int c);
};

extern "C" void* __stdcall sub_00592ce0();
extern "C" void __stdcall sub_00784860();

void S_func_00750fa0::construct(int a, int b, int c)
{
    m_field1c = sub_00592ce0();
    m_field40 = 0;
    m_field44 = 0;
    m_field48 = 0;
    m_field4c = 0;
    m_field50 = 0;
    m_field54 = 0;
    m_field58 = 0;
    m_field5c = 0;
    m_field60 = 0;
    m_field64 = 0;
    m_field68 = 0;
    m_field6c = 0;
    m_field70 = 0;
    m_field74 = 0;
    m_field78 = 0.0f;
    m_field7c = 0.0f;
    m_field80 = 0;
    sub_00784860();
}
