// from server: 56% by tester
struct Node {
    char pad[0x28];
};

struct Tree {
    char pad0[4];
    Node* head;
    Node* find(int* key);
    Node* insert_unique(int* key, Node* hint);
};

struct String {
    void* rep;
    String(const String&);
    ~String();
};

struct Key {
    String str;
    int num;
    Key(const String& s) : str(s), num(0) {}
    ~Key() {}
};

extern "C" {
    int __stdcall CompareString(const String* a, const String* b);
    void __stdcall StringCtor(String* self, const String* other);
    void __stdcall StringDtor(String* self);
}

struct Settings {
    Tree tree;
    Node* getOrCreate(int* key);
};

Node* Settings::getOrCreate(int* key) {
    Node* found = tree.find(key);
    if (found != tree.head) {
        if (!CompareString((const String*)((char*)found + 0xc), (const String*)key)) {
            return (Node*)((char*)found + 0x28);
        }
    }
    Key local(*(const String*)key);
    Node* result = tree.insert_unique(key, found);
    Node* ret = *(Node**)result;
    return (Node*)((char*)ret + 0x28);
}
