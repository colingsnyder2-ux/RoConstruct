// from server: 100% by king_originala
struct Object {
    void notify(void* property);
};

typedef void (__thiscall *Callback)(void* object, void* property);

struct S {
    int unknown0;
    void* property;
    int valueOffset;
    int unknown12;
    Callback callback;
    int callbackAdjustment;

    void set(void* object, const int& value);
};

void S::set(void* object, const int& value)
{
    char* base = object ? static_cast<char*>(object) - 20 : 0;
    int* destination = reinterpret_cast<int*>(base + valueOffset);

    if (*destination != value) {
        *destination = value;
        if (callback)
            callback(base + callbackAdjustment, property);
        reinterpret_cast<Object*>(base)->notify(property);
    }
}
