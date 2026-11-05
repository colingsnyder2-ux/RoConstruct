// from server: 100% by king_originala
struct Tag {
    unsigned char value;
};

extern char descriptor;
extern void __cdecl dispatch(void *, void **, int, Tag);

void __cdecl f(void *context, void **output, int kind)
{
    if (kind != 3) {
        Tag tag = { 0 };
        dispatch(context, output, kind, tag);
    } else {
        *output = &descriptor;
    }
}
