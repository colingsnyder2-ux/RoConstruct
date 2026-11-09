// from server: 48% by atomic.potato
struct BlockBlockContact
{
    void *unknown(float);
};

void *BlockBlockContact::unknown(float value)
{
    return ((void *(*)(BlockBlockContact *, float))0x75ac40)(this, value);
}
