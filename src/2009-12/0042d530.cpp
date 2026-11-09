// from server: 79% by atomic.potato
struct CMultiPlayerPane {
    char pad[0x54];
    void* field54;
    void func(int a, int b, int c);
};

void CMultiPlayerPane::func(int a, int b, int c)
{
    if (a != 1 && field54 != 0) {
        extern void __stdcall sub_7f3c32(int, int, int, int, int);
        sub_7f3c32(0, 0, b, c, 1);
    }
    extern void __stdcall sub_7f3e30(CMultiPlayerPane*);
    sub_7f3e30(this);
}
