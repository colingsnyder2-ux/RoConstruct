// from server: 100% by tajop
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

__declspec(noreturn) void __stdcall sub_62ff20();

struct Ctrl_006352b0 {
    char pad[0x20];
    void* m_hWnd;
    char pad2[0x108];
    int m_12c;
};

struct Arr_006352b0 {
    virtual ~Arr_006352b0();
    Ctrl_006352b0** m_pData;
    int m_nSize;

    int GetSize() const { return m_nSize; }
    Ctrl_006352b0* const& GetAt(int i) const
    {
        if (i >= 0 && i < m_nSize)
            return m_pData[i];
        sub_62ff20();
    }
};

struct Bar_006352b0 {
    char pad[0x8];
    Arr_006352b0 m_arr;

    int sub_6a3940(int);
};

struct S_func_006352b0 {
    char pad[0x44];
    int m_44;
    char pad2[0x2c];
    S_func_006352b0* m_74;
    char pad3[0x4c];
    void* m_c4;

    void f(int, int);
    Bar_006352b0* sub_633900();
    int sub_6338d0(int);
    int sub_633860();
};

void S_func_006352b0::f(int a, int b)
{
    Bar_006352b0* bar = sub_633900();

    if (b == 0 && m_c4 != 0) {
        if (bar->sub_6a3940(0) == 0) {
            sub_6338d0(0);
        }
    }

    if (m_44 > 0 && m_74->m_c4 != 0) {
        sub_633860();
        if (bar->sub_6a3940(0) != 0) {
            Ctrl_006352b0* c = bar->m_arr.GetAt(bar->m_arr.GetSize() - 1);
            if (c->m_12c != 0) {
                PostMessageA(c->m_hWnd, 0x113, 0xccca, 0);
            }
        }
    }
}
