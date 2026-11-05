// from server: 100% by king_originala
void __cdecl alignedFree(void *);

struct ArrayStorage {
    void *data;
    int size;
    int capacity;
    ~ArrayStorage();
};

inline ArrayStorage::~ArrayStorage()
{
    alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct BlockBlockContact {
    char padding[0x34];
    ArrayStorage first;
    ArrayStorage second;
    ~BlockBlockContact();
};

BlockBlockContact::~BlockBlockContact()
{
}
