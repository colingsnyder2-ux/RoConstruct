// from server: 52% by colin
struct Node {
    char pad0[4];
    int value;
    char pad1[0xb4];
    Node* next;
};

struct VClient {
    char pad[0xbc];
    Node* head;
    char pad2[0x1da8 - 0xbc - 4];
    Node sentinel;
    bool check(int arg);
};

extern "C" int __stdcall sub_605550(void* self, void* out, void* out2);
extern "C" void __stdcall _invalid_parameter_noinfo();

bool VClient::check(int arg) {
    Node* n = this->head;
    if (n == 0) {
        return false;
    }
    Node* end = &this->sentinel;
    do {
        int saved = end->value;
        void* local1 = 0;
        void* local2 = 0;
        sub_605550(end, &local1, &local2);
        void** p = (void**)local1;
        if (*p != 0 && *p != end) {
            _invalid_parameter_noinfo();
        }
        if (*(int*)((char*)local1 + 4) != saved) {
            return true;
        }
        n = *(Node**)((char*)n + 0xbc);
    } while (n != 0);
    return false;
}
