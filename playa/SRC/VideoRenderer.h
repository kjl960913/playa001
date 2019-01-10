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

#ifndef VIDEORENDERER_H
#define VIDEORENDERER_H

/*
 * Base Classes
 */

#include "VideoRendererOverlay.h"
#include "VideoRendererRGB.h"
#include "MediaClasses.h"

/*
 * VideoRenderer Wrapper Class
 */

class MediaVideoRenderer : public MediaItemVideoRenderer {

	MediaVideoRendererOverlay *overlayRenderer;
	MediaVideoRendererRGB     *rgbRenderer;
	MediaVideoRenderer        *renderer;

public:

	MediaVideoRenderer();
	~MediaVideoRenderer();

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
	 * Video Renderer Functions
	 */

	MP_RESULT Init(HWND hwnd, unsigned int width, unsigned int height, media_video_mode_t preferedMode);
	MP_RESULT InitFullscreen(HWND hwnd, unsigned int width, unsigned int height, media_video_mode_t preferedMode);

	/*
	 * This 2 are not used
	 *
	 */

	MP_RESULT Init(HWND hwnd, unsigned int width, unsigned int height);
	MP_RESULT InitFullscreen(HWND hwnd, unsigned int width, unsigned int height);

	/*
	 * The rest of them
	 *
	 */

	media_video_mode_t GetVideoMode();
	MP_RESULT          Stop();
	RECT              *GetFullscreenRects(); 

	MP_RESULT Draw(MediaBuffer *buffer, RECT *rect, int frameNumber, int invertFlag);
	MP_RESULT DrawFullscreen(MediaBuffer *buffer, int frameNumber, int invertFlag, int desktopMode);

	MP_RESULT Close();
};

#endif