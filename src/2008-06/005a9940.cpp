// from server: 100% by king_originala
extern const char* typeName;

extern "C" void* __cdecl checkUserdata(void* state, int index, const char* name);
extern "C" void __cdecl pushBoolean(void* state, int value);

#pragma float_control(precise, off, push)

int __cdecl compareValues(void* state)
{
    const float* second = static_cast<const float*>(checkUserdata(state, 2, typeName));
    const float* first = static_cast<const float*>(checkUserdata(state, 1, typeName));

    int equal = first[0] == second[0]
             && first[1] == second[1]
             && first[2] == second[2] ? 1 : 0;

    pushBoolean(state, static_cast<unsigned char>(equal));
    return 1;
}

#pragma float_control(pop)
