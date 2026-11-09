// from server: 71% by colin
struct CXTPDockingPaneContext
{
    void func_006ed350(int, int, int, int, int, int);
    void sub_006ed2a0(int, int, int, int);
};

extern "C" void* __stdcall CreateRectRgn(int, int, int, int);
extern "C" unsigned int __stdcall GetPixel(void*, int, int);
extern "C" void __stdcall sub_00630238(void*);

void CXTPDockingPaneContext::func_006ed350(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int width = a4 - a2;
    int height = a6 - a3;
    void* rgn = CreateRectRgn(0, 0, 0, 0);
    sub_00630238(rgn);
    int i;
    int j;
    int found = 0;
    int lastx = 0;
    for (i = 0; i < height; i++)
    {
        int flag = 0;
        int prevx = 0;
        for (j = 0; j < width; j++)
        {
            unsigned int px = GetPixel(*(void**)(a5 + 4), j, i);
            int inside = (px != 0xFFFFFFFF) ? 1 : 0;
            if (flag)
            {
                if (!inside)
                {
                    prevx = j;
                    flag = 0;
                }
            }
            else
            {
                if (inside)
                {
                    sub_006ed2a0(a1, prevx, i, j);
                    flag = 1;
                }
            }
        }
        if (!flag)
        {
            sub_006ed2a0(a1, prevx, i, j);
        }
    }
}
