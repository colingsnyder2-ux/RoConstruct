// from server: 49% by atomic.potato
char func_00743a00(char* first, char* last, char result)
{
    while (first != last)
    {
        if (*first == '\\')
            *first = '/';
        ++first;
    }
    return result;
}
