// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Column {
    char pad0[0xb0];
    int field_b0;
    char pad1[0x10];

    Column(int, const char*, int, int, int, int, int);
    void setVisible(int);
};

struct Header {
    char pad0[0x7c];
    int field_7c;
    char pad1[8];
    volatile int field_88;

    void setMode(int);
};

struct Report {
    char pad0[0x288];
    Header* volatile header;

    Column* addColumn(Column*);
};

struct S;

struct VTable {
    char pad0[0x194];
    Report* (__thiscall *getReport)(S*);
};

struct S {
    VTable* vtable;

    int baseInitialize(int);
    int f(int);
};

int S::f(int a1)
{
    int result = baseInitialize(a1);
    if (result == -1)
        return result;

    Report* report = vtable->getReport(this);

    Header* header = report->header;
    header->field_88 = 1;
    Header* mode = report->header;
    mode->field_7c = 0;
    report->header->setMode(1);

    Column* column = report->addColumn(
        new Column(0, "Name", 300, 1, -1, 1, 1));
    column->setVisible(1);
    column->field_b0 = 0;
    return 0;
}
