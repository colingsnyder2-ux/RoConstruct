// from server: 48% by atomic.potato
void f(char* s)
{
    if (s == 0 || s == (char*)-1)
        return;

    char* d = s;
    char c = *s;

    while (c != 0)
    {
        if (c == '&' && s[1] == c)
        {
            *d = c;
            ++d;
        }
        c = s[1];
        ++s;
    }

    *d = 0;
}
