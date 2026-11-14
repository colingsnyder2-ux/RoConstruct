// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DLog (inactive): OpenRBX G3D Log source; 2008 file checks supported by original assembly.
// >>> native-status (generated) -- do not edit >>>
// G3DLog | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d0dec04e | roc native-status --write
#line 1 ".\\G3Dcpp\\Log.cpp"
/**
  @file Log.cpp

  @maintainer Morgan McGuire, morgan@graphics3d.com
  @created 2001-08-04
  @edited  2005-07-01
 */

#include "G3D/platform.h"
#include "G3D/Log.h"
#include "G3D/format.h"
#include "G3D/Array.h"
#include "G3D/fileutils.h"
#include <time.h>

#ifdef G3D_WIN32
    #include <imagehlp.h>
#else
    #include <stdarg.h>
#endif

namespace G3D {

Log* Log::commonLog = NULL;

Log::Log(const std::string& filename, int stripFromStackBottom) : 
    stripFromStackBottom(stripFromStackBottom) {

    this->filename = filename;

    logFile = fopen(filename.c_str(), "w");

    if (logFile != NULL) {
        // Turn off buffering.
        setvbuf(logFile, NULL, _IONBF, 0);

        fprintf(logFile, "Application Log\n");
        time_t t;
        time(&t);
        fprintf(logFile, "Start: %s\n", ctime(&t));
        fflush(logFile);
    }

    if (commonLog == NULL) {
        commonLog = this;
    }
}


Log::~Log() {
    section("Shutdown");
    println("Closing log file");
    
    // Make sure we don't leave a dangling pointer
    if (Log::commonLog == this) {
        Log::commonLog = NULL;
    }

    if (logFile != NULL) {
        fclose(logFile);
    }
}


FILE* Log::getFile() const {
    return logFile;
}

Log* Log::common() {
    if (commonLog == NULL) {
        commonLog = new Log();
    }
    return commonLog;
}


std::string Log::getCommonLogFilename() {
    return common()->filename;
}


void Log::section(const std::string& s) {
    if (logFile != NULL) {
        fprintf(logFile, "_____________________________________________________\n");
        fprintf(logFile, "\n    ###    %s    ###\n\n", s.c_str());
    }
}


void __cdecl Log::printf(const char* fmt, ...) {
    printHeader();

	va_list arg_list;
	va_start(arg_list, fmt);
    print(vformat(fmt, arg_list));
    va_end(arg_list);
}


void __cdecl Log::vprintf(const char* fmt, va_list argPtr) {
    vfprintf(logFile, fmt, argPtr);
}


void Log::print(const std::string& s) {
    if (logFile != NULL) {
        printHeader();
        fprintf(logFile, "%s", s.c_str());
    }
}


void Log::println(const std::string& s) {
    if (logFile != NULL) {
        printHeader();
        fprintf(logFile, "%s\n", s.c_str());
    }
}


void Log::printHeader() {
    time_t t;
    if (time(&t) != ((time_t)-1)) {
        /*
        char buf[32];
        strftime(buf, 32, "[%H:%M:%S]", localtime(&t));
    
         Removed because this doesn't work on SDL threads.

        #ifdef _DEBUG
            std::string bt = getBacktrace(15, 2, stripFromStackBottom);
            fprintf(logFile, "\n %s %s\n\n", buf, bt.c_str());
        #endif

        fprintf(logFile, "\n %s \n", buf);
        */

    } else {
        println("[Error getting time]");
    }
}

}
