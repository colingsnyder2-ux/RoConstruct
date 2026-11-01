// from server: 100% by king_originala
inline void* operator new(unsigned int, void* p) { return p; }
inline void operator delete(void*, void*) {}

struct S
{
    S(void*);
};

S* __stdcall sub_4CB010(void* argument, void* storage)
{
    new (storage) S(argument);
    return static_cast<S*>(storage);
}
