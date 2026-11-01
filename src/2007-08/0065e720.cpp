// from server: 100% by colin
struct Inner {
    char pad[0x24];
    int value;
};

struct CXTPReportColumn {
    char pad[0x54];
    Inner* inner;
    int getValue();
};

extern "C" Inner* __fastcall get_inner(Inner* self);

int CXTPReportColumn::getValue()
{
    return get_inner(inner)->value;
}
