#pragma once
#include <vector>
#include "cursorCon.hpp"

using namespace std;

namespace Musoeun
{
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

	class Object
	{
	public:

		int Object_position_x = 0;
		int Object_position_y = 0;

		int Object_scale_x = 1;
		int Object_scale_y = 1;

		bool SetActive = true;

		Object(int x, int y)
		{
			SetPosition(x, y);
		}
		~Object() {}

		void SetPosition(int x, int y)
		{
			Object_position_x = x;
			Object_position_y = y;
		}

		//vector<char>
		void Render(char* ScreenBuffer) //스크린 버퍼 배열을 인자값으로 받음
		{
			if (SetActive)
			{
				ScreenBuffer[(Object_position_x + 1) * Object_position_y] = '*';
			}
		}

		vector<class Component> components; //이 오브젝트가 가지고 있는 컴포넌트 리스트
	};

	class Scene
	{
	public:

		vector<char> ScreenBuffer;

		int Viewport_width=10;
		int Viewport_height=10;

		Scene(int width, int height) : ScreenBuffer((width + 1)* height)
		{
			Viewport_width = width;
			Viewport_height = height;

			int j = 0;  /* 세로 index */

			while (j < height)
			{
				int i = 0;	/* 가로 index */

				while (i < width + 1) /* 개행문자때문에 + 1*/
				{
					if (i == width)
						ScreenBuffer[i + (j * (width + 1))] = '\n';
					else
					{
						if (i == 0 ||i == (width - 1) || j == 0 || j == (height - 1))
							ScreenBuffer[i + (j * (width + 1))] = '#';
						else
							ScreenBuffer[i + (j * (width + 1))] = ' ';
					}
					i += 1;
				}
				j += 1;
			}
			ScreenBuffer[height * (width + 1) - 1] = '\0';
		}
		~Scene() {}

		vector<class Object> Hierarchy; //이 게임의 오브젝트들을 가지고 있는 리스트 이름 Hierarchy

		void Draw()
		{
			for (int i = 0; i < Hierarchy.size() ; i++) //하이어라키의 오브젝트가 가지고 있는 렌더 함수 실행
			{
				Hierarchy[i].Render(&ScreenBuffer[((Hierarchy[i].Object_position_y)+1)* Viewport_height+ (Hierarchy[i].Object_position_x+1)+1]);//각 포지션에 1은 테두리 때문에, 맨뒤 1은 개행 때문에
			}

			cursor::gotoxy(0, 0);
			cout.write(ScreenBuffer.data(), ScreenBuffer.size());
		}
	};

	void MGameLoop()
	{
		Scene scene1(20,20);
		Object obj1(1, 1);
		scene1.Hierarchy.push_back(obj1);

		while (true)
		{
			//system("cls");
			scene1.Draw();
		}
	};
}
