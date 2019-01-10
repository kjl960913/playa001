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

#ifndef AUDIO_RENDERER_H
#define AUDIO_RENDERER_H

#include "MediaClasses.h"
#include "DebugFile.h"


/*
 * Direct Sound Includes
 */

#include <math.h>
#include <dsound.h>

/*
 * Audio Renderer Class
 *
 * - Only one available for the moment
 *
 */

class MediaAudioRenderer : public MediaItemAudioRenderer {

public:

	LPDIRECTSOUND       lpDirectSound;
	LPDIRECTSOUNDBUFFER lpBuffer;
	WAVEFORMATEX       *ourFormat;

    DWORD               dwBufferSize;     
    DWORD               dwNextWriteOffset; 
    DWORD               dwProgress;
	DWORD               dwLastPlayPos;
	
	unsigned long       dwPlayed;
	
	HANDLE              audioThread;
	UINT                uTimerID;
	LONG                lInTimer;
	DWORD               id;
	
	MediaAudioCallback  callback;
	void               *lpData;
	int                 paused;

	/*
	 * Functions
	 *
	 */

	MediaAudioRenderer();
	~MediaAudioRenderer();

	/*
	 * Media Item functions
	 */

	media_type_t  GetType();
	char         *GetName();
	
	MP_RESULT     Connect(MediaItem *item);
	MP_RESULT     ReleaseConnections();

	DWORD         GetCaps();
	MP_RESULT     Configure(HINSTANCE hInstance, HWND hwnd);

	/*
	 * Audio Renderer Functions
	 */

	MP_RESULT     Open(HWND hwnd, WAVEFORMATEX *inFormat);

	MP_RESULT     SetCallback(void *lpData, MediaAudioCallback callback);
	MP_RESULT     SetVolume(unsigned int volume);

	unsigned long GetAudioTime();
	MP_RESULT     Bufferize();

	MP_RESULT     Start();
	MP_RESULT     Pause();
	MP_RESULT     Stop();

	MP_RESULT     Close();
};

#endif