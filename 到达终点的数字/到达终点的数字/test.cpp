//每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。
//返回到达终点需要的最小移动次数。
//
//示例 1:
//
//输入 : target = 3
//输出 : 2
// 解释 :
//	第一次移动，从 0 到 1 。
//	第二次移动，从 1 到 3 。
//	示例 2 :
//
//输入 : target = 2
// 输出 : 3
//  解释 :
//	 第一次移动，从 0 到 1 。
//	 第二次移动，从 1 到 - 1 。
//	 第三次移动，从 - 1 到 2 。

//思路：1.如果现在的目标数字为4，只管无脑加1+2+3 = 6 6-4 = 偶数，所以将2调整为-2，所以也就只需要步
//2.假设现在的目标数字是7，1+2+3+4 = 10 10-7 = 奇数  这个奇数可以分解成1+2 将2调整成-2，1可以先走一步，再退一步
//3.但是实际上此时又有了新的情况，1+2+3+4+2 = 15 - 7 = 8 又是偶数，所以我们基于上一种办法只需多走一步，如果走一步差
//不为偶数时才需要走两步

class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		int cur = 0, sum = 0;
		while (sum < target)
		{
			cur++;
			sum += cur;
		}

		int gap = sum - target;
		if (gap % 2 == 0)
			return cur;
		else
		{
			if (cur % 2 == 0)
				return cur + 1;
			else
				return cur + 2;
		}
	}
};