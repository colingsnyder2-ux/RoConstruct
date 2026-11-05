// from server: 100% by atomic.potato
struct IdSerializer {
    bool equals(const IdSerializer& other);
};

bool __thiscall IdSerializer::equals(const IdSerializer& other)
{
    const unsigned int* a = reinterpret_cast<const unsigned int*>(this);
    const unsigned int* b = reinterpret_cast<const unsigned int*>(&other);
    unsigned int i = 0;

    do {
        if (a[i] != b[i])
            return false;
        ++i;
    } while (i < 4);

    return true;
}
