// from server: 100% by king_originala
struct Matrix
{
    float data[9];
    Matrix(const Matrix &);
};

struct Value
{
    Matrix rotation;
    float x, y, z;
};

struct GetSetImpl
{
    char padding[8];
    const Value &(__thiscall *function)(void *);
    int adjustment;
    int index;

    Value Invoke(void *argument);
};

Value GetSetImpl::Invoke(void *argument)
{
    char *object = argument ? (char *)argument - 0x14 : 0;
    return function(
        object + 0x1c0 +
        (*(int *)(*(char **)(object + 0x1c0) + index) + adjustment));
}
