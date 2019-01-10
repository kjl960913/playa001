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

#ifndef VIDEODECODER_H
#define VIDEODECODER_H

/*
 * Base Classes
 */

#include "VideoDecoderDecore.h"
#include "VideoDecoderVFW.h"
#include "MediaClasses.h"

/*
 * VideoDecoder Class
 */

class MediaVideoDecoder : public MediaItemVideoDecoder {

private:

	MediaItemVideoDecoder   *decoder;

public:

	MediaVideoDecoderDecore *decoreDecoder;
	MediaVideoDecoderVFW    *vfwDecoder;

	MediaVideoDecoder();
	~MediaVideoDecoder();

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
	 * Video Decoder Functions
	 *
	 */

	unsigned int       GetFrameSize();

	media_video_mode_t GetVideoMode();
	BOOL               GetInvertFlag();
	MP_RESULT          SetVideoMode(media_video_mode_t mode);

	MP_RESULT          SetQuality(DWORD quality);
	DWORD              GetQuality();

	MP_RESULT          Decompress(MediaBuffer *mb_out, unsigned int stride);
	MP_RESULT          Drop(MediaBuffer *mb_out, unsigned int stride);

};


#endif // VIDEODECODER_H