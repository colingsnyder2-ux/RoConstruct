// from server: 100% by king_originala
struct S {
    void* get();
};

extern S* __cdecl lookup(void*);

bool __cdecl check(void* value)
{
    S* object = lookup(value);
    return (object ? object->get() : 0) != 0;
}
