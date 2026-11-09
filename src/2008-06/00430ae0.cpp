// from server: 100% by king_originala
struct CommandBars {
    void sub_6a3a10(int);
};

struct TabClient {
    void sub_705440(int);
};

struct CXTPDockingPaneManager {
    char pad[0x128];
    int field_128;
    void func(int);
};

struct CMainFrame {
    char pad0[0xec];
    CommandBars* field_ec;
    char pad1[0x104 - 0xf0];
    char field_104;
    char pad2[0x138 - 0x105];
    char field_138[0x284 - 0x138];
    TabClient field_284;

    void sub_6a0db8(int, int);
    void sub_430ae0(int, int);
};

void CMainFrame::sub_430ae0(int a, int b)
{
    field_ec->sub_6a3a10(a);
    int flag = 0;
    if (a == 0)
        flag = (field_104 == 0);
    field_284.sub_705440(flag);
    ((CXTPDockingPaneManager*)field_138)->func(a);
    if (field_ec != 0)
        field_ec->sub_6a3a10(a);
    sub_6a0db8(a, b);
}
