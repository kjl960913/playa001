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

#ifndef MEDIA_PLAYBACK_H
#define MEDIA_PLAYBACK_H

#include <windows.h>

#include "Input.h"
#include "Decaps.h"
#include "MediaBuffer.h"
#include "VideoDecoder.h"
#include "VideoBuffer.h"
#include "VideoRenderer.h"
#include "AudioDecoder.h"
#include "AudioRenderer.h"
#include "MediaClasses.h"
#include "Subtitles.h"

#define  WM_PLAYA_PLAYBACK_END (WM_USER + 2)

/*
 * Playback Class 
 * --------------
 * 
 * - Offers a frontend to all the
 *   mediaclasses items and filters
 * 
 */

class MediaPlayback {

public:

	MediaInput         *input;
	MediaDecaps        *decaps;
	MediaVideoDecoder  *videoDecoder;
	MediaVideoBuffer   *videoBuffer;
	MediaVideoRenderer *videoRenderer;
	MediaAudioDecoder  *audioDecoder;
	MediaAudioRenderer *audioRenderer;
	MediaSubtitler     *subtitler;

	HWND                hwndPlayback;
	RECT               *videoRect;

	BOOL                hasVideo;
	BOOL                hasAudio;
	BOOL                hasSubtitles;

	BOOL                playing;
	BOOL                paused;
	BOOL                rewind;
	BOOL                fastForward;
	BOOL                fullscreen;
	BOOL                desktopMode;

	BOOL                end;
	BOOL                buffering;
	BOOL                hasToBuffer;
	DWORD               bufferingProgress;

	DWORD               loop;
	DWORD               baseTime;
	DWORD               stopTime;
	DWORD               volume;

	HANDLE              playbackMutex;
	HANDLE              videoThread;
	DWORD               videoThreadId;

	DWORD               videoFrames;
	DWORD               audioBytes;

	char                filename[512];

	/*
	 * Functions
	 */

	MediaPlayback();
	~MediaPlayback();

	MP_RESULT     OpenMedia(char *lpFilename, HWND hwndPlayback);

	MP_RESULT     OpenMediaSource(char *lpFilename);
	MP_RESULT     OpenMediaFromSource(HWND hwnd);

	BOOL          HasVideo();
	BOOL          HasAudio();

	char         *GetFilename();

	unsigned int  GetVideoWidth();
	unsigned int  GetVideoHeight();
	unsigned long GetVideoTime();
	unsigned long GetAudioTime();
	double        GetPlaybackProgress();
	unsigned int  GetActualTime();
	unsigned int  GetTotalTime();
	double        GetCurrentFps();

	BOOL          IsPaused();
	BOOL          IsPlaying();
	BOOL          IsInFullscreen();
	BOOL          IsOverlay();

	BOOL          IsBuffering();
	DWORD         GetBufferingProgress();
	MP_RESULT     UpdateBuffering();

	MP_RESULT     FlipToGDI();

	MP_RESULT     Play();
	MP_RESULT     Pause();
	MP_RESULT     NextFrame();
	MP_RESULT     Stop(int redrawWindow);
	MP_RESULT     Close();
	MP_RESULT     FastForward();
	MP_RESULT     Rewind();

	MP_RESULT     Seek(int percent);
	MP_RESULT     MaintainImage();

	MP_RESULT     SetDesktopMode(BOOL on);
	MP_RESULT     SetVideoRect(RECT *rect);
	MP_RESULT     SetFullscreen(int active, HWND hwnd);
	MP_RESULT     SetVolume(int volume);
	MP_RESULT     SetLoop(int loop);
};

#endif // MEDIA_PLAYBACK_H