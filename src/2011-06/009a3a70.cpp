// from server: 58% by atomic.potato
void copy_words(const unsigned int* first, const unsigned int* last, unsigned int* out)
{
    while (first != last)
    {
        if (out != 0)
            *out = *first;
        ++first;
        ++out;
    }
}
