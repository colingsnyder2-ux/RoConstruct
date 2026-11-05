// from server: 63% by atomic.potato
extern "C" void imported_call(void *, void *);

struct CXTPReportRecordItem
{
    void *f(void *);
};

void *CXTPReportRecordItem::f(void *arg)
{
    imported_call(arg, (char *)this + 0x60);
    return arg;
}
