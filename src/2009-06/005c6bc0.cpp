// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /fp:fast /GS- /EHsc /MD
struct Counter {
    unsigned int used();
    unsigned int total();
    float ratio();
};
float Counter::ratio()
{
    return (float)used() / (float)total();
}
