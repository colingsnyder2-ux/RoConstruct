// from server: 100% by atomic.potato
struct CRobloxControlColorSelector
{
    void SetValue(int value);
};

void CRobloxControlColorSelector::SetValue(int value)
{
    *(int*)((char*)this + 0x104) = value;
    if (value == 0)
    {
        int flags = *(int*)((char*)this + 0xd0);
        typedef void (__thiscall *Function)(CRobloxControlColorSelector*, int);
        Function function = *(Function*)(*(int*)this + 0x94);
        function(this, flags & 0xffffffdf);
    }
}
