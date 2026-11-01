// Boundary between the MFC client and the recovered player engine.
#ifndef P6_ENGINE_H
#define P6_ENGINE_H
#ifdef __cplusplus
extern "C" {
#endif
int P6EngineStartup(void);
int P6EngineReadable(const char* path);
int P6EngineOpen(void* window, const char* path, int width, int height, int play);
int P6EngineScript(const char* command);
typedef void (*P6TreeVisitor)(int depth, const char* className, const char* name, void* item, void* context);
typedef void (*P6PropertyVisitor)(const char* category, const char* name, const char* value, int readOnly, void* context);
int P6DataProperties(void* item, P6PropertyVisitor visitor, void* context);
int P6DataSetProperty(void* item, const char* name, const char* value);
void P6EngineSetRunning(int running);
int P6EngineRunning(void);
void P6DataWalk(P6TreeVisitor visitor, void* context);
int P6EnginePlay(void);
int P6EngineIsOpen(void);
int P6EngineSave(const char* path);
int P6EngineFrame(void);
int P6EngineFrames(void);
void P6EngineReport(void);
int P6EngineCapture(const char* path);
void P6EngineResize(void);
void P6EngineClose(void);
#ifdef __cplusplus
}
#endif
#endif
