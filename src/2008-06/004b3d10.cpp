// from server: 100% by king_originala
extern void *elementConstructor;
extern void *elementDestructor;

extern void __stdcall constructArray(
    void *, unsigned int, unsigned int, void *, void *);

struct Base {
    unsigned char storage[0xE24];
    Base();
    ~Base();
};

struct S : Base {
    unsigned char elements[0x100 * 0x1C];
    S();
};

S::S()
{
    constructArray(elements, 0x1C, 0x100,
                   elementConstructor, elementDestructor);
}
