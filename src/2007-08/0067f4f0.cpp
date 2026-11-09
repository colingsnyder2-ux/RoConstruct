// from server: 100% by colin
// roc 2007-08 0067f4f0  unit: CXTPControlSelector  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0067f4f0

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
