// from server: 100% by colin
struct S
{
    unsigned char padding[20];
    void* volatile value;
};

extern int __cdecl process(S* object);

bool __cdecl getValue(S* object, int* result)
{
    void* v = object->value;
    if (v)
    {
        try
        {
            *result = process(object);
            return true;
        }
        catch (...)
        {
        }
    }
    return false;
}