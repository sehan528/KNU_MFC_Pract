
// KNU_MFC_PractView.cpp: CKNUMFCPractView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "KNU_MFC_Pract.h"
#endif

#include "KNU_MFC_PractDoc.h"
#include "KNU_MFC_PractView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKNUMFCPractView

IMPLEMENT_DYNCREATE(CKNUMFCPractView, CView)

BEGIN_MESSAGE_MAP(CKNUMFCPractView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CKNUMFCPractView 생성/소멸

CKNUMFCPractView::CKNUMFCPractView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CKNUMFCPractView::~CKNUMFCPractView()
{
}

BOOL CKNUMFCPractView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CKNUMFCPractView 그리기

void CKNUMFCPractView::OnDraw(CDC* /*pDC*/)
{
	CKNUMFCPractDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CClientDC dc(this);
	CRect rect;
	GetClientRect(rect);
	int stepx = rect.right / 200; // 원의 반지름이 100인 원을 계속 그려야 된다.
	int stepy = rect.bottom / 200;
	int i, j = 0;

	/*
	for (int i = 0; i < stepx; i++) {
		dc.Ellipse(i*200, 0, (i+1)*200, 200);!@#
	}
	for (int j = 0; j < stepy; j++) {
		dc.Ellipse(0, j*200, 200, (j+1)*200);
	}
	*/ // 원시적 해결.

	for (i = 0; i < stepy; i++) {
		for (j = 0; j < stepx; j++) {
			dc.Ellipse((j) * 200, i * 200, (j + 1) * 200, (i + 1) * 200);
		}
		dc.Ellipse(0, i * 200, 200, (i + 1) * 200);
	}
	/* 출력 솔루션 해결중. MessageBox int data casting 이 막혔음.
	int check = i * j;
	printf("%d", i * j);
	MessageBox(L"TEST" + check, L"Result", MB_OK | MB_ICONINFORMATION);
	*/
}


// CKNUMFCPractView 인쇄

BOOL CKNUMFCPractView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CKNUMFCPractView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CKNUMFCPractView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CKNUMFCPractView 진단

#ifdef _DEBUG
void CKNUMFCPractView::AssertValid() const
{
	CView::AssertValid();
}

void CKNUMFCPractView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKNUMFCPractDoc* CKNUMFCPractView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKNUMFCPractDoc)));
	return (CKNUMFCPractDoc*)m_pDocument;
}
#endif //_DEBUG


// CKNUMFCPractView 메시지 처리기
