// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    ~String();
};

extern void (__thiscall *destroyString)(String *);

__forceinline String::~String()
{
    destroyString(this);
}

struct EnumDescriptor {
    String format(const int &value);
};

extern EnumDescriptor *__cdecl getEnumDescriptor();
extern void __cdecl initializeEnum();
extern int enumInitializationFlag;
extern void __cdecl initializeOnce(void (__cdecl *function)(), int *flag);
extern unsigned char typeProperty;

struct S {
    unsigned char padding[0x1A0];
    int type;

    void notify(void *property);
    void setName(const String &name);
    void setType(int value);
};

void S::setType(int value)
{
    if (value != type) {
        type = value;
        notify(&typeProperty);
        if (type != 0) {
            initializeOnce(initializeEnum, &enumInitializationFlag);
            EnumDescriptor *descriptor = getEnumDescriptor();
            String name = descriptor->format(type);
            setName(name);
        }
    }
}
