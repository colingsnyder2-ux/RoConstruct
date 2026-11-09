// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
struct Counter {
    unsigned int n;
    bool ok();
};
bool Counter::ok()
{
    return n < 64000000;
}
