// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Tuple {
    unsigned char storage[24];

    Tuple(unsigned int count);
    ~Tuple();
    void* element(unsigned int index);
};

extern void __cdecl transfer(void* state, unsigned int index,
                            void* value, int flag);

void __cdecl buildTuple(Tuple** destination, void* state, unsigned int count)
{
    Tuple* replacement = new Tuple(count);
    Tuple* previous = *destination;

    if (replacement != previous && previous != 0)
        delete previous;

    *destination = replacement;

    unsigned int index = 0;
    while (index < count) {
        void* value = (*destination)->element(index);
        ++index;
        transfer(state, index, value, 1);
    }
}
