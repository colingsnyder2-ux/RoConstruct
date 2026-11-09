// from server: 100% by Espeon
// from server: 86% by colin
struct __declspec(dllimport) String
{
    char* data;

    String() throw();
    ~String() throw();
    void __cdecl Format(const char* format, ...);
    operator const char*() const throw();
    String& operator=(const char* text);
};

struct __declspec(dllimport) PathString
{
    char* data;

    PathString() throw();
    ~PathString() throw();
    void __cdecl Format(const char* format, ...);
    operator const char*() const throw();
    PathString& operator=(const char* text);
};

extern "C" int __stdcall VerQueryValueA(
    const void* block,
    const char* subBlock,
    void** value,
    unsigned int* length);

extern "C" int __cdecl sub_7A6368(void*, void*);

struct DxUserInput
{
    unsigned short language;
    unsigned short codePage;
    void* block;

    String query(const String& name);
};

String DxUserInput::query(const String& name)
{
    String result;
    PathString path;

    path.Format("\\StringFileInfo\\%04x%04x\\%s",
                language, codePage, name.data);

    void* value = 0;
    unsigned int length = 0;

    if (VerQueryValueA(block, path, &value, &length))
        result = static_cast<const char*>(value);

    return result;
}
