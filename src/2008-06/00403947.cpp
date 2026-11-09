// from server: 81% by king_originala
struct CRegObject {
    long f(unsigned long, unsigned long, unsigned long);
};

long CRegObject::f(unsigned long value, unsigned long, unsigned long)
{
    try {
        throw value;
    }
    catch (...) {
        return (long)0x8007000eUL;
    }
}
