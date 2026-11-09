// from server: 100% by Espeon
// from server: 94% by king_originala
struct Node {
    char padding[16];
    int value;
};

struct Container {
    char padding[24];
    Node* end;
};

struct Iterator {
    Container** owner;
    Node* node;
};

extern "C" {
    extern __declspec(dllimport) void __cdecl invalid_parameter_noinfo();
}

struct Writer {
    void write(const int* value, int count, int flag);
};

struct S {
    char padding[32];
    int count;

    Iterator* lookup(Iterator* result, const int* key);
    void f(Writer* writer, int key);
};

void S::f(Writer* writer, int key)
{
    Iterator temporary;
    Iterator* position = lookup(&temporary, &key);
    void (__cdecl *report)() = invalid_parameter_noinfo;

    if (!position->owner)
        report();

    Container* container = position->owner ? *position->owner : 0;

    if (position->node == container->end)
        report();

    int value = position->node->value;
    writer->write(&value, count, 1);
}

