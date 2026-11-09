// Read-only x86 crash observer. No target instructions or data are patched.
#include <windows.h>
#include <cstdio>
#include <string>
#include <vector>

int main(int argc,char** argv)
{
    if(argc<2)return 1;
    std::setvbuf(stdout,0,_IONBF,0);
    SetEnvironmentVariableA("_NO_DEBUG_HEAP","1");
    std::string command;
    for(int i=1;i<argc;++i)command+=(i>1?" \"":"\"")+std::string(argv[i])+"\"";
    std::vector<char> text(command.begin(),command.end());text.push_back(0);
    STARTUPINFOA startup={sizeof(startup)};PROCESS_INFORMATION process={0};
    if(!CreateProcessA(argv[1],&text[0],0,0,FALSE,DEBUG_ONLY_THIS_PROCESS,0,0,&startup,&process))return 2;
    std::printf("FAULT_PROCESS pid=%lu\n",process.dwProcessId);
    DWORD start=GetTickCount();bool loader=false;
    for(;;){
        if(GetTickCount()-start>60000){TerminateProcess(process.hProcess,3);break;}
        DEBUG_EVENT event;
        if(!WaitForDebugEvent(&event,1000))continue;
        DWORD action=DBG_CONTINUE;
        if(event.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT){
            std::printf("FAULT_IMAGE base=%p\n",event.u.CreateProcessInfo.lpBaseOfImage);
            if(event.u.CreateProcessInfo.hFile)CloseHandle(event.u.CreateProcessInfo.hFile);
        }else if(event.dwDebugEventCode==CREATE_THREAD_DEBUG_EVENT){
            CloseHandle(event.u.CreateThread.hThread);
        }else if(event.dwDebugEventCode==LOAD_DLL_DEBUG_EVENT){
            if(event.u.LoadDll.hFile)CloseHandle(event.u.LoadDll.hFile);
        }else if(event.dwDebugEventCode==EXCEPTION_DEBUG_EVENT){
            DWORD code=event.u.Exception.ExceptionRecord.ExceptionCode;
            if(code==EXCEPTION_BREAKPOINT && !loader)loader=true;
            else{
                action=DBG_EXCEPTION_NOT_HANDLED;
                if(code==EXCEPTION_ACCESS_VIOLATION || code==EXCEPTION_STACK_OVERFLOW){
                    HANDLE thread=OpenThread(THREAD_GET_CONTEXT,FALSE,event.dwThreadId);
                    CONTEXT context={0};context.ContextFlags=CONTEXT_FULL;
                    if(thread && GetThreadContext(thread,&context)){
                        std::printf("FAULT code=%08lx first=%lu eip=%08lx esp=%08lx ebp=%08lx ecx=%08lx esi=%08lx edi=%08lx\n",code,event.u.Exception.dwFirstChance,context.Eip,context.Esp,context.Ebp,context.Ecx,context.Esi,context.Edi);
                        DWORD stack[96]={0};SIZE_T got=0;
                        ReadProcessMemory(process.hProcess,reinterpret_cast<void*>(context.Esp),stack,sizeof(stack),&got);
                        for(unsigned i=0;i<got/4;++i)std::printf("STACK %02u %08lx\n",i,stack[i]);
                    }
                    if(thread)CloseHandle(thread);
                }
            }
        }else if(event.dwDebugEventCode==EXIT_PROCESS_DEBUG_EVENT){
            std::printf("FAULT_EXIT code=%lu\n",event.u.ExitProcess.dwExitCode);
            ContinueDebugEvent(event.dwProcessId,event.dwThreadId,action);break;
        }
        ContinueDebugEvent(event.dwProcessId,event.dwThreadId,action);
    }
    CloseHandle(process.hThread);CloseHandle(process.hProcess);
    return 0;
}
