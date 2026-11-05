// from server: 100% by king_originala
extern "C" void* __cdecl getDescriptor();

struct Base {
    unsigned char storage[52];
    Base(void*, const char*, int);
    virtual ~Base();
};

struct Value {
    unsigned int data[2];
    Value();
    ~Value();
};

struct S : Base {
    unsigned int functionLow;
    unsigned int functionHigh;
    Value first;
    Value second;

    S(unsigned int, unsigned int, const char*, const char*, const char*, int);
    virtual ~S();
    void initialize(const char*, const char*);
};

S::S(unsigned int low, unsigned int high, const char* name,
     const char* firstName, const char* secondName, int attributes)
    : Base(getDescriptor(), name, attributes),
      functionLow(low),
      functionHigh(high),
      first(),
      second()
{
    initialize(firstName, secondName);
}
