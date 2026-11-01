// from server: 100% by king_originala
#pragma optimize("", off)

void* __cdecl operator new(unsigned int, void*);

struct Mesh {
    int* data;
    int size;
    int capacity;

    bool contains(const int* value);
    void resize(int count, bool flag);
    void append(const int& value);
};

void Mesh::append(const int& value)
{
    if (size < capacity) {
        new (data + size) int(value);
        ++size;
    } else {
        if (contains(&value)) {
            int copy = value;
            append(copy);
        } else {
            resize(size + 1, false);
            data[size - 1] = value;
        }
    }
}
