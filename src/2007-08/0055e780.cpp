// from server: 100% by colin
// roc 2007-08 0055e780  unit: RBX::FixedCameraCommand  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055e780

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
