#pragma once
/*
Node의 구성
 - name : 점심장소의 이름
 - desc : 부연설명
 - freq : 선택된 빈도수
*/
typedef struct LunchPlaceInfo {
	char* name;
	char* desc;
	int freq;
	LunchPlaceInfo* pNext;
}LunchPlaceInfo;

/*
- 2015년 9월 21일 : 모듈화의 작업이 되지 않아 추후에 작업이 필요한 상태
*/

/*
 - 파일 관리 부분 
   # openFile()
   # saveLunchPlaceInfoToFile()
   # closeFile()

 - Linked List관리 부분
   # LoadFile(char* path)
   # getLunchPlaceInfo(int index)
   # insertLunchPlaceInfo(char* name, char* desc)
   # modifyLunchPlaceInfo(int index, char* name, char* desc)
   # insertLunchPlaceInfo(char* name, char* desc)
   # deleteLunchPlaceInfo(int index)
 
 - Data parsing 부분
   # getLine(char* line)
   # getParsedData(char* line)

 - 점심장소 무작위 추첨 부분
   # LunchPlaceInfo* pickLunchPlace();

 - 메모리 관리 부분
   # release()
   # mallocNode() - 추가 구현 예정
   # freeNode() - 추가 구현 예정
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////파일 관리 부분///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
저장된 *txt 파일을 연다.
 - 해당 경로에 파일이 없으면 새 파일을 만든다.
 - input : File path
 - output : 0(success), non-zero(error)
*/
int openFile(char* path);

/*
Linked list에 저장된 노드를 open 했었던 파일의 이름으로 overwriting한다.
- close()를 호출하여 open()에서 열었던 파일을 닫는다.
- 파일 쓰기용으로 파일을 다시 연다.
- 현재 Linked list의 Node를 file에 쓴다.
- 파일을 닫는다.
- input : x
- output : 0(success), non-zero(error : 추가 예정)
*/
int saveLunchPlaceInfoToFile();

/*
open()에서 열었던 파일을 닫는다.
- input : x
- output : x
*/
void closeFile();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////Linked List관리 부분////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
파일안의 Data를 line별로 parsing하여 Linked List로 Load한다.
 - open()함수를 호출하여 특정 경로의 파일을 open한다
 - Parsing시 필요한 getLine()과 getParsedData()를 호출한다.
 - input : file path
 - output : 0(success), non-zero(error : 추가 예정)
*/
int LoadFile(char* path);

/*
Linked list에 저장된 노드들 중 특정 index에 해당하는 노드를 리턴한다.
- input : 사용자가 원하는 index 번호
- output : index에 해당하는 노드
*/
LunchPlaceInfo* getLunchPlaceInfo(int index);

/*
Linked list에 저장된 노드에서 새로운 노드를 추가한다.
- input : 점심장소 문자열, 부연설명 문자열
- output : 0(success), non-zero(error : 추가 예정)
*/
int insertLunchPlaceInfo(char* name, char* desc);

/*
Linked list에 저장된 노드에서 특정 index의 노드를 수정한다.
- input : 사용자가 지정한 index 번호, 점심장소 문자열, 부연설명 문자열
- output : 0(success), non-zero(error)
*/
int modifyLunchPlaceInfo(int index, char* name, char* desc);

/*
Linked list에 저장된 노드에서 특정 index의 노드를 삭제한다.
- input : 사용자가 지정한 index 번호
- output : 0(success), non-zero(error)
*/
int deleteLunchPlaceInfo(int index);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////Data Parsing 부분/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
파일의 끝부분까지 호출시마다 한 줄씩 라인을 읽어온다.
 - input : 1byte의 동적할당된 메모리
 - output : 파일에 있는 한 줄의 line 문자열
*/
static char* getLine(char* line);

/*
입력된 line을 Parsing한다.
 - 파싱 포맷 : <FREQ>=선택된 빈도수,<NAME>=점심장소이름,<DESC>=부연설명
 - input : 파일에서 읽어온 한 개의 line의 문자열
 - output : Parsing 후 얻어온 값들을 포함하고 있는 LunchPlaceInfo 구조체
 - Parsing 실패시 { NULL, NULL, -1 } 값의 LunchPlaceInfo구조체를 리턴
*/
static LunchPlaceInfo getParsedData(char* line);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////점심장소 무작위 추첨 부분/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Linked list에 저장된 노드들 중 random하게 1개의 노드를 뽑는다.	
 - 5개의 후보 노드를 뽑는다(같은 노드를 뽑은경우 다시 뽑는다).
 - 노드의 총 개수가 5개 이하인 경우, 전체 노드들이 후보가 된다.
 - 노드의 개수가 0인 경우 NULL 리턴
 - 뽑은 노드들 중 빈도수가 가장 적은 노드를 뽑는다(동일할 경우 먼저 뽑힌 노드를 선택한다).
 - 최종 선택된 노드의 빈도수를 1증가시킨다.
*/
LunchPlaceInfo* pickLunchPlace();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////메모리 관리 부분/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Linked list에 사용하였던 동적 할당 메모리를 모두 해제한다.
- input : x
- output : 0(success), non-zero(error : 추가 예정)
*/
int release();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
