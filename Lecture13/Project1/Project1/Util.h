#pragma once

void CheckError(int e)
{
	if (e == 1)
	{
		printf("[line:%d, %s]������ �߻��߽��ϴ�.\n", __LINE__, __func__);
		exit(1);
	}
}