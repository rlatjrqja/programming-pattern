#include <vector>
#include <iostream>
#include <Windows.h>

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

		virtual void Render(char* ScreenBuffer, int Viewport_width) //��ũ�� ���� �迭�� ���ڰ����� ����
		{
			if (SetActive) //Ȱ�� ���¶��
			{
				for (int j = 0; j < Object_scale_y; j++)
				{
					for (int i = 0; i < Object_scale_x; i++)
					{
						ScreenBuffer[i + j * (Viewport_width + 1)] = '*';
					}
				}
			}
		}

		vector<class Component> components; //�� ������Ʈ�� ������ �ִ� ������Ʈ ����Ʈ
	};

	class Cube :public Object
	{
	public:
		Cube(int x, int y) :Object(x, y)
		{

		}
		~Cube() {}

		void Render(char* ScreenBuffer, int Viewport_width) //��ũ�� ���� �迭�� ���ڰ����� ����
		{
			if (SetActive) //Ȱ�� ���¶��
			{
				for (int j = 0; j < Object_scale_y; j++)
				{
					for (int i = 0; i < Object_scale_x; i++)
					{
						ScreenBuffer[i + j * (Viewport_width + 1)] = '*';
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
			//��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (8 << 4) + 0b0001);//b:2���� e:������ x:16���� l:8bit*00000000
			for (int i = 0; i < strlen(text); i++)
			{
				ScreenBuffer[i] = text[i];
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (8 << 4) + 0b1111);
		}
		int Selected()
		{
			COORD pos = { Object_position_x,Object_position_y+10 };
			COORD pos2 = { 0,0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (8 << 4) + 0b0001);
			cout << text;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (8 << 4) + 0b1111);
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
				for (int i = 0; i < width + 1; i++)/* ���๮�ڶ����� + 1*/
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


		vector<Object*> Hierarchy; //�� ������ ������Ʈ���� ������ �ִ� ����Ʈ �̸� Hierarchy


		void Draw()
		{

			for (int i = 0; i < Hierarchy.size(); i++) 
			//���̾��Ű�� ������Ʈ�� ������ �ִ� ���� �Լ� ����
			{
				int position = ((Hierarchy[i]->Object_position_y) + 1) * (Viewport_width + 1) + (Hierarchy[i]->Object_position_x + 1);
				Hierarchy[i]->Render(&ScreenBuffer[position], Viewport_width);
				//�� �����ǿ� 1�� �׵θ� ������, �ǵ� 1�� ���� ������
			}

			cout.write(ScreenBuffer.data(), ScreenBuffer.size());
		}
	};
}