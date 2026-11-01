// from server: 100% by tester
struct First {
    virtual ~First();
};

struct Second {
    virtual ~Second();
};

struct Base : First, Second {
    ~Base();
};

struct Tool : Base {
    ~Tool();
};

Tool::~Tool()
{
}
