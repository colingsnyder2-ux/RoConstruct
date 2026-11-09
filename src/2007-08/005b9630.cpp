// from server: 34% by colin
// roc 2007-08 005b9630  unit: RBX::VFaceInstance::?$EnumPropDescriptor  size: 774 bytes

extern "C" {
    void* __stdcall sub_52C940(int, const char*);
    void __stdcall sub_77E6A4(void*);
    void __stdcall sub_77E6AC(void*);
}

struct String {
    char buf[16];
    String();
    ~String();
};

struct EnumDescBase {
    void* vftable;
};

struct DescribedBase {
    void* vftable;
};

struct EnumPropertyDescriptor {
    void* vftable;
};

struct GetSet {
    void* vftable;
};

struct EnumPropDescriptor : EnumPropertyDescriptor {
    GetSet* getset;
    const EnumDescBase* enumDesc;

    void setValue(DescribedBase* object, int value);
    void setValue(DescribedBase* object, float value);
    void setValue(DescribedBase* object, void* value);
    void setValue(DescribedBase* object, const String& value);
};

struct Node {
    Node* next;
    void* value;
};

struct PropMap {
    void* vftable;
    Node* head;
};

struct Instance {
    void* vftable;
    PropMap* props;
};

struct EnumPropDescriptorImpl : EnumPropDescriptor {
    void construct(const char* name, const char* category);
};

extern int dword_8C65D4;
extern void* dword_8C65D0;
extern void* dword_8C65CC;
extern void* dword_8C65C8;
extern void* dword_8C65C4;
extern void* dword_8C65C0;
extern void* dword_8C2298;

bool __stdcall sub_55D8A0(void*);
void* __stdcall sub_55D3B0(void*, void*);
bool __stdcall sub_55D460(void*, void*);
bool __stdcall sub_55D310(void*, void*);
bool __stdcall sub_55D710(void*, void*);
void* __stdcall sub_5B7E80(void*, void*);
void* __stdcall sub_5B7EE0(void*, void*);
bool __stdcall sub_5DC2A0(void*);

void EnumPropDescriptorImpl::construct(const char* name, const char* category)
{
    if (!(dword_8C65D4 & 1)) {
        dword_8C65D4 |= 1;
        dword_8C65D0 = sub_52C940(-1, (const char*)0x787EDC);
    }
    if (!(dword_8C65D4 & 2)) {
        dword_8C65D4 |= 2;
        dword_8C65CC = sub_52C940(-1, (const char*)0x7B8D54);
    }
    if (!(dword_8C65D4 & 4)) {
        dword_8C65D4 |= 4;
        dword_8C65C8 = sub_52C940(-1, (const char*)0x7B8D4C);
    }
    if (!(dword_8C65D4 & 8)) {
        dword_8C65D4 |= 8;
        dword_8C65C4 = sub_52C940(-1, (const char*)0x7B8D44);
    }
    if (!(dword_8C65D4 & 0x10)) {
        dword_8C65D4 |= 0x10;
        dword_8C65C0 = sub_52C940(-1, (const char*)0x7B8D38);
    }

    Instance* inst = (Instance*)this;
    Node* node = inst->props->head;
    while (node) {
        void* key = node->value;
        if (key) {
            if (sub_55D8A0(key)) {
                node = node->next;
                continue;
            }
            void* desc = sub_55D3B0(key, dword_8C2298);
            if (!desc) {
                node = node->next;
                continue;
            }
            void* propName = 0;
            if (!sub_55D460((char*)desc + 4, &propName)) {
                node = node->next;
                continue;
            }
            if (propName == dword_8C65D0) {
                String str;
                sub_77E6A4(&str);
                if (sub_55D310((char*)key + 0xC, &str)) {
                    void* val = 0;
                    void* tmp = 0;
                    void* r = sub_5B7E80(&str, &tmp);
                    if (sub_5DC2A0(r)) {
                        this->setValue((DescribedBase*)key, *(int*)&val);
                    } else {
                        this->setValue((DescribedBase*)key, 0);
                    }
                }
                sub_77E6AC(&str);
            } else if (propName == dword_8C65CC) {
                String str;
                sub_77E6A4(&str);
                if (sub_55D310((char*)key + 0xC, &str)) {
                    void* val = 0;
                    void* r = sub_5B7EE0(&str, &val);
                    if (sub_5DC2A0(r)) {
                        this->setValue((DescribedBase*)key, *(int*)&val);
                    }
                }
                sub_77E6AC(&str);
            } else if (propName == dword_8C65C8) {
                float f = 0.0f;
                if (sub_55D710((char*)key + 0xC, &f)) {
                    this->setValue((DescribedBase*)key, f);
                }
            } else if (propName == dword_8C65C4) {
                float f = 0.0f;
                if (sub_55D710((char*)key + 0xC, &f)) {
                    this->setValue((DescribedBase*)key, f);
                }
            } else if (propName == dword_8C65C0) {
                String str;
                sub_77E6A4(&str);
                if (sub_55D310((char*)key + 0xC, &str)) {
                    void* val = 0;
                    void* r = sub_5B7E80(&str, &val);
                    if (sub_5DC2A0(r)) {
                        if (val) {
                            this->setValue((DescribedBase*)key, val);
                        }
                    }
                }
                sub_77E6AC(&str);
            }
        }
        node = node->next;
    }
}
