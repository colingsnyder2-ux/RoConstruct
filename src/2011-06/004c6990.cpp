// from server: 100% by atomic.potato
struct EventDesc
{
    unsigned char padding[0x44];
    EventDesc *next;
    bool matches(EventDesc *value);
};

bool EventDesc::matches(EventDesc *value)
{
    while (value != 0)
    {
        value = value->next;
        if (value == this)
            return true;
    }
    return false;
}
