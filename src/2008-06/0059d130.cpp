// from server: 100% by king_originala
typedef unsigned Word;

struct Triple
{
    Word a, b, c;
};

extern void __cdecl registerDescriptor(void*, void*);
extern Word __cdecl getClassDescriptor();
extern Word __cdecl getTypeDescriptor();
extern void __cdecl releaseObject(void*);

struct Owner
{
    void* p;

    Owner(Owner&);
    ~Owner();
};

__forceinline Owner::Owner(Owner& other)
{
    void* value = other.p;
    other.p = 0;
    p = value;
}

__forceinline Owner::~Owner()
{
    if (p)
        releaseObject(p);
}

extern Owner __cdecl createBinding(Triple, Triple);

struct Base
{
    Word table;
    Word data[5];
    Word descriptor;

    Base(Word, Word, Word);
    void initialize(Word, Word, Word, Word, Word);
    ~Base();
};

__forceinline Base::Base(Word name, Word attributes, Word flags)
{
    registerDescriptor(reinterpret_cast<void*>(0x59c490),
                       reinterpret_cast<void*>(0x97648c));
    Word classDescriptor = getClassDescriptor();
    Word typeDescriptor = getTypeDescriptor();
    initialize(typeDescriptor, classDescriptor, name, attributes, flags);
    descriptor = classDescriptor;
}

struct S : Base
{
    Owner binding;
    Word finalDescriptor;

    S(Word, Word, Triple, Triple, Word);
};

S::S(Word name, Word attributes, Triple first, Triple second, Word flags)
    : Base(name, attributes, flags),
      binding((table = 0x832f74, createBinding(first, second)))
{
    registerDescriptor(reinterpret_cast<void*>(0x59c490),
                       reinterpret_cast<void*>(0x97648c));
    finalDescriptor = getClassDescriptor();
}
