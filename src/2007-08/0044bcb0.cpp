// from server: 53% by colin
// roc 2007-08 0044bcb0  unit: CRobloxControlColorSelector  size: 623 bytes

extern "C" __declspec(dllimport) void __stdcall InflateRect(void*, int, int);
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct CRobloxControlColorSelector {
    void method(int);
};

extern int* g_8bbebc;
extern int* g_8bbec0;

int __stdcall sub_63a000();
int __stdcall sub_63a580();
int __stdcall sub_6308b0(int*, int);
int __stdcall sub_668f70();
int __stdcall sub_668770(int, int);
int __stdcall sub_6308aa(int*, int, int);

void CRobloxControlColorSelector::method(int a2)
{
    int count;
    int i;
    int idx;
    int* base;
    int* end;
    int* p;
    int v;
    int flag;
    int r;
    int t1, t2, t3, t4;
    int rect[4];

    base = g_8bbebc;
    end = g_8bbec0;
    i = 0;
    if (base == 0) {
        count = 0;
    } else {
        count = (int)((char*)end - (char*)base) / 12;
    }
    if (count <= 0) goto done;

    idx = 0;
    for (;;) {
        base = g_8bbebc;
        end = g_8bbec0;

        {
            int q = i / 8;
            int rem = i % 8;
            int x = *(int*)((char*)this + 0xc0) + (rem << 5) + 2;
            int y = *(int*)((char*)this + 0xc4) + (q << 5) + 2;
            t1 = x;
            t2 = y;
            t3 = x + 0x20;
            t4 = y + 0x20;
        }

        if (i == *(int*)((char*)this + 0x168)) goto skip_check;

        if (base == 0) {
            _invalid_parameter_noinfo();
            base = g_8bbebc;
        } else {
            int n = (int)((char*)end - (char*)base) / 12;
            if ((unsigned)i >= (unsigned)n) {
                _invalid_parameter_noinfo();
                base = g_8bbebc;
            }
        }
        if (*(int*)((char*)base + idx) != *(int*)((char*)this + 0x174)) goto next;

    skip_check:
        {
            int (*fn)(void*) = *(int(**)(void*))this;
            fn = (int(*)(void*))*(int*)((char*)fn + 0x78);
            r = fn(this);
            if (r != 0) {
                if (i == *(int*)((char*)this + 0x168))
                    flag = 1;
                else
                    flag = 0;
            } else {
                flag = 0;
            }
        }

        p = (int*)sub_63a000();

        {
            int* b2 = g_8bbebc;
            if (b2 == 0) {
                _invalid_parameter_noinfo();
                b2 = g_8bbebc;
            } else {
                int n = (int)((char*)g_8bbec0 - (char*)b2) / 12;
                if ((unsigned)i >= (unsigned)n) {
                    _invalid_parameter_noinfo();
                    b2 = g_8bbebc;
                }
            }
            b2 = (int*)((char*)b2 + idx);
            v = *(int*)((char*)this + 0x9c);
            if (v == -1) {
                int* q = *(int**)((char*)this + 0x158);
                if (q != 0) {
                    sub_63a580();
                }
            }
            {
                int c = *b2;
                int eq = (c == *(int*)((char*)this + 0x174)) ? 1 : 0;
                int eq2 = (i == *(int*)((char*)this + 0x168)) ? 1 : 0;
                int (*fn2)(void*, int, int, int, int, int, int, int, int, int, int, int, int, int) =
                    (int(*)(void*, int, int, int, int, int, int, int, int, int, int, int, int, int))
                    *(int*)((char*)*(int**)p + 0x84);
                fn2(p, eq2, v, eq, 0, 1, 5, t1, t2, t3, t4, a2, 0, 0);
            }
        }

    next:
        InflateRect(rect, -3, -3);
        {
            int v2 = *(int*)((char*)this + 0x9c);
            if (v2 == -1) {
                int* q = *(int**)((char*)this + 0x158);
                if (q != 0) {
                    sub_63a580();
                }
            }
            if (v2 != 0) {
                int* b3 = g_8bbebc;
                if (b3 == 0) {
                    _invalid_parameter_noinfo();
                    b3 = g_8bbebc;
                } else {
                    int n = (int)((char*)g_8bbec0 - (char*)b3) / 12;
                    if ((unsigned)i >= (unsigned)n) {
                        _invalid_parameter_noinfo();
                        b3 = g_8bbebc;
                    }
                }
                {
                    int val = *(int*)((char*)b3 + idx);
                    sub_6308b0(rect, val);
                }
            }
        }
        {
            int a = sub_668f70();
            int b = sub_668770(a, 0x10);
            int c = sub_668f70();
            int d = sub_668770(c, 0x10);
            sub_6308aa(rect, d, b);
        }

        idx += 0xc;
        i++;
        if (i < count) continue;
        break;
    }

done:
    return;
}
