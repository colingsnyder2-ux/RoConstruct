// from server: 100% by colin
struct Link {
    void* unused;
    void* previous;
};

struct State {
    void* previous;
    Link* link;
    void* context;
    int active;

    State(void*);
};

struct Object;

struct ObjectTable {
    int (__stdcall* query)(Object*, const void*, void**);
    unsigned long (__stdcall* addRef)(Object*);
    unsigned long (__stdcall* release)(Object*);
};

struct Object {
    ObjectTable* table;
};

struct String {
    void* data;
};

extern "C" void* __cdecl get_state();
extern "C" void __stdcall release_state(int, void*);
extern "C" int (__stdcall* CoCreateInstance)(
    const void*, Object*, unsigned long, const void*, void**);

extern const unsigned char classId[];
extern const unsigned char interfaceId[];
extern const char errorFormat[];
extern const char logContext[];

extern void (__thiscall* constructString)(String*);
extern void (__cdecl* formatString)(String*, const char*, ...);
extern const char* (__thiscall* stringText)(String*);
extern void (__thiscall* destroyString)(String*);

extern void __cdecl logMessage(int, int, int);

int __stdcall function(void*, Object** output)
{
    State state(get_state());
    Object* object = 0;

    int result = CoCreateInstance(
        classId, 0, 23, interfaceId, reinterpret_cast<void**>(&object));

    if (result) {
        constructString(reinterpret_cast<String*>(&output));
        formatString(reinterpret_cast<String*>(&output), errorFormat, result);

        result = reinterpret_cast<int (__cdecl*)(int, int, int)>(logMessage)(
            reinterpret_cast<int>(logContext),
            reinterpret_cast<int>(
                stringText(reinterpret_cast<String*>(&output))),
            result);

        destroyString(reinterpret_cast<String*>(&output));

        if (object)
            object->table->release(object);

        if (state.link)
            state.link->previous = state.previous;

        if (state.active)
            release_state(0, state.context);

        return result;
    }

    Object* temporary = object;
    if (object)
        object->table->addRef(object);

    Object* current = object;
    int copied;
    if (!output) {
        copied = static_cast<int>(0x80004003UL);
    } else {
        *output = temporary;
        if (temporary) {
            temporary->table->addRef(temporary);
            current = object;
        }
        copied = 0;
    }

    if (temporary) {
        temporary->table->release(temporary);
        current = object;
    }

    if (current)
        current->table->release(current);

    if (state.link)
        state.link->previous = state.previous;

    if (state.active)
        release_state(0, state.context);

    return copied;
}
