#pragma once
#include <vector>

using namespace std;

namespace Musoeun
{
	class Scene
	{
	public:
		int Viewport_width;
		int Viewport_height;
		char ScreenBuffer[1] = { 'a' };

		vector<class Object> Hierarchy; //이 게임의 오브젝트들을 가지고 있는 리스트 이름 Hierarchy

		void Draw()
		{
			for (int i = 0; i < Hierarchy.size() ; i++) //하이어라키의 오브젝트가 가지고 있는 렌더 함수 실행
			{
				Hierarchy[i].Render(ScreenBuffer);
			}
			for (int i = 0; i < Hierarchy.size(); i++) //하이어라키의 오브젝트들을 모두 출력한다
			{
				cout << ScreenBuffer;
			}
		}
	};

	class Object
	{
	public:

		Object(){}
		~Object(){}

		int Object_position_x;
		int Object_position_y;

		void Render(char *ScreendBuffer) //스크린 버퍼 배열을 인자값으로 받음
		{
			
		}

		vector<class Component> components; //이 오브젝트가 가지고 있는 컴포넌트 리스트
	};

	class Component
	{
	public:
		void Start()
		{

		}
		void Update()
		{

		}
	};


	class GameLoop
	{
	public:
		void Run()
		{
			Scene scene1;
			scene1.Draw();
		}
	};
}
