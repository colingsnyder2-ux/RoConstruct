// from server: 46% by Intel
struct SpanningEdge {
    int field_C;
    int field_10;

    int __cdecl compare(SpanningEdge* other);
};

int __stdcall sub_7B9350(int);
int __cdecl sub_72B460(int, int, int, int);
void __cdecl sub_972290(int, int);
int __cdecl sub_E5809C(int, int, int);

int SpanningEdge::compare(SpanningEdge* other) {
    int v0 = sub_7B9350(this->field_C);
    int v1 = sub_7B9350(other->field_C);
    int v2 = 0;
    if (this->field_10)
        v2 = sub_7B9350(this->field_10);
    int v3 = 0;
    if (other->field_10)
        v3 = sub_7B9350(other->field_10);

    int result = sub_72B460(v3, v2, v1, v0);

    if (*(char*)0xE580B3) {
        int temp = sub_72B460(v3, v2, v1, v0);
        if (result != temp) {
            if (*(int*)0xE5809C) {
                if (sub_E5809C(0x12C, 0xBEE9E0, 0xBEED90))
                    goto LABEL_1;
            }
            sub_972290(0xBEED08, *(char*)0xE580B3);
        }
    LABEL_1:
        if (*(char*)0xE580B3) {
            temp = sub_72B460(v2, v3, v0, v1);
            if (result != temp) {
                if (*(int*)0xE5809C) {
                    if (sub_E5809C(0x12D, 0xBEE9E0, 0xBEED90))
                        goto LABEL_2;
                }
                sub_972290(0xBEEC50, *(char*)0xE580B3);
            }
        LABEL_2:
            if (*(char*)0xE580B3) {
                temp = sub_72B460(v2, v1, v3, v0);
                temp = -temp;
                if (result != temp) {
                    if (*(int*)0xE5809C) {
                        if (sub_E5809C(0x12E, 0xBEE9E0, 0xBEEC20))
                            goto LABEL_3;
                    }
                    sub_972290(0xBEEB98, *(char*)0xE580B3);
                }
            LABEL_3:
                if (*(char*)0xE580B3) {
                    temp = sub_72B460(v0, v1, v2, v3);
                    temp = -temp;
                    if (result != temp) {
                        if (*(int*)0xE5809C) {
                            if (sub_E5809C(0x12F, 0xBEE9E0, 0xBEEB68))
                                goto LABEL_4;
                        }
                        sub_972290(0xBEEAE0, *(char*)0xE580B3);
                    }
                LABEL_4:;
                }
            }
        }
    }
    return result;
}
