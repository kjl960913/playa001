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


#ifndef AUDIO_DECODER_MP3_H
#define AUDIO_DECODER_MP3_H

#include "MediaClasses.h"
#include "mp3/mpglib.h"
#include "mp3/ring.h"

/*
 * ACM wrapper
 *
 */

#define MP3_INPUT_BUFFER_SIZE 2048

class MediaAudioDecoderMP3 : public MediaItemAudioDecoder {

private:

	MediaItemDecaps *decaps;

	WAVEFORMATEX    *oFormat;
	char            *in_buffer;
	char            *out_buffer;
	
	struct mpstr    mp;
	int             last_result;
	int             real_size;

	int DecompressMp3(char *outmemory, int outmemsize, int *done);

public:

	MediaAudioDecoderMP3();
	~MediaAudioDecoderMP3();

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