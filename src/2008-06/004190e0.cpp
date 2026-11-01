// from server: 100% by king_originala
struct S {
    long resolve(const void* iid, wchar_t** names, unsigned int count,
                 unsigned long locale, long* ids);
};

extern S globalObject;

long __stdcall f(void* object, const void* iid, wchar_t** names,
                 unsigned int count, unsigned long locale, long* ids)
{
    return globalObject.resolve(iid, names, count, locale, ids);
}
