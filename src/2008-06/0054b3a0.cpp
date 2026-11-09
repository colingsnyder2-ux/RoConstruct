// from server: 100% by colin
// roc-flags: /EHsc
#pragma optimize("", off)

struct Iterator {
    unsigned int words[2];
    bool __thiscall equal(const Iterator& other) const;
    void* __thiscall value() const;
    char* __thiscall node() const;
};

struct String {
    unsigned char storage[28];
    __declspec(dllimport) String();
    __declspec(dllimport) ~String();
};

struct Pair {
    unsigned int key;
    String value;
    Pair(const unsigned int& key, const String& value);
    ~Pair();
};

struct Map {
    bool __thiscall contains(const unsigned int& key, void* value);
};

extern "C" void* __cdecl resolve(void* value);

struct Mesh {
    unsigned char padding[8];
    Map map;

    Iterator __thiscall find(const unsigned int& key);
    Iterator __thiscall end();
    Iterator __thiscall insert(Iterator position, const Pair& value);
    char* __thiscall f(const unsigned int& key);
};

char* Mesh::f(const unsigned int& key)
{
    Iterator position = find(key);
    if (position.equal(end()) ||
        map.contains(key, resolve(position.value())))
    {
        position = insert(Iterator(position), Pair(key, String()));
    }
    return position.node() + 4;
}
