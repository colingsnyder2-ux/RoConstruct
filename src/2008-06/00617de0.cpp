// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void *);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char data[20];
    virtual ~Base();
};

struct S : Base {
    char string_data[28];
    virtual ~S();
};

S::~S()
{
    destroy_string(string_data);
}
