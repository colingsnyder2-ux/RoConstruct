// from server: 45% by atomic.potato
typedef unsigned int Value;

extern "C" Value __cdecl sub_73cde0(Value, Value*);

struct S
{
    Value f(Value, Value);
};

Value S::f(Value a, Value b)
{
    Value* p = (Value*)((char*)this + 0x1c);
    Value* v = (Value*)*p;
    v = (Value*)((char*)v + 0x10);
    Value t = sub_73cde0(a, (Value*)((char*)&t + 0));
    typedef Value (__thiscall *Fn)(Value*, Value, Value);
    return ((Fn)*(Value*)v)(v, b, t);
}
