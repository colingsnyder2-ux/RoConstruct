// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct String
{
    unsigned char data[28];
    __declspec(dllimport) int compare(const char* value) const;
    __declspec(dllimport) const char* c_str() const;
    __declspec(dllimport) ~String();
};

struct NamedValue
{
    int reserved;
    String name;
};

inline const char* name_c_str(NamedValue* value)
{
    NamedValue* named_value = value;
    return named_value->name.c_str();
}

struct Interface
{
    NamedValue* unused;
    NamedValue* display;
    NamedValue* key;
};

struct S
{
    Interface* object;
    int argument;
    String get();
};

struct Stream
{
    int marker;
};

struct InputPart
{
    int reserved[2];
};

struct CombinedStream : InputPart, Stream
{
};

extern Stream& __cdecl insert_text(Stream&, const char*);
extern Stream& __cdecl insert_character(Stream&, char);

typedef Stream& (__cdecl *InsertString)(Stream&, const String&);
extern InsertString insert_string;

void emit(const char* key, CombinedStream* output, S* value)
{
    NamedValue* key_value = value->object->key;
    if (key_value->name.compare(key) != 0)
        return;

    insert_text(*static_cast<Stream*>(output),
                name_c_str(value->object->display));
    insert_character(*static_cast<Stream*>(output), ':');

    insert_string(*static_cast<Stream*>(output), value->get());
    insert_character(*static_cast<Stream*>(output), ';');
}
