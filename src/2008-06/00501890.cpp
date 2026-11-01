// from server: 100% by king_originala
struct Exception {
    void* vtable;
    unsigned long base[2];
    const void* sourceType;
    const void* targetType;
};

typedef void (__thiscall *CopyBadCast)(void*, const void*);
extern CopyBadCast copyBadCast;

extern unsigned char lexicalCastVtable;
extern unsigned char lexicalCastThrowInfo;

extern "C" __declspec(noreturn) void __stdcall
throwException(void*, void*);

void throwLexicalCast(const Exception& source)
{
    Exception value;
    copyBadCast(&value, &source);
    value.vtable = &lexicalCastVtable;
    value.sourceType = source.sourceType;
    value.targetType = source.targetType;
    throwException(&value, &lexicalCastThrowInfo);
}
