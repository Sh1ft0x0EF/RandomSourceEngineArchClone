
#ifndef XLIB_WINDOW_H
#define XLIB_WINDOW_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

class IXLibEventHandler
{
public:
	virtual ~IXLibEventHandler() {}
	virtual void HandleEvent( const XEvent &event, bool bQuit ) = 0;
};

class CNullEventHandler: public IXLibEventHandler
{
public:
	virtual void HandleEvent(const XEvent &event, bool bQuit) {}
};

class CXLibWindow
{
public:
	CXLibWindow();
	~CXLibWindow();
	
	void SetEventHandler( IXLibEventHandler *pHandler );
	
	bool OpenWindow( int argc, char *argv[] );
	void CloseWindow();
	
	void ResizeWindow( int width, int height );
	
	void ProcessEvents();
	
	Display *GetDisplay() const { return m_pDisplay; }
	const Window &GetWindow() const { return m_Window; }
	
	int32_t GetScreen() const { return m_iScreen; }
	
	Pixmap CreatePixmap( float width, float height );
	void FreePixmap( Pixmap pixmap );
	
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	
	float GetAspectRatio() const;
	
	KeySym GetKey( const XKeyEvent &event ) const;
	
	void SetAutoRepeat( bool bOn )
	{
		bOn ? XAutoRepeatOn(m_pDisplay) : XAutoRepeatOff(m_pDisplay);
		XFlush(m_pDisplay);
	}
	
private:
	static CNullEventHandler m_NullEventHandler;

private:
	Display *m_pDisplay;
	int m_iScreen;
	Window m_Window;
	
	Atom m_wmDeleteMessage;
	
	IXLibEventHandler *m_pEventHandler;
	
	int m_iWindowWidth;
	int m_iWindowHeight;
};

#endif // XLIB_WINDOW_H
