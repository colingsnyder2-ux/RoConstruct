// from server: 100% by king_originala
struct Unknown;

struct UnknownTable {
    void *entry0;
    void *entry1;
    unsigned long (__stdcall *release)(Unknown *);
};

struct Unknown {
    UnknownTable *table;
};

struct ConnectionArray {
    void *reserved;
    Unknown **items;
    int count;

    Unknown *getAt(int index);
    Unknown *getUnknown(unsigned long cookie);
    int remove(unsigned long cookie);
};

inline Unknown *ConnectionArray::getAt(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return items[index];
}

inline Unknown *ConnectionArray::getUnknown(unsigned long cookie)
{
    if (cookie == 0 || cookie > (unsigned long)count)
        return 0;
    return getAt((int)(cookie - 1));
}

inline int ConnectionArray::remove(unsigned long cookie)
{
    unsigned long index = cookie - 1;
    if (index < cookie && index < (unsigned long)count) {
        if (items[index] != 0) {
            items[index] = 0;
            return 1;
        }
    }
    return 0;
}

extern "C" long __stdcall Unadvise(ConnectionArray *array, unsigned long cookie)
{
    Unknown *object = array->getUnknown(cookie);
    long result = array->remove(cookie) ? 0 : (long)0x80040200UL;
    if (result == 0 && object != 0)
        object->table->release(object);
    return result;
}
