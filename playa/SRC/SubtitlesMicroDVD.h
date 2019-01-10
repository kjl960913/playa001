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


#ifndef SUBTITLES_MICRODVD_H
#define SUBTITLES_MICRODVD_H

#include "Input.h"
#include "MediaClasses.h"

#define SUB_INPUT_BUFFER_SIZE 512

/*
 * The MicroDVD subtitles
 * reader Class...
 *
 */

class MediaSubtitlerMicroDVD : public MediaItemSubtitler {

private:

	MediaBuffer *inputBuffer;
	MediaInput  *inputFile;
	DWORD        firstFrame;
	DWORD        lastFrame;
	DWORD        firstSubtitleFrame;
	DWORD        previousLastFrame;
	subtitles_t  subtitles;

	/*
	 * Private Funcs
	 */

	MP_RESULT ParseSubtitle();
	MP_RESULT SeekToFrame(DWORD frameNumber);

public:

	MediaSubtitlerMicroDVD();
	~MediaSubtitlerMicroDVD();

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
	 * Subtitler
	 */

	MP_RESULT     Open(char *lpFilename);
	subtitles_t  *GetSubtitles(DWORD frameNumber);
	MP_RESULT     Close();

};

#endif