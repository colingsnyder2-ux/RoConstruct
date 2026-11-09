// from server: 17% by atomic.potato
struct Node {
    char pad0[4];
    Node* parent;
    char pad8[0x3d];
    char color;
};

extern "C" bool (__thiscall *less_str)(const void* a, const void* b);

struct S {
    char pad0[4];
    Node* header;
    int size;
    void insert_hint(int, void*, void*, int);
    void* find_hint(void*, void*);
    void* lower_bound(void*, void*);
    void* erase_hint(void*);
    void* lookup(const void*, void*);
};

void S::insert_hint(int, void*, void*, int) {}
void* S::find_hint(void*, void*) { return 0; }
void* S::lower_bound(void*, void*) { return 0; }
void* S::erase_hint(void*) { return 0; }

void* S::lookup(const void* key, void* hint) {
    if (size == 0) {
        insert_hint(1, (void*)key, hint, 1);
        return hint;
    }
    Node* header = this->header;
    Node* node = (Node*)hint;
    if (node == header->parent) {
        if (less_str((char*)node + 0xc, key)) {
            insert_hint(1, (void*)key, hint, 1);
            return hint;
        }
    } else if (node == header) {
        Node* left = header->parent;
        if (less_str(key, (char*)left + 0xc)) {
            insert_hint(0, (void*)left, hint, 1);
            return hint;
        }
    } else {
        if (less_str((char*)node + 0xc, key)) {
            void* next = find_hint(node, (void*)key);
            if (next != 0) {
                insert_hint(1, (void*)next, hint, 1);
                return hint;
            }
        }
    }
    if (less_str(key, (char*)node + 0xc)) {
        void* prev = lower_bound(node, (void*)key);
        if (prev != 0) {
            insert_hint(0, (void*)prev, hint, 1);
            return hint;
        }
    }
    void* result = erase_hint(hint);
    *(void**)hint = result;
    return hint;
}
