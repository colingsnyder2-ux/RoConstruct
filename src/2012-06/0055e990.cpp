// from server: 62% by atomic.potato
struct EventDesc
{
    char pad[0x44];
};

struct Range
{
    EventDesc* first;
    EventDesc* last;
};

typedef void (__cdecl *Callback)(EventDesc*, void*);

Range* func_0055e990(Range* result, EventDesc* first, EventDesc* last, Callback callback, void* arg)
{
    EventDesc* it = first;
    if (it != last)
    {
        do
        {
            callback(it, arg);
            it = (EventDesc*)((char*)it + 0x44);
        } while (it != last);
    }
    result->first = first;
    result->last = last;
    return result;
}
