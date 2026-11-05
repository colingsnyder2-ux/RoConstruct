// from server: 100% by king_originala
struct String
{
    char* value;
    String() : value(0) {}
    String(const String&);
    ~String();
};

extern const char* (__thiscall *getString)(const String*);

struct Registry
{
    char storage[0x5C];
    Registry(int loading, String parent, const char* section);
    ~Registry();
    int open(const char* name);
};

struct Switch
{
    void set(int value);
};

struct State
{
    void set(int value);
};

struct Frame
{
    char padding0[0x104];
    unsigned char pending;
    unsigned char blocked;
    char padding1[2];
    String name;
    char padding2[0x178];
    Switch option;
    char padding3[0x15B];
    State state;

    void load(int value);
    void exchange(Registry* registry, int loading);
    void reset();
    void finish();
    void restore(int value);
};

void Frame::restore(int value)
{
    if (pending && !blocked)
    {
        state.set(5);
        load(value);
        option.set(1);

        Registry registry(1, String(), "IDE");
        if (registry.open(getString(&name)))
            exchange(&registry, 1);
        else
        {
            reset();
            finish();
        }

        pending = 0;
    }
}
