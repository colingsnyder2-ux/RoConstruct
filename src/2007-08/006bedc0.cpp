// from server: 100% by colin
struct XTPPaintThemes_CXTPOffice2003Theme
{
    int IsThemeActive(void* p);
};

extern "C" int __stdcall sub_63d710(void* p);

int XTPPaintThemes_CXTPOffice2003Theme::IsThemeActive(void* p)
{
    if (sub_63d710(p) == 0)
    {
        if ((*(unsigned char*)((char*)p + 0xe8) & 0xf) != 0)
            return 1;
    }
    return 0;
}
