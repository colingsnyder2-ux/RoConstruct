// from server: 47% by colin
extern "C" int __cdecl sprintf(char*, const char*, ...);

struct Exposer {
    void* vtable;
    void* field4;
    char field8;
    char pad[1];
    char fieldA[0x100];
    char field10A[0x100];
    void method(int, int, int, int);
};

void Exposer::method(int a, int b, int c, int d)
{
    char buf[0x108];
    int tmp[4];
    void* obj;
    int v;
    short s;
    char ch;
    int r;

    obj = field4;
    (*(void (__thiscall**)(void*, int, int, void*))(*(int*)obj + 0xa0))(obj, *(int*)0x892abc, *(int*)0x892ac0, tmp);
    v = *(int*)tmp;
    s = *(short*)((char*)tmp + 4);

    if (field8 == 0) {
        r = ((int (__cdecl*)(int, int, int, int, char*))0x4b7f70)(v, (int)s, a, b, field10A);
        sprintf(buf, (const char*)0x79e9a4, fieldA, (int)*(char*)c, d, r, *(int*)0x892abc, *(int*)0x892ac0);
    } else {
        ch = *(char*)c;
        r = ((int (__cdecl*)(int))0x4b6d40)(*(int*)&ch);
        if (r == 0) {
            r = (*(int (__thiscall**)(Exposer*, int))(*(int*)this + 0x48))(this, *(int*)&ch);
        }
        r = ((int (__cdecl*)(int, int, int, int, char*))0x4b7f70)(v, (int)s, a, b, field10A);
        sprintf(buf, (const char*)0x79e978, fieldA, r, d, *(int*)0x892abc, *(int*)0x892ac0);
    }

    (*(void (__thiscall**)(Exposer*, void*))(*(int*)this + 0x44))(this, tmp);
}
