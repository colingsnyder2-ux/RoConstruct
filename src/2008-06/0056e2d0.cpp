// from server: 100% by king_originala
extern "C" bool __cdecl convertValue(int value, int* result);

struct Receiver;

struct ReceiverTable {
    void* reserved[3];
    void (__thiscall* set)(Receiver*, void*, int*);
};

struct Receiver {
    ReceiverTable* table;
};

struct S {
    unsigned char reserved[24];
    Receiver* receiver;

    bool f(void* object, int value);
};

bool S::f(void* object, int value)
{
    if (convertValue(value, &value)) {
        receiver->table->set(receiver, object, &value);
        return true;
    }
    return false;
}
