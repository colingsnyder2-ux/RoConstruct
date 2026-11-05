/**
 @file AVI.cpp
 @maintainer Morgan McGuire, matrix@graphics3d.com
 */

#include "AVI.h"

namespace G3D {


/** 
@cite http://msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_avifileopen.asp
*/

static const char* aviErrorCodeToString(HRESULT result) {
    switch (result) {
    case AVIERR_BADFORMAT:
        return "could not be read, is a corrupt, or is in an unrecognized format.";

    case AVIERR_MEMORY:
        return "could not be opened because of insufficient memory.";
    
    case AVIERR_FILEREAD:
        return "could not be opened because a disk error occurred while reading.";

    case AVIERR_FILEOPEN:
        return "could not be opened because a disk error occurred.";

    case REGDB_E_CLASSNOTREG:
        return "has no associated file type in the registry.";

    default:
        return "triggered an unknown error and could not be opened.";
    }
}


/** 
 The Windows AVI interface uses global intialization state.  We add a 
 reference count to allow multiple simultaneously open files.  Access this
 through AVIInit and AVIExit.
 */
static void AVIChangeCount(int inc) {
    static int count = 0;
    
    if ((count == 0) && (inc == 1)) {
    	AVIFileInit();
    }

    if ((count == 1) && (inc == -1)) {
        AVIFileExit();
    }

    count += inc;
}

static void AVIInit() {
    AVIChangeCount(1);
}

static void AVIExit() {
    AVIChangeCount(-1);
}

AVIReader::AVIReader(const std::string& filename) : 
    m_ok(false), 
    m_error(""), 
    m_filename(filename), 
    pgf(NULL), 
    nNumAudioStreams(0), 
    nNumVideoStreams(0),
    m_numFrames(0) {
	
    AVIInit();

    if (AVIFileOpen(&pAviFile, filename.c_str(), OF_READ, NULL)) {
        m_error = std::string("Unable to open ") + filename;
    	return;
    }

    // File info
    AVIFileInfo(pAviFile, &info, sizeof(info));

    // Find the audio and video streams
    do {
        if (AVIFileGetStream(pAviFile, &pAudio[nNumAudioStreams],
            streamtypeAUDIO, nNumAudioStreams)) {
            break;
        }
    } while(++nNumAudioStreams < MAX_AUDIO_STREAMS);

    do {
        DWORD result = AVIFileGetStream(pAviFile, &pVideo[nNumVideoStreams], streamtypeVIDEO, nNumVideoStreams);
        if (result != 0) {
            bool noVideo = (result == AVIERR_NODATA);
            (void)noVideo;

            if (result == AVIERR_MEMORY) {
                m_error = std::string("Out of memory while procssing ") + filename;
                return;
            }
            break;
        }
    } while(++nNumVideoStreams < MAX_VIDEO_STREAMS);

    if (nNumVideoStreams == 0) {
        m_error = std::string("No video data found in ") + filename;
        return;
    }

    // Process video stream 0
    // Video stream info (see http://msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_avistreaminfo_str.asp)
    AVISTREAMINFO videoInfo;
    if (AVIStreamInfo(pVideo[0], &videoInfo, sizeof(videoInfo))) {
        m_error = std::string("Unable to read video stream 0 info from ") + filename;
        return;
    }

    if (videoInfo.fccType != streamtypeVIDEO) {
        m_error = std::string("Incorrectly labeled video data found in ") + filename;
        return;
    }

    {
        char temp[5];
        temp[0] = (videoInfo.fccHandler >> 24) & 0xFF;
        temp[1] = (videoInfo.fccHandler >> 16) & 0xFF;
        temp[2] = (videoInfo.fccHandler >> 8) & 0xFF;
        temp[3] = videoInfo.fccHandler & 0xFF;
        temp[4] = '\0';
        m_codec = std::string(temp);
    }

    m_numFrames = videoInfo.dwLength;

    m_width  = videoInfo.rcFrame.right - videoInfo.rcFrame.left;
    m_height = videoInfo.rcFrame.bottom - videoInfo.rcFrame.top;

    /*
    // Read stream format data
    // Find out how large the format data is (in bytes)
    LONG lSize;
    if (AVIStreamReadFormat(pVideo[0], AVIStreamStart(pVideo[0]), NULL, &lSize)) {
        m_error = std::string("Unable to read stream format on stream 0 from ") + filename;
        return;
    }

    // Read the format data
    LPBYTE pChunk = new BYTE[lSize];
    if (AVIStreamReadFormat(pVideo[0], AVIStreamStart(pVideo[0]), pChunk, &lSize)) {
        m_error = std::string("Unable to read stream format on stream 0 from ") + filename;
        delete[] pChunk;
        pChunk = NULL;
        return;
    }
    delete[] pChunk;
    pChunk = NULL;
    */

    // We always want 24-bit RGB data (this appears to be the most compatible format)

    // (could use the biCompression field to move data around, however that doesn't work on Win98/ME)
    // http://msdn.microsoft.com/library/default.asp?url=/library/en-us/gdi/bitmaps_1rw2.asp
    BITMAPINFOHEADER biWanted;
    biWanted.biSize             = sizeof(BITMAPINFOHEADER);
    biWanted.biWidth            = m_width;
    // Normally, negative height means flip upside down (to the format G3D wants),
    // however the AVI functions don't support that convention.
    biWanted.biHeight           = m_height;
    biWanted.biPlanes           = 1;
    biWanted.biBitCount         = 24;
    biWanted.biCompression      = BI_RGB;
    biWanted.biSizeImage        = 0; // May be zero for RGB images
    biWanted.biXPelsPerMeter    = 0;
    biWanted.biYPelsPerMeter    = 0;
    biWanted.biClrUsed          = 3;
    biWanted.biClrImportant     = 0;

    pgf = AVIStreamGetFrameOpen(pVideo[0], &biWanted);
    if (pgf == NULL) {
        m_error = std::string("Unable to read frames from stream 0 as RGB data in ") + filename;
        return;
    }

    m_ok = true;
}


AVIReader::~AVIReader() {

    // Release resources
    if (pgf) {
        if (AVIStreamGetFrameClose(pgf)) {
            // Error
        }
        pgf = NULL;
    }

    for (int i = 0; i < nNumAudioStreams; ++i) {
        AVIStreamRelease(pAudio[i]);
    }

    for (int i = 0; i < nNumVideoStreams; ++i) {
        AVIStreamRelease(pVideo[i]);
    }

    AVIFileRelease(pAviFile);
    pAviFile = NULL;

    AVIExit();
}


void AVIReader::getFrame(int f, GImage& im, int channels) {

    LPBITMAPINFOHEADER lpbi;
    lpbi = (LPBITMAPINFOHEADER)AVIStreamGetFrame(pgf, f);

    // We know the data is in Windows 32-bit dib format.
    // The 12 constant is a hack--without it this gives textures that 
    // are slightly shifted :(
    const Color3uint8* pData = (Color3uint8*)((uint8*)lpbi + lpbi->biSize + 12);

    alwaysAssertM((channels == 1) || (channels == 3) || (channels == 4), "Illegal number of channels");

    im.resize(m_width, m_height, channels);

    // Copy the data from pData to the image, rearranging as necessary
    switch(channels) {
    case 1:
        for (int y = 0; y < m_height; ++y) {
            const Color3uint8* srcRow = pData + y * m_width;
            uint8*             dstRow = im.byte() + (m_height - y - 1) * m_width;

            for (int x = 0; x < m_width; ++x) {
                const Color3uint8& src = srcRow[x];
                dstRow[x] = ((int)src.r + (int)src.g + (int)src.b) / 3;
            }
        }
        break;

    case 3:
        for (int y = 0; y < m_height; ++y) {
            const Color3uint8* srcRow = pData + y * m_width;
            Color3uint8*       dstRow = im.pixel3() + (m_height - y - 1) * m_width;

            for (int x = 0; x < m_width; ++x) {
                const Color3uint8& src = srcRow[x];
                Color3uint8&       dst = dstRow[x];
                dst.r = src.b;
                dst.g = src.g;
                dst.b = src.r;
            }
        }
        break;

    case 4:
        for (int y = 0; y < m_height; ++y) {
            const Color3uint8* srcRow = pData + y * m_width;
            Color4uint8*       dstRow = im.pixel4() + (m_height - y - 1) * m_width;

            for (int x = 0; x < m_width; ++x) {
                const Color3uint8& src = srcRow[x];
                Color4uint8&       dst = dstRow[x];
                dst.r = src.b;
                dst.g = src.g;
                dst.b = src.r;
                dst.a = 255;
            }
        }
        break;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////


AVIWriter::AVIWriter(
    const std::string& filename, 
    int width, 
    int height, 
    int period, 
    const std::string& codec,
    bool promptForCompressOptions) : 
        state(STATE_WRITING), 
        pAviFile(NULL), 
        m_filename(filename), 
        m_ok(true),
        m_width(width),
        m_height(height),
        m_codec(codec) {

    AVIInit();    

    alwaysAssertM(codec.length() == 4, "codec must have exactly four characters.");

    if (fileExists(filename)) {
        // Delete the file so we can overwrite without error
        BOOL success = DeleteFile(filename.c_str());
    }

    HRESULT result = AVIFileOpen(&pAviFile, filename.c_str(), OF_CREATE, NULL);

    if (result != AVIERR_OK) {
        setError(aviErrorCodeToString(result));
        return;
    }

    m_period = period;
    audio = NULL;
    video = NULL;
    compressedVideo = NULL;
    nframe = 0; 
    nsamp = 0;

    frameBytes = m_width * m_height * 3;

    createStreams(promptForCompressOptions);
}


void AVIWriter::setError(const std::string& str) {

    m_errorString = std::string("File '") + m_filename + "' " + str;
    m_ok = false;

    if (state == STATE_WRITING) {
        AVIExit();
    }

    state = STATE_ERROR;
}


void AVIWriter::createStreams(bool promptForCompressOptions) {

    debugAssert(video == NULL);
    debugAssert(compressedVideo == NULL);

    HRESULT result;

    // create the stream
    AVISTREAMINFO strhdr;
    ZeroMemory(&strhdr, sizeof(strhdr));

    strhdr.fccType = streamtypeVIDEO;// stream type
    strhdr.fccHandler = 0;
    strhdr.dwScale = m_period;
    strhdr.dwRate = 1000;
    strhdr.dwSuggestedBufferSize = frameBytes;

    SetRect(&strhdr.rcFrame, 0, 0, m_width, m_height);

    result = AVIFileCreateStream(pAviFile, &video, &strhdr);
    if (result != AVIERR_OK) {
        setError("encountered an error while writing a frame.");
        return;
    }

    /*
    typedef struct { 
    DWORD  fccType; 
    DWORD  fccHandler; 
    DWORD  dwKeyFrameEvery; 
    DWORD  dwQuality; 
    DWORD  dwBytesPerSecond; 
    DWORD  dwFlags; 
    LPVOID lpFormat; 
    DWORD  cbFormat; 
    LPVOID lpParms; 
    DWORD  cbParms; 
    DWORD  dwInterleaveEvery; 
    } AVICOMPRESSOPTIONS; 
    */
    AVICOMPRESSOPTIONS myopts;
    ZeroMemory(&myopts, sizeof(myopts));

    // Default to raw, uncompressed frames
    myopts.fccType = streamtypeVIDEO;
    myopts.fccHandler = mmioFOURCC(m_codec[0], m_codec[1], m_codec[2], m_codec[3]);
    myopts.dwFlags = AVICOMPRESSF_VALID;
    myopts.dwQuality = 100;

    AVICOMPRESSOPTIONS* optionArray[1];
    optionArray[0] = &myopts;

    if (promptForCompressOptions) { 
        BOOL result = (BOOL)AVISaveOptions(NULL, 0, 1, &video, optionArray);

        if (result == false) {
            // User aborted
            AVISaveOptionsFree(1, optionArray);            
            setError("was aborted by user dialog.");
            return;
        }
    }

    result = AVIMakeCompressedStream(&compressedVideo, video, optionArray[0], NULL);
    if (promptForCompressOptions) {
        // Save the compression options
        AVISaveOptionsFree(1, optionArray);
    }

    if (result != AVIERR_OK) {
        setError("had a problem creating a compressed video stream.");
        return;
    }

    BITMAPINFOHEADER    bi;
    bi.biSize             = sizeof(BITMAPINFOHEADER);
    bi.biWidth            = m_width;
    // Normally, negative height means flip upside down (to the format G3D wants),
    // however the AVI functions don't support that convention.
    bi.biHeight           = m_height;
    bi.biPlanes           = 1;
    bi.biBitCount         = 24;
    bi.biCompression      = BI_RGB;
    bi.biSizeImage        = 0; // May be zero for RGB images
    bi.biXPelsPerMeter    = 0;
    bi.biYPelsPerMeter    = 0;
    bi.biClrUsed          = 3;
    bi.biClrImportant     = 0;

    const int position = 0;
    result = AVIStreamSetFormat(compressedVideo, position, &bi, bi.biSize + bi.biClrUsed * sizeof(RGBQUAD));

    if (result != AVIERR_OK) {
        setError("had a problem setting the compressed video stream format.");
        return;
    }
}


AVIWriter::~AVIWriter() {
    alwaysAssertM(state == STATE_COMMITTED || state == STATE_ABORTED || state == STATE_ERROR, 
        "Destroyed AVIWriter without committing or aborting");
}


void AVIWriter::writeFrame(const GImage& im) {
    if (! ok()) {
        debugAssertM(ok(), "Can't write to error file.");
        return;
    }

    if ((im.width != m_width) || (im.height != m_height)) {
        debugAssertM(false, "Dimensions of each frame must match");
        return;
    }   


    static GImage out;
    out.resize(im.width, im.height, 3);

    // Copy im to out, flipping and converting to 3 channels
    switch (im.channels) {
    case 1:
        // TODO: We could handle this by using an 8-bit bitmap format when setting the color channels
        // Flip and spread colors
        for (int y = 0; y < im.height; ++y) {
            for (int x = 0; x < im.width; ++x) {
                const uint8 s = im.pixel1(x, y);
                Color3uint8 d;
                d.r = s; d.g = s; d.b = s;
                out.pixel3(x, out.height - y - 1) = d;
            }
        }
        break;

    case 3:
        // Flip upside down
        GImage::flipRGBVertical(im.byte(), out.byte(), im.width, im.height);

        // Swap color channels
        GImage::RGBtoBGR(out.byte(), out.byte(), out.width * out.height);
        break;

    case 4:
        // Flip and convert colors to dib format
        for (int y = 0; y < im.height; ++y) {
            for (int x = 0; x < im.width; ++x) {
                const Color4uint8& s = im.pixel4(x, y);
                Color3uint8 d;
                d.r = s.b; d.g = s.g; d.b = s.r;
                out.pixel3(x, out.height - y - 1) = d;
            }
        }
        break;
    }


    HRESULT result = AVIStreamWrite(compressedVideo, nframe, 1, out.byte(), frameBytes, AVIIF_KEYFRAME, NULL, NULL);
    if (result != AVIERR_OK) {
        setError("encountered an error while writing a frame.");
        return;
    }
    ++nframe;   
}


void AVIWriter::getCodecs(Array<std::string>& comp) {
    // TODO
}


void AVIWriter::closeFile() {
    debugAssert(state == STATE_WRITING);
    debugAssert(pAviFile);

    if (audio) {
        AVIStreamRelease(audio);
        audio = NULL;
    }

    if (compressedVideo) {
        AVIStreamRelease(compressedVideo);
        compressedVideo = NULL;
    }

    if (video) {
        AVIStreamRelease(video);
        video = NULL;
    }

    AVIFileRelease(pAviFile);
    pAviFile = NULL;
    AVIExit();
}

void AVIWriter::commit() {
    alwaysAssertM(state == STATE_WRITING, "Cannot commit when not writing a file.");

    closeFile();
    state = STATE_COMMITTED;
}


void AVIWriter::abort() {
    alwaysAssertM(state == STATE_WRITING, "Cannot abort when not writing a file.");

    closeFile();
    state = STATE_ABORTED;
}


}
