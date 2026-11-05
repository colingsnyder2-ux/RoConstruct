// from server: 33% by tester
struct DomResourceIcon;

struct IconHandle {
    const DomResourceIcon* m_domIcon;
    int compare(const IconHandle& rhs) const;
};

extern "C" int __stdcall ULongLongToULong(const unsigned long long* p, unsigned long* out);
extern "C" int __stdcall UIntMult(unsigned int a, unsigned int b, unsigned int* out);

int IconHandle::compare(const IconHandle& rhs) const
{
    unsigned int size = (unsigned int)((char*)rhs.m_domIcon + 8);
    size &= 0xfffffff8;
    unsigned long long result;
    if (ULongLongToULong(&result, (unsigned long*)&size) < 0)
        return 0;
    unsigned int out;
    if (UIntMult((unsigned int)(unsigned long)result, 0x10, &out) < 0)
        return 0;
    int r = ((int (__thiscall*)(void*, const DomResourceIcon*, unsigned int))0)(0, 0, 0);
    return 0;
}
