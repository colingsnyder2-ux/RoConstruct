// from server: 48% by Intel
struct Node {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct Container {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    Node* field_10;
};

extern "C" void __stdcall sub_966F60(Container*);

void __cdecl sub_9671F0(int a1, int a2, int a3) {
    if (a3 == -1) {
        return;
    }
    int* ptr = reinterpret_cast<int*>(a2);
    int val = *ptr;
    if (val == -1) {
        *ptr = a3;
        return;
    }
    Container* container = reinterpret_cast<Container*>(a1);
    Node* node = container->field_10;
    int ecx = val;
    while (true) {
        int edx = node[ecx].field_C;
        edx >>= 14;
        edx -= 0x1FFFF;
        if (edx == -1) {
            break;
        }
        int next = edx + ecx + 1;
        if (next == -1) {
            break;
        }
        ecx = next;
    }
    sub_966F60(container);
}
