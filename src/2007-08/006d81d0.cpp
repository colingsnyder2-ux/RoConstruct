// from server: 100% by colin
struct S_func_006d81d0 {
    char pad0[4];
    void* m_pHashTable;
    unsigned int m_nHashTableSize;
    int f(unsigned int key, void** ppResult, unsigned int* pBucket);
};

extern "C" int __stdcall sub_0068f840(void* node, unsigned int* pKey);

int S_func_006d81d0::f(unsigned int key, void** ppResult, unsigned int* pBucket)
{
    unsigned int hash = key >> 4;
    *pBucket = hash;
    unsigned int bucket = hash % m_nHashTableSize;
    *reinterpret_cast<unsigned int*>(ppResult) = bucket;
    void** table = reinterpret_cast<void**>(m_pHashTable);
    if (table == 0)
        return 0;
    void* node = table[bucket];
    while (node != 0) {
        if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(node) + 0xc) == *pBucket) {
            unsigned int tmp;
            if (sub_0068f840(node, &tmp) != 0)
                return reinterpret_cast<int>(node);
        }
        node = *reinterpret_cast<void**>(reinterpret_cast<char*>(node) + 8);
    }
    return 0;
}
