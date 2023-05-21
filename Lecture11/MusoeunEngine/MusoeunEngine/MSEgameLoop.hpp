#pragma once
#include "Asset.hpp";

using namespace std;
using namespace asset;

namespace Musoeun
{
	

	void MGameLoop()
	{
		bool isGameing = true;

		Scene scene1(20,20); //20x20 ũ�� �� ����
		Object cube1(7, 10);
		cube1.Object_scale_x = 2;
		cube1.Object_scale_y = 4;
		Object cube2(2, 2);//x = 2, y = -2 ��ġ�� ť�� ����
		scene1.Hierarchy.push_back(cube1);
		scene1.Hierarchy.push_back(cube2);

		while (isGameing)
		{
			scene1.Draw();
		}
	};
}
