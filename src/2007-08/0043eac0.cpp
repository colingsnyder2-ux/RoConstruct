// from server: 11% by colin
struct EnumDescriptor;

struct Item {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
};

struct EnumDescriptor {
    char pad0[4];
    void* allItemsBegin;
    void* allItemsEnd;
    char pad1[0x10];
    void* vtable;
    void addLegacyName(const char* name, int value);
    void addLegacy(const char* name, int value);
    void addPair(const char* name, int value);
    void convertToIndex(int value, void* out);
    void convertToValue(unsigned int index, void* out);
    void convertToString(unsigned int index, void* out);
    void method(int* arg);
};

extern "C" void __stdcall sub_77e6d8();
extern "C" void __stdcall sub_77e698(void*);
extern "C" void __stdcall sub_77e6ac(void*);
extern "C" void __stdcall sub_77ddb8(void*, const char*);
extern "C" void __cdecl sub_439d10(void*, void*, void*);
extern "C" void __cdecl sub_698630(void*);
extern "C" void __cdecl sub_697d10(void*, int);

void EnumDescriptor::method(int* arg) {
    int* p = arg;
    int val = p[1];
    void* it = allItemsBegin;
    void* end = allItemsEnd;
    bool found = false;
    while (it != end) {
        void* cur = it;
        int* item = *(int**)cur;
        int itemVal = item ? item[1] : 0;
        if (itemVal == val) {
            found = true;
            break;
        }
        it = (char*)it + 4;
    }
    if (!found) {
        sub_697d10(this, 0);
    } else {
        sub_697d10(this, 1);
    }
}
