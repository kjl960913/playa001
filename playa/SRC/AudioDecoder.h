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


#ifndef AUDIO_DECODER_H
#define AUDIO_DECODER_H

#include "AudioDecoderMP3.h"
#include "AudioDecoderACM.h"
#include "MediaClasses.h"

/*
 * Audio Decoder Wrapper
 *
 */

class MediaAudioDecoder : public MediaItemAudioDecoder {

private:

	MediaAudioDecoderACM  *acmDecoder;
	MediaAudioDecoderMP3  *mp3Decoder;
	MediaItemAudioDecoder *decoder;

public:

	MediaAudioDecoder();
	~MediaAudioDecoder();

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

	unsigned int Decompress(void *buffer, unsigned int size);

};

#endif