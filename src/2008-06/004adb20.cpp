// from server: 100% by king_originala
struct Temporary
{
    char storage[48];
    void initialize();
};

struct Destination
{
    int reserved;
    int active;
    void apply(Temporary*);
};

void __cdecl process(void*, Temporary*);

void __cdecl reconstruct(Destination* destination, void* source)
{
    Temporary temporary;
    temporary.initialize();
    process(source, &temporary);
    if (destination->active != 0)
        destination->apply(&temporary);
}
