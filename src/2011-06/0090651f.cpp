// from server: 45% by atomic.potato
typedef void (__cdecl *FunctionType)(float, void*, void*, void*, void*);

extern "C" void __cdecl Function9092d5(int);

extern "C" FunctionType FunctionC9B640;

void __declspec(naked) Function90651F(float a, void* b, void* c, void* d, void* e)
{
    Function9092d5(1);
    FunctionC9B640(a, e, d, c, b);
}
