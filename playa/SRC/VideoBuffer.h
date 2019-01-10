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

#ifndef VIDEO_BUFFER_H
#define VIDEO_BUFFER_H

#include "MediaClasses.h"

/*
 * Defines
 *
 */ 

#define VIDEO_BUFFER_SIZE                5
#define VIDEO_BUFFER_END_NOT_REACHED 32768

/* 
 * Video Buffer Class
 *
 * - only one implementation
 *
 */

class MediaVideoBuffer : public MediaItemVideoBuffer {

public:

	MediaBuffer           *buffer[VIDEO_BUFFER_SIZE];
	MediaItemVideoDecoder *decoder;

	DWORD                  bufferedFrames;
	HANDLE                 bufferingMutex;
	HANDLE                 bufferingThread;
	DWORD                  bufferingThreadId;

	unsigned int           stride;
	BOOL                   suspended;
	DWORD                  endReachedAt;

	BOOL                   enabled;

	MediaVideoBuffer();
	~MediaVideoBuffer();

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
	 * Video Buffer functions
	 */

	MP_RESULT     StartBuffering(unsigned int stride);
	MP_RESULT     StopBuffering();

	MediaBuffer  *GetOneFrame();
	MediaBuffer  *GetLastFrame();
	MP_RESULT     DropOneFrame();

};

#endif // VIDEO_BUFFER_H