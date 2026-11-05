// from server: 100% by king_originala
struct Link;

struct LinkArray {
    Link** data;
    int count;
    int capacity;
    void resize(int count, Link* value);
};

struct Link {
    char reserved[0x14];
    Link* parent;
    int index;
    LinkArray links;
    char* flag28;
    char* flag2c;

    void reset();
    void remove(Link* link);
};

extern "C" void __cdecl release(void* memory);

void Link::remove(Link* link)
{
    int index = link->index;
    LinkArray& array = links;
    Link* last = array.data[array.count - 1];
    array.data[index] = last;
    last->index = index;
    array.resize(array.count - 1, 0);
    link->index = -1;

    if (links.count == 0) {
        release(flag28);
        flag28 = 0;
    }

    if (!flag28 || !flag28[4]) {
        if (parent)
            parent->reset();
        else if (flag2c)
            flag2c[8] = 1;

        if (flag28)
            flag28[4] = 1;
    }
}
