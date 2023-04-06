#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <tchar.h>

float f(float x, float y, float z) {
	float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
	return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z) {
	for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
		if (f(x, y, z) <= 0.0f)
			return y;

	return 0.0f;
}

int main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
	                        0xc);//SetConsoleTextAttribute()是Windows系统中一个可以设置控制台窗口字体颜色和背景色的计算机函数
	HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);// GetStdHandle()检索指定标准设备的句柄（标准输入、标准输出或标准错误）
	_TCHAR buffer[25][80] = { _T(' ') };
	_TCHAR ramp[] = _T("vvvvvvvv");
	int count = 0;
	int count1 = 0;

	for (float t = 0.0f;; t += 0.1f) {
		int sy = 0;
		float s = sinf(t);
		float a = s * s * s * s * 0.2f;

		for (float z = 1.3f; z > -1.2f; z -= 0.1f) {
			_TCHAR *p = &buffer[sy++][0];
			float tz = z * (1.2f - a);

			for (float x = -1.5f; x < 1.5f; x += 0.05f) {
				float tx = x * (1.2f + a);
				float v = f(tx, 0.0f, tz);

				if (v <= 0.0f) {
					float y0 = h(tx, tz);
					float ny = 0.01f;
					float nx = h(tx + ny, tz) - y0;
					float nz = h(tx, tz + ny) - y0;
					float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
					float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
					*p++ = ramp[(int)(d * 5.0f)];
				} else
					*p++ = ' ';
			}
		}

		for (sy = 0; sy < 25; sy++) {
			COORD coord = { 0, sy };
			SetConsoleCursorPosition(o, coord);//作用是设置控制台(cmd)光标位置
			WriteConsole(o, buffer[sy], 79, NULL, 0);//从当前光标位置开始，将字符串写入控制台屏幕缓冲区
		}

		if (count <= 22) {
			printf("I Love You") ;//表白内容
			printf("            To CSDN");// 被表白者的名字
			count++;
		} else {
			printf("You Are My Best Lover.\n");
			count++;

			if (count >= 44) {
				count = 0;
			}
		}

		Sleep(36);//Sleep函数:执行挂起一段时间，也就是等待一段时间在继续执行
	}
}