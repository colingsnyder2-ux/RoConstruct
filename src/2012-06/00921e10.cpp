// from server: 96% by tajop
struct Node {
    Node* next;
    Node* prev;
    void init() { next = this; prev = this; }
};
struct List {
    Node head;
    unsigned size;
    List() { volatile char t = 0; head.init(); size = 0; }
    ~List();
};
struct Str {
    char storage[0x1c];
    Str();
    ~Str();
};
extern void (Str::*g_strCtor)();
inline Str::Str() { (this->*g_strCtor)(); }
struct Count {
    int value;
    Count() : value(0) {}
};
struct Item {
    int value;
    Item();
    ~Item();
};
struct S {
    int first;
    List list;
    Str name;
    Count count;
    bool flag;
    Item item0;
    Item item1;
    S();
};
S::S() : first(0), flag(false)
{
}
