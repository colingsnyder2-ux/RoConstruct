// from server: 100% by tester
typedef bool (__cdecl *Pred)(int, int);

int* find_if(int* first, int* last, Pred pred, int dummy, int value)
{
    while (first != last)
    {
        if (pred(*first, value))
            break;
        ++first;
    }
    return first;
}
