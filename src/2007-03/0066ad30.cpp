// from server: 100% by tester
char* __cdecl strip_ampersands(char* p)
{
    if (p != 0 && p != (char*)-1)
    {
        char* d = p;
        char c = *p;
        if (c != 0)
        {
            do
            {
                if (c != '&' || p[1] == c)
                {
                    *d = c;
                    d++;
                }
                c = p[1];
                p++;
            } while (c != 0);
        }
        *d = 0;
    }
    return p;
}
