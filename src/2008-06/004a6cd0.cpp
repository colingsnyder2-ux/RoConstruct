// from server: 100% by king_originala
extern void __cdecl transfer(void *destination, const float *source);

void *__cdecl copy_three(void *destination, const float *source)
{
    transfer(destination, source);
    transfer(destination, source + 1);
    transfer(destination, source + 2);
    return destination;
}
