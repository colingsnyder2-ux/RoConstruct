// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
unsigned int decode(const unsigned int* p)
{
    return *p ^ 0xdeadbeef;
}
