// from server: 77% by colin
struct LDraw2RobloxColorMap
{
    int* data;
    int size;
    LDraw2RobloxColorMap& append(int count);
};

extern "C" int (__stdcall *g_77e6d8)();
extern "C" int (__stdcall *g_77e5e8)(int*);

LDraw2RobloxColorMap& LDraw2RobloxColorMap::append(int count)
{
    if (data != (int*)-2)
    {
        if (data == 0)
            g_77e6d8();
        int* p = data;
        int cap = g_77e5e8(p) + *(int*)((char*)p + 0x14);
        if ((unsigned)(size + count) > (unsigned)cap)
        {
            g_77e6d8();
        }
        else
        {
            int cap2 = g_77e5e8(p) + *(int*)((char*)p + 0x14);
            if ((unsigned)(size + count) < (unsigned)cap2)
            {
                g_77e6d8();
            }
        }
    }
    size += count;
    return *this;
}
