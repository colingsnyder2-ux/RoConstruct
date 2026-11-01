// from server: 100% by colin
struct CXTPControlGallery
{
    int sub_006b3590();
    int func_006b3730();
};

int CXTPControlGallery::func_006b3730()
{
    if (sub_006b3590() != 0)
        return 0;
    return (*(int (__thiscall **)(CXTPControlGallery *))(*(int *)this + 0x6c))(this);
}
