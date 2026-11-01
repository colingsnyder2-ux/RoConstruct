// from server: 100% by king_originala
extern void __cdecl registerType(void (__cdecl *)(), unsigned int *);
extern void __cdecl typeCallback();
extern unsigned int typeState;
extern unsigned int __cdecl getDescriptor();
extern unsigned int __cdecl getOtherDescriptor();
extern void __cdecl releaseStorage(void *);

struct Temporary {
    mutable void *value;
    ~Temporary() { if (value) releaseStorage(value); }
    void *release() const {
        void *result = value;
        value = 0;
        return result;
    }
};

extern Temporary __cdecl makeValue(unsigned int, unsigned int,
                                   unsigned int, unsigned int);

struct Owner {
    void *value;
    Owner(const Temporary &source) : value(source.release()) {}
    ~Owner() { if (value) releaseStorage(value); }
};

struct Base {
    unsigned int storage[5];
    Base(unsigned int, unsigned int, unsigned int,
         unsigned int, unsigned int);
    virtual ~Base();
};

struct DescriptorBase : Base {
    unsigned int descriptor;
    DescriptorBase(unsigned int x, unsigned int y, unsigned int a,
                   unsigned int b, unsigned int g);
};

inline DescriptorBase::DescriptorBase(unsigned int x, unsigned int y,
                                      unsigned int a, unsigned int b,
                                      unsigned int g)
    : Base(x, y, a, b, g), descriptor(y)
{
}

struct S : DescriptorBase {
    Owner owned;
    unsigned int finalDescriptor;

    S(unsigned int, unsigned int, unsigned int, unsigned int,
      unsigned int, unsigned int, unsigned int);
    virtual ~S();
};

S::S(unsigned int a, unsigned int b, unsigned int c,
     unsigned int d, unsigned int e, unsigned int f,
     unsigned int g)
    : DescriptorBase(getOtherDescriptor(),
                     (registerType(typeCallback, &typeState),
                      getDescriptor()),
                     a, b, g),
      owned(makeValue(c, d, e, f)),
      finalDescriptor(
          (registerType(typeCallback, &typeState), getDescriptor()))
{
}
