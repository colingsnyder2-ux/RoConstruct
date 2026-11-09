// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs roc_codex_com_pointercatch_a18f3f1468ad233e.cpp

// Candidate translation unit (score above; library headers required).

extern void* __cdecl operator new(unsigned int);
extern void* objectTable[];

struct Module;
struct ModuleTable {
    void (__thiscall* first)(Module*);
    void (__thiscall* lock)(Module*);
};
struct Module {
    ModuleTable* table;
};
extern Module* module;

struct Exception {
    long status;
    Exception(const Exception&);
    ~Exception(); void Delete();
};

struct Object {
    void** table;
    long references;
    void* begin;
    void* end;
    void* current;
    void* owner;
    unsigned int flags;

    Object() throw();
    static long __stdcall Create(Object** result);
};

__forceinline Object::Object() throw()
{
    references = 0;
    current = 0;
    end = 0;
    begin = 0;
    owner = 0;
    flags = 0;
    table = objectTable;
    module->table->lock(module);
}

long __stdcall Object::Create(Object** result)
{
    if (!result)
        return (long)0x80004003;

    *result = 0;
    long status = (long)0x8007000e;
    Object* object = 0;

try {
        object = new Object;
    }
    catch (Exception* exception) { exception->Delete(); }
    if (object)
        status = 0;

    *result = object;
    return status;
}
