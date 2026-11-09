// from server: 59% by Intel
struct Image {
    int find(void* key);
};

int Image::find(void* key) {
    unsigned int hash = reinterpret_cast<unsigned int>(key);
    unsigned int index = (hash + (hash >> 3)) % *reinterpret_cast<unsigned int*>(this + 0x18);
    int* bucket = reinterpret_cast<int*>(*reinterpret_cast<int*>(this + 0x14) + index * 4);
    int* prev = bucket;
    int* entry = reinterpret_cast<int*>(*bucket);

    while (entry) {
        if (reinterpret_cast<int*>(entry[-2]) == key)
            break;
        prev = entry;
        entry = reinterpret_cast<int*>(*entry);
    }

    if (!entry)
        return 0;

    if (*prev)
        return reinterpret_cast<int>(entry);

    int result = reinterpret_cast<int>(entry);
    int (__thiscall *remove)(void*, int*, int*) = reinterpret_cast<int (__thiscall*)(void*, int*, int*)>(0x5a8480);
    remove(this + 0x10, bucket, prev);
    return result;
}
