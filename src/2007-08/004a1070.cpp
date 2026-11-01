// from server: 67% by colin
struct BoundFuncDesc {
    void* function;
    void* construct(void* out, int a, int b);
};

struct ArgList {
    void* begin;
    void* end;
};

extern "C" void __cdecl _invalid_parameter_noinfo();

void __stdcall sub_49F9A0(void* out, int a, int b);

ArgList* __cdecl sub_586610();

void* BoundFuncDesc::construct(void* out, int a, int b) {
    int local = 0;
    sub_49F9A0(&local, 5, 1);
    ArgList* list = sub_586610();
    unsigned int index = (unsigned int)out;
    if (list->begin == 0 || index >= ((char*)list->end - (char*)list->begin) / 4) {
        _invalid_parameter_noinfo();
    }
    *(int*)&local = ((int*)list->begin)[index];
    *(int*)out = local;
    return this;
}
