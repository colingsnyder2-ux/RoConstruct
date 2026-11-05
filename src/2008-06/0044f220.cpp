// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct __declspec(dllimport) String {
    void* data;
    String(void*) throw();
    String(const String&);
    ~String() throw();
    void* manager() const throw();
    int length() const;
    const char* text() const;
};

extern void* (__thiscall *get_manager)(const String*);
extern void (__thiscall *construct_string)(String*, void*);
extern int (__thiscall *get_length)(const String*);
extern const char* (__thiscall *get_text)(const String*);
extern int (__cdecl *string_length)(const char*);
extern void (__cdecl *concatenate)(String*, const char*, int,
                                  const char*, int);

String __cdecl operator+(const char* left, const String& right)
{
    String result(right.manager());
    concatenate(&result, left, string_length(left),
                right.text(), right.length());
    return result;
}