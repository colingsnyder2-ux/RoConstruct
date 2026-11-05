// from server: 59% by atomic.potato
struct Inner {
    char pad[8];
};

struct Outer {
    char pad[8];
    Inner* inner;
};

struct A { void f(Outer* arg); };

void A::f(Outer* arg)
{
    ((void(__thiscall*)(void*, Outer*))0x917430)(arg, (Outer*)this);
    ((void(__thiscall*)(Inner*, Outer*))0x925c70)(((Outer*)this)->inner, arg);
    ((void(__thiscall*)(void*, void*, Inner*))0x954cc0)((char*)arg + 8, (void*)0x925c10, ((Outer*)this)->inner);
}
