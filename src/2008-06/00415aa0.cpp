// from server: 100% by king_originala
struct Variant {
    unsigned short type;
    unsigned char data[14];

    long moveTo(Variant* destination);
};

extern "C" long (__stdcall *VariantClear)(Variant*);
extern "C" int (__cdecl *memcpy_s)(void*, unsigned int, const void*, unsigned int);
void __cdecl checkResult(int);

long Variant::moveTo(Variant* destination)
{
    if (!destination)
        return (long)0x80004003;

    long result = VariantClear(destination);
    if (result >= 0) {
        checkResult(memcpy_s(destination, 16, this, 16));
        type = 0;
        result = 0;
    }
    return result;
}
