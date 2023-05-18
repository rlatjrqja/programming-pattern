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

		vector<class Object> Hierarchy; //�� ������ ������Ʈ���� ������ �ִ� ����Ʈ �̸� Hierarchy

		void Draw()
		{
			for (int i = 0; i < Hierarchy.size() ; i++) //���̾��Ű�� ������Ʈ�� ������ �ִ� ���� �Լ� ����
			{
				Hierarchy[i].Render(ScreenBuffer);
			}
			for (int i = 0; i < Hierarchy.size(); i++) //���̾��Ű�� ������Ʈ���� ��� ����Ѵ�
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

		void Render(char *ScreendBuffer) //��ũ�� ���� �迭�� ���ڰ����� ����
		{
			
		}

		vector<class Component> components; //�� ������Ʈ�� ������ �ִ� ������Ʈ ����Ʈ
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
