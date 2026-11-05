// from server: 21% by colin
struct EventArguments {
    void* data[8];
    EventArguments();
    ~EventArguments();
    void* operator[](int i);
};

struct GenericSlotWrapper {
    virtual ~GenericSlotWrapper();
    virtual void execute(const EventArguments& arguments) = 0;
};

struct CountableBase {
    void addRef();
    void release();
};

struct TGenericSlotWrapper : GenericSlotWrapper, CountableBase {
    void* slot;
    char pad[0x20];
    int field24;
    char pad2[0x20];
    int field48;
    char pad3[0x30];
    EventArguments args;

    TGenericSlotWrapper(const void* s);
    virtual ~TGenericSlotWrapper();
    virtual void execute(const EventArguments& arguments);
};

extern "C" {
    void __stdcall sub_5C37D0(void*);
    void __stdcall sub_570030(void*);
    void __stdcall sub_62FC62(void*);
    void __stdcall sub_728350(void*);
    void* __stdcall sub_5BE820(void*);
    void __stdcall sub_56C7A0(void*, void*, void*);
    void __stdcall sub_5BD510(void*, void*, int);
    void* __stdcall sub_5C3E20(void*, void*);
    void* __stdcall sub_53AAC0(void*, void*, void*);
    void __stdcall sub_5376E0(void*);
    void __stdcall sub_56C8F0(void*, void*);
    void __stdcall sub_56CC00(void*, void*);
    void __stdcall sub_56CB10(void*);
    void __stdcall sub_5BD590(void*, int);
    void __stdcall sub_412DC0(void*, void*);
    void __stdcall sub_630B9E(void*, void*);
    void __stdcall sub_77E698(void*, const char*);
}

TGenericSlotWrapper::TGenericSlotWrapper(const void* s)
{
    slot = (void*)s;
    field24 = 0;
    field48 = 0;
    sub_5C37D0(&args);
    sub_570030(this);
}

TGenericSlotWrapper::~TGenericSlotWrapper()
{
    sub_5C37D0(&args);
    sub_570030(this);
}

void TGenericSlotWrapper::execute(const EventArguments& arguments)
{
    int* p = (int*)this;
    int v24 = p[9];
    if (v24 == 0) {
        sub_728350(*(void**)this);
        return;
    }
    int v48 = p[18];
    char flag = 0;
    if (v48 == 0) {
        void* r = sub_5BE820((void*)v24);
        v48 = (int)r;
        if (r == 0) {
            char buf[0x40];
            sub_77E698(buf, "lua_newthread failed");
            sub_412DC0(buf, &buf[0x40]);
            sub_630B9E(&buf[0x40], (void*)0x8410C0);
        }
        flag = 1;
    }
    sub_56C7A0((void*)v24, (char*)this + 0xc, (void*)v48);
    sub_5BD510((void*)v24, (void*)v48, 1);
    void* r2 = sub_5C3E20((void*)v48, (void*)arguments.data[0]);
    void* r3 = sub_53AAC0(*(void**)((char*)this + 8), (void*)v48, r2);
    int v = (int)r3;
    int cmp = v - 1;
    if (cmp == 0) {
        sub_5376E0((char*)this + 0x30);
    } else {
        cmp = cmp - 1;
        if (cmp == 0) {
            sub_5376E0((char*)this + 0x30);
            sub_728350(*(void**)this);
        }
    }
    if (p[9] == 0) {
        sub_728350(*(void**)this);
    }
    if (flag) {
        if (v == 0 && p[9] != 0) {
            void* tmp;
            sub_56C8F0(&tmp, (void*)v48);
            sub_56CC00((char*)this + 0x30, tmp);
            sub_56CB10(&tmp);
        }
        sub_5BD590((void*)v24, -2);
    }
    sub_5BD590((void*)v48, 0);
}
