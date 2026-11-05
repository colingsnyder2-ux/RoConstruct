// from server: 100% by atomic.potato
void reverse_copy(const char* source, char* destination, unsigned int count)
{
    unsigned int i = 0;
    if (count > 0)
    {
        source += count - 1;
        do
        {
            destination[i] = *source--;
            ++i;
        }
        while (i < count);
    }
}
