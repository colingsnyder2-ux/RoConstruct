// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_toolprocess_34050624e3c21ea8.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>

struct Argument
{
    char padding[0x104];
    void* value;
};

typedef boost::shared_ptr<Argument> SharedArgument;

struct Object
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool permitted();
    virtual bool accept(void*);

    char padding[0x1c0];
    int state;

    void apply(void*);
    void process(SharedArgument);
};

struct Model
{
    Object* query();
};

extern char instanceType;
extern char modelType;
extern int __stdcall classify(void*);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern int __cdecl checkModel(Model*);
extern void* __cdecl resolveObject(void*);
extern void __cdecl consume(void*);

void Object::process(SharedArgument argument)
{
    if (state == 2)
    {
        void* value = argument->value;
        if (classify(value) == 5)
        {
            Model* model = static_cast<Model*>(
                __RTDynamicCast(value, 0, &instanceType, &modelType, 0));
            if (model && checkModel(model))
            {
                Object* object = model->query();
                if (object && !object->permitted())
                    goto done;
            }

            void* object = resolveObject(value);
            if (object && accept(object))
            {
                consume(object);
                apply(value);
            }
        }
    }
done:
    ;
}