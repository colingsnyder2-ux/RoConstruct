// from server: 42% by colin
// roc 2007-08 006ab3e0  unit: CXTPRibbonBar  size: 705 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ab3e0

struct CXTPRibbonBar {
    char pad[0x1000];
    int f(int);
};

struct RECT {
    int left;
    int top;
    int right;
    int bottom;
};

extern "C" {
    int __stdcall EqualRect(const RECT*, const RECT*);
    int __stdcall IntersectRect(RECT*, const RECT*, const RECT*);
}

extern "C" int __stdcall sub_63a130();
extern "C" int __stdcall sub_639d80();
extern "C" int __stdcall sub_63a580();
extern "C" int __stdcall sub_644710();
extern "C" int __stdcall sub_62fef6(int);
extern "C" int __stdcall sub_632790(int, int, int, int, int);
extern "C" int __stdcall sub_6d2910(int, int, int);
extern "C" int __stdcall sub_41ece0(int, int);

int CXTPRibbonBar::f(int arg)
{
    int result = 0;
    RECT r1;
    RECT r2;
    RECT r3;
    int v1, v2, v3, v4;
    int i;
    int count;
    int x1, y1, x2, y2;
    int flag;
    int w, h;
    int tmp;

    if (sub_63a130() & 2)
        return result;

    r1.left = *(int*)((char*)this + 0xc0);
    r1.top = *(int*)((char*)this + 0xc4);
    r1.right = *(int*)((char*)this + 0xc8);
    r1.bottom = *(int*)((char*)this + 0xcc);

    if (!IntersectRect(&r2, &r1, (RECT*)((char*)this + 0x2c)))
        return result;

    v1 = *(int*)((char*)this + 0x154);
    v2 = *(int*)(v1 + 0x34);
    v3 = *(int*)(v1 + 0x3c);
    v4 = *(int*)(v1 + 0x38);
    tmp = *(int*)(v1 + 0x40);

    count = *(int*)(arg + 0x640);
    w = tmp - count + 2;

    r3.left = v2;
    r3.top = v3;
    r3.right = v4;
    r3.bottom = w;

    if (IntersectRect(&r2, &r3, &r1))
    {
        x1 = r2.left;
        y1 = r2.top;
        x2 = r2.right;
        y2 = r2.bottom;
        h = (x1 + x2) / 2;
        w = y2 - 6;
        flag = 1;
    }
    else
    {
        if (sub_639d80() == 4)
        {
            if (r2.right - r2.left > (w - v4) / 2)
            {
                sub_41ece0((int)&r3, (int)&r2);
                h = *(int*)&r3;
                w = v4 - 2;
                flag = 5;
            }
            else
            {
                goto loc_6ab519;
            }
        }
        else
        {
        loc_6ab519:
            if (*(int*)((char*)this + 0xf8) == 0xa)
            {
                w = v4 - 2;
                h = r2.top;
                flag = 5;
            }
            else
            {
                sub_41ece0((int)&r3, (int)&r2);
                tmp = (w - v4) / 3;
                if (*(int*)((char*)&r3 + 4) < tmp + v4)
                {
                    w = v4 + 2;
                }
                else
                {
                    sub_41ece0((int)&r3, (int)&r2);
                    tmp = (2 * (w - v4)) / 3;
                    if (*(int*)((char*)&r3 + 4) > tmp + v4)
                    {
                        w = v4 - 2;
                    }
                    else
                    {
                        sub_41ece0((int)&r3, (int)&r2);
                        w = *(int*)((char*)&r3 + 4);
                    }
                }
                h = r2.left + 0xb;
                flag = 4;
            }
        }
    }

    {
        void* p = (void*)sub_62fef6(0x74);
        if (p)
        {
            int v5 = (*(int(__thiscall**)(void*, void*))(*(int*)this + 0x58))(this, &r3);
            int v6 = *(int*)((char*)this + 0x9c);
            if (v6 == -1)
            {
                int v7 = *(int*)((char*)this + 0x158);
                if (v7)
                    v6 = sub_63a580();
            }
            result = sub_632790(v5, h, w, flag, v6);
        }
        else
        {
            result = 0;
        }
    }

    {
        int v8 = *(int*)((char*)this + 0x30);
        int v9 = *(int*)(v8 + 0x34);
        sub_6d2910(v8 + 0x2c, v9, result);
    }

    return result;
}
