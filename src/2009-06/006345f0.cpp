// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
struct State;
struct Vector2 { float x, y; };
extern const char* vector2Type;
extern "C" Vector2* __cdecl checkVector(State*, int, const char*);
extern "C" void __cdecl pushBoolean(State*, int);
#pragma float_control(precise, off)
int __cdecl vector2sEqual(State* state)
{
    Vector2* second = checkVector(state, 2, vector2Type);
    Vector2* first = checkVector(state, 1, vector2Type);
    int equal = (static_cast<double>(first->x) == second->x
              && static_cast<double>(first->y) == second->y) ? 1 : 0;
    pushBoolean(state, static_cast<unsigned char>(equal));
    return 1;
}
