// from server: 100% by colin
struct S {
    char pad[0x18];
    void* field_18;
    void* field_1c;
    void* method(int a, int b);
};

extern "C" void* __cdecl sub_0062fef6(unsigned int size);

void* S::method(int a, int b)
{
    void* p = sub_0062fef6(0x10);
    if (p) {
        *(int*)((char*)p + 0) = 0;
        *(int*)((char*)p + 4) = a;
        *(int*)((char*)p + 8) = 1;
        *(int*)((char*)p + 12) = b;
    } else {
        p = 0;
    }
    if (this->field_1c == 0) {
        this->field_18 = p;
        this->field_1c = p;
    } else {
        *(void**)this->field_1c = p;
        this->field_1c = p;
    }
    return p;
}
