// from server: 100% by king_originala
struct TypeInfo;

struct TypeInfoTable {
    void* slot0;
    unsigned long (__stdcall *addRef)(TypeInfo*);
};

struct TypeInfo {
    TypeInfoTable* table;
};

struct TypeInfoHolder {
    unsigned long data[3];
    TypeInfo* info;
    long initialize(unsigned long locale);
};

extern TypeInfoHolder holder;

long __stdcall function(void* object, unsigned int index,
                        unsigned long locale, TypeInfo** output)
{
    if (index != 0)
        return (long)0x8002000bUL;

    if (!output)
        return (long)0x80004003UL;

    long result = 0;
    if (!holder.info)
        result = holder.initialize(locale);

    *output = holder.info;
    if (holder.info) {
        holder.info->table->addRef(holder.info);
        result = 0;
    }

    return result;
}
