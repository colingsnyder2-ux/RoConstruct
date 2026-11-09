// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /hotpatch
// from server: 57% by king_originala
#pragma optimize("s", on)

extern char byte_96dcf8;
extern int dword_97f2ac;

struct Tail {
    ~Tail() {}
};

struct Item {
    char padding[0x10];
    struct Interface *object;
};

struct Interface;

struct InterfaceTable {
    void *entry0;
    void *entry1;
    unsigned long (__stdcall *release)(Interface *);
};

struct Interface {
    InterfaceTable *table;
};

struct CXTIconHandle {
    int field0;
    int field4;
    Item **field8;
    Item **fieldC;
    char field10[0x10];
    Tail field20;

    CXTIconHandle();
    ~CXTIconHandle();
    void method_7a6116();
    void method_7a61d8();
};

extern "C" int __stdcall sub_7a60c2(CXTIconHandle *);
extern "C" void __stdcall sub_7a6132(CXTIconHandle *, int);
extern "C" void (__stdcall *DeleteCriticalSection)(void *);

CXTIconHandle::CXTIconHandle()
{
    method_7a6116();
    field0 = 0x2c;
    if (sub_7a60c2(this) < 0) {
        byte_96dcf8 = 1;
        field0 = 0;
    }
}

CXTIconHandle::~CXTIconHandle()
{
    sub_7a6132(this, dword_97f2ac);
}

void CXTIconHandle::method_7a61d8()
{
    if (field0 != 0) {
        Item **p = field8;
        while (p < fieldC) {
            Item *item = *p;
            if (item != 0) {
                Interface *object = item->object;
                if (object != 0)
                    object->table->release(object);
                item->object = 0;
            }
            ++p;
        }
        DeleteCriticalSection(field10);
        field0 = 0;
    }
}


