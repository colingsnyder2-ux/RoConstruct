// from server: 100% by atomic.potato
struct VContentFilter_BoundFuncDesc
{
    bool sub_76B0C0(int);
    bool sub_769A70(int);
    int compare(int);
};

int VContentFilter_BoundFuncDesc::compare(int a)
{
    if (sub_76B0C0(a))
        return sub_769A70(a) ? 1 : 2;
    return 0;
}
