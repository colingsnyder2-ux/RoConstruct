// from server: 72% by atomic.potato
struct S
{
    int (*fn)(int);
    int offset;
    S* GetSetImpl(int, int);
    void Set(int);
};

S* S::GetSetImpl(int, int value)
{
    S* result = this;
    int adjusted = value ? value - 28 : 0;
    int value2 = fn(offset + adjusted);
    result->Set(value2);
    return result;
}
