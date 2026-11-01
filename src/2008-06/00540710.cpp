// from server: 100% by king_originala
extern void __cdecl move_range(int*, int*, int*);

struct S {
    char padding[16];
    int* end;

    void destroy_range(int*, int*);
    void make_result(int*, int, int*);
    int* f(int*, int, int*);
};

#pragma optimize("", off)

int* S::f(int* result, int context, int* position)
{
    move_range(position + 1, end, position);
    destroy_range(end - 1, end);
    end = end - 1;
    make_result(result, context, position);
    return result;
}
