// from server: 76% by atomic.potato
extern "C" void f(void *, void *);

void f(void **first, void **last, void **end)
{
    if (first != last)
    {
        do
        {
            --last;
            --end;
            f(end, last);
        } while (last != first);
    }
}
