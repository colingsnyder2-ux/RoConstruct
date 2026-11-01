// from server: 100% by king_originala
struct S {
    double getValue();
};

void __cdecl writeValue(void* output, double value);

void __cdecl serialize(S* object, void* output)
{
    writeValue(output, object->getValue());
}
