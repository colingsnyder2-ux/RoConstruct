// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern int (__cdecl *copy_bytes)(unsigned char*, unsigned int,
                                const unsigned char*, unsigned int);
extern unsigned char* (__cdecl *find_bytes)(const unsigned char*,
                                           const unsigned char*);
extern const unsigned char* source;
extern void __cdecl check_result(int);

struct Content
{
    unsigned char data[0x1226];
    unsigned short limit;
    int kind;
    int flags;
    int field1230;
    int field1234;
    int field1238;
    int field123c;
    int field1240;

    void Init();
    void f(int, unsigned int);
};

struct String
{
    unsigned char* text;
    int reserved;
    void assign(int);
};

struct StringHeader;

struct StringManager
{
    virtual void unused() = 0;
    virtual void release(StringHeader*) = 0;
};

struct StringHeader
{
    StringManager* manager;
    int length;
    int capacity;
    volatile long references;

    __forceinline void release();
};

__forceinline void StringHeader::release()
{
    volatile long* count = &references;
    if (_InterlockedExchangeAdd(count, -1) - 1 <= 0)
        manager->release(this);
}

bool __cdecl test_content(int value)
{
    Content content;
    content.Init();
    content.kind = 2;
    content.flags = 4;
    content.limit = 0x50;
    check_result(copy_bytes(content.data, 0x21, source, 4));
    content.f(value, 0);

    if (content.kind == 0 ||
        (content.kind > 1 && content.kind <= 3))
        return false;

    String string;
    string.assign(value);
    unsigned char* (__cdecl *search)(const unsigned char*,
                                    const unsigned char*) = find_bytes;

    if (((StringHeader*)string.text - 1)->length >= 0)
    {
        unsigned char* found = search(
            string.text, (const unsigned char*)"javascript:");
        if (found && found - string.text == 0)
        {
            ((StringHeader*)string.text - 1)->release();
            return true;
        }

        if (((StringHeader*)string.text - 1)->length >= 0)
        {
            found = search(string.text, (const unsigned char*)"jscript:");
            if (found && found - string.text == 0)
            {
                ((StringHeader*)string.text - 1)->release();
                return true;
            }
        }
    }

    ((StringHeader*)string.text - 1)->release();
    return false;
}
