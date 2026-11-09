// from server: 36% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall type_info_equal(const void*, const void*);

struct RbxRefObject
{
    void* vtable;
    long references;
};

struct RbxSignalValue
{
    int type;
    int flags;
    void* object;
    int a;
    int b;
    int c;
};

struct RbxCallable
{
    void f(int, RbxSignalValue*, int);
};

void RbxCallable::f(int, RbxSignalValue* value, int mode)
{
    if (mode == 2)
    {
        RbxRefObject* object =
            value ? reinterpret_cast<RbxRefObject*>(value->object) : 0;

        if (object &&
            _InterlockedExchangeAdd(&object->references, -1) == 1)
        {
            void (**table)(void) =
                reinterpret_cast<void (**)(void)>(object->vtable);
            table[2]();
        }
        return;
    }

    if (mode == 3)
    {
        int equal = type_info_equal(
            reinterpret_cast<void*>(value->type),
            reinterpret_cast<void*>(0xd837f0));

        value->type = equal ? value->flags : 0;
        return;
    }

    if (mode != 0 && mode != 1)
    {
        value->type = 0xd837f0;
        reinterpret_cast<unsigned char*>(value)[4] = 0;
        reinterpret_cast<unsigned char*>(value)[5] = 0;
        return;
    }

    if (!value)
        return;

    int type = value->type;
    int flags = value->flags;
    void* objectPointer = value->object;
    int a = value->a;
    int b = value->b;
    int c = value->c;

    value->type = type;
    value->flags = flags;
    value->object = objectPointer;

    if (objectPointer)
    {
        RbxRefObject* object =
            reinterpret_cast<RbxRefObject*>(objectPointer);
        _InterlockedExchangeAdd(&object->references, 1);
    }

    value->a = a;
    value->b = b;
    value->c = c;

    if (mode == 1 && objectPointer)
    {
        RbxRefObject* object =
            reinterpret_cast<RbxRefObject*>(objectPointer);

        if (_InterlockedExchangeAdd(&object->references, -1) == 1)
        {
            void (**table)(void) =
                reinterpret_cast<void (**)(void)>(object->vtable);
            table[2]();
        }
    }
}
