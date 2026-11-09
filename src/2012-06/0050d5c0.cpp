// from server: 57% by atomic.potato
struct S
{
    void __cdecl f(int* first, int* last, int* value);
};

void S::f(int* first, int* last, int* value)
{
    while (first != last)
    {
        value -= 4;
        first -= 4;
        value[0] = first[0];
        value[1] = first[1];
        value[2] = first[2];
        value[3] = first[3];
    }
}
