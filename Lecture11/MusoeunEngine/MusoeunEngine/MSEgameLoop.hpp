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
		void Render(char* ScreenBuffer) //��ũ�� ���� �迭�� ���ڰ����� ����
		{
			if (SetActive)
			{
				ScreenBuffer[(Object_position_x + 1) * Object_position_y] = '*';
			}
		}

		vector<class Component> components; //�� ������Ʈ�� ������ �ִ� ������Ʈ ����Ʈ
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

			int j = 0;  /* ���� index */

			while (j < height)
			{
				int i = 0;	/* ���� index */

				while (i < width + 1) /* ���๮�ڶ����� + 1*/
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

		vector<class Object> Hierarchy; //�� ������ ������Ʈ���� ������ �ִ� ����Ʈ �̸� Hierarchy

		void Draw()
		{
			for (int i = 0; i < Hierarchy.size() ; i++) //���̾��Ű�� ������Ʈ�� ������ �ִ� ���� �Լ� ����
			{
				Hierarchy[i].Render(&ScreenBuffer[((Hierarchy[i].Object_position_y)+1)* Viewport_height+ (Hierarchy[i].Object_position_x+1)+1]);//�� �����ǿ� 1�� �׵θ� ������, �ǵ� 1�� ���� ������
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
