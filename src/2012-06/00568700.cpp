// from server: 26% by atomic.potato
struct S {
    void func(float a, float b, float c);
};

extern "C" void __cdecl func_5683e0(int*);

void S::func(float a, float b, float c) {
    static const float global_value = *(float*)0xB74878;
    
    float temp1 = a - b;
    float temp2 = c - b;
    float result = (temp1 * global_value) / temp2;
    
    if (result < 0.0f) {
        result = 0.0f;
    } else if (result > global_value) {
        result = global_value;
    }
    
    int int_result = (int)result;
    int args[3] = {0};
    args[1] = int_result;
    func_5683e0(args);
}
