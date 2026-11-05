// from server: 100% by colin
struct RESOLUTIONENTRY
{
    int width;
    int height;
    int refresh;
};

struct CRenderSettings
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    unsigned char field30;

    CRenderSettings(const RESOLUTIONENTRY* src);
};

CRenderSettings::CRenderSettings(const RESOLUTIONENTRY* src)
{
    field0 = 0;
    field4 = 0;
    field8 = 0;

    if (src->width != 0)
    {
        field8 = src->refresh;
        field0 = src->width;
        field4 = ((int (__cdecl *)(int, int))src->width)(src->height, 0);
    }

    fieldC = *(const int*)((const char*)src + 0x0C);
    field10 = *(const int*)((const char*)src + 0x10);
    field14 = *(const int*)((const char*)src + 0x14);
    field18 = *(const int*)((const char*)src + 0x18);
    field1C = *(const int*)((const char*)src + 0x1C);
    field20 = *(const int*)((const char*)src + 0x20);
    field24 = *(const int*)((const char*)src + 0x24);
    field28 = *(const int*)((const char*)src + 0x28);
    field2C = *(const int*)((const char*)src + 0x2C);
    field30 = 0;
}
