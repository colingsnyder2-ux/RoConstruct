// from server: 100% by tester
typedef bool (__cdecl *Pred)(int);

int* find_if(int* first, int* last, Pred pred)
{
    while (first != last)
    {
        if (pred(*first))
            break;
        ++first;
    }
    return first;
}
