// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern char table_00839354[];
extern char table_0083933c[];

struct Cursor
{
    void* table;
    void* secondaryTable;
    char storage[0x40];

    void func_00619de0(void* object);
    Cursor(void* object);
};

__forceinline Cursor::Cursor(void* object)
{
    func_00619de0(object);
    table = table_00839354;
    secondaryTable = table_0083933c;
}

struct S
{
    char padding[0x18];
    void* object;

    Cursor* func_005c69f0();
};

Cursor* S::func_005c69f0()
{
    return new Cursor(object);
}
