// x86 Windows hardware-breakpoint observer for the rebuilt selftest.
// No target instructions are patched. Addresses come from this EXE's linker map.
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

struct ThreadState {
    DWORD sites[4],active[4],receiver[3],operation;
    bool returning[3];
    ThreadState(){ZeroMemory(this,sizeof(*this));}
};
static bool read(HANDLE process,DWORD address,void* data,SIZE_T size){
    SIZE_T count=0;
    return ReadProcessMemory(process,reinterpret_cast<void*>(address),data,size,&count) && count==size;
}
static DWORD word(HANDLE process,DWORD address){DWORD value=0;read(process,address,&value,4);return value;}
static void registers(CONTEXT& context,const ThreadState& state){
    context.Dr0=state.active[0];context.Dr1=state.active[1];
    context.Dr2=state.active[2];context.Dr3=state.active[3];
    context.Dr6=0;context.Dr7=0x55; // Four local execution breakpoints, one byte each.
}
int main(int argc,char** argv){
    if(argc!=6 && argc!=7)return 1;
    std::setvbuf(stdout,0,_IONBF,0);
    DWORD sites[4];for(int i=0;i<4;++i)sites[i]=std::strtoul(argv[i+2],0,16);
    std::string command="\""+std::string(argv[1])+"\" --selftest";
    std::vector<char> mutableCommand(command.begin(),command.end());mutableCommand.push_back(0);
    STARTUPINFOA startup={sizeof(startup)};PROCESS_INFORMATION process={0};
    if(!CreateProcessA(argv[1],&mutableCommand[0],0,0,FALSE,DEBUG_ONLY_THIS_PROCESS,0,0,&startup,&process))return 2;
    std::map<DWORD,ThreadState> threads;
    DWORD base=0,start=GetTickCount(),hits[4]={0,0,0,0};bool loader=false;
    int result=3;
    for(;;){
        if(GetTickCount()-start>60000){std::puts("TRACE_TIMEOUT");TerminateProcess(process.hProcess,3);break;}
        DEBUG_EVENT event;
        if(!WaitForDebugEvent(&event,1000)){if(GetLastError()==ERROR_SEM_TIMEOUT)continue;break;}
        DWORD action=DBG_CONTINUE;
        if(event.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT || event.dwDebugEventCode==CREATE_THREAD_DEBUG_EVENT){
            bool initial=event.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT;
            HANDLE thread=initial?event.u.CreateProcessInfo.hThread:event.u.CreateThread.hThread;
            if(initial){
                base=reinterpret_cast<DWORD>(event.u.CreateProcessInfo.lpBaseOfImage);
                if(event.u.CreateProcessInfo.hFile)CloseHandle(event.u.CreateProcessInfo.hFile);
                std::printf("TRACE_IMAGE base=%08lx\n",base);
            }
            ThreadState state;
            for(int i=0;i<4;++i)state.sites[i]=state.active[i]=base+(sites[i]-0x400000);
            if(argc==7)state.operation=base+(std::strtoul(argv[6],0,16)-0x400000);
            CONTEXT context={0};context.ContextFlags=CONTEXT_DEBUG_REGISTERS;
            if(!GetThreadContext(thread,&context)){std::puts("TRACE_CONTEXT_ERROR");TerminateProcess(process.hProcess,4);break;}
            registers(context,state);
            if(!SetThreadContext(thread,&context)){std::puts("TRACE_SET_CONTEXT_ERROR");TerminateProcess(process.hProcess,4);break;}
            threads[event.dwThreadId]=state;
            if(thread!=process.hThread)CloseHandle(thread);
        }else if(event.dwDebugEventCode==LOAD_DLL_DEBUG_EVENT){
            if(event.u.LoadDll.hFile)CloseHandle(event.u.LoadDll.hFile);
        }else if(event.dwDebugEventCode==EXCEPTION_DEBUG_EVENT){
            DWORD code=event.u.Exception.ExceptionRecord.ExceptionCode;
            if(code==EXCEPTION_BREAKPOINT && !loader){loader=true;}
            else if(code==EXCEPTION_SINGLE_STEP){
                HANDLE thread=OpenThread(THREAD_GET_CONTEXT|THREAD_SET_CONTEXT|THREAD_QUERY_INFORMATION,FALSE,event.dwThreadId);
                CONTEXT context={0};context.ContextFlags=CONTEXT_FULL|CONTEXT_DEBUG_REGISTERS;
                if(!thread || !GetThreadContext(thread,&context)){std::puts("TRACE_STEP_CONTEXT_ERROR");TerminateProcess(process.hProcess,4);break;}
                ThreadState& state=threads[event.dwThreadId];
                bool found=false;
                for(int slot=0;slot<4;++slot)if(context.Eip==state.active[slot] && (context.Dr6&(1<<slot))){
                    found=true;
                    if(slot==2 && state.returning[2]){
                        std::printf("TRACE_ENTITY_CREATED entity=%08lx subentity=%08lx\n",state.receiver[2],context.Eax);
                        state.returning[2]=false;state.active[2]=state.sites[2];
                    }else if(slot<2 && state.returning[slot]){
                        DWORD receiver=state.receiver[slot];
                        if(slot==0){
                            DWORD data=word(process.hProcess,receiver+0x0c),count=word(process.hProcess,receiver+0x10);
                            DWORD level0=count?word(process.hProcess,data):0,level1=count>1?word(process.hProcess,data+4):0;
                            std::printf("TRACE_PRODUCER_RETURN mesh=%08lx levels=%lu level0=%08lx level1=%08lx\n",receiver,count,level0,level1);
                        }else{
                            std::printf("TRACE_UPLOAD_RETURN level=%08lx backend=%08lx\n",receiver,word(process.hProcess,receiver+0x24));
                        }
                        state.returning[slot]=false;state.active[slot]=state.sites[slot];
                    }else if(slot==3 && state.operation && state.active[3]==state.operation){
                        std::printf("TRACE_RENDER_OPERATION subentity=%08lx submesh=%08lx lod=%lu\n",context.Ecx,
                            word(process.hProcess,context.Ecx+0x54),word(process.hProcess,context.Ecx+0x134));
                        state.active[3]=state.sites[3];
                    }else{
                        ++hits[slot];
                        if(slot<2){
                            state.receiver[slot]=context.Ecx;
                            state.active[slot]=word(process.hProcess,context.Esp);
                            state.returning[slot]=true;
                            std::printf("TRACE_%s_ENTRY receiver=%08lx return=%08lx\n",slot==0?"PRODUCER":"UPLOAD",context.Ecx,state.active[slot]);
                        }else if(slot==2){
                            std::printf("TRACE_ENTITY_CREATE entity=%08lx submesh=%08lx lod=%lu\n",context.Ecx,word(process.hProcess,context.Esp+4),word(process.hProcess,context.Esp+8));
                            state.receiver[2]=context.Ecx;state.active[2]=word(process.hProcess,context.Esp);state.returning[2]=true;
                            if(state.operation)state.active[3]=state.operation;
                        }else std::printf("TRACE_ENTITY_DESTROY entity=%08lx\n",context.Ecx);
                    }
                }
                if(!found){std::printf("TRACE_UNEXPECTED_STEP eip=%08lx dr6=%08lx\n",context.Eip,context.Dr6);TerminateProcess(process.hProcess,4);CloseHandle(thread);break;}
                registers(context,state);context.EFlags|=0x10000; // RF resumes the trapped instruction once.
                if(!SetThreadContext(thread,&context)){std::puts("TRACE_RESUME_ERROR");TerminateProcess(process.hProcess,4);CloseHandle(thread);break;}
                CloseHandle(thread);
            }else{
                std::printf("TRACE_EXCEPTION code=%08lx address=%p first=%lu\n",code,event.u.Exception.ExceptionRecord.ExceptionAddress,event.u.Exception.dwFirstChance);
                action=DBG_EXCEPTION_NOT_HANDLED;
            }
        }else if(event.dwDebugEventCode==EXIT_PROCESS_DEBUG_EVENT){
            std::printf("TRACE_EXIT code=%lu producer=%lu upload=%lu entity=%lu destroy=%lu\n",event.u.ExitProcess.dwExitCode,hits[0],hits[1],hits[2],hits[3]);
            result=event.u.ExitProcess.dwExitCode==0 && hits[0] && hits[1] && hits[2] && hits[2]==hits[3]?0:5;
            ContinueDebugEvent(event.dwProcessId,event.dwThreadId,action);break;
        }
        if(!ContinueDebugEvent(event.dwProcessId,event.dwThreadId,action))break;
    }
    CloseHandle(process.hThread);CloseHandle(process.hProcess);
    return result;
}
