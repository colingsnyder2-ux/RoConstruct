// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct Name;
struct KeyBase { int x; };
struct Key : KeyBase {};

Name const& __cdecl getLocalScope();

struct Map {
    char data[84];
    void*& lookup(KeyBase* const& key);
};

struct S_func_00451a10 {
    char pad[84];
    Map map;
    void f(Key* key, void* node);
};

void S_func_00451a10::f(Key* key, void* node)
{
    if (node) {
        void* value = *(void**)((char*)node + 4);
        map.lookup(key) = value;
    } else {
        void* value = (void*)&getLocalScope();
        map.lookup(key) = value;
    }
}
