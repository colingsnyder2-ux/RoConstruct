// from server: 100% by EspClaude
// from server: 81% by EspClaude
// roc 2009-06 004c1a30  unit: RBX::VShirt::?$FactoryProduct  size: 486 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c1a30
//

// from server: 100% by king_originala
// roc 2008-06 00493bf0  unit: RBX::VShirt::?$FactoryProduct  size: 424 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00493bf0
//

extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct String;
extern void (__thiscall *destroyString)(String*);
extern void (__thiscall *swapString)(String*, String&);

struct String
{
    unsigned char data[28];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Iterator
{
    typedef void (__cdecl *Cleanup)(void*, void*, int);

    Cleanup* manager;
    unsigned int reserved;
    unsigned char storage[72];

    bool equal(const Iterator& other) const;
    String dereference();
    void increment();
    ~Iterator();
};

inline Iterator::~Iterator()
{
    if (manager)
    {
        Cleanup cleanup = *manager;
        if (cleanup)
            cleanup(storage, storage, 2);
        manager = 0;
    }
}

__forceinline void reverse(String* first, String* last)
{
    for (; first != last && first != --last; ++first)
        swapString(first, *last);
}

struct Position
{
    void* owner;
    String* pointer;
};

struct S
{
    void* owner;
    unsigned int reserved[2];
    String* begin;
    String* end;

    void insert(void* owner, String* position, unsigned int count,
                const String& value);
    void func_00493bf0(Position position, Iterator first, Iterator last,
                       unsigned int unused);
};

void S::func_00493bf0(Position position, Iterator first, Iterator last,
                     unsigned int unused)
{
    if (!first.equal(last))
    {
        int oldSize = end - begin;
        int offset = position.pointer - begin;

        while (!first.equal(last))
        {
            String* insertionPoint = end;
            if (begin > insertionPoint)
                _invalid_parameter_noinfo();

            void* insertionOwner = owner;
            insert(insertionOwner, insertionPoint, 1, first.dereference());
            first.increment();
        }

        reverse(begin + offset, begin + oldSize);
        reverse(begin + oldSize, end);
        reverse(begin + offset, end);
    }
}
