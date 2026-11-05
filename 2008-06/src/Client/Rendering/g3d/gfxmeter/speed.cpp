#include "../include/G3DAll.h"

// @cite based on code by Ian Cheswick

#ifdef G3D_WIN32

/**
 Time is in milliseconds
 */
typedef	void (*DELAY_FUNC)(uint32 time);

int64 GetCyclesDifference(DELAY_FUNC DelayFunction, uint32 uiParameter) {
    // Two successive readings of the RDTSC
	unsigned int t0Hi, t0Lo;
	unsigned int t1Hi, t1Lo;

#   define rdtsc _asm _emit 0x0f _asm _emit 0x31
	__try {
		_asm {

            // Get the count before calling the known delay function
			rdtsc
			mov         esi, eax
			mov         edi, edx

            // call the delay function
            push        uiParameter
            call        DelayFunction
			pop         ebx

            // Get the count after the delay function
			rdtsc
			mov         t1Hi, edx
			mov         t1Lo, eax

			mov         t0Hi, edi
			mov         t0Lo, esi
		}
    } __except (1) {

        // Something horrible has happened.  Abort
		return 0;
	}
#   undef rdtsc

    // Compute the total cycle difference
	return ((((int64)t1Hi) << 32) + t1Lo) - 
           ((((int64)t0Hi) << 32) + t0Lo);
}


void Delay(uint32 time) {
	LARGE_INTEGER Frequency, StartCounter, EndCounter;
	__int64 x;

	// Get the frequency of the high performance counter.
    if (!QueryPerformanceFrequency(&Frequency)) {
        return;
    }
	x = Frequency.QuadPart / 1000 * time;

	// Get the starting position of the counter.
	QueryPerformanceCounter(&StartCounter);

	do {
		// Get the ending position of the counter.	
		QueryPerformanceCounter (&EndCounter);
	} while (EndCounter.QuadPart - StartCounter.QuadPart < x);
}


void DelayOverhead(uint32 time) {
	LARGE_INTEGER Frequency, StartCounter, EndCounter;
	__int64 x;

	// Get the frequency of the high performance counter.
    if (!QueryPerformanceFrequency(&Frequency)) {
        return;
    }

	x = Frequency.QuadPart / 1000 * time;

	// Get the starting position of the counter.
	QueryPerformanceCounter(&StartCounter);
	
	do {
		// Get the ending position of the counter.	
		QueryPerformanceCounter(&EndCounter);
	} while (EndCounter.QuadPart - StartCounter.QuadPart == x);
}



int CPU_speed_in_MHz() {
	const int N = 2;

    // Execution time, in milliseconds
	unsigned int time = 50;
	int64 total = 0;
    int64 overhead = 0;

	for (int i = 0; i < N; ++i) {
		total += GetCyclesDifference(Delay, time);
		overhead += GetCyclesDifference(DelayOverhead, time);
	}

	// Calculate the MHz speed.
	total -= overhead;
	total /= N;
	total /= time;
	total /= 1000;

	return (int)total;
}

#else

int CPU_speed_in_MHz() {
    return 0;
}

#endif
