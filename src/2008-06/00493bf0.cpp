// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct String;
extern void (__thiscall *destroyString)(String*);

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
            cleanup(storage, storage, 1);
        manager = 0;
    }
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
    void reverse(String* first, String* last);
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
