// from server: 49% by Intel
struct TypedPropertyDescriptor {
    void* base;
    void* limit;
    void* current;
    unsigned int count;

    void Release();
};

extern "C" void __stdcall sub_982114(void*);

void TypedPropertyDescriptor::Release() {
    int index = 0;
    if (count > 0) {
        do {
            current = static_cast<char*>(current) + 0x38;
            ++index;
            if (current == limit) {
                current = base;
            }
        } while (index < count);
    }
    void* head = base;
    if (head) {
        sub_982114(head);
    }
}
