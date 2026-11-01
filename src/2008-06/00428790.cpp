// from server: 100% by colin
struct Text
{
    char reserved[20];
    unsigned int length;
};

struct Buffer
{
    char reserved[4];

    __declspec(dllimport) Buffer();
    __declspec(dllimport) ~Buffer() throw();
    __declspec(dllimport) const char* c_str() const;
};

extern const char* (__thiscall* text_data)(const Text*);
extern void (__cdecl* format_buffer)(Buffer*, const char*, ...);

extern const char format_with_text[];
extern const char format_without_text[];
extern void __cdecl log_message(int, const char*);







bool __cdecl func_00428790(const char* expression, const Text* text,
                          const char* file, int line)
{
    Buffer message;

    if (text->length > 0)
        format_buffer(&message, format_with_text,
                      expression, text_data(text), file, line);
    else
        format_buffer(&message, format_without_text,
                      expression, file, line);

    log_message(1, message.c_str());

    volatile unsigned int* p = 0;
    p[0] = p[1];

    return false;
}
