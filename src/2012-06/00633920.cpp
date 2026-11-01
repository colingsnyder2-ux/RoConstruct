// from server: 61% by Intel




extern "C" void* __cdecl malloc(unsigned int);

struct Table {
    int vftable;
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10;

    Table* ctor(unsigned char a1, int a2);
};

Table* Table::ctor(unsigned char a1, int a2) {
    this->vftable = 0xB83B64;
    this->field_4 = 0;
    void* mem = malloc(0x9C0);
    this->field_10 = a1;
    this->field_8 = (int)mem;
    *(int*)mem = a2;
    this->field_C = 1;

    int* arr = (int*)this->field_8;
    for (int i = 1; i < 0x270; ++i) {
        int prev = arr[i - 1];
        unsigned int t = (prev >> 30) ^ prev;
        t = t * 0x6C078965 + i;
        arr[i] = t;
    }
    return this;
}
