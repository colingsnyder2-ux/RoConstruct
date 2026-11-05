// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Pair
{
    float x;
    float y;
};

extern float value_00827490;
extern const float* __cdecl func_005736f0(Pair*, const Pair*);

Pair* __stdcall func_005cf190(Pair* result)
{
    Pair input;
    Pair temporary;
    input.x = value_00827490;
    input.y = value_00827490;

    float value = *func_005736f0(&temporary, &input);
    result->x = value;
    result->y = value;
    return result;
}
