// from server: 100% by king_originala
struct Value {
    char stringData[28];
    unsigned int extra;
};

typedef void (__thiscall *StringCopy)(void *, const void *);
extern StringCopy copyString;

struct Block {
    char padding[0x140];
    Value value;
    Value *copy(Value *result);
};

Value *Block::copy(Value *result)
{
    Value *source = &value;
    volatile int state = 0;
    copyString(result, source);
    result->extra = source->extra;
    return result;
}
