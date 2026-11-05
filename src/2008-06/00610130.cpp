// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Result
{
    float values[6];
};

extern const float threshold;
extern const float tolerance;

extern void __cdecl calculate(Result *, void *);

struct Contact
{
    bool check(void *, float);
};

int __cdecl testContact(void *object, Contact *contact)
{
    Result result;
    calculate(&result, object);
    if (result.values[1] < threshold || contact->check(object, tolerance))
        return 1;
    return 0;
}
