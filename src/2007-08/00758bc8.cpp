// from server: 78% by colin
extern "C" int __stdcall func_00630af7(void*, int, int, void*);

struct S_func_00758bc8 {
    char pad[0xfc];
    int m();
};

int S_func_00758bc8::m()
{
    return func_00630af7((char*)this + 0xfc, 8, 2, (void*)0x492360);
}
