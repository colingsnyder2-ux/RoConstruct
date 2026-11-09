// from server: 100% by atomic.potato
struct CXTPPropExchange
{
    int GetCount();
};

extern "C" void __cdecl sub_850A00(CXTPPropExchange *, const char *, int *, int);

int CXTPPropExchange::GetCount()
{
    int value = 0;
    sub_850A00(this, "Count", &value, 0);
    return value;
}
