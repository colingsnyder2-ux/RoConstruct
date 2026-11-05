// from server: 73% by atomic.potato
struct RefPropDescriptor
{
    int f(int);
    struct Field
    {
        int operator[](int);
    };
    Field *field;
};

int RefPropDescriptor::f(int value)
{
    Field *object = field;
    int result = (*object)[value];
    if (result)
        return result + 28;
    return 0;
}
