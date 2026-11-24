// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: layout is {4-byte value, std::string}, consistent with the boost/std pair<int, std::string> copy constructor
struct IntStringPair {
    int first;
    std::string second;
};

// INFERRED: the original is unoptimized (/Od-style) vendor code with a plain ebp frame
#pragma optimize("", off)

extern "C" IntStringPair* __fastcall fn_00550f60(IntStringPair* self, int unusedEdx, const IntStringPair* other)
{
    self->first = other->first;
    // INFERRED: explicit constructor call, so no placement-new null check or EH frame is emitted
    self->second.std::basic_string<char>::basic_string(other->second);
    return self;
}

#pragma optimize("", on)
