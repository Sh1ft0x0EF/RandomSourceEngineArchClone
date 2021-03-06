
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "XLibWindow.h"
#include "mathutil.h"

#include <string>
#include <vector>
#include <memory>

class CGraphicsComponent;
class CEntity;
struct renderableContext_s;
typedef struct renderableContext_s renderableContext_t;

typedef struct text_s
{
	uint32_t x, y;
	std::string text;
} text_t;

class CGraphicsEngine
{
public:
	CGraphicsEngine( CXLibWindow &window );
	~CGraphicsEngine();
	
	bool		SupportsDBX() const;
	
	void		DrawText( float x, float y, const std::string &text );
	
	void		ClearWindow();
	
	void		BeginFrame();
	void		EndFrame();
	
	void		QueueRenderables( const std::shared_ptr< std::vector<renderableContext_t> > &pRenderables );
	
private:
	// converts the 0.0f-1.0f range of x,y to a uint_point_t in terms of pixels on the screen
	void		NormalizedToScreenRes( float in_x, float in_y, uint_point_t &out ) const;
	
	void		RenderObject( const renderableContext_t &renderableContext );
	
	uint32_t	GetColour( const char *colour );
	void		SetActiveColour( uint32_t colour );
	
private:
	CXLibWindow &m_window;
	GC m_graphicsContext;
	std::shared_ptr< std::vector<renderableContext_t> > m_pRenderables;
	std::vector<text_t> m_textQueue;
};

#endif // GRAPHICS_H
