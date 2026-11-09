// from server: 100% by king_originala
struct State;

extern "C" unsigned* __cdecl to_userdata(State*, int);
extern "C" int __cdecl get_metatable(State*, int);
extern "C" void __cdecl get_field(State*, int, const char*);
extern "C" int __cdecl raw_equal(State*, int, int);
extern "C" void __cdecl set_top(State*, int);

extern const char* metatable_name;

bool __cdecl extract_value(State* state, int index, unsigned* result)
{
    unsigned* value = to_userdata(state, index);
    if (value)
    {
        if (get_metatable(state, index))
        {
            get_field(state, -10000, metatable_name);
            if (raw_equal(state, -1, -2))
            {
                set_top(state, -3);
                *result = *value;
                return true;
            }
        }
        else
        {
            set_top(state, -2);
        }
    }
    return false;
}
