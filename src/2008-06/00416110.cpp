// from server: 100% by king_originala
struct type_info {
    bool operator==(const type_info&) const;
};

extern type_info empty_type;
extern type_info string_type;
extern bool (type_info::*type_info_equal)(const type_info&) const;

struct placeholder {
    virtual ~placeholder();
    virtual const type_info& type() const = 0;
};

struct any {
    placeholder* content;
};

extern void (__thiscall *copy_string)(void*, const void*);
extern void (__thiscall *construct_bad_cast)(void*, const char*);

struct string {
    unsigned char storage[28];

    string(const string& source) {
        copy_string(this, &source);
    }

    ~string();
};

struct bad_cast {
    unsigned long storage[3];

    bad_cast(const char* message) {
        construct_bad_cast(this, message);
        storage[0] = 0x0080BA2CUL;
    }

    ~bad_cast();
};

extern __declspec(noreturn) void __cdecl raise_bad_cast(const void*);

string __cdecl cast_string(const any* value)
{
    const string* result = 0;

    if (value) {
        placeholder* content = value->content;
        const type_info& info = content ? content->type() : empty_type;

        if ((info.*type_info_equal)(string_type))
            result = reinterpret_cast<const string*>(
                reinterpret_cast<const char*>(value->content) + 4);
    }

    if (!result) {
        bad_cast error("bad cast");
        raise_bad_cast(&error);
    }

    return string(*result);
}
