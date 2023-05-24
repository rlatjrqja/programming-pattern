#pragma once
#include "Asset.hpp";

using namespace std;
using namespace asset;

namespace Musoeun
{
	void MGameLoop()
	{
		bool isGameing = true;

		Scene scene1(20,20); //20x20 크기 씬 생성

		Object cube1(3, 3);
		cube1.Object_scale_x = 5;
		cube1.Object_scale_y = 2;

		Object cube2(10, 10); //x = 2, y = -2 위치에 큐브 생성

		Object cube3(3, 7);
		cube3.Object_scale_x = 4;
		scene1.Hierarchy.push_back(cube1);
		scene1.Hierarchy.push_back(cube2);
		scene1.Hierarchy.push_back(cube3);

		while (isGameing)
		{
			scene1.Draw();
		}
	};
}
