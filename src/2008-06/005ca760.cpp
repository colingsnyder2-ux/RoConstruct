// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_secondaryswitch63cef399ef22e360.cpp

// Candidate translation unit (score above; library headers required).
struct InputObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool check(int value);
    bool ctrlKeyDown()const;
};

struct InputObject2
{
    virtual bool check(int value);
};

struct KeyboardSecondaryController
{
    char pad0[0xc];
    void* field_c;
    float getValue(int key);
};



float KeyboardSecondaryController::getValue(int key)
{
    void* p = this->field_c;
    InputObject* obj = p ? *(InputObject**)((char*)p + 0x130):0;
    if (obj == 0)
        return 0.0f;

    switch(key){case 6:return obj->check(0x12f)?1.0f:0.0f;default: {

    if (obj->check(0x133))
        return 0.0f;
    if (obj->check(0x134))
        return 0.0f;

    void* p2 = this->field_c;
    InputObject* obj2;
    if (p2 != 0)
        obj2 = *(InputObject**)((char*)p2 + 0x130);
    else
        obj2 = 0;
    if (obj2->ctrlKeyDown())
        return 0.0f;

    void* p3 = this->field_c;
    InputObject* obj3;
    if (p3 != 0)
        obj3 = *(InputObject**)((char*)p3 + 0x130);
    else
        obj3 = 0;
    bool b77 = obj3->check(0x77);

    void* p4 = this->field_c;
    InputObject* obj4;
    if (p4 != 0)
        obj4 = *(InputObject**)((char*)p4 + 0x130);
    else
        obj4 = 0;
    bool b73 = obj4->check(0x73);

    void* p5 = this->field_c;
    InputObject* obj5;
    if (p5 != 0)
        obj5 = *(InputObject**)((char*)p5 + 0x130);
    else
        obj5 = 0;
    bool b61 = obj5->check(0x61);

    void* p6 = this->field_c;
    InputObject* obj6;
    if (p6 != 0)
        obj6 = *(InputObject**)((char*)p6 + 0x130);
    else
        obj6 = 0;
    bool b64 = obj6->check(0x64);

    switch(key){
    case 1:if(b61)return 1.0f;if(b64)return -1.0f;return 0.0f;
    case 2:if(b77)return 1.0f;if(b73)return -1.0f;return 0.0f;
    case 3:if((b77&&!b61)||(b64&&!b73)||(b77&&b64))return 1.0f;
           if((b73&&!b64)||(b61&&!b77)||(b73&&b61))return -1.0f;return 0.0f;
    case 4:if((b77&&!b64)||(b61&&!b73)||(b77&&b61))return 1.0f;
           if((b73&&!b61)||(b64&&!b77)||(b73&&b64))return -1.0f;return 0.0f;
    default:return 0.0f;}
}

}
}
