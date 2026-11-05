// from server: 26% by colin
struct CXTColorWnd {
    char pad[0x80];
    int field_80;
    int field_84;
    void draw(int);
};

extern "C" void __stdcall sub_738b0e(void*, int, int, int);
extern "C" void __stdcall sub_738b08(void*, void*);
extern "C" void __stdcall sub_63097c(void*, void*, int, int);
extern "C" void __stdcall sub_630976(void*, int, int);
extern "C" void __stdcall sub_41f680(void*);
extern int dword_8c9750;

void CXTColorWnd::draw(int)
{
    int a = field_80;
    int b = field_84;
    char buf1[8];
    char buf2[8];
    sub_738b0e(buf1, 0, 1, 0xffffff);
    sub_738b0e(buf2, 0, 1, 0);
    void* p;
    if (dword_8c9750 == 1)
        p = buf1;
    else
        p = buf2;
    void* q;
    sub_738b08(&q, p);
    sub_63097c(q, &q, a - 5, b - 1);
    sub_630976(q, a - 10, b - 1);
    sub_63097c(q, &q, a - 5, b);
    sub_630976(q, a - 10, b);
    sub_63097c(q, &q, a - 5, b + 1);
    sub_630976(q, a - 10, b + 1);
    sub_63097c(q, &q, a + 5, b - 1);
    sub_630976(q, a + 10, b - 1);
    sub_63097c(q, &q, a + 5, b);
    sub_630976(q, a + 10, b);
    sub_63097c(q, &q, a + 5, b + 1);
    sub_630976(q, a + 10, b + 1);
    sub_63097c(q, &q, a - 1, b - 5);
    sub_630976(q, a - 1, b - 10);
    sub_63097c(q, &q, a, b - 5);
    sub_630976(q, a, b - 10);
    sub_63097c(q, &q, a + 1, b - 5);
    sub_630976(q, a + 1, b - 10);
    sub_63097c(q, &q, a - 1, b + 5);
    sub_630976(q, a - 1, b + 10);
    sub_63097c(q, &q, a, b + 5);
    sub_630976(q, a, b + 10);
    sub_63097c(q, &q, a + 1, b + 5);
    sub_630976(q, a + 1, b + 10);
    sub_738b08(&q, q);
    sub_41f680(buf1);
    sub_41f680(buf2);
}
