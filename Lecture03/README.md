#Lecture 03 : VI에디터 실습 및 C++ 기초
* VI 에디터의 기초 사용법을 실습한다
* G++을 이용하여 기초 C++ 컴파일을 해본다
* 2023-03-25 복습 겸 배운내용 추가 정리 하려고 켬
* 작업 이전 mingW-64로 가서 컴파일러를 다운해야 한다
* 윈도우의 환경변수 편집에서 path에 컴파일러가 있는 bin파일의 경로를 추가한다
	@ 집에서 gcc 명령어를 입력하니 command not found 라는 문구가 나왔다
		> 컴파일러 설치 후 git bash를 재시작하지 않았기 때문
* gcc 소스파일명 -o abc 을 입력하면 abc라는 이름으로 exe파일이 생긴다
* -o 파일명을 입력하지 않고 두개 이상의 소스파일을 컴파일하면 나중에 컴파일한 소스코드만 a.exe로 남게된다
* 파일명은 mv oldname newname 으로 변경할 수 있고, 소스코드를 변경했다면 최초 컴파일과 동일하게 입력해 덮어쓴다
* c++로 짜여진 main.cpp의 std::endl; 는 출력후 버퍼를 비우며, 개행한다
* endl 대신 ends (null삽입), fixed (소수점 이하 자리 고정) 등으로 대체될 수 있다
