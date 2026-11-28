// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: all type layouts are local; the originals are not in the headers.
struct Local_00607f90_Vec3 {
    float x, y, z;
};

struct Local_00607f90_Geom {
    char pad[0x10];
    Local_00607f90_Vec3* vertices;
};

struct Local_00607f90_Obj {
    char pad[0x9c];
    Local_00607f90_Geom* geometry;
    void* data;
};

struct Local_00607f90_Contact {
    char pad0[8];
    int type;
    Local_00607f90_Vec3* first;
    Local_00607f90_Vec3* second;
    char pad1[0x10];
    int secondIndex;
    int firstIndex;
};

struct Local_00607f90_Self {
    char pad[0x0c];
    Local_00607f90_Obj* objects[2];
};

extern int g_0084aec8[][4];

extern "C" Local_00607f90_Contact* __fastcall fn_00607cc0(Local_00607f90_Self* self, int unusedEdx,
                                                          void* a, void* b, int type, int c, int d);

extern "C" Local_00607f90_Contact* __fastcall fn_00607f90(Local_00607f90_Self* self, int unusedEdx,
                                                          int firstObject, int secondObject,
                                                          int firstIndex, int faceIndex, int secondIndex)
{
    Local_00607f90_Obj* secondObjectPtr = self->objects[secondObject];
    Local_00607f90_Obj* firstObjectPtr = self->objects[firstObject];
    void* secondData = secondObjectPtr->data;
    void* firstData = firstObjectPtr->data;
    Local_00607f90_Contact* result = fn_00607cc0(self, 0, firstData, secondData, 4, firstIndex, secondIndex);

    int offset = g_0084aec8[secondIndex][0] * 3;
    Local_00607f90_Vec3* second = reinterpret_cast<Local_00607f90_Vec3*>(
        reinterpret_cast<float*>(self->objects[secondObject]->geometry->vertices) + offset);
    Local_00607f90_Vec3* first = self->objects[firstObject]->geometry->vertices
                               + g_0084aec8[faceIndex][firstIndex];

    result->secondIndex = secondIndex;
    result->firstIndex = firstIndex;
    result->first = first;
    result->second = second;
    result->type = 4;
    return result;
}
