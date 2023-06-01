#pragma once

void CheckError(int e)
{
	if (e == 1)
	{
		printf("[line:%d, %s]에러가 발생했습니다.\n", __LINE__, __func__);
		exit(1);
	}
}