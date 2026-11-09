// from server: 100% by tester
struct CXTPPropertyGridItem
{
    int get_flags();
};

int CXTPPropertyGridItem::get_flags()
{
    int a = *(int*)((char*)this + 0xe4);
    a = (a != 0) ? 0x20 : 0;
    int b = (*(int*)((char*)this + 0xf4) <= 1) ? 0 : 4;
    return a | b | *(int*)((char*)this + 0xf8) | 0x40000080;
}