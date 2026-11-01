// from server: 100% by king_originala
struct S_func_005fa610 {
    char pad0[4];
    int m_x;
    int* f();
};

struct Array {
    S_func_005fa610** data;
    int count;
    void resize(int count, int value);
};

struct Storage {
    char pad0[24];
    Array array;
};

struct Kernel {
    char pad0[16];
    Storage* storage;
    void remove(S_func_005fa610* object);
};

void Kernel::remove(S_func_005fa610* object)
{
    Array* array = &storage->array;
    int index = *object->f();
    S_func_005fa610* last = array->data[array->count - 1];
    array->data[index] = last;
    *last->f() = index;
    array->resize(array->count - 1, 0);
    *object->f() = -1;
}
