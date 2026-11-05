// from server: 40% by atomic.potato
typedef bool (__stdcall *Pred)(int);

int** __cdecl func_006f3dc0(int** out, int* first, int* last, Pred pred)
{
    int* it = first;
    if (it != last)
    {
        do
        {
            if (pred(*it))
                break;
            ++it;
        } while (it != last);
    }
    *out = it;
    return out;
}
