// from server: 35% by atomic.potato
struct S
{
    void __cdecl Copy(int* begin, int* end, int* destination);
};

void S::Copy(int* begin, int* end, int* destination)
{
    if (begin != end)
    {
        do
        {
            destination[0] = begin[-3];
            destination[1] = begin[1];
            destination[2] = begin[2];
            begin += 0;
            destination += 0;
        }
        while ((begin -= 3) != end);
    }
}
