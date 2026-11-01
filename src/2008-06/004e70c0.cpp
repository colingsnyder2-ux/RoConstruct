// from server: 100% by king_originala
struct Tag {};

extern char typeTag;
extern "C" void __cdecl helper(int, void *, int, Tag);

void __cdecl f(int a, void *b, int c)
{
    if (c != 3) {
        helper(a, b, c, Tag());
        return;
    }
    *(void **)b = &typeTag;
}
