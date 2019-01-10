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


#ifndef AUDIO_DECODER_ACM_H
#define AUDIO_DECODER_ACM_H

#include "MediaClasses.h"
#include "RingBuffer.h"

/*
 * ACM wrapper
 *
 */

#include <mmsystem.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <mmreg.h>
#include <msacm.h>

class MediaAudioDecoderACM : public MediaItemAudioDecoder {

private:

	MediaItemDecaps *decaps;

	HACMSTREAM       hacm;
	ACMSTREAMHEADER  acmHeader;
	DWORD            acm;
	DWORD            acmLeft;
	DWORD            acmInLeft;

	DWORD			 outputSize;
	DWORD            inputSize;

	WAVEFORMATEX    *oFormat;
	char            *in_buffer;
	char            *out_buffer;

	MediaRingBuffer *ring;

public:

	MediaAudioDecoderACM();
	~MediaAudioDecoderACM();

	/*
	 * MediaItem Funcs
	 */

	media_type_t  GetType();
	char         *GetName();
	
	MP_RESULT     Connect(MediaItem *item);
	MP_RESULT     ReleaseConnections();

	DWORD         GetCaps();
	MP_RESULT     Configure(HINSTANCE hInstance, HWND hwnd);

	/*
	 * Audio Decoder
	 */

	WAVEFORMATEX *GetAudioFormat();
	MP_RESULT     EmptyAudioBuffer();

	unsigned int  Decompress(void *buffer, unsigned int size);

};

#endif