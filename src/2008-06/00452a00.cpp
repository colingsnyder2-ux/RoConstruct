// from server: 100% by king_originala
extern void (__cdecl *invalidParameter)();

extern void __cdecl registerValue(void (__cdecl*)(), void*);
extern void __cdecl initializeIndex();
extern void __cdecl initializeType();
extern unsigned char indexStorage;
extern unsigned char typeStorage;
extern unsigned int __cdecl func_0044f360();
extern void* __cdecl func_004137a0();

struct Control
{
    void* value;
    Control();
    Control& operator=(const Control&);
};

inline Control::Control() : value(0)
{
}

struct Result
{
    void* object;
    Control control;
    ~Result();
};

struct Entry
{
    void* object;
    Control control;

    Entry();
    Entry(const Entry&);
};

inline Entry::Entry() : object(0), control()
{
}

struct Entries
{
    unsigned char padding[12];
    Entry* first;
    Entry* last;
    Entry* limit;

    void resize(unsigned int, Entry);
    unsigned int size() const;
    Entry& at(unsigned int, void (__cdecl*)());
};

inline unsigned int Entries::size() const
{
    return static_cast<unsigned int>(last - first);
}

inline Entry& Entries::at(unsigned int index, void (__cdecl *handler)())
{
    if (index >= size())
        handler();
    return first[index];
}

struct S
{
    unsigned char padding[0x190];
    Entries entries;

    Result create(void*);
    void* get();
};

void* S::get()
{
    registerValue(initializeIndex, &indexStorage);
    unsigned int index = func_0044f360();
    void (__cdecl *handler)() = invalidParameter;

    if (index + 1 > entries.size())
        entries.resize(index + 1, Entry());
    else
    {
        void* object = entries.at(index, handler).object;
        if (object)
            return object;
    }

    registerValue(initializeType, &typeStorage);
    Result result = create(func_004137a0());

    if (!result.object)
        return 0;

    void* object = result.object;
    Entry& entry = entries.at(index, handler);
    entry.object = result.object;
    entry.control = result.control;
    return object;
}
