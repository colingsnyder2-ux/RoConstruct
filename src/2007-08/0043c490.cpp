// from server: 18% by colin
struct RBXName {
    void* dummy;
};

struct EnumDescriptor;

struct EnumItem {
    const char* name;
    unsigned int attributes;
    int value;
    unsigned int index;
    EnumDescriptor* owner;
};

struct EnumDescriptor {
    void* vtable;
    EnumItem** allItemsBegin;
    EnumItem** allItemsEnd;
    EnumItem** allItemsCap;
    unsigned int enumCount;
    unsigned int enumCountMSB;
};

struct NameLookup {
    void* dummy;
};

struct Variant {
    char data[64];
};

struct String {
    char data[28];
};

struct EnumDescriptorHelper {
    EnumDescriptor* self;
};

extern "C" void __stdcall _invalid_parameter_noinfo(void);
extern "C" void __stdcall sub_77DDB8(void*, const char*);
extern "C" void __stdcall sub_77E6D8(void);

extern "C" void __cdecl sub_439D10(void*, void*, void*);
extern "C" void __cdecl sub_43C400(void*, void*, void*);
extern "C" void __cdecl sub_697D10(void*, int);
extern "C" void __cdecl sub_698630(void*);

struct EnumDescriptor2 {
    void* vtable;
    EnumItem** allItemsBegin;
    EnumItem** allItemsEnd;
    EnumItem** allItemsCap;
    unsigned int enumCount;
    unsigned int enumCountMSB;

    void convertToValue(int index, Variant& value);
    void convertToString(int index, String& value);
    bool convertToValue2(int index, Variant& value);
    void convertToString2(int index, String& value);
    void throwListTooLong();
    void finalize(bool flag);
};

void EnumDescriptor2::convertToValue(int index, Variant& value)
{
    EnumItem** it = allItemsBegin;
    EnumItem** end = allItemsEnd;
    bool found = false;

    while (it != end) {
        EnumItem* item = *it;
        if (item->index == (unsigned int)index) {
            found = true;
            break;
        }
        ++it;
    }

    if (found) {
        EnumItem* item = *it;
        Variant tmp;
        sub_43C400(this, &tmp, item);
        float* f = (float*)&tmp;
        float r = f[0];
        float g = f[1];
        float b = f[2];
        void (__thiscall *fn)(void*, float*) =
            *(void (__thiscall **)(void*, float*))(*(unsigned int*)this + 0xf4);
        float color[3];
        color[0] = r;
        color[1] = g;
        color[2] = b;
        fn(this, color);
    }
}

void EnumDescriptor2::convertToString(int index, String& value)
{
    EnumItem** it = allItemsBegin;
    EnumItem** end = allItemsEnd;
    bool found = false;

    while (it != end) {
        EnumItem* item = *it;
        if (item->index == (unsigned int)index) {
            found = true;
            break;
        }
        ++it;
    }

    if (found) {
        EnumItem* item = *it;
        Variant tmp;
        sub_43C400(this, &tmp, item);
        void (__thiscall *fn)(void*, Variant*, String*) =
            *(void (__thiscall **)(void*, Variant*, String*))(*(unsigned int*)this + 0xf8);
        fn(this, &tmp, &value);
    }
}

bool EnumDescriptor2::convertToValue2(int index, Variant& value)
{
    EnumItem** it = allItemsBegin;
    EnumItem** end = allItemsEnd;
    bool found = false;

    while (it != end) {
        EnumItem* item = *it;
        if (item->index == (unsigned int)index) {
            found = true;
            break;
        }
        ++it;
    }

    if (found) {
        EnumItem* item = *it;
        Variant tmp;
        sub_43C400(this, &tmp, item);
        float* f = (float*)&tmp;
        float r = f[0];
        float g = f[1];
        float b = f[2];
        void (__thiscall *fn)(void*, float*) =
            *(void (__thiscall **)(void*, float*))(*(unsigned int*)this + 0xf4);
        float color[3];
        color[0] = r;
        color[1] = g;
        color[2] = b;
        fn(this, color);
        return true;
    }
    return false;
}

void EnumDescriptor2::convertToString2(int index, String& value)
{
    EnumItem** it = allItemsBegin;
    EnumItem** end = allItemsEnd;
    bool found = false;

    while (it != end) {
        EnumItem* item = *it;
        if (item->index == (unsigned int)index) {
            found = true;
            break;
        }
        ++it;
    }

    if (found) {
        EnumItem* item = *it;
        Variant tmp;
        sub_43C400(this, &tmp, item);
        void (__thiscall *fn)(void*, Variant*, String*) =
            *(void (__thiscall **)(void*, Variant*, String*))(*(unsigned int*)this + 0xf8);
        fn(this, &tmp, &value);
    }
}

void EnumDescriptor2::throwListTooLong()
{
    String s;
    sub_77DDB8(&s, "list<T> too long");
    sub_698630(this);
    sub_697D10(this, 0);
}

void EnumDescriptor2::finalize(bool flag)
{
    sub_697D10(this, flag ? 0 : 1);
}
