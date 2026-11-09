// from server: 52% by atomic.potato
extern "C" bool CheckReady(void *);
extern "C" bool CheckValid(void *);

struct KeyframeSequenceProvider
{
    char padding[0x94];

    bool IsReady();
    bool IsValid();
};

bool KeyframeSequenceProvider::IsReady()
{
    char *p = padding + 0x94;
    if (CheckReady(p))
        return false;
    if (CheckValid(p))
        return false;
    return true;
}

bool KeyframeSequenceProvider::IsValid()
{
    return false;
}
