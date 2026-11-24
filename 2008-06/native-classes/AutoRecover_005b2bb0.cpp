// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available, so the RBX types below are local stand-ins.
// INFERRED: the real constructor takes a hidden "most-derived" flag from the virtual bases.
// That flag cannot be written in source, so it is modelled as an int argument that is
// forwarded through the base-initializer helper, as in the byte-exact analog.
// INFERRED: the constant stores are vtable addresses; each is declared as an unknown global g_<8hex>.
// INFERRED: FactoryProduct has a non-trivial destructor (declared only); this creates the EH
// frame (state -1 -> 0 after the base constructor) seen in the original prologue.

extern "C" {
extern char g_00834eb4[];
extern char g_00846144[];
extern char g_00834f8c[];
extern char g_00834f7c[];
extern char g_00834f74[];
extern char g_00834f6c[];
extern char g_00834f5c[];
extern char g_00834f4c[];
extern char g_00834f3c[];
extern char g_00834f2c[];
extern char g_00834f1c[];
extern char g_00834f0c[];
extern char g_00834f04[];
extern char g_00834eec[];
extern char g_00834ee4[];
extern char g_00834ec8[];
}

#define ADDR(x) reinterpret_cast<unsigned>(x)

namespace RBX {

class Hat;
class Accoutrement;
extern const char* const sHat;

template<class T, class B, const char* const* N>
struct FactoryProduct {
    unsigned data[118];
    FactoryProduct(int);
    ~FactoryProduct();
};

template<class T, const char* const* N, class Base>
struct Described {
    static unsigned __cdecl classDescriptor();
};

template<class T, class B, const char* const* N>
struct DescribedCreatable : FactoryProduct<T, B, N> {
    typedef FactoryProduct<T, B, N> BaseT;

    static __forceinline int prepare(DescribedCreatable* p, int complete)
    {
        volatile int constructionFlags = 0;
        if (complete) {
            p->data[0x150 / 4] = ADDR(g_00834eb4);
            p->data[0x1d4 / 4] = ADDR(g_00846144);
        }
        return 0;
    }

protected:
    DescribedCreatable(int complete);
};

template<class T, class B, const char* const* N>
DescribedCreatable<T, B, N>::DescribedCreatable(int complete)
    : BaseT(prepare(this, complete))
{
    this->data[0x1c / 4] = Described<T, N, BaseT>::classDescriptor();

    int* table = reinterpret_cast<int*>(this->data[0x150 / 4]);
    this->data[0x00 / 4] = ADDR(g_00834f8c);
    this->data[0x10 / 4] = ADDR(g_00834f7c);
    this->data[0x14 / 4] = ADDR(g_00834f74);
    this->data[0x20 / 4] = ADDR(g_00834f6c);
    this->data[0x24 / 4] = ADDR(g_00834f5c);
    this->data[0x44 / 4] = ADDR(g_00834f4c);
    this->data[0x64 / 4] = ADDR(g_00834f3c);
    this->data[0x84 / 4] = ADDR(g_00834f2c);
    this->data[0xa4 / 4] = ADDR(g_00834f1c);
    this->data[0xc4 / 4] = ADDR(g_00834f0c);
    this->data[0x130 / 4] = ADDR(g_00834f04);
    this->data[0x140 / 4] = ADDR(g_00834eec);

    *reinterpret_cast<unsigned*>(
        reinterpret_cast<char*>(this) + 0x150 + table[1]) = ADDR(g_00834ee4);

    table = reinterpret_cast<int*>(this->data[0x150 / 4]);
    *reinterpret_cast<unsigned*>(
        reinterpret_cast<char*>(this) + 0x150 + table[2]) = ADDR(g_00834ec8);

    table = reinterpret_cast<int*>(this->data[0x150 / 4]);
    int offset = table[1];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x14c + offset) = offset - 0x78;

    table = reinterpret_cast<int*>(this->data[0x150 / 4]);
    offset = table[2];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x14c + offset) = offset - 0x80;
}

template struct DescribedCreatable<Hat, Accoutrement, &sHat>;

} // namespace RBX
