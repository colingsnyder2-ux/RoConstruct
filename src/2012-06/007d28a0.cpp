// from server: 64% by atomic.potato
extern "C" void basic_string_copy(void* destination, void* source);

struct Pants
{
    char padding[132];
    void* value;
    Pants* f(void* argument);
};

Pants* Pants::f(void* argument)
{
    void* source = *(void**)((char*)this + 132);
    *(int*)((char*)argument + 12) = 0;
    basic_string_copy((char*)argument + 28, source);
    *(void**)((char*)argument + 28) = *(void**)((char*)source + 28);
    return (Pants*)argument;
}
