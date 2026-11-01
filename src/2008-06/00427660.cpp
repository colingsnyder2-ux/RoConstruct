// from server: 100% by king_originala
extern "C" void* __cdecl allocate(unsigned int);
extern "C" void __cdecl construct(void*, const void*);
extern "C" void __cdecl deallocate(void*);

typedef void (__thiscall *StringDestructor)(void*);
typedef bool (__thiscall *TypeEquality)(const void*, const void*);

extern StringDestructor destroyString;
extern TypeEquality equalType;
extern const unsigned char typeDescriptor[];

void __cdecl manage(void** source, void** destination, int operation)
{
    if (operation == 0)
    {
        void* original = *source;
        void* copy = allocate(32);
        construct(copy, original);
        *destination = copy;
    }
    else if (operation == 1)
    {
        void* object = *destination;
        destroyString(static_cast<char*>(object) + 4);
        deallocate(object);
        *destination = 0;
    }
    else
    {
        if (equalType(*destination, typeDescriptor))
            *destination = *source;
        else
            *destination = 0;
    }
}
