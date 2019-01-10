/**************************************************************************************
 *                                                                                    *
 * This application contains code from OpenDivX and is released as a "Larger Work"    *
 * under that license. Consistant with that license, this application is released     *
 * under the GNU General Public License.                                              *
 *                                                                                    *
 * The OpenDivX license can be found at: http://www.projectmayo.com/opendivx/docs.php *
 * The GPL can be found at: http://www.gnu.org/copyleft/gpl.html                      *
 *                                                                                    *
 * Copyright (c) 2001 - Project Mayo                                                  *
 *                                                                                    *
 * Authors: Damien Chavarria                                                          *
 *          DivX Advanced Research Center <darc at projectmayo.com>                   *
 *                                                                                    *
 **************************************************************************************/

#ifndef _MEDIA_CLASSES_H
#define _MEDIA_CLASSES_H

#include <windows.h>

/*
 * basic types used 
 * everywhere
 */

#include "MediaBuffer.h"
#include "Error.h"

/* 
 * Media type for 
 * identifying items
 */

typedef enum {

		MEDIA_TYPE_INPUT,
		MEDIA_TYPE_DECAPS,
		MEDIA_TYPE_VIDEO_DECODER,
		MEDIA_TYPE_AUDIO_DECODER,
		MEDIA_TYPE_VIDEO_BUFFER,
		MEDIA_TYPE_VIDEO_RENDERER,
		MEDIA_TYPE_AUDIO_RENDERER,
		MEDIA_TYPE_SUBTITLER,

} media_type_t;

/* 
 * Capabilities types
 *
 */

#define MEDIA_CAPS_CAN_CONFIGURE 0x00000001
#define MEDIA_CAPS_BUFFERIZE     0x00000002

/*
 * Types for Input Media 
 *
 */

/*
 * File mode enum
 */

typedef enum {

		INPUT_OPEN_ASCII,	
		INPUT_OPEN_BINARY

} media_input_mode_t;

/*
 * Seek Enum
 */

typedef enum {

		INPUT_SEEK_SET,
		INPUT_SEEK_CUR,
		INPUT_SEEK_END

} media_input_seek_t;

/*
 * Video Mode Enum
 */

typedef enum {
	
		VIDEO_MODE_NONE,
		VIDEO_MODE_RGB8,
		VIDEO_MODE_RGB16,
		VIDEO_MODE_RGB24,
		VIDEO_MODE_RGB32,
		VIDEO_MODE_YUV9,
		VIDEO_MODE_YUV12,
		VIDEO_MODE_YUY2,
		VIDEO_MODE_UYVY,

} media_video_mode_t;

/*
 * Virtual Classes to describe
 * the different Media Nodes,
 * Buffers, and Streams used by
 * the Playa...
 *
 */

class MediaItem {

private:

	media_type_t  type;
	char         *name;


public:

	/*
	 * Basic Info Functions
	 */

	virtual media_type_t  GetType() = 0;
	virtual char         *GetName() = 0;

	/*
	 * The Attach() method that will 
	 * be used to connect MediaItems
	 */

	virtual MP_RESULT     Connect(MediaItem *item) = 0;
	virtual MP_RESULT     ReleaseConnections()     = 0;

	/*
	 * Function to get CAPS
	 * and configure items...
	 *
	 */

	virtual DWORD         GetCaps()                                 = 0;
	virtual MP_RESULT     Configure(HINSTANCE hInstance, HWND hwnd) = 0;
};

/*
 * MediaItemInput:
 * ---------------
 *
 * - Input Media Item
 *
 */

class MediaItemInput : public MediaItem {

public:

	virtual MP_RESULT    Open(char *url, media_input_mode_t mode)  = 0;

	virtual long         GetSize()                                 = 0;
	virtual long         GetBufferSize()                           = 0;
	virtual long         GetBufferPosition()                       = 0;
	virtual long         GetBufferingSize()                        = 0;

	virtual unsigned int Read(MediaBuffer *mb, unsigned int size)  = 0;
	virtual unsigned int Seek(int size, media_input_seek_t method) = 0;
	virtual unsigned int GetLine(MediaBuffer *mb)                  = 0;
	
	virtual BOOL         EndOfFile()                               = 0;
	virtual MP_RESULT    Close()                                   = 0;
};

/*
 * MediaItemDecaps:
 * ----------------
 *
 * - Decaps streams
 *
 */

class MediaItemDecaps : public MediaItem {

public:

	virtual unsigned int      GetNumberOfVideoStreams()                                                 = 0;
	virtual unsigned int      GetNumberOfAudioStreams()                                                 = 0;

	virtual unsigned int      GetVideoWidth(unsigned int StreamId)                                      = 0;
	virtual unsigned int      GetVideoHeight(unsigned int StreamId)                                     = 0;
	virtual double            GetVideoFrameRate(unsigned int StreamId)                                  = 0;
	virtual char             *GetVideoCompression(unsigned int StreamId)                                = 0;
	virtual BITMAPINFOHEADER *GetVideoHeader(unsigned int StreamId)                                     = 0;

	virtual unsigned long     GetCurrentVideoFrame(unsigned int StreamId)                               = 0;
	virtual unsigned long     GetTotalVideoFrames(unsigned int StreamId)                                = 0;
	virtual unsigned long     GetTotalVideoTime(unsigned int StreamId)                                  = 0;
	
	virtual unsigned int      GetAudioBits(unsigned int StreamId)                                       = 0;
	virtual unsigned int      GetAudioChannels(unsigned int StreamId)                                   = 0;
	virtual unsigned int      GetAudioFrequency(unsigned int StreamId)                                  = 0;
	virtual WAVEFORMATEX     *GetAudioFormat(unsigned int StreamId)                                     = 0;

