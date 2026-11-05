// from server: 96% by atomic.potato
struct S
{
    S *next;
};

S *f(S *p)
{
    S *ecx;
    S *edx;
    S *eax;

    if (p)
        ecx = (S *)((char *)p + 0x30);
    else
        ecx = 0;

    edx = ecx->next;
    eax = edx;

    if (eax->next != ecx)
    {
        do
        {
            eax = eax->next;
        } while (eax->next != ecx);
    }

    eax->next = edx;
    return eax;
}
