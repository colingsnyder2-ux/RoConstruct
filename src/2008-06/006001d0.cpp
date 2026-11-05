// from server: 100% by king_originala
struct Prefix {
    char padding[20];
};

struct Argument {
    char padding[428];
    int* virtualTable;
};

struct Object : Prefix, Argument {
    void notify(void* property);
};

typedef void (__thiscall *Callback)(void*, void*);

struct S {
    void* reserved;
    void* property;
    int valueOffset;
    int valueVirtualOffset;
    Callback callback;
    int callbackOffset;
    int callbackVirtualOffset;

    void set(Argument* argument, const bool& value);
};

void S::set(Argument* argument, const bool& value)
{
    Object* object = static_cast<Object*>(argument);
    bool* destination = reinterpret_cast<bool*>(
        reinterpret_cast<char*>(object) + 448 +
        *reinterpret_cast<int*>(
            reinterpret_cast<char*>(object->virtualTable) + valueVirtualOffset) +
        valueOffset);

    if (*destination != value) {
        *destination = value;
        if (callback) {
            callback(
                reinterpret_cast<char*>(object) + 448 +
                *reinterpret_cast<int*>(
                    reinterpret_cast<char*>(object->virtualTable) +
                    callbackVirtualOffset) +
                callbackOffset,
                property);
        }
        object->notify(property);
    }
}
