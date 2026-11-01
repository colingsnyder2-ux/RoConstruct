// from server: 100% by colin
struct CXTPControlGallery
{
    int GetSelected();
};

extern int __stdcall sub_63a580(int);

int CXTPControlGallery::GetSelected()
{
    int result = *(int *)((char *)this - 0xdc);
    if (result == -1)
    {
        int p = *(int *)((char *)this - 0x20);
        if (p != 0)
        {
            return ((int (__thiscall *)(int))sub_63a580)(p);
        }
    }
    return result;
}
