// from server: 100% by tajop
struct Hook { Hook* next; };
struct ItemBase { int key; char pad[0x2c]; };
struct Item : ItemBase, Hook {};

struct S {
    bool f(int* key, Hook** list, int unused);
};

bool S::f(int* key, Hook** list, int unused) {
    for (Hook* cur = (*list)->next; cur != *list; cur = cur->next) {
        if (*key == static_cast<Item*>(cur)->key) {
            *list = cur;
            return false;
        }
    }
    return true;
}
