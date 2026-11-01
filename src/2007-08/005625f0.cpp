// from server: 67% by colin
struct DataModel;

struct IDataState {
    virtual void method0();
    virtual void method1(int);
};

struct RunStateVerb {
    char pad0[8];
    DataModel* m_dataModel;
    virtual void doIt(IDataState* dataState);
};

struct AllCanSelectCommand : RunStateVerb {
    virtual void doIt(IDataState* dataState);
};

extern "C" void __cdecl sub_55E290();
extern "C" void __cdecl sub_578380(int, int);
extern "C" void __cdecl sub_4108B0();

void AllCanSelectCommand::doIt(IDataState* dataState)
{
    DataModel* dm = m_dataModel;
    sub_55E290();
    int v = *(int*)((char*)m_dataModel + 0x188);
    sub_578380(v, 0);
    sub_4108B0();
    dataState->method1(1);
    *(int*)((char*)dataState + 4) = -1;
}
