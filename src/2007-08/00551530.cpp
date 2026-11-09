// from server: 31% by colin
struct Node {
    Node* next;
    Node* prev;
    int value;
};

struct List {
    Node* head;
};

struct StreamBuf {
    char pad0[4];
    List* list;
    char pad8[4];
    void* field_c;
    char pad10[0xc];
    unsigned char flags_1c;
};

struct GzipDecompressor {
    StreamBuf* buf;
};

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* p);
    void __stdcall invalid_parameter_noinfo();
    void* __stdcall string_ctor(void* self, const char* s);
}

struct String {
    char pad[0x1c];
    String(const char* s);
};

struct S {
    GzipDecompressor* gz;
    void func(int a, int b, int c);
};

void S::func(int a, int b, int c) {
    StreamBuf* sb = gz->buf;
    if (sb->flags_1c & 1) {
        String s("chain complete");
        invalid_parameter_noinfo();
    }
    int val = 0;
    if (sb->list->head != 0) {
        Node* n = sb->list->head->next;
        if (n == sb->list->head) {
            invalid_parameter_noinfo();
        }
        if (n == sb->list->head) {
            invalid_parameter_noinfo();
        }
        val = n->value;
    }
    int size = a;
    if (size == -1) size = 0x80;
    int count = b;
    if (count == -1) count = sb->list->head->value;
    void* mem = operator_new(0x60);
    Node* newNode = 0;
    if (mem != 0) {
        newNode = (Node*)mem;
        newNode->next = 0;
        newNode->prev = 0;
        newNode->value = 0;
    }
    Node* head = sb->list->head;
    Node* first = head->next;
    newNode->value = count;
    newNode->next = first;
    newNode->prev = head;
    first->prev = newNode;
    head->next = newNode;
    if (val != 0) {
        void* p = (void*)val;
        void** vtbl = *(void***)p;
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0x38/4];
        fn(p, first->value);
    }
    if (sb->field_c != 0) {
        void* p = sb->field_c;
        void** vtbl = *(void***)p;
        void (*fn)(void*) = (void (*)(void*))vtbl[1];
        fn(p);
    }
}
