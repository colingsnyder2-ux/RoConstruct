// from server: 91% by atomic.potato
struct S
{
    int value0;
    int value4;
    int value8;
    int valueC;
    int value10;
    S *init();
};

extern "C" void __stdcall function_004df390(void *);

S *S::init()
{
    function_004df390((char *)this + 8);
    this->value0 = -1;
    this->value10 = -1;
    return this;
}
