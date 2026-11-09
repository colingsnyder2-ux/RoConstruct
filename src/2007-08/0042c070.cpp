// from server: 64% by colin
struct Node {
    Node* next;
    char pad[4];
    int value;
};

struct Result {
    void* f0;
    void* f4;
    void* f8;
};

void process(Node* first, Node* last, void* fn, void* arg, Result* out);

void process(Node* first, Node* last, void* fn, void* arg, Result* out)
{
    Node* cur = first;
    while (cur != last) {
        ((void (__stdcall*)(int, void*))fn)(cur->value, arg);
        cur = cur->next;
    }
    out->f0 = fn;
    out->f4 = arg;
    out->f8 = last;
}
