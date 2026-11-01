// from server: 100% by king_originala
struct S {
    void* vtable;
    unsigned char baseData[8];
    const void* sourceType;
    const void* targetType;

    S(const S& other);
};

extern void* (__thiscall* copyBadCast)(S*, const S&);

S::S(const S& other)
{
    copyBadCast(this, other);
    vtable = reinterpret_cast<void*>(0x827224);
    sourceType = other.sourceType;
    targetType = other.targetType;
}
