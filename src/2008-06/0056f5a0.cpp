// from server: 100% by king_originala
struct Color {
    float x, y, z;
};

extern "C" bool __cdecl convertColor(void*, Color*);

struct Sink;

struct SinkTable {
    void* reserved[3];
    void (__thiscall *set)(Sink*, void*, const Color*);
};

struct Sink {
    SinkTable* table;
};

struct S {
    char reserved[24];
    Sink* sink;
    bool f(void* object, void* value);
};

bool S::f(void* object, void* value)
{
    Color color;
    if (convertColor(value, &color)) {
        sink->table->set(sink, object, &color);
        return true;
    }
    return false;
}
