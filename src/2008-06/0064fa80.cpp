// from server: 100% by king_originala
struct Facet;

extern const Facet* __cdecl getFacet(const void* locale);

typedef char (__thiscall *LowerFunction)(const Facet*, char);
extern LowerFunction lowerCharacter;

char* __cdecl transformCharacters(const char* first, const char* last,
                                 char* output, const void* volatile locale)
{
    while (first != last) {
        char value = *first;
        *output = lowerCharacter(getFacet(locale), value);
        ++first;
        ++output;
    }
    return output;
}
