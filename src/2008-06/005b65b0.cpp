// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_fmod_2008_exact_56149336968faa42.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/format.h>
#include <util/standardout.h>
#include <stdexcept>
typedef int FMOD_RESULT;
static char *FMOD_ErrorString(FMOD_RESULT errcode)
{
    switch (errcode)
    {
case 1: return "Tried to call lock a second time before unlock was called. ";
case 2: return "Tried to call a function on a data type that does not allow this type of functionality (ie calling Sound::lock on a streaming sound). ";
case 3: return "Neither NTSCSI nor ASPI could be initialised. ";
case 4: return "An error occurred while initialising the CDDA subsystem. ";
case 5: return "Couldn't find the specified device. ";
case 6: return "No audio tracks on the specified disc. ";
case 7: return "No CD/DVD devices were found. ";
case 8: return "No disc present in the specified drive. ";
case 9: return "A CDDA read error occurred. ";
case 10: return "Error trying to allocate a channel. ";
case 11: return "The specified channel has been reused to play another sound. ";
case 12: return "A Win32 COM related error occured. COM failed to initialize or a QueryInterface failed meaning a Windows codec or driver was not installed properly. ";
case 13: return "DMA Failure.  See debug output for more information. ";
case 14: return "DSP connection error.  Connection possibly caused a cyclic dependancy. ";
case 15: return "DSP Format error.  A DSP unit may have attempted to connect to this network with the wrong format. ";
case 16: return "DSP connection error.  Couldn't find the DSP unit specified. ";
case 17: return "DSP error.  Cannot perform this operation while the network is in the middle of running.  This will most likely happen if a connection or disconnection is attempted in a DSP callback. ";
case 18: return "DSP connection error.  The unit being connected to or disconnected should only have 1 input or output. ";
case 81: return "An Event failed to be retrieved, most likely due to 'just fail' being specified as the max playbacks behavior. ";
case 82: return "Can't execute this command on an EVENT_INFOONLY event. ";
case 83: return "An error occured that wasn't supposed to.  See debug log for reason. ";
case 84: return "Event failed because 'Max streams' was hit when FMOD_INIT_FAIL_ON_MAXSTREAMS was specified. ";
case 85: return "FSB mismatches the FEV it was compiled with or FEV was built for a different platform. ";
case 86: return "A category with the same name already exists. ";
case 87: return "The requested event, event group, event category or event property could not be found. ";
case 19: return "Error loading file. ";
case 20: return "Couldn't perform seek operation.  This is a limitation of the medium (ie netstreams) or the file format. ";
case 21: return "Media was ejected while reading. ";
case 22: return "End of file unexpectedly reached while trying to read essential data (truncated data?). ";
case 23: return "File not found. ";
case 24: return "Unwanted file access occured. ";
case 25: return "Unsupported file or audio format. ";
case 26: return "A HTTP error occurred. This is a catch-all for HTTP errors not listed elsewhere. ";
case 27: return "The specified resource requires authentication or is forbidden. ";
case 28: return "Proxy authentication is required to access the specified resource. ";
case 29: return "A HTTP server error occurred. ";
case 30: return "The HTTP request timed out. ";
case 31: return "FMOD was not initialized correctly to support this function. ";
case 32: return "Cannot call this command after System::init. ";
case 33: return "An error occured that wasn't supposed to.  Contact support. ";
case 34: return "On Xbox 360, this memory address passed to FMOD must be physical, (ie allocated with XPhysicalAlloc.) ";
case 35: return "Value passed in was a NaN, Inf or denormalized float. ";
case 36: return "An invalid object handle was used. ";
case 37: return "An invalid parameter was passed to this function. ";
case 38: return "An invalid speaker was passed to this function based on the current speaker mode. ";
case 39: return "The vectors passed in are not unit length, or perpendicular. ";
case 40: return "PS2 only.  fmodex.irx failed to initialize.  This is most likely because you forgot to load it. ";
case 41: return "Reached maximum audible playback count for this sound's soundgroup. ";
case 42: return "Not enough memory or resources. ";
case 43: return "Can't use FMOD_OPENMEMORY_POINT on non PCM source data, or non mp3/xma/adpcm data if FMOD_CREATECOMPRESSEDSAMPLE was used. ";
case 44: return "PS2 only.  Not enough memory or resources on PlayStation 2 IOP ram. ";
case 45: return "Not enough memory or resources on console sound ram. ";
case 46: return "Tried to call a command on a 3d sound when the command was meant for 2d sound. ";
case 47: return "Tried to call a command on a 2d sound when the command was meant for 3d sound. ";
case 48: return "Tried to use a feature that requires hardware support.  (ie trying to play a VAG compressed sound in software on PS2). ";
case 49: return "Tried to use a feature that requires the software engine.  Software engine has either been turned off, or command was executed on a hardware channel which does not support this feature. ";
case 50: return "Couldn't connect to the specified host. ";
case 51: return "A socket error occurred.  This is a catch-all for socket-related errors not listed elsewhere. ";
case 52: return "The specified URL couldn't be resolved. ";
case 53: return "Operation on a non-blocking socket could not complete immediately. ";
case 54: return "Operation could not be performed because specified sound is not ready. ";
case 55: return "Error initializing output device, but more specifically, the output device is already in use and cannot be reused. ";
case 56: return "Error creating hardware sound buffer. ";
case 57: return "A call to a standard soundcard driver failed, which could possibly mean a bug in the driver or resources were missing or exhausted. ";
case 58: return "Error enumerating the available driver list. List may be inconsistent due to a recent device addition or removal. ";
case 59: return "Soundcard does not support the minimum features needed for this soundsystem (16bit stereo output). ";
case 60: return "Error initializing output device. ";
case 61: return "FMOD_HARDWARE was specified but the sound card does not have the resources nescessary to play it. ";
case 62: return "Attempted to create a software sound but no software channels were specified in System::init. ";
case 63: return "Panning only works with mono or stereo sound sources. ";
case 64: return "An unspecified error has been returned from a 3rd party plugin. ";
case 65: return "The number of allowed instances of a plugin has been exceeded. ";
case 66: return "A requested output, dsp unit type or codec was not available. ";
case 67: return "A resource that the plugin requires cannot be found. (ie the DLS file for MIDI playback) ";
case 68: return "An error occured trying to initialize the recording device. ";
case 69: return "Specified Instance in FMOD_REVERB_PROPERTIES couldn't be set. Most likely because it is an invalid instance number, or another application has locked the EAX4 FX slot. ";
case 73: return "The error occured because the sound referenced contains subsounds.  The operation cannot be performed on a parent sound, or a parent sound was played without setting up a sentence first. ";
case 70: return "This subsound is already being used by another sound, you cannot have more than one parent to a sound.  Null out the other parent's entry first. ";
case 71: return "Shared subsounds cannot be replaced or moved from their parent stream, such as when the parent stream is an FSB file. ";
case 72: return "The subsound's mode bits do not match with the parent sound's mode bits.  See documentation for function that it was called with. ";
case 74: return "The specified tag could not be found or there are no tags. ";
case 75: return "The sound created exceeds the allowable input channel count.  This can be increased using the maxinputchannels parameter in System::setSoftwareFormat. ";
case 76: return "Something in FMOD hasn't been implemented when it should be! contact support! ";
case 77: return "This command failed because System::init or System::setDriver was not called. ";
case 78: return "A command issued was not supported by this object.  Possibly a plugin without certain callbacks specified. ";
case 79: return "An error caused by System::update occured. ";
case 80: return "The version number of this file format is not supported. ";
case 0: return "No errors.";
    default: return "Unknown error.";
    }
}
void checkResult(FMOD_RESULT result)
{
    if (result != 0) {
        std::string message = G3D::format("FMOD %d: %s", result, FMOD_ErrorString(result));
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, message.c_str());
        throw std::runtime_error(message);
    }
}
