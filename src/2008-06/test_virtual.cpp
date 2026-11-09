// test extern C position
extern "C" void bar();

namespace std {
    class __declspec(dllimport) exception {
    public:
        virtual ~exception();
    };
}

struct Derived : std::exception {
    virtual ~Derived();
};

Derived::~Derived() {
    bar();
}