// from server: 100% by king_originala
struct Geometry;
struct Clump;

struct Edge {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int query();
    virtual void slot4();
    virtual int type();
};

typedef Edge Primitive;
typedef void (__cdecl* InvalidHandler)();

extern Primitive* __cdecl getFirstB(Geometry*);
extern "C" InvalidHandler _invalid_parameter_noinfo;

struct Children {
    void* allocator;
    Clump** first;
    Clump** last;

    unsigned int size() const;
    Clump*& at(unsigned int index, InvalidHandler handler);
};

inline unsigned int Children::size() const
{
    return static_cast<unsigned int>(last - first);
}

inline Clump*& Children::at(unsigned int index, InvalidHandler handler)
{
    if (index >= size())
        handler();
    return *(first + index);
}

struct Clump {
    char padding0[0x1c];
    Geometry* geometry;
    char padding1[0x10];
    Children children;

    int count();
};

int Clump::count()
{
    int result = 0;
    Primitive* primitive = getFirstB(geometry);

    if (!primitive->query()) {
        int type = primitive->type();
        if (type == 8)
            result = type - 7;
    }

    unsigned int i = 0;
    if (i < children.size()) {
        InvalidHandler handler = _invalid_parameter_noinfo;
        do {
            result += children.at(i, handler)->count();
            ++i;
        } while (i < children.size());
    }

    return result;
}
