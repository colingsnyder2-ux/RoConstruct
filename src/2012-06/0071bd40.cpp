// from server: 17% by Intel




struct Value {
    char s[28];
    int extra;
};

extern "C" void __stdcall construct(Value* p, const void* v);

struct VTable {
    void* begin;
    void* end;
};

struct StringDescriptor {
    int gap0[11];
    int bucketCount;
    int gap1[3];
    int* buckets;
    int size;
    int maxSize;

    int __thiscall func(void* key, int* out);
};

int __thiscall StringDescriptor::func(void* key, int* out) {
    int vtableIndex;
    if (this)
        vtableIndex = *(int*)((char*)this - 12 + 44);
    else
        vtableIndex = 0;
    int allocSize = (vtableIndex + 1) * 4;
    void* buffer = operator new(allocSize);
    VTable* vt = (VTable*)buffer;
    void* beginIter;
    vt->begin = 0;
    ((void (__thiscall*)(void*, void**))vt->begin)(key, &beginIter);
    void* endIter;
    vt->end = 0;
    ((void (__thiscall*)(void*, void**))vt->end)(key, &endIter);
    int hash = 0;
    ((int (__cdecl*)(void*, void*, void*, void*))0x4d59f0)(&hash, beginIter, endIter, 0);
    int idx = hash % bucketCount;
    int* bucket = buckets + idx;
    char local[16] = {0};
    int* slot = (int*)((char*)bucket + 4);
    void* args[3] = { local, out, key };
    char result;
    ((char (__thiscall*)(StringDescriptor*, void**))0x71a3c0)(this, args);
    if (!result) {
        if (out && *out) {
            Value* val = (Value*)((char*)*out - 32);
            construct(val, *(const void**)key);
            *out = (int)(val + 1);
        }
        return 0;
    }
    Value* node = (Value*)slot;
    construct(node, *(const void**)key);
    *out = (int)(node + 1);
    if (maxSize > idx)
        maxSize = idx;
    return (int)node;
}
