// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct TypeInfo
{
    void* table;
};

extern TypeInfo expected_type;
extern bool (__thiscall *type_equal)(const TypeInfo*, const TypeInfo*);

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Value
{
    const TypeInfo* type;
    void* first;
    void* second;
    Control* control;
};

void __cdecl func_00418f10(const Value* source, Value* destination, int operation)
{
    if (operation == 0)
    {
        if (destination)
        {
            destination->type = source->type;
            destination->first = source->first;
            destination->second = source->second;
            Control* control = source->control;
            destination->control = control;
            if (control)
                _InterlockedIncrement(&control->strong);
        }
    }
    else if (operation == 1)
    {
        Control* control = destination->control;
        if (control && _InterlockedDecrement(&control->strong) == 0)
        {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    }
    else
    {
        destination->type = type_equal(destination->type, &expected_type)
            ? reinterpret_cast<const TypeInfo*>(source) : 0;
    }
}
