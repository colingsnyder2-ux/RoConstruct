// from server: 100% by king_originala
void __cdecl alignedFree(void*);

struct String {
    void* data;
    int length;
    int capacity;

    String(const String&);
};

struct Argument : String {
    bool first;
    bool second;

    Argument(const Argument& other)
        : String(other), first(other.first), second(other.second)
    {
    }

    ~Argument() { alignedFree(data); }
};

struct S {
    int value;
    Argument argument;

    S(int, int, Argument);
};

S::S(int v, int, Argument source)
    : value(v), argument(source)
{
}
