// from server: 27% by colin
struct RBXName;

struct Descriptor {
    Descriptor(const char* name, int attributes);
};

struct EnumDescriptor;

struct EnumItem : Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
    EnumItem(const char* name, int attributes, int value, unsigned int index, const EnumDescriptor& owner);
};

struct EnumDescriptor {
    char pad[0x104];
    void* allItemsBegin;
    void* allItemsEnd;
    void* allItemsCap;
    char pad2[0x10c - 0x110 + 0x10c];
    void* field_10c;
    void* field_110;
    void* field_114;

    void addItem(const EnumItem* item);
    void convertToIndex(int value, int* out);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void __stdcall sub_439D10(void* a, void* b);
extern "C" void __stdcall sub_448EA0(void* a);
extern "C" void* __stdcall sub_49D670(void* a, void* b);
extern "C" void* __stdcall sub_62FF02();
extern "C" void* __stdcall sub_630D36(void* a, void* b, void* c, void* d, void* e);

void EnumDescriptor::addItem(const EnumItem* item) {
    void** begin = (void**)((char*)this + 0x104);
    void** end = (void**)((char*)this + 0x108);
    void** cap = (void**)((char*)this + 0x10c);

    if (*end > *cap) {
        _invalid_parameter_noinfo();
    }

    void* e = *end;
    void* c = *cap;
    if (e > c) {
        _invalid_parameter_noinfo();
    }

    if (begin != 0) {
        if (begin != begin) {
            _invalid_parameter_noinfo();
        }
    } else {
        _invalid_parameter_noinfo();
    }

    while (e != c) {
        if (begin == 0) {
            _invalid_parameter_noinfo();
        }
        if (e < *end) {
            _invalid_parameter_noinfo();
        }

        int val = *(int*)e;
        void* result = sub_630D36((void*)val, (void*)0x881f4c, (void*)0x884f70, (void*)0, (void*)0);
        if (result != 0) {
            void* tmp;
            sub_49D670(&tmp, result);
            void* v = sub_62FF02();
            sub_448EA0(*(void**)((char*)v + 4));
        }

        if (e < *end) {
            _invalid_parameter_noinfo();
        }
        e = (char*)e + 8;
    }

    if (*end < *cap) {
        _invalid_parameter_noinfo();
    }
    *end = (char*)*end + 4;
}
