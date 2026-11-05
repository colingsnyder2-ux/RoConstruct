// from server: 60% by atomic.potato
typedef void (__thiscall *FunctionType)(void *, void *);

struct CXTAuxData
{
    void *method(void *);
};

void *CXTAuxData::method(void *argument)
{
    FunctionType function = (FunctionType)0x00B24780;
    function(argument, (char *)this + 0xB0);
    return argument;
}
