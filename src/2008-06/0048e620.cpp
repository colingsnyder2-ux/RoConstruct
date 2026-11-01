// from server: 100% by king_originala
extern "C" unsigned int __cdecl strlen(const char*);

struct S {
    void initialize(const char* first, const char* last);
};

S* __cdecl construct(S* destination, const char* text)
{
    volatile int unused = 0;
    destination->initialize(text, text + strlen(text));
    return destination;
}
