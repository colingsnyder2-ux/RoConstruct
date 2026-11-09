// from server: 27% by colin
extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo(void);
extern "C" __declspec(dllimport) void __stdcall sub_77DDB8(void*, const char*);

struct Name;
struct Variant;

struct EnumDescriptor;

struct Item {
    const EnumDescriptor* owner;
    const int value;
    const unsigned int index;
};

struct EnumDescriptor {
    char pad0[4];
    void* allItemsBegin;
    void* allItemsEnd;
    void* allItemsCap;
    unsigned int enumCount;
    unsigned int enumCountMSB;
    char pad1[0x100 - 0x18];
    void* nameTable;
    char pad2[0x108 - 0x104];
    void* nameTableEnd;

    bool convertToValue(unsigned int index, Variant& value) const;
    bool convertToString(unsigned int index, void* str) const;
};

struct Variant {
    void* data;
};

struct EnumItem : public Item {
    bool convertToValue(Variant& value) const;
    bool convertToString(void* str) const;
};

struct EnumConverter {
    char pad0[4];
    void* begin;
    void* end;
    void* cap;

    void* find(const Name* name);
    void* convertToValue(const Name* name, Variant& value);
    void* convertToString(const Name* name, void* str);
};

extern "C" void __stdcall sub_439D10(void* out, void* in, void* arg);
extern "C" void __stdcall sub_43C400(void* out, void* in, void* arg);
extern "C" void __stdcall sub_697D10(void* self, int arg);
extern "C" void __stdcall sub_698630(void* self);

struct VBrickColor {
    char pad0[4];
    void* begin;
    void* end;
    void* cap;

    bool convertToValue(const Name* name, Variant& value);
    bool convertToString(const Name* name, void* str);
};

bool VBrickColor::convertToValue(const Name* name, Variant& value) {
    void* cur = this->begin;
    void* end = this->end;
    unsigned char found = 0;
    void* savedCur = cur;

    if (cur > end) {
        _invalid_parameter_noinfo();
    }

    void* it = cur;
    void* itEnd = this->end;

    if (this->begin > itEnd) {
        _invalid_parameter_noinfo();
    }

    if (this != 0) {
        if (this != this) {
            _invalid_parameter_noinfo();
        }
    } else {
        _invalid_parameter_noinfo();
    }

    while (it != itEnd) {
        if (this != 0) {
            _invalid_parameter_noinfo();
        }
        if (it >= this->end) {
            _invalid_parameter_noinfo();
        }

        const Item* item = *(const Item**)it;

        void* tmp1;
        void* tmp2;
        sub_439D10(&tmp1, &tmp2, (void*)name);

        void* foundIt = tmp1;
        if (foundIt != this->begin) {
            if (this == 0) {
                _invalid_parameter_noinfo();
            }
            if (foundIt == this->end) {
                _invalid_parameter_noinfo();
            }

            const Item* foundItem = *(const Item**)foundIt;

            if (!found) {
                Variant v;
                sub_43C400(&v, &foundItem, (void*)name);
                Variant* vp = &v;
                void* self = (char*)this - 0x10c;
                void* vtbl = *(void**)self;
                void (*fn)(void*, Variant*) = *(void (**)(void*, Variant*))((char*)vtbl + 0xf4);
                fn(self, vp);
            } else {
                void* self = (char*)this - 0x10c;
                void* owner = *(void**)((char*)self - 0x10c);
                owner = (char*)owner + 0xf8;
                Variant v;
                sub_43C400(&v, &foundItem, (void*)name);
                void* vtbl = *(void**)owner;
                bool (*fn)(void*, Variant*, Variant*) = *(bool (**)(void*, Variant*, Variant*))vtbl;
                if (!fn(owner, &v, &value)) {
                    sub_77DDB8(0, "list<T> too long");
                    sub_698630((char*)this - 0x10c);
                    sub_697D10((char*)this - 0x10c, 0);
                    return false;
                }
            }

            found = 1;
            it = (char*)it + 8;
        } else {
            it = (char*)it + 8;
        }
    }

    sub_697D10((char*)this - 0x10c, found ? 0 : 1);
    return found != 0;
}
