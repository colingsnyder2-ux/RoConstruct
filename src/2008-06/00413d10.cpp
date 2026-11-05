// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Data {
    unsigned int value;
    unsigned int unused[2];
    unsigned int position;
    unsigned int limit;
};

struct Result {
    unsigned int value;
    unsigned int position;
};

struct CopyVerb {
    char padding[0x154];
    Data* data;
    Result* get(Result* result);
};

Result* CopyVerb::get(Result* result)
{
    Data* source = data;
    unsigned int position = source->position;
    result->value = 0;
    if (position > source->limit)
        invalid_parameter_noinfo();
    result->value = source->value;
    result->position = position;
    return result;
}
