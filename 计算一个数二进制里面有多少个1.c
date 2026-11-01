#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//主函数（entry point）：程序从这里开始执行，返回 0 表示正常结束
int main() {

	//任务：统计并输出一个整数在内存中的二进制表示里 1 的个数
	int a = -1;//被统计的数；-1 在 32 位 int 的补码（two's complement）里是 32 个 1
	int sum = 0;//统计 1 的个数的计数器（counter）
	int i = 1;//按位与（bitwise AND）用的掩码（mask），初值为 1
	printf("a= %d\n", a);
	//为什么要先把 a 转成 unsigned int（无符号整数）？
	//因为对负的 int 直接右移属于实现定义行为（implementation-defined），
	//在 MSVC 上 -1 >> 1 结果仍然是 -1，b 永远不会变成 0，会造成死循环（infinite loop）；
	//转成无符号数后右移是逻辑右移（logical shift），高位补 0，循环一定能结束。
	unsigned int b = (unsigned int)a;
	while (b) {//b 为 0 说明二进制位都处理完了，退出循环
		i = 1;//每轮都要把掩码重置为 1；否则某一位是 0 后 i 一直是 0，后面的 1 会漏统计
		i = i & b;//用掩码取 b 的最低位（least significant bit）：该位是 1 则 i=1，是 0 则 i=0
		if (i == 1)//只有最低位是 1 时，计数器才加 1
			sum++;
		b = b >> 1;//整体右移一位，丢掉刚检查过的最低位，下一轮检查新的最低位

	}
	printf("a二进制中1有= %d个\n", sum);
	
	return 0;
}
