// from server: 47% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct DataModel;

struct IDataState;

struct EngineStatsCommand {
    char pad[0xc];
    DataModel* dataModel;
    void doIt(IDataState* dataState);
};

extern "C" void __fastcall sub_564830(void* p, IDataState* dataState);
extern "C" void __fastcall sub_564860(void* p, IDataState* dataState);

void EngineStatsCommand::doIt(IDataState* dataState)
{
    sub_564830(dataModel, dataState);
    sub_564860(dataModel, dataState);

    if (dataState) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)dataState + 4), -1) == 1) {
            void** vtbl = *(void***)dataState;
            ((void (__thiscall*)(void*))vtbl[1])(dataState);
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)dataState + 8), -1) == 1) {
            void** vtbl = *(void***)dataState;
            ((void (__thiscall*)(void*))vtbl[2])(dataState);
        }
    }
}
