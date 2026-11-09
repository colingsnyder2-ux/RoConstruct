// from server: 100% by colin
struct CXTPPropertyGridItem
{
    int get_flags();
};

int CXTPPropertyGridItem::get_flags()
{
    int a = *(int*)((char*)this + 0xe8);
    a = (a != 0) ? 0x20 : 0;
    int b = (*(int*)((char*)this + 0xf8) <= 1) ? 0 : 4;
    return a | b | *(int*)((char*)this + 0xfc) | 0x40000080;
}
