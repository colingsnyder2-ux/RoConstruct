// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern void __cdecl copy_object(void*, const void*);

typedef void (__thiscall *StringDestructor)(void*);
typedef bool (__thiscall *TypeEquality)(const void*, const void*);

extern StringDestructor destroy_string;
extern TypeEquality equal_type;
extern const char object_type;

void __cdecl manage(const void* const* source, void** destination,
                    int operation, bool)
{
    if (operation == 0)
    {
        const void* original = *source;
        void* copy = operator new(32);
        copy_object(copy, original);
        *destination = copy;
    }
    else if (operation == 1)
    {
        void* object = *destination;
        destroy_string(static_cast<char*>(object) + 4);
        operator delete(object);
        *destination = 0;
    }
    else
    {
        if (equal_type(*destination, &object_type))
            *destination = const_cast<void*>(*source);
        else
            *destination = 0;
    }
}
