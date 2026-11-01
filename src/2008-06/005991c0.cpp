// from server: 100% by king_originala
struct Triple {
    float x, y, z;
};

struct Six {
    float a, b, c, d, e, f;
};

struct Data {
    char reserved[0x24];
    Triple input;
    Six output;
};

struct S {
    Six* compute(Six* result, const Triple* input);
};

extern void __cdecl prepare(S*, const void*, Data*);

void __cdecl update(S* object, const void* value, Data* data)
{
    Six temporary;
    prepare(object, value, data);
    Six* result = object->compute(&temporary, &data->input);
    data->output.a = result->a;
    data->output.b = result->b;
    data->output.c = result->c;
    data->output.d = result->d;
    data->output.e = result->e;
    data->output.f = result->f;
}
