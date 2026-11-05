// from server: 100% by atomic.potato
struct S_func_00671f60 {
    int padding_0[93];
    int value_174;
    void f(int value);
};

extern "C" void __stdcall function_00411f60(int value);

void S_func_00671f60::f(int value)
{
    if (value == value_174)
        return;

    value_174 = value;
    function_00411f60(0xCCE180);
}
