// from server: 58% by atomic.potato
struct HandlesBase
{
    static void Copy(float* begin, float* end, float* destination);
};

void HandlesBase::Copy(float* begin, float* end, float* destination)
{
    while (begin != end)
    {
        if (destination != 0)
        {
            destination[0] = begin[0];
            destination[1] = begin[1];
        }
        begin += 2;
        destination += 2;
    }
}
