// from server: 100% by king_originala
struct Object;

struct Ref
{
    Object *p;
};

struct DxUserInput
{
    char pad[402];
    unsigned char enabled;

    void helper(Ref *result, int value);
    Ref *f(Ref *result, int value);
};

Ref *DxUserInput::f(Ref *result, int value)
{
    volatile int zero = 0;
    if (enabled)
    {
        helper(result, value);
        return result;
    }

    result->p = 0;
    return result;
}
