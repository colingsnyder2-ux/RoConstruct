// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct StringStorage {
    char data[28];
};

extern StringStorage& (__thiscall *assignString)(
    StringStorage*, const StringStorage*);

struct Entry {
    unsigned int first;
    unsigned int second;
    StringStorage name;
    StringStorage value;
};

Entry* __cdecl copyBackward(Entry* first, Entry* last, Entry* result)
{
    while (first != last) {
        --last;
        --result;
        result->first = last->first;
        result->second = last->second;
        assignString(&result->name, &last->name);
        assignString(&result->value, &last->value);
    }
    return result;
}