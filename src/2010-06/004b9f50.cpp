// from server: 61% by atomic.potato
typedef unsigned int DWORD;

struct PantsString
{
    char data[16];
};

extern "C" PantsString* basic_string_copy(PantsString*, const PantsString*);

struct Pants
{
    PantsString value;
    PantsString* copy(PantsString*);
};

PantsString* Pants::copy(PantsString* result)
{
    basic_string_copy(result, reinterpret_cast<const PantsString*>(
        reinterpret_cast<const char*>(this) + 0x98));
    result->data[0x1c] = value.data[0x1c];
    return result;
}
