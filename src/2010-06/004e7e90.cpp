// from server: 41% by atomic.potato
struct S
{
    void f();
};

struct T
{
};

extern "C" T* __cdecl func_004e7e30(T*);
extern "C" void __cdecl func_004e1a60(S*, T*);

void S::f()
{
    T value;
    T* result = func_004e7e30(&value);
    func_004e1a60(this, result);
}
