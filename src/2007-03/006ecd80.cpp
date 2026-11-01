// from server: 100% by tester
struct CXTColorHex {
    char pad[0x74];
    int field_74;
    char pad2[0x80 - 0x74 - 4];
    struct Node* field_80;
    int func(int arg);
};

struct Node {
    Node* next;
    char pad[4];
    Node* field_8;
    char pad2[0x18 - 8 - 4];
    int field_18;
};

int CXTColorHex::func(int arg) {
    Node* node = field_80;
    bool found = false;
    if (node != 0) {
        do {
            Node* inner = node->field_8;
            if (inner != 0) {
                if (arg == inner->field_18) {
                    if (arg != 0xffffff || found || field_74 < 0xb0) {
                        return (int)inner;
                    }
                    found = true;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return 0;
}
