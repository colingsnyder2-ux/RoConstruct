// from server: 40% by Intel
struct LuaStatsItem {
    char pad_0[0x10];
    struct Inner* m_inner;
    char pad_14[0xC];
    int m_field20;
    int m_field24;
    int m_field28;
    int m_field2C;
    int m_field30;

    void f_00853e30();
};

struct Inner {
    char pad_0[0xC];
    int m_fieldC;
    int m_field10;
    int m_field14;
    int m_field34;
    int m_field3C;
};

extern "C" void __stdcall sub_936640(int, LuaStatsItem*);
extern "C" void __stdcall sub_932f00(LuaStatsItem*);
extern "C" int __stdcall sub_936f60(LuaStatsItem*, int, int, int);

void LuaStatsItem::f_00853e30()
{
    sub_936640(m_field20, this);
    sub_932f00(this);

    int v1 = m_inner->m_fieldC;
    int v2 = m_inner->m_field10;
    int v3 = v2 * 4;
    sub_936f60(this, v1, v3, 0);

    int v4 = m_inner->m_field3C;
    int v5 = m_inner->m_field34;
    int v6 = sub_936f60(this, v5, v4, 0);
    m_inner->m_field34 = v6;
    m_inner->m_field3C = 0;

    int v7 = m_field30;
    int v8 = m_field28;
    int v9 = (v7 + v7 * 2) * 4;
    sub_936f60(this, v8, v9, 0);

    int v10 = m_field2C;
    int v11 = m_field20;
    int v12 = v10 * 16;
    sub_936f60(this, v11, v12, 0);

    int (__stdcall* callback)(int, int, LuaStatsItem*, int) = (int (__stdcall*)(int, int, LuaStatsItem*, int))m_inner->m_fieldC;
    LuaStatsItem* adjustedThis = (LuaStatsItem*)((char*)this - 0x20);
    callback(m_inner->m_field10, 0x198, adjustedThis, 0);
}
