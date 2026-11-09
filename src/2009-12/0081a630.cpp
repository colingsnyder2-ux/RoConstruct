// from server: 83% by atomic.potato
extern "C" void __stdcall sub_98DEC0(void *);
extern "C" void __stdcall sub_7F43E2(void *);
extern "C" void __cdecl sub_7F385A(void *);

struct XTP_REPORTRECORDITEM_METRICS
{
    XTP_REPORTRECORDITEM_METRICS(unsigned char);
};

XTP_REPORTRECORDITEM_METRICS::XTP_REPORTRECORDITEM_METRICS(unsigned char flags)
{
    sub_98DEC0((char *)this + 0x2c);
    sub_7F43E2(this);
    if (flags & 1)
        sub_7F385A(this);
}
