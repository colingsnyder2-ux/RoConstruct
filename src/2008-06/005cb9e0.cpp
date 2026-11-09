// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

extern char table_83a2bc[];
extern char table_83a2b0[];
extern char table_83a2a8[];
extern char table_83a2a0[];
extern char table_83a290[];
extern char table_83a280[];
extern char table_83a270[];
extern char table_83a260[];
extern char table_83a250[];
extern char table_83a240[];
extern char table_81e1e0[];
extern char table_839fa4[];
extern char table_839fbc[];
extern char table_832a04[];

struct Base {
    unsigned char data[0x130];
    Base();
    ~Base();
};

struct Layer : Base {
    unsigned int first;
    Layer();
    ~Layer();
};

__forceinline Layer::Layer() : Base() {
    *(void**)(data + 0x00) = table_83a2bc;
    *(void**)(data + 0x10) = table_83a2b0;
    *(void**)(data + 0x14) = table_83a2a8;
    *(void**)(data + 0x20) = table_83a2a0;
    *(void**)(data + 0x24) = table_83a290;
    *(void**)(data + 0x44) = table_83a280;
    *(void**)(data + 0x64) = table_83a270;
    *(void**)(data + 0x84) = table_83a260;
    *(void**)(data + 0xa4) = table_83a250;
    *(void**)(data + 0xc4) = table_83a240;
    first = 0;
}

struct Pair {
    unsigned int second;
    Pair();
    ~Pair();
};

inline Pair::Pair() : second(0) {}

struct Reference {
    void* pointer;
    Reference(void*);
    ~Reference();
    void reset(void*);
};

inline Reference::Reference(void* p) : pointer(0) {
    reset(p);
}

struct Controller;

struct CallbackA {
    void* volatile table;
    unsigned int first;
    unsigned int second;
    Controller* owner;
    CallbackA(Controller*);
};

inline CallbackA::CallbackA(Controller* p)
    : table(table_81e1e0), first(0), second(0), owner(p) {
    table = table_839fa4;
}

struct CallbackB {
    void* volatile table;
    unsigned int first;
    unsigned int second;
    Controller* owner;
    CallbackB(Controller*);
};

inline CallbackB::CallbackB(Controller* p)
    : table(table_81e1e0), first(0), second(0), owner(p) {
    table = table_839fbc;
}

struct CallbackC {
    void* volatile table;
    unsigned int first;
    unsigned int second;
    CallbackC();
};

inline CallbackC::CallbackC()
    : table(table_81e1e0), first(0), second(0) {
    table = table_832a04;
}

struct Controller : Layer {
    Pair pair;
    Reference a;
    Reference b;
    Reference c;
    Controller();
};

Controller::Controller()
    : Layer(),
      pair(),
      a(new CallbackA(this)),
      b(new CallbackB(this)),
      c(new CallbackC)
{
}
