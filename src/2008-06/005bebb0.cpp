// from server: 100% by king_originala
struct String {
    char reserved[4];
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;
};

extern unsigned int (__thiscall* find_first_of)(
    const String*, const char*, unsigned int, unsigned int);
extern String* (__thiscall* substring)(
    const String*, String*, unsigned int, unsigned int);
extern void (__thiscall* destroy_string)(String*);
extern double (__cdecl* parse_number)(const char*);

bool parse_vector(const String& text, float* result)
{
    int first = (int)find_first_of(&text, ",;", 0, 2);
    if (first < 0)
        return false;

    String temporary;
    String* part = substring(&text, &temporary, 0, first);
    result[0] = (float)parse_number(
        part->capacity >= 16 ? part->data.pointer : part->data.buffer);
    destroy_string(&temporary);

    ++first;
    int second = (int)find_first_of(&text, ",;", first, 2);
    if (second < first)
        return false;

    part = substring(&text, &temporary, first, second - first);
    result[1] = (float)parse_number(
        part->capacity >= 16 ? part->data.pointer : part->data.buffer);
    destroy_string(&temporary);

    int start = second + 1;
    int length = (int)text.length;
    if (length < start)
        return false;

    part = substring(&text, &temporary, start, length - start);
    result[2] = (float)parse_number(
        part->capacity >= 16 ? part->data.pointer : part->data.buffer);
    destroy_string(&temporary);
    return true;
}
