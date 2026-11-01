// from server: 100% by king_originala
struct Primitive {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int isExcluded();
    virtual void slot4();
    virtual int kind();
};

extern Primitive* __cdecl getFirstB(void*);
extern void (__cdecl* invalidParameter)();

struct Clump {
    char pad0[0x1c];
    void* source;
    char pad1[0x14];
    Clump** begin;
    Clump** volatile end;

    Primitive* find(int* index);
};

Primitive* Clump::find(int* index)
{
    Primitive* primitive = getFirstB(source);
    if (!primitive->isExcluded() && primitive->kind() == 8) {
        if (*index == 0)
            return primitive;
        --*index;
    }

    unsigned int i = 0;
    if (i < (unsigned int)(end - begin)) {
        void (__cdecl* handler)() = invalidParameter;
        do {
            if (i >= (unsigned int)(end - begin))
                handler();

            Clump*& child = begin[i];
            Primitive* result = child->find(index);
            if (result)
                return result;
            ++i;
        } while (i < (unsigned int)(end - begin));
    }

    return 0;
}
