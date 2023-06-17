#include <vector>
#include <iostream>
#include <Windows.h>

#define red 0b0100
#define green 0b0010
#define blue 0b0001
#define yellow 0b0110
#define bluegreen 0b0011
#define purple 0b0101
#define gray 0b0111
#define black 0b0000
#define white 0b1111

using namespace std;

namespace asset
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

		Object() {}
		Object(int x, int y)
		{
			SetPosition(x, y);
		}
		virtual ~Object() {}

		void SetPosition(int x, int y)
		{
			Object_position_x = x;
			Object_position_y = y;
		}
		void SetScale(int x, int y)
		{
			Object_scale_x = x;
			Object_scale_y = y;
		}

		virtual void Render(char* ScreenBuffer, int Viewport_width) //스크린 버퍼 배열을 인자값으로 받음
		{
			if (SetActive) //활성 상태라면
			{
				for (int j = 0; j < Object_scale_y; j++)
				{
					for (int i = 0; i < Object_scale_x; i++)
					{
						ScreenBuffer[i + j * (Viewport_width + 1)] = '+';
					}
				}
			}
		}

		vector<class Component> components; //이 오브젝트가 가지고 있는 컴포넌트 리스트
	};

	class Cube :public Object
	{
	public:
		Cube(int x, int y) :Object(x, y)
		{

		}
		~Cube() {}

		void Render(char* ScreenBuffer, int Viewport_width) //스크린 버퍼 배열을 인자값으로 받음
		{
			if (SetActive) //활성 상태라면
			{
				for (int j = 0; j < Object_scale_y; j++)
				{
					for (int i = 0; i < Object_scale_x; i++)
					{
						ScreenBuffer[i + j * (Viewport_width + 1)] = '#';
					}
				}
			}
		}
	};
	class UI:public Object
	{
	public :
		char text[20];
		UI(int x, int y,const char* str) :Object(x, y)
		{
			strcpy_s(text, str);
		}
		~UI() {}
		void SetText(const char* str)
		{
			strcpy_s(text, str);
		}
		void SetText(const char* str,int)
		{
			strcpy_s(text, str);
		}

		void Render(char* ScreenBuffer, int Viewport_width)
		{
			for (int i = 0; i < strlen(text); i++)
			{
				ScreenBuffer[i] = text[i];
			}
		}

		int Selected(int color) //b:2진수 e:유리수 x:16진수 l:8bit*00000000
		{
			COORD pos = { Object_position_x + 1,Object_position_y + 1 };

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0b0000 << 4) + color);
			cout << text;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0b0000 << 4) + 0b1111);
			return 1;
		}
	};

	class Scene
	{
	public:

		vector<char> ScreenBuffer;

		int Viewport_width = 10;
		int Viewport_height = 10;

		Scene(int width, int height) : ScreenBuffer((width + 1)* height)
		{
			Viewport_width = width;
			Viewport_height = height;


			for (int j = 0; j < height; j++)
			{
				for (int i = 0; i < width + 1; i++)/* 개행문자때문에 + 1*/
				{
					if (i == width)
						ScreenBuffer[i + (j * (width + 1))] = '\n';
					else
					{
						if (i == 0 || i == (width - 1) || j == 0 || j == (height - 1))
							ScreenBuffer[i + (j * (width + 1))] = '#';
						else
							ScreenBuffer[i + (j * (width + 1))] = ' ';
					}
				}
			}

			ScreenBuffer[height * (width + 1) - 1] = '\0';
		}
		~Scene() {}


		vector<Object*> Hierarchy; //이 게임의 오브젝트들을 가지고 있는 리스트 이름 Hierarchy


		void Draw()
		{

			for (int i = 0; i < Hierarchy.size(); i++) 
			//하이어라키의 오브젝트가 가지고 있는 렌더 함수 실행
			{
				int position = ((Hierarchy[i]->Object_position_y) + 1) * (Viewport_width + 1) + (Hierarchy[i]->Object_position_x + 1);
				Hierarchy[i]->Render(&ScreenBuffer[position], Viewport_width);
				//각 포지션에 1은 테두리 때문에, 맨뒤 1은 개행 때문에
			}

			cout.write(ScreenBuffer.data(), ScreenBuffer.size());
		}
	};
}