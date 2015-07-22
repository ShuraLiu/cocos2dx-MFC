#ifndef __MFC_GLVIEW__H_
#define __MFC_GLVIEW__H_



#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCGLView.h"

NS_CC_BEGIN

class MFCGLView : public GLView
{
public:
	//����MFCGLView
	static MFCGLView* create(HWND hWnd);


	//������������
	MFCGLView(void);
	virtual ~MFCGLView(void);


	//�Զ���GLView������д�ĺ���
	virtual bool isOpenGLReady();
	virtual void end();
	virtual void swapBuffers();
	virtual void setFrameSize(float width, float height);
	virtual void setIMEKeyboardState(bool bOpen);

	//��ʼ��GLView
	virtual bool init(HWND hWnd);

	//������Ϣ����
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

private:
	//��ʼ��OpenGL
	bool InitGL();

	//�ͷ�OpenGL
	void ReleaseGL();

	HWND                                m_hWnd;               //View��Ӧ�Ĵ��ھ��
	HDC                                 m_hDC;                //���ڻ�ͼ�豸
	HGLRC                               m_hRC;                //OpenGL��Ⱦ����

	bool                                m_bCaptured;          //�Ƿ�׽���
	float                               m_fFrameZoomFactor;   //֡���ű���
};

NS_CC_END

#endif // !__MFC_GLVIEW__H_