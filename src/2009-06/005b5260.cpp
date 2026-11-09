// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /MD
void unused(int*);
int index(int x, int u, int y, int width)
{
    unused(&u);
    return x * width + y;
}
