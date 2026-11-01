// from server: 100% by tester
struct String {};
extern String& (__thiscall *append)(String*, const char*);
extern const char* (__thiscall *get_text)(const String*);
struct Entry {
    int value;
    String text;
};
void func_00435510(int* count, String* output, Entry** entry)
{
    if (*count > 0)
        append(output, ", ");
    Entry* e = *entry;
    append(output, get_text(&e->text));
    ++*count;
}