	virtual unsigned int      GetNextVideoFrameSize(unsigned int StreamId)                              = 0;
	virtual unsigned int      ReadVideoFrame(unsigned int StreamId, MediaBuffer *mb)                    = 0;

	virtual unsigned int      ReadAudioData(unsigned int StreamId, char *buffer, unsigned int bytes)    = 0;
	virtual MP_RESULT         UpdateForSize()                                                           = 0;

	virtual MP_RESULT		  SeekAudio(unsigned int StreamId, long bytes)                              = 0;
	virtual MP_RESULT         SeekVideo(unsigned int StreamId, long frame)                              = 0;
	virtual MP_RESULT         ReSeekAudio(unsigned int StreamId)                                        = 0;

	virtual MP_RESULT         Seek(unsigned int videoStreamId, unsigned int audioStreamId, int percent) = 0;
	virtual MP_RESULT         Rewind(unsigned int videoStreamId, unsigned int audioStreamId)            = 0;

	virtual MP_RESULT         SeekNextKeyFrame(unsigned int StreamId)                                   = 0;
	virtual MP_RESULT         SeekPreviousKeyFrame(unsigned int StreamId)                               = 0;
};

/*
 * MediaItemVideoDecoder:
 * --------------------
 *
 * - Decode Video from Stream
 *
 *
 */

class MediaItemVideoDecoder : public MediaItem {

public:

	virtual unsigned int       GetFrameSize()                        = 0;

	virtual media_video_mode_t GetVideoMode()                        = 0;
	virtual BOOL               GetInvertFlag()                       = 0;
	virtual MP_RESULT          SetVideoMode(media_video_mode_t mode) = 0;

	virtual MP_RESULT          SetQuality(DWORD quality)             = 0;
	virtual DWORD              GetQuality()                          = 0;

	virtual MP_RESULT          Decompress(MediaBuffer *mb_out, unsigned int stride)       = 0;
	virtual MP_RESULT          Drop(MediaBuffer *mb_out, unsigned int stride)             = 0;
};

/*
 * MediaItemVideoBuffer
 * --------------------
 *
 * - Bufferize decoded images
 *
 */

class MediaItemVideoBuffer : public MediaItem {

public:

	virtual MP_RESULT    StartBuffering(unsigned int stride) = 0;
	virtual MP_RESULT    StopBuffering()  = 0;

	virtual MediaBuffer *GetOneFrame()    = 0;
	virtual MediaBuffer *GetLastFrame()   = 0;
	virtual MP_RESULT    DropOneFrame()   = 0;
};

/*
 * MediaItemVideoRenderer:
 * ----------------------- 
 *
 * - Renders video on the screen
 *
 */

class MediaItemVideoRenderer : public MediaItem {

public:

	virtual MP_RESULT Init(HWND hwnd, unsigned int width, unsigned int height)                                = 0;
	virtual MP_RESULT InitFullscreen(HWND hwnd, unsigned int width, unsigned int height)                      = 0;

	virtual media_video_mode_t GetVideoMode()                                                                 = 0;
	virtual RECT              *GetFullscreenRects()                                                           = 0; 
  
	virtual MP_RESULT Draw(MediaBuffer *buffer, RECT *rect, int frameNumber, int invertFlag)                  = 0;
	virtual MP_RESULT DrawFullscreen(MediaBuffer *buffer, int frameNumber, int invertFlag, int desktopMode)   = 0;

	virtual MP_RESULT Stop()                                                                                  = 0;

	virtual MP_RESULT Close()                                                                                 = 0;
};

/*
 * Type for subtitles
 * transfer...
 *
 */

typedef struct _subtitles_t {

	char *subtitlesText[4];
	DWORD nbSubtitles;

} subtitles_t;

/* 
 * MediaItemSubtitler
 * ------------------
 *
 * - Readssubtitles
 *
 */

class MediaItemSubtitler : public MediaItem {

public:

	virtual MP_RESULT    Open(char *lpFilename)                  = 0;
	virtual subtitles_t *GetSubtitles(DWORD frameNumber)         = 0;
	virtual MP_RESULT    Close()                                 = 0;
};

/*
 * MediaItemAudioDecoder:
 * ----------------------
 *
 * - Decodes audio to a buffer
 *
 */

class MediaItemAudioDecoder : public MediaItem {

public:

	virtual WAVEFORMATEX *GetAudioFormat()                                   = 0;
	virtual MP_RESULT     EmptyAudioBuffer()                                 = 0;

	virtual unsigned int  Decompress(void *buffer, unsigned int size) = 0;

};

/*
 * MediaItemAudioRenderer:
 * -----------------------
 *
 * - Renderer audio to system soundcard
 *
 */

/* 
 * Audio Callback
 */

typedef unsigned int (*MediaAudioCallback)(void *lpData, void *buffer, unsigned int size);


class MediaItemAudioRenderer : public MediaItem {

public:

	virtual MP_RESULT     Open(HWND hwnd, WAVEFORMATEX *inFormat)                = 0;

	virtual MP_RESULT     SetCallback(void *lpData, MediaAudioCallback callback) = 0;
	virtual MP_RESULT     SetVolume(unsigned int volume)                         = 0;

	virtual unsigned long GetAudioTime()                                         = 0;
	virtual MP_RESULT     Bufferize()                                            = 0;

	virtual MP_RESULT     Start()                                                = 0;
	virtual MP_RESULT     Pause()                                                = 0;
	virtual MP_RESULT     Stop()                                                 = 0;

	virtual MP_RESULT     Close()                                                = 0;
};


#endif // MEDIA_CLASSES_H
