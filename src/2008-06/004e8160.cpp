// from server: 100% by colin
extern const double* infinityValue;
extern unsigned int instanceCount;
extern unsigned char primaryTable[];
extern unsigned char secondaryTable[];

struct S {
    void* volatile table;
    unsigned int field04;
    volatile unsigned int field08;
    volatile unsigned int field0C;
    volatile unsigned int field10;
    volatile float field14;
    volatile float field18;
    volatile float field1C;
    void* volatile field20;
    volatile unsigned int field24;

    S(float value);
};

S::S(float value)
{
    table = primaryTable;
    field04 = 0;
    field14 = 0.0f;
    field18 = value;
    field08 = 0;

    static double infinity = *infinityValue;
    field1C = (float)infinity;

    field20 = secondaryTable;
    field24 = 0;
    ++instanceCount;
    field10 = 0;
    field0C = 0;
}
