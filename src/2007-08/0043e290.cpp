// from server: 38% by colin
struct Descriptor {
    Descriptor(const char*, unsigned int);
};

struct EnumDescriptor;

struct Item : Descriptor {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
    Item(const char*, unsigned int, int, unsigned int, const EnumDescriptor&);
};

struct EnumDescriptor {
    char pad0[0xb4];
    void* field_b4;
    char pad1[0x110 - 0xb8];
    int field_110;
    bool convertToValue(unsigned int, void*) const;
    bool convertToString(unsigned int, void*) const;
    void addItem(unsigned int, int, void*, unsigned int, int);
};

struct Name {
    char pad[4];
    void* ptr;
};

extern "C" void* __stdcall sub_69ab30(void*);
extern "C" void __stdcall sub_69ec10(void*);
extern "C" void __stdcall sub_69e890(void*, unsigned int, int, void*, int);
extern "C" void __stdcall DrawFrameControl(void*, void*, unsigned int, unsigned int);

Item::Item(const char* name, unsigned int attributes, int value_, unsigned int index_, const EnumDescriptor& owner_)
    : Descriptor(name, attributes), owner(owner_), value(value_), index(index_)
{
    if (owner_.field_110 == 0)
        return;

    int a = (int)index_ - 1;
    int b = (int)index_ + 0xc;
    int c = (int)index_ + 0x20;
    int d = (int)index_ + 0x28;
    int e = (c + d) / 2;
    int f = e - 6;
    int g = e + 7;

    void* p = sub_69ab30(owner_.field_b4);
    if (*(int*)((char*)p + 4) == 1) {
        void* q = (char*)p + 0x10;
        sub_69ec10(q);
        if (*(int*)((char*)p + 4) != 0) {
            int r;
            if (owner_.convertToValue(index_, &a)) {
                if (owner_.convertToString(index_, &a))
                    r = 0xc;
                else
                    r = 4;
            } else {
                if (owner_.convertToString(index_, &a))
                    r = 9;
                else
                    r = 1;
            }
            void* n = 0;
            if (name != 0)
                n = *(void**)((char*)name + 4);
            sub_69e890(q, 3, r, &a, 0);
            return;
        }
    }

    int r2 = owner_.convertToString(index_, &a) ? 0x400 : 0;
    int r3 = owner_.convertToValue(index_, &a) ? 0x100 : 0;
    DrawFrameControl(*(void**)((char*)name + 4), &a, 4, r2 | r3);
}
