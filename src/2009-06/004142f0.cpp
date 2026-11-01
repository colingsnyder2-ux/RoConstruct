// from server: 100% by EspClaude
// from server: 95% by EspClaude
// roc 2009-06 004142f0  unit: CopyVerb  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004142f0
//

// from server: 100% by king_originala
// roc 2008-06 00413d10  unit: CopyVerb  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00413d10
//

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
    char padding[0x8c];
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
