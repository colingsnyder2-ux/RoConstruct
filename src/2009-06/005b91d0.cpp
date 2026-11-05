// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
struct Tag {};
void callee(void* a, void* b, Tag t);
void forward(void* a, void* b)
{
    Tag t;
    callee(a, b, t);
}
