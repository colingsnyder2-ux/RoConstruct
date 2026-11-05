// from server: 100% by tester
struct Inner {
    char pad[0x24];
    int value;
    int f();
    int g(int);
};

struct CXTPReportColumn {
    char pad[0x54];
    Inner* inner;
    int getValue();
    int isSomething();
};

extern "C" int __fastcall sub_0065e720(CXTPReportColumn*);
extern "C" int __fastcall sub_00656780(int);

int CXTPReportColumn::isSomething()
{
    if (inner->f() != 0)
    {
        if (inner->g(0) == (int)this)
        {
            return sub_00656780(sub_0065e720(this));
        }
    }
    return 0;
}
