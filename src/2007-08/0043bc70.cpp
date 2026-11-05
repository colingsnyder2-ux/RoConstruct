// from server: 25% by colin
struct EnumDescriptor;

struct Item {
    const EnumDescriptor& owner;
    const int value;
    const unsigned int index;
};

struct EnumDescriptor {
    char pad0[4];
    Item** itemsBegin;
    Item** itemsEnd;
    unsigned int enumCount;
    unsigned int enumCountMSB;
    bool convertToValue(unsigned int index, void* value) const;
    bool convertToString(unsigned int index, void* value) const;
    float getValue(unsigned int index) const;
};

struct EnumDesc {
    char pad0[0x100];
    EnumDescriptor desc;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void __stdcall sub_77ddb8(void*, const char*);

extern "C" void __stdcall sub_697d10(void*, int);

extern "C" void __stdcall sub_698630(void*);

extern "C" void __stdcall sub_439d10(void*, void*, void*);

extern "C" float __stdcall sub_43bbe0(void*, int);

struct EnumDescHelper {
    bool f(void* arg);
};

bool EnumDescHelper::f(void* arg) {
    EnumDesc* self = (EnumDesc*)((char*)this - 0x100);
    Item** it = self->desc.itemsBegin;
    Item** end = self->desc.itemsEnd;
    Item** savedEnd = end;
    bool found = false;
    void* p = *(void**)((char*)arg + 4);
    void* local1c;
    void* local2c;
    sub_439d10(&local1c, &local2c, p);
    Item** cur = (Item**)local2c;
    if (cur != (Item**)p) {
        while (1) {
            Item* item = *cur;
            Item** iit = (Item**)((char*)item + 0x10);
            Item** iend = (Item**)((char*)item + 0x18);
            Item** icur = *(Item***)((char*)item + 0x14);
            if (icur > iend) {
                _invalid_parameter_noinfo();
            }
            if (iit != iit) {
                _invalid_parameter_noinfo();
            }
            if (icur != iend) {
                while (1) {
                    if (!found) {
                        float v = sub_43bbe0(self, *(int*)icur);
                        ((void(__thiscall*)(EnumDescriptor*, float*))(*(void***)&self->desc)[0x3a])(&self->desc, &v);
                    } else {
                        float v = sub_43bbe0(self, *(int*)icur);
                        float v2;
                        if (!((bool(__thiscall*)(EnumDescriptor*, float*, float*))(*(void***)&self->desc)[0x3b])(&self->desc, &v2, &v)) {
                            goto fail;
                        }
                    }
                    found = true;
                    icur += 2;
                    if (icur == iend) break;
                }
            }
            cur += 1;
            if (cur == (Item**)p) break;
        }
    }
    {
        int flag = found ? 0 : 1;
        sub_697d10(self, flag);
    }
    return found;
fail:
    {
        void* tmp;
        sub_77ddb8(&tmp, "list<T> too long");
        sub_698630(self);
        sub_697d10(self, 0);
    }
    return false;
}
