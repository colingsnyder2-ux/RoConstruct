// from server: 100% by atomic.potato
struct Args
{
    int pad[3];
    int value;
};

extern "C" unsigned char __stdcall Compare(Args* a, Args* b)
{
    if (a->value < b->value)
        return 1;
    if (a->value > b->value)
        return 0;
    return a < b;
}
