#include <windows.h>
#include <cstdio>
int main(int argc,char** argv){
 if(argc!=2)return 1;
 STARTUPINFOA startup={sizeof(startup)};PROCESS_INFORMATION proc={0};
 if(!CreateProcessA(argv[1],0,0,0,FALSE,DEBUG_ONLY_THIS_PROCESS,0,0,&startup,&proc))return 2;
 DEBUG_EVENT event;bool loader=true;
 while(WaitForDebugEvent(&event,10000)){
  DWORD action=DBG_CONTINUE;
  if(event.dwDebugEventCode==LOAD_DLL_DEBUG_EVENT && event.u.LoadDll.hFile)CloseHandle(event.u.LoadDll.hFile);
  if(event.dwDebugEventCode==CREATE_PROCESS_DEBUG_EVENT && event.u.CreateProcessInfo.hFile)CloseHandle(event.u.CreateProcessInfo.hFile);
  if(event.dwDebugEventCode==OUTPUT_DEBUG_STRING_EVENT){
   char text[4096]={0};SIZE_T count=0;
   ReadProcessMemory(proc.hProcess,event.u.DebugString.lpDebugStringData,text,4095,&count);
   std::printf("DEBUGSTRING %s\n",text);
  }
  if(event.dwDebugEventCode==EXCEPTION_DEBUG_EVENT){
   DWORD code=event.u.Exception.ExceptionRecord.ExceptionCode;
   std::printf("EXCEPTION %08lx address=%p first=%lu\n",code,event.u.Exception.ExceptionRecord.ExceptionAddress,event.u.Exception.dwFirstChance);
   if(code==EXCEPTION_BREAKPOINT && loader)loader=false;
   else if(code==EXCEPTION_BREAKPOINT || code==EXCEPTION_ACCESS_VIOLATION){
    HANDLE thread=OpenThread(THREAD_GET_CONTEXT|THREAD_QUERY_INFORMATION,FALSE,event.dwThreadId);
    CONTEXT context={0};context.ContextFlags=CONTEXT_FULL;
    if(GetThreadContext(thread,&context)){
     std::printf("EIP=%08lx ESP=%08lx EBP=%08lx\n",context.Eip,context.Esp,context.Ebp);
     DWORD stack[48]={0};SIZE_T count=0;ReadProcessMemory(proc.hProcess,(void*)context.Esp,stack,sizeof(stack),&count);
     for(unsigned i=0;i<count/4;++i)std::printf("STACK %08lx %08lx\n",context.Esp+i*4,stack[i]);
    }
    CloseHandle(thread);TerminateProcess(proc.hProcess,code);
   }else action=DBG_EXCEPTION_NOT_HANDLED;
  }
  if(event.dwDebugEventCode==EXIT_PROCESS_DEBUG_EVENT){std::printf("EXIT %08lx\n",event.u.ExitProcess.dwExitCode);break;}
  ContinueDebugEvent(event.dwProcessId,event.dwThreadId,action);
 }
 CloseHandle(proc.hThread);CloseHandle(proc.hProcess);return 0;
}
