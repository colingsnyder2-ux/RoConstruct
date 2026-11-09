// from server: 73% by atomic.potato
extern "C" void PasteVerb(void *, void *);

struct GfxClustererPart
{
};

int * __cdecl copy(int *first, int *last, int *destination)
{
    while (first != last)
    {
        PasteVerb(destination, first);
        ++first;
        ++destination;
    }
    return destination;
}
